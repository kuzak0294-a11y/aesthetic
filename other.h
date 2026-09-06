Vector2 rotatePoint1(const Vector2& point, const Vector2& center, float angle)
{
	float s = math::sin(angle);
	float c = math::cos(angle);

	Vector2 rotatedPoint;
	rotatedPoint.x = (point.x - center.x) * c - (point.y - center.y) * s + center.x;
	rotatedPoint.y = (point.x - center.x) * s + (point.y - center.y) * c + center.y;

	return rotatedPoint;
}
void PlayerRvanka(bool PreventTp, PlayerWalkMovement* Walk) {
	if (!PreventTp) return;
	Vector3 headPos = big_target_player->GetBoneByID(head);
	Vector3 playerPos = local_player->transform()->position();

	if (playerPos.Distance(headPos) > 4.f) return;

	Vector2 center(headPos.x, headPos.z);
	float radius = 0.5f;
	int numLines = 1;
	float angleStep = 2 * M_PI / numLines;
	static float rotation = 0.0f;
	rotation += 3.0f * Time::deltaTime();

	for (int i = 0; i < numLines; ++i) {
		float angle = i * angleStep + rotation;

		Vector2 startPoint = rotatePoint1(Vector2(center.x + radius, center.y), center, angle);
		Vector3 teleportPos(startPoint.x, headPos.y + 0.04f, startPoint.y);
		Walk->TeleportTo(Vector3(teleportPos), local_player);
	}
}
bool IsFlying(bool PreventFlyhack)
{
	BasePlayer* ply = local_player;
	Vector3 current = ply->transform()->position();
	Vector3 old = ply->lastSentTick()->position();
	Vector3 overrided = current;
	bool result = TestFlying(ply, old, current);

	if (flyhackDistanceVertical >= (vars::antihack::maxverticalflyhack - 0.01f)) {
		overrided = Vector3(overrided.x, old.y, overrided.z);
		if (result && PreventFlyhack/* && !(Vars::Misc::InteractiveDebug && Debugging)*/) {
			if (overrided != current && current.y - overrided.y > 0.001)
				ply->ForcePositionTo(overrided);
		}
	}
	if (flyhackDistanceHorizontal >= (vars::antihack::maxhorisontalflyhack - 0.01f)) {
		overrided = Vector3(old.x, overrided.y, old.z);
		if (result && PreventFlyhack/* && !(Vars::Misc::InteractiveDebug && Debugging)*/) {
			if (overrided != current && overrided.Distance2D(current) > 0.001)
				ply->ForcePositionTo(overrided);
		}
	}

	return result;
}
void InteractiveFlyHack(bool IsTrue, PlayerWalkMovement* Walk)
{
	if (IsTrue)
	{
		float FlySpeed = vars::misc::interactivedebug_speed;
		Vector3 TargetMovement = Walk->TargetMovement();
		Vector3 Movement = TargetMovement * FlySpeed;

		Walk->flying(true);
		Walk->gravityMultiplier(0.f);
		if (Input::GetKeyInt(KeyCode::Space)) {
			Movement += Vector3(0.f, 2.f * FlySpeed, 0.f);
		}
		if (Walk->Ducking()) {
			Movement -= Vector3(0.f, 2.f * FlySpeed, 0.f);
		}
		Walk->TargetMovement(Movement);
	}
	else
	{
		Walk->gravityMultiplier(2.5f);
	}
}
Vector2 rotatePointxx(const Vector2& point, const Vector2& center, double angle) {
	const double radians = angle * M_PI / 180.0;
	const double cosAngle = math::cos(radians);
	const double sinAngle = math::sin(radians);

	const double translatedX = point.x - center.x;
	const double translatedY = point.y - center.y;

	const double rotatedX = translatedX * cosAngle - translatedY * sinAngle;
	const double rotatedY = translatedX * sinAngle + translatedY * cosAngle;

	return { (float)rotatedX + center.x, (float)rotatedY + center.y };
}
void Show_Melee_Radius(BaseMelee* _this)
{
	Vector3 objectcenter = local_player->playerModel()->position();
	int radius = _this->maxDistance() + 3;

	int diameter = 2 * radius;
	double rotationAngle = Time::time() * 50.0;

	for (int i = 0; i <= diameter; i++) {
		for (int j = 0; j <= diameter; j++) {
			int distanceX = math::abs(j - radius);
			int distanceY = math::abs(i - radius);
			int distanceX1 = math::abs(j + radius);
			int distanceY1 = math::abs(i + radius);
			double distance = math::sqrt(distanceX * distanceX + distanceY * distanceY);

			if (distance == radius - 1) {
				Vector2 center = { (float)radius * 2,(float)radius * 2 };
				Vector2 point = { (float)distanceX1,(float)distanceY1 };
				int curpos = radius * 2;
				int size = 18;
				Vector2 rtp[18];
				for (int angle = 0; angle <= 90; angle += 5) {
					Vector2 rotatedPoint = rotatePointxx(point, center, angle + rotationAngle); // Add rotationAngle to the angle
					rtp[angle / 5] = rotatedPoint;
				}
				for (int i = 0; i < size - 10; i++) {
					float transparency = static_cast<float>(i) / (size - 2);
					Color lineColor(255.f, 255.f, 255.f, transparency * 255);
					DDraw::Line(Vector3(rtp[i].x + objectcenter.x - curpos, objectcenter.y + 1.0f, rtp[i].y + objectcenter.z - curpos), Vector3(rtp[i + 1].x + objectcenter.x - curpos, objectcenter.y + 1.0f, rtp[i + 1].y + objectcenter.z - curpos), lineColor, 0.001f, false, true);
				}
			}
		}
	}
}

bool DoOreAttack(Vector3 pos, BaseEntity* p, BaseMelee* w, bool istree = false)
{
	if (w->nextAttackTime() >= Time::time()) return false;
	if (w->timeSinceDeploy() < w->deployDelay()) return false;
	auto g_hit_test = HitTest::New();
	if (!g_hit_test) return false;

	auto trans = p->transform();

	Ray r = Ray(local_player->GetBoneByID(head), (pos - local_player->GetBoneByID(head)).Normalized());
	g_hit_test->HitEntity(p);
	g_hit_test->DidHit(true);
	if (istree) g_hit_test->HitTest_HitMaterial((String*)il2cpp::methods::new_string(_("wood")));
	g_hit_test->MaxDistance(w->maxDistance());
	g_hit_test->HitTransform(trans);
	g_hit_test->AttackRay(r);
	g_hit_test->HitPoint(trans->InverseTransformPoint(pos));
	g_hit_test->HitNormal(trans->InverseTransformDirection(pos));
	g_hit_test->damageProperties(w->damageProperties());

	w->StartAttackCooldown(w->repeatDelay());
	w->ProcessAttack((HitTest*)g_hit_test);
	return true;
}