Vector2 screen_center = Vector2();
namespace vars {
	namespace antihack
	{
		Vector2 flyhack_ind_pos;
		float maxverticalflyhack;
		float verticalflyhack;
		float maxhorisontalflyhack;
		float horisontalflyhack;
		inline bool flyhackindicator;
		inline bool antiflykick;
		inline bool anti_inside_terrain;
		//
		inline bool speedhackindicator;
		float speedhack;
		float speedhack_cur;
		Vector2 speedhack_pos;
	}
	namespace manipulator
	{
		inline bool stopo;
		inline bool manipulator;
		float maxangle = 30.0f;
		float desync = 0.0f;
		Vector3 m_manipulate = Vector3::Zero();
		KeyCode manipulatorkey;
		inline bool manipulatorind;
		Vector2 manipulatorind_pos;
	}
	namespace bulletteleport
	{
		inline bool tp_heli_bullet;
		inline bool tp_bullet;
		inline bool hitscan1;
		inline bool hitscan;
		float maxangle = 30;
	}
	namespace trasers
	{
		inline bool movement_line;
		Color movement_line_color;
		float movement_line_time = 3.00f;
		inline bool bullet_tracers;
		Color bullet_tracers_color;
		float bullet_tracers_time = 3.00f;
	}
	namespace psilent {
		inline bool psilent;
		KeyCode psilentkey;
		//
		inline bool show_fov;
		Color fov_color;
		float tarer_fov;
		float setter_fov = 120.f;
		float lags = 0.1f;
		inline bool target_line;
		Color target_line_color;
		//
		int HitBone = 0;
		inline bool ignorepeople[12];
		//
		inline bool target_belt;
		float target_belt_size = 55.f;
		Vector2 belt_pos;
		Vector2 belt_size;
	}
	namespace esp {
		inline bool oofindicators;

		inline bool skeleton;
		Color skeletoncolor;
		inline bool name;
		Color namecolor;
		int box_mode = 0;
		inline bool box;
		Color boxcolor;
		Color pidoras;
		inline bool weapon;
		Color weaponcolor;
		inline bool distance;
		Color distancecolor;
		inline bool flags;
		Color flagscolor;
		inline bool healthbar;
		inline bool looking_direction;
		Color looking_directioncolor;
		inline bool outline = true;
		//
		inline bool show_choose[12] = {true, false, false, false, false, false, false}; // По умолчанию показывать только игроков
		//
		inline bool radar;
		float radar_size;
		Vector2 radar_pos;
		//
		inline bool kill_effect;
		int kill_effect_type = 0; // 0 = souls escape, 1 = souls escape omni
		//
		inline bool player_chams;
		int player_chams_type = 0; // 0 = Rainbow, 1 = Flat
		Color player_chams_color;
		float player_chams_alpha = 0.4f; // Яркость чамсов (0.0 - 1.0)
		float player_chams_rainbow_speed = 1.0f; // Скорость rainbow shader (0.1 - 10.0)
		Color player_chams_visible_color; // Цвет для видимых игроков
		Color player_chams_invisible_color; // Цвет для невидимых игроков (за стенами)
	}
	namespace weapon {
		inline bool projectile_skip;
		inline bool sphere_hitscan1;
		inline bool sphere_hitscan;
		inline bool sphere_RADIUS;		// STW (Shoot Through Walls)
		inline bool stw_enabled;
		KeyCode stw_key;
		float stw_max_distance = 150.f;
		inline bool stw_indicator;
		Vector2 stw_indicator_pos;

		// Rapid Fire
		inline bool rapidfire;
		float rapidfire_speed = 1.0f;

		inline bool thick_bullet;
		float bullet_hitbox_size;
		//
		inline bool norecoil;

		float norecoil_value_x = 100.0f;
		float norecoil_value_y = 100.0f;
		//
		inline bool no_sway;
		inline bool no_bob;
		inline bool no_lower;
		//
		inline bool weaponspam;
		KeyCode weaponspam_key;
		float weaponspam_delay = 20.0f;
		//
		inline bool changebulletspeed;
		float bulletspeed;
		//
		inline bool bullet_resize;
		float bullet_size = 1.f;
		//
		inline bool alwayshotspot;
		inline bool silent_melee;
		inline bool hamerdraw;
		inline bool show_silent_radius;
		inline bool piercematerials;
		inline bool instakill;
		inline bool instant_hit;
		inline bool nospread;
		inline bool automatic;
		Vector2 autoreload_pos;
		inline bool autoreload;
		inline bool autoreloadindicator;
		inline bool eokachance;
		inline bool hit_material;
		//
		inline bool autofarmore;
		inline bool autofarmtree;
	}
	namespace localplayer
	{
		inline bool chams;
		int chams_type = 0;
		inline bool autoheal;
		inline bool doorspammer;
		inline bool silentstash;
		//static bool keepinstantrevive;
		//KeyCode keepinstantrevive_key;
		//static bool keeptargetalive;
		//KeyCode keeptargetalive_key;
		inline bool silentcollectiblet;
		inline bool silentturret;
		inline bool stoprecycler;
		inline bool auto_upgrade;
		int upgrade = 0;
		inline bool gesture_spam;
		int gesture = 0;
		inline bool suicide;
		KeyCode suicidekey;
		inline bool silent_melee;

