bool UnlockCursor() {
	if (!menu_opened) return false;
	auto set_visible = rc<void(*)(bool)>(*rc<DWORD64*>(il2cpp::method(_("Cursor"), _("set_visible"), 0, _(""), _("UnityEngine"))));
	set_visible(true);
	auto set_lockstate = rc<void(*)(int)>(*rc<DWORD64*>(il2cpp::method(_("Cursor"), _("set_lockState"), 0, _(""), _("UnityEngine"))));
	set_lockstate(0);
	return true;
}

void CursorManagerUpdate_hk(DWORD64 _this)
{
	auto CursorManagerUpdate_orig = rc<void(*)(DWORD64)>((DWORD64)(g_base + CO::CursorManagerUpdate));
	if (!UnlockCursor()) {
		CursorManagerUpdate_orig(_this);
	}
}