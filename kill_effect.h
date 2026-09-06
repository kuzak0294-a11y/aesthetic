#pragma once

namespace kill_effect {
  
    void check_kill(BasePlayer* victim);
    
   
    const char* effect_souls_escape = "assets/jmo assets/cartoon fx remaster/cfxr prefabs/eerie/cfxr2 souls escape.prefab";
    const char* effect_souls_escape_omni = "assets/jmo assets/cartoon fx remaster/cfxr prefabs/eerie/variants/cfxr2 souls escape (omni).prefab";
    
  
    uintptr_t cached_effect_1 = 0;
    uintptr_t cached_effect_2 = 0;
    
    
    struct PlayerDeathTracker {
        uintptr_t player_ptr;
        bool was_dead;
    };
    
    PlayerDeathTracker death_tracker[100];
    int tracker_count = 0;
   
    void update_health_tracker(BasePlayer* player) {
        if (!player || (uintptr_t)player < 0x10000) return;
        if (!vars::esp::kill_effect) return;
        
        uintptr_t player_ptr = (uintptr_t)player;
        bool is_currently_dead = player->is_dead();
        
        
        int found_index = -1;
        for (int i = 0; i < tracker_count; i++) {
            if (death_tracker[i].player_ptr == player_ptr) {
                found_index = i;
                break;
            }
        }
        
        if (found_index >= 0) {
            
            bool was_dead = death_tracker[found_index].was_dead;

            if (!was_dead && is_currently_dead) {
                check_kill(player);
            }
            
            
            death_tracker[found_index].was_dead = is_currently_dead;
        } else {
           
            if (!is_currently_dead && tracker_count < 100) {
                death_tracker[tracker_count].player_ptr = player_ptr;
                death_tracker[tracker_count].was_dead = false;
                tracker_count++;
            }
        }
    }
    
  
    uintptr_t load_effect_prefab(int effect_type) {
        if (!ghost_effect_bundle || ghost_effect_bundle < 0x10000) return 0;
        
        
        if (effect_type == 0 && cached_effect_1) return cached_effect_1;
        if (effect_type == 1 && cached_effect_2) return cached_effect_2;
        const char* effect_name = (effect_type == 1) ? effect_souls_escape_omni : effect_souls_escape;
        String* effect_string = (String*)il2cpp::methods::new_string(effect_name);
        if (!effect_string) return 0;
        auto prefab = AssetBundle::LoadAsset_Internal(ghost_effect_bundle, *effect_string, il2cpp::type_object(_("UnityEngine"), _("GameObject")));
        
        if (prefab && prefab >= 0x10000) {
            
            if (effect_type == 0) cached_effect_1 = prefab;
            else cached_effect_2 = prefab;
        }
        
        return prefab;
    }
    
    
    void spawn_effect(Vector3 position, int effect_type = 0) {
        if (!vars::esp::kill_effect) return;
        if (!local_player || (uintptr_t)local_player < 0x10000) return;
        if (!ghost_effect_bundle || ghost_effect_bundle < 0x10000) return;
        auto prefab = load_effect_prefab(effect_type);
        if (!prefab || prefab < 0x10000) return;
        auto instantiate = rc<uintptr_t(*)(uintptr_t, Vector3, Quaternion)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("Instantiate"), 3, _("UnityEngine.Object,UnityEngine.Vector3,UnityEngine.Quaternion"), _("UnityEngine"))));
        if (!instantiate) return;
        Quaternion rotation = {0, 0, 0, 1};
        auto effect_instance = instantiate(prefab, position, rotation);
        if (effect_instance && effect_instance >= 0x10000) {
            auto destroy = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("Destroy"), 2, _("UnityEngine.Object,System.Single"), _("UnityEngine"))));
            if (destroy) {
                destroy(effect_instance, 5.0f);
            }
        }
    }
    
  
    void check_kill(BasePlayer* victim) {
        if (!vars::esp::kill_effect) return;
        if (!victim || (uintptr_t)victim < 0x10000) return;
        if (!local_player || (uintptr_t)local_player < 0x10000) return;
        
      
        Vector3 head_pos = victim->GetBoneByID(head);
        if (head_pos.is_empty()) {
            
            auto transform = victim->transform();
            if (transform && (uintptr_t)transform >= 0x10000) {
                head_pos = transform->position();
                head_pos.y += 1.f; 
            } else {
                return;
            }
        }
        
       
        spawn_effect(head_pos, vars::esp::kill_effect_type);
    }
}
