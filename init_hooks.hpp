namespace u_hooks {
	namespace orig {
		static auto hk_SteamPlatformUpdate = rc<void(*)(SteamPlatform*)>(*rc<uintptr_t*>(il2cpp::method(_("SteamPlatform"), _("Update"), 0, _(""), _("Rust.Platform.Steam"))));
		static auto hk_PerfomanceUiUpdate = rc<void (*)(void* instance)>(*rc<uintptr_t*>(il2cpp::method(_("PerformanceUI"), _("Update"), 0, _(""), _("Facepunch"))));
		static auto hk_ProjectileUpdate = rc<void(*)(Projectile*)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("Update"), 0, _(""), _(""))));
		static auto hk_BasePlayer_ClientInput = rc<void (*)(BasePlayer*, InputState*)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), 1, _(""), _(""))));
		static auto hk_DoFixedUpdate = rc<void (*)(void*, void*)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		static auto hk_OnAttacked = rc<void (*)(void*, HitInfo*)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnAttacked"), 1, _(""), _(""))));
		static auto hk_ProcessAttack = rc<void (*)(DWORD64, HitTest*)>(*rc<DWORD64*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));
		static auto hk_PlayerWalkMovementClient = rc<void (*)(void*, uintptr_t, void*)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		static auto hk_SetSprinting = rc<void (*)(void*, bool)>(*rc<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));
		static auto hk_TryToMove = rc<void(*)(void*)>(*rc<uintptr_t*>(il2cpp::method(_("ItemIcon"), _("TryToMove"), -1, _(""), _(""))));
		static auto DoAttack = rc<void(*)(DWORD64)>(*rc<DWORD64*>(il2cpp::method(_("BaseProjectile"), _("DoAttack"), 0, _(""), _(""))));
	}
	void init_hooks() {
		orig::hk_SteamPlatformUpdate = rc<void(*)(SteamPlatform*)>(*rc<uintptr_t*>(il2cpp::method(_("SteamPlatform"), _("Update"), 0, _(""), _("Rust.Platform.Steam"))));
		orig::hk_PerfomanceUiUpdate = rc<void (*)(void* instance)>(*rc<uintptr_t*>(il2cpp::method(_("PerformanceUI"), _("Update"), 0, _(""), _("Facepunch"))));
		orig::hk_ProjectileUpdate = rc<void(*)(Projectile*)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("Update"), 0, _(""), _(""))));
		orig::hk_BasePlayer_ClientInput = rc<void (*)(BasePlayer*, InputState*)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), 1, _(""), _(""))));
		orig::hk_DoFixedUpdate = rc<void (*)(void*, void*)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		orig::hk_OnAttacked = rc<void (*)(void*, HitInfo*)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnAttacked"), 1, _(""), _(""))));
		orig::hk_ProcessAttack = rc<void (*)(DWORD64, HitTest*)>(*rc<DWORD64*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));
		orig::hk_PlayerWalkMovementClient = rc<void (*)(void*, uintptr_t, void*)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		orig::hk_SetSprinting = rc<void (*)(void*, bool)>(*rc<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));
		orig::hk_TryToMove = rc<void(*)(void*)>(*rc<uintptr_t*>(il2cpp::method(_("ItemIcon"), _("TryToMove"), -1, _(""), _(""))));
		orig::DoAttack = rc<void(*)(DWORD64)>(*rc<DWORD64*>(il2cpp::method(_("BaseProjectile"), _("DoAttack"), 0, _(""), _(""))));
	}
}
#include "OtherHook.hpp"
#include "BaseMelee.hpp"
#include "ItemIcon.hpp"
#include "PlayerWalkMovement.hpp"
#include "PerformanceUI.hpp"
#include "BaseProjectile.hpp"
#include "Projectile.hpp"
#include "ProjectileShoot.hpp"
#include "SteamPlatform.hpp"
#include "BasePlayer.hpp"
