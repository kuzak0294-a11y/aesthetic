bool canjump = false;
int spin = 0;
int jitter = 0;
Vector3 pre_last_pos;
void HandleJumping(PlayerWalkMovement* a1,ModelState* state, bool wantsJump, bool jumpInDirection = false)
{
	if (!a1 || !state || !wantsJump) return;
	//a1->grounded() = (a1->climbing() = (a1->sliding() = false));
	a1->grounded(false);
	a1->climbing(false);
	a1->sliding(false);
	a1->jumping(true);
	a1->jumptime(Time::time());
	a1->ladder(nullptr);

	state->ducked(false);
	state->jumped(true);
	

	Vector3 curVel = a1->body()->velocity();
	a1->body()->velocity({ curVel.x, 10, curVel.z });
}
float speedhackPauseTime;
void hkPlayerWalkMovementClient(void* player_walk_movement, uintptr_t inputstate, void* model_state) {
	u_hooks::orig::hk_PlayerWalkMovementClient(player_walk_movement, inputstate, model_state);
	
	// Fake Lag
	if (vars::misc::fakelag) {
		fakelag::enabled = true;
		fakelag::key = vars::misc::fakelag_key;
		fakelag::ticks = vars::misc::fakelag_ticks;
		fakelag::indicator = vars::misc::fakelag_indicator;
		fakelag::indicator_pos = vars::misc::fakelag_indicator_pos;
		fakelag::process((PlayerWalkMovement*)player_walk_movement);
	}
	
	if (vars::misc::always_sprint) {
		u_hooks::orig::hk_SetSprinting(model_state, true);
	}

	if (vars::misc::spider) {
		auto collider = u_mem::read<uintptr_t>((uintptr_t)player_walk_movement + values::PlayerWalkMovement::capsule);
		u_sdk::set_radius(collider, 0.44f);
	}
	else
	{
		auto collider = u_mem::read<uintptr_t>((uintptr_t)player_walk_movement + values::PlayerWalkMovement::capsule);
		u_sdk::set_radius(collider, 0.5f);
	}
	if (vars::misc::no_fall_damage) {
		((PlayerWalkMovement*)player_walk_movement)->groundtime(9999999.f);
	}
	if (vars::misc::inf_jump) {
		bool wantsJump = ((InputState*)inputstate)->WasJustPressed(BUTTON::JUMP);
		HandleJumping((PlayerWalkMovement*) player_walk_movement,(ModelState*)model_state, wantsJump, true);
	}
	if (vars::localplayer::suicide && Input::GetKey(vars::localplayer::suicidekey))
		local_player->OnLand(-1337);
	if (vars::misc::spider) {
		u_mem::write<float>((uintptr_t)player_walk_movement + values::PlayerWalkMovement::groundAngleNew, 0.f);
		u_mem::write<float>((uintptr_t)player_walk_movement + values::PlayerWalkMovement::groundAngle, 0.f);
	}
	if (vars::misc::always_shoot) {
		((ModelState*)model_state)->set_flag(ModelState::Flag::OnGround);
		u_mem::write<float>((uintptr_t)player_walk_movement + 0x4C, 1);//private float <Grounded>k__BackingField; // 0x4C
	}
	if (vars::misc::attack_on_mountables) {
		auto mountable = u_mem::read<uintptr_t>((uintptr_t)local_player + values::BasePlayer::mounted);
		if (mountable)
			u_mem::write<bool>(mountable + values::BaseMountable::canWieldItems, true);
	}
	if (vars::weapon::no_bob)
	{
		BaseViewModel viewModel;
		viewModel.disableBob();
	}
	if (vars::weapon::no_lower)
	{
		BaseViewModel viewModel;
		viewModel.disableLower();
	}
	if (vars::trasers::movement_line) {
		DDraw::Line(pre_last_pos, local_player->transform()->position(), { vars::trasers::movement_line_color.r / 255.f, vars::trasers::movement_line_color.g / 255.f, vars::trasers::movement_line_color.b / 255.f, vars::trasers::movement_line_color.a / 255.f }, vars::trasers::movement_line_time, false, true);
	}
	//farmbot::farmbot();
	if (vars::antihack::speedhackindicator) {
		float deltaTime = Time::deltaTime();
		speedhackPauseTime = max(0.f, speedhackPauseTime - deltaTime);

		Matrix4x4 _mv; _mv.Identity();
		Matrix4x4 matrix4x = _mv;
		Vector3 vector = pre_last_pos;
		Vector3 a = local_player->transform()->position();

		float running = 1.0f;
		float ducking = 0.f;
		float crawling = 0.f;
		if (AntiHack::speedhack_protection >= 2)
		{
			bool flag2 = local_player->IsRunning();
			bool flag3 = local_player->IsDucked();
			bool flag4 = local_player->IsSwimming();
			bool flag5 = local_player->IsCrawling();
			running = (flag2 ? 1.0f : 0.f);
			ducking = ((flag3 || flag4) ? 1.0f : 0.f);
			crawling = (flag5 ? 1.0f : 0.f);
		}
		float speed = local_player->GetSpeed(running, ducking, crawling);

		Vector3 v = a - vector;
		float num = v.Magnitude2D();
		float num2 = deltaTime * speed;
		if (num > num2)
		{
			auto Meta = TerrainMeta::New();
			Vector3 v2 = Meta->HeightMap()->GetNormal(vector);
			Vector3 lhs = Vector3(v2.x, v2.y, v2.z);
			float num3 = max(0.f, lhs.dot(lhs)) * AntiHack::speedhack_slopespeed * deltaTime;
			num = max(0.f, num - num3);
		}
		float num4 = max((speedhackPauseTime > 0.f) ? AntiHack::speedhack_forgiveness_inertia : AntiHack::speedhack_forgiveness, 0.1f);
		float num5 = num4 + max(AntiHack::speedhack_forgiveness, 0.1f);
		vars::antihack::speedhack = Mathf::Clamp(vars::antihack::speedhack, -num5, num5);
		vars::antihack::speedhack = Mathf::Clamp(vars::antihack::speedhack - num2, -num5, num5);
		if (vars::antihack::speedhack > num4) {
			//result = true;
		}
		else
		{
			vars::antihack::speedhack = math::ImClamp(vars::antihack::speedhack + num, -num5, num5);
			/*if (vars::antihack::speedhack > num4)
			{
				result = true;
			}
			else
				result = false;*/
		}
		vars::antihack::speedhack_cur = vars::antihack::speedhack + 4.01f;
	}
		
	pre_last_pos = local_player->transform()->position();

	if (vars::misc::no_watercollision)
	{
		Vector3 vel = rc<BaseMovement*>(player_walk_movement)->TargetMovement();
		Vector3 local = local_player->GetBoneByID(BoneList::l_foot);
		float currentwater = WaterLevel::GetWaterDepth(local, true, false, local_player);
		float upperwater = local.y - currentwater;
		upperwater -= 1.f;
		if (upperwater < 0.f && vel.y <= 0.1f) {
			vel.y = -upperwater;
			u_mem::write<float>((uintptr_t)player_walk_movement + values::PlayerWalkMovement::groundAngleNew, 0.f);
			u_mem::write<float>((uintptr_t)player_walk_movement + values::PlayerWalkMovement::groundAngle, 0.f);
		}
		rc<BaseMovement*>(player_walk_movement)->TargetMovement(vel);
	}
	if (vars::misc::admin_mode)
		u_mem::write<bool>((uintptr_t)player_walk_movement + 0x18, false);
	u_sdk::IgnoreLayerCollision(Layer::Player_Movement, Layer::Tree, vars::misc::no_treecollision);
	u_sdk::IgnoreLayerCollision(Layer::Player_Movement, Layer::AI, vars::misc::no_playercollision);
	IsInsideTerrain(vars::antihack::anti_inside_terrain);
	//farmbot(vars::misc::farmbot);
	IsFlying(vars::antihack::antiflykick);
	PlayerRvanka(vars::misc::teleport_to_head && Input::GetKey(vars::misc::teleport_to_headkey), ((PlayerWalkMovement*)player_walk_movement));
	InteractiveFlyHack(vars::misc::interactivedebug && Input::GetKey(vars::misc::interactivedebugkey), ((PlayerWalkMovement*)player_walk_movement));
	if (vars::misc::bhop && Input::GetKey(vars::misc::bhopkey))
	{
		static float b = 32.0f;
		if (b >= 32.0f) {
			float radius = local_player->GetRadius();
			float height = local_player->GetHeight(false);
			Vector3 vector = (local_player->lastSentTick()->position() + local_player->transform()->position()) * 0.5f;
			float flyhack_extrusion = 0.25f;
			Vector3 vector2 = vector + Vector3(0.0f, radius - flyhack_extrusion, 0.0f);
			Vector3 vector3 = vector + Vector3(0.0f, height - radius, 0.0f);
			float radius2 = radius - 0.05f;
			bool isgrounded = Physics::CheckCapsule(vector2, vector3, radius2, 1503731969, QueryTriggerInteraction::Ignore);
			if (isgrounded) {
				((PlayerWalkMovement*)player_walk_movement)->Jump(((ModelState*)model_state), false);
				b = 0.0f;
			}
		}
		b++;
	}

	if (!vars::misc::gravity)
		((PlayerWalkMovement*)player_walk_movement)->gravityMultiplier(2.5f);
	else
		((PlayerWalkMovement*)player_walk_movement)->gravityMultiplier(vars::misc::gravity_value);
}
void hkDoFixedUpdate(void* base_movement, void* modelstate) {
	typedef void(__stdcall* Inp)(void*, void*);
	float speed = (u_mem::read<bool>((uintptr_t)base_movement + values::PlayerWalkMovement::swimming) || u_mem::read<float>((uintptr_t)base_movement + 0x4C) > 0.5f) ? 1.7f : (u_mem::read<bool>((uintptr_t)base_movement + values::PlayerWalkMovement::jumping) /*jump*/ ? 8.f : 5.5f);// playermovmen
	Vector3 vel = u_mem::read<Vector3>((uintptr_t)base_movement + 0x3C); //private Vector3 <TargetMovement>k__BackingField;    //private float <Ducking>k__BackingField; 0x44
	speed = max(speed, vel.Length());
	if (vars::misc::always_sprint && !local_player->is_wounded()) {
		float len = vel.Length(); 
		if (len > 0.f) {
			vel = Vector3(vel.x / len * speed, vel.y, vel.z / len * speed);
			*rc<Vector3*>((uintptr_t)base_movement + 0x3C) = vel;
		}
	}
	u_hooks::orig::hk_DoFixedUpdate(base_movement, modelstate);
}