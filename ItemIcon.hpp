void hkTryToMove(void* a1) {
	u_hooks::orig::hk_TryToMove(a1);
	if (vars::misc::fastloot) {
		auto queuedForLooting = u_mem::read<bool>((uintptr_t)a1 + values::ItemIcon::queuedForLooting);
		if (queuedForLooting) {
			((ItemIcon*)a1)->RunTimedAction();
		}
	}
}