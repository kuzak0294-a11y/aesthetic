uintptr_t game_object;
void hkPerformanceUI(void* instance) {
	if (!game_object)
	{
		game_object = il2cpp::methods::object_new(il2cpp::init_class(_("GameObject"), _("UnityEngine")));
		GameObject::Internal_CreateGameObject(game_object, _(L""));
		GameObject::Internal_AddComponentWithType(game_object, il2cpp::type_object(_(""), _("DevControls")));
		Object::DontDestroyOnLoad(game_object);
	}
	u_hooks::orig::hk_PerfomanceUiUpdate(instance);
}