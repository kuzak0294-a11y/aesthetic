void hkProcessAttack(DWORD64 melee, HitTest* hitTest) { //public override void OnAttacked(HitInfo info)
	if (vars::weapon::alwayshotspot)
	{
		if (objects::closest_TreeEntity_see && objects::closest_TreeEntity_dist <= 3 && objects::closest_TreeEntity_dist < objects::closest_OreResourceEntity_dist)
		{
			if (objects::closest_TreeMarker_see && objects::closest_TreeMarker_dist <= 3)
			{
				hitTest->HitTransform(objects::closest_TreeMarker->transform());
				hitTest->HitPoint(objects::closest_TreeMarker->transform()->InverseTransformPoint(objects::closest_TreeMarker->transform()->position()));
				hitTest->HitTest_HitMaterial((String*)il2cpp::methods::new_string(_("wood")));
				memory_client_entities_count = 0;
			}
		}

		if (objects::closest_OreResourceEntity_see && objects::closest_OreResourceEntity_dist <= 3 && objects::closest_OreResourceEntity_dist < objects::closest_TreeEntity_dist)
		{
			if (objects::closest_OreHotSpot_see && objects::closest_OreHotSpot_dist <= 3)
			{
				hitTest->HitTransform(objects::closest_OreHotSpot->transform());
				hitTest->HitPoint(objects::closest_OreHotSpot->transform()->InverseTransformPoint(objects::closest_OreHotSpot->transform()->position()));
				memory_client_entities_count = 0;
			}
		}
	}
	return u_hooks::orig::hk_ProcessAttack(melee, hitTest);
}