#pragma once
float last_stw_shot_time = 0.f;
void STW_DirectAttack(BasePlayer* target, BoneList bone = head) {
    if (!local_player || !target || !local_player->active_weapon()) return;
    if (local_player->is_dead() || local_player->is_sleeping() || local_player->is_wounded()) return;
    if (RPC_Counter.Calculate() > 100) return;

    auto baseprojectile = local_player->active_entity<BaseProjectile>();
    if (!baseprojectile) return;

    auto classname = baseprojectile->get_class_name();
    if (!classname) return;
    if (!u_crt::m_strcmp(classname, _("BaseProjectile")) && 
        !u_crt::m_strcmp(classname, _("BowWeapon")) && 
        !u_crt::m_strcmp(classname, _("CompoundBowWeapon")) &&
        !u_crt::m_strcmp(classname, _("BaseLauncher")) && 
        !u_crt::m_strcmp(classname, _("CrossbowWeapon")) && 
        !u_crt::m_strcmp(classname, _("FlintStrikeWeapon")) && 
        !u_crt::m_strcmp(classname, _("SnowballGun")) &&
        !u_crt::m_strcmp(classname, _("SpinUpWeapon"))) {
        return;
    }
    if (!Reload(baseprojectile)) return;
    if (!CLProject(baseprojectile)) return;
    if (Time::time() < baseprojectile->nextAttackTime()) return;
    if (local_player->active_weapon()->isBroken()) return;
    float currentTime = Time::fixedTime();
    float timeSinceLastShot = currentTime - last_stw_shot_time;
    if (timeSinceLastShot < baseprojectile->repeatDelay()) return;

    if (!local_player->eyes()) return;
    Vector3 eyePos = local_player->eyes()->position();
    Transform* targetTransform = target->GetTransform(bone);
    if (!targetTransform) return;
    
    Vector3 targetPos = targetTransform->position();
    float distance = eyePos.Distance(targetPos);

    if (distance > vars::weapon::stw_max_distance) return;
    if (distance < 1.f) return;

    auto mod = ((Networkable*)baseprojectile->primaryMagazine()->ammoType())->GetComponent(il2cpp::type_object(_(""), _("ItemModProjectile")));
    if (!mod) return;

    auto projectileObject = u_mem::read<uintptr_t>((uintptr_t)mod + values::ItemModProjectile::projectileObject);
    if (!projectileObject) return;

    UINT_PTR projectileType = (UINT_PTR)il2cpp::type_object(_(""), _("Projectile"));
    if (!projectileType) return;

    Type* projectileClass = (Type*)GetClassObject(projectileObject);
    if (!projectileClass) return;

    Projectile* projectilePrefab = (Projectile*)GameObject::GetGameObjectComponent(projectileType, (UINT_PTR)projectileClass);
    if (!projectilePrefab) return;
    PlayerProjectileAttack* ppa = PlayerProjectileAttack::New();
    if (!ppa) return;

    PlayerAttack* pa = PlayerAttack::New();
    if (!pa) return;

    HitTest* hitTest = HitTest::New();
    if (!hitTest) return;
    float bulletSpeed = ((ItemModProjectile*)mod)->projectileVelocity() * baseprojectile->GetProjectileVelocityScale(false);
    float travelTime = distance / bulletSpeed;
    Vector3 direction = (targetPos - eyePos).Normalized();
    Vector3 hitVelocity = direction * bulletSpeed;
    hitTest->DidHit(true);
    hitTest->HitEntity(target);
    hitTest->HitTransform(targetTransform);
    hitTest->HitPoint(targetTransform->InverseTransformPoint(targetPos));
    hitTest->HitNormal(targetTransform->InverseTransformDirection((targetPos - eyePos).Normalized()));
    hitTest->AttackRay(Ray(eyePos, direction));
    hitTest->damageProperties(projectilePrefab->damageProperties());
    hitTest->MaxDistance(distance);
    hitTest->HitDistance(distance);
    hitTest->BestHit(true);
    hitTest->type(0x1);
    hitTest->Radius(0.f);
    hitTest->Forgiveness(0.5f);
    hitTest->ignoreEntity((BaseEntity*)local_player);
    Attack* attack = hitTest->BuildAttackMessage(local_player);
    if (!attack) return;
    pa->attack(attack);
    pa->projectileID(baseprojectile->primaryMagazine()->contents());
    ppa->playerAttack(pa);
    ppa->hitDistance(distance);
    ppa->travelTime(travelTime);
    ppa->hitVelocity(hitVelocity);
    local_player->SendProjectileAttack(ppa);
    RPC_Counter.Increment();
    last_stw_shot_time = currentTime;
    if (vars::trasers::bullet_tracers) {
        DDraw::Line(eyePos, targetPos, 
            { vars::trasers::bullet_tracers_color.r / 255.f, 
              vars::trasers::bullet_tracers_color.g / 255.f, 
              vars::trasers::bullet_tracers_color.b / 255.f, 
              vars::trasers::bullet_tracers_color.a / 255.f }, 
            vars::trasers::bullet_tracers_time, false, true);
    }
}
void STW_Tick() {
    if (!vars::weapon::stw_enabled) return;
    if (!Input::GetKey(vars::weapon::stw_key)) return;
    if (!target_player) return;
    BoneList selectedBone = head;
    
    switch (vars::psilent::HitBone) {
        case 0: selectedBone = head; break;
        case 1: selectedBone = neck; break;
        case 2: selectedBone = spine4; break;
        case 3:
            selectedBone = (BoneList)(math::rand() % 3 == 0 ? head : (math::rand() % 2 == 0 ? neck : spine4));
            break;
        default: selectedBone = head; break;
    }

    STW_DirectAttack(target_player, selectedBone);
}