		inline bool zoom;
		KeyCode zoomkey;

		inline bool autorefill;
		inline bool fast_loot;
		inline bool auto_farm_ore;
		inline bool auto_farm_tree;
	}
	namespace misc {
		inline bool namespoofer;
		inline bool randomnick;
		wchar_t nick[256];

		inline bool unload_cheat = false;

		// Chat Spammer
		inline bool chat_spammer;
		KeyCode chat_spammer_key;
		float chat_spammer_delay = 1.0f;

		// Fake Lag
		inline bool fakelag;
		KeyCode fakelag_key;
		float fakelag_ticks = 14.f;
		inline bool fakelag_indicator;
		Vector2 fakelag_indicator_pos;

		inline bool admin_mode;
		inline bool is_real_admin;
		inline bool gravity;
		float gravity_value;

		inline bool look_allert;

		inline bool antiaim;
		int antiaim_mode = 0;
		float spinspeed = 5.f;

		inline bool teleport_to_head;
		KeyCode teleport_to_headkey;

		inline bool speedhack;
		float speedhackspeed;
		KeyCode speedhackkey;

		inline bool bhop;
		KeyCode bhopkey;

		inline bool interactivedebug;
		float interactivedebug_speed;
		KeyCode interactivedebugkey;

		inline bool no_watercollision;
		inline bool no_playercollision;
		inline bool no_treecollision;
		inline bool attack_on_mountables;
		inline bool always_sprint;
		inline bool inf_jump;
		inline bool always_shoot;
		inline bool spider;
		inline bool no_fall_damage;
		inline bool silent_walk;
		inline bool collider;
		inline bool instant_loot;
		inline bool auto_heal;
		inline bool farm_assist;
		int instant_suicide = 0;
		float zoom_value = 50.f;
		inline bool raycast_sphere;
		Color raycast_sphere_color;
		inline bool fastloot;

		inline bool farmbot;

		inline bool sky_color_changer;
		Color sky_color;
		inline bool stars_changer;
		inline bool ambient_changer;
		Color ambient_color;
		float stars_amount;
		float stars_size;
		inline bool rayleigh_changer;
		float rayleigh = 10.f;
		inline bool mie_changer;
		float mie = 10.f;
		inline bool brightness_changer;
		float brightness = 10.f;
		inline bool time_changer;
		float time_amount = 10.f;
		inline bool fov_changer;
		float fov_amount = 90.f;
		inline bool thirdperson_changer;
		float th_dist = 2.f;
		float th_fov = 70.f;
		inline bool ratio_changer;
		float ratio_amount = 1.9f;


		inline bool noclouds;
		inline bool atmospherecontrast;
		inline bool nofog;
		inline bool norain;
		inline bool nothunder;
		inline bool nowind;
		inline bool brightcave;
	}
	namespace object {
		float max_ores_distance;
		inline bool show_ores_distance;
		inline bool show_ores_ico;
		inline bool ores[12];

		float max_berrys_distance;
		inline bool show_berrys_distance;
		inline bool show_berrys_ico;
		inline bool berrys[12];

		float max_others_distance;
		inline bool show_others_distance;
		inline bool show_others_ico;
		inline bool others[12];

		float max_vehicles_distance;
		inline bool show_vehicles_distance;
		inline bool vehicles[12];

		float max_traps_distance;
		inline bool show_traps_distance;
		inline bool show_traps_ico;
		inline bool traps[12];

		float max_animals_distance;
		inline bool show_animals_distance;
		inline bool animals[12];

		float max_crates_distance;
		inline bool show_crates_distance;
		inline bool crates[12];

		float max_homeobjects_distance;
		inline bool show_homeobjects_distance;
		inline bool show_homeobjects_ico;
		inline bool homeobjects[12];

		float max_mainobjects_distance;
		inline bool show_mainobjects_distance;
		inline bool mainobjects[12];

		inline bool show_dropeeditems_ico = false;

		inline bool debug;
		inline bool debug_ent;
	}
}
int memory_client_entities_count;
float lastshottime, lastmeleeshottime, time_since_last_shot;
bool just_shot, did_reload;
Color defoultcolorpickercolor;