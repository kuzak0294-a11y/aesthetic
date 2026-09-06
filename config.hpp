#pragma once
#include <windows.h>
namespace config {
    constexpr const wchar_t* CONFIG_FOLDER = L"C:\\Aesthetic\\";
    constexpr const wchar_t* CONFIG_EXT = L".cfg";
    constexpr int MAX_CONFIGS = 32;
    constexpr int MAX_NAME_LEN = 256;
    constexpr int BUFFER_SIZE = 131072;
    class JsonSerializer {
        char buffer[BUFFER_SIZE];
        int pos = 0;
        int indent = 0;
        bool needs_comma = false;

        void write_char(char c) { if (pos < BUFFER_SIZE - 1) buffer[pos++] = c; }
        void write_str(const char* s) { while (*s && pos < BUFFER_SIZE - 1) buffer[pos++] = *s++; }
        void write_indent() { for (int i = 0; i < indent * 2; i++) write_char(' '); }
        
        void write_comma_if_needed() {
            if (needs_comma) { write_str(",\n"); }
            needs_comma = true;
        }

    public:
        
        void begin_object() { write_char('{'); write_char('\n'); indent++; needs_comma = false; }
        void end_object() { write_char('\n'); indent--; write_indent(); write_char('}'); needs_comma = true; }
        void begin_array() { write_char('['); write_char('\n'); indent++; needs_comma = false; }
        void end_array() { write_char('\n'); indent--; write_indent(); write_char(']'); needs_comma = true; }

        
        void write_key(const char* key) {
            write_comma_if_needed();
            write_indent();
            write_char('"'); write_str(key); write_str("\": ");
        }

       
        void write(bool v) { write_str(v ? "true" : "false"); }
        
        void write(int v) {
            if (v < 0) { write_char('-'); v = -v; }
            if (v == 0) { write_char('0'); return; }
            char temp[16]; int i = 0;
            int div = 1000000000;
            bool started = false;
            while (div > 0) {
                int digit = (v / div) % 10;
                if (digit || started) { temp[i++] = '0' + digit; started = true; }
                div /= 10;
            }
            temp[i] = '\0'; write_str(temp);
        }

        void write(float v) {
            if (v < 0) { write_char('-'); v = -v; }
            int int_part = (int)v;
            write((int)int_part);
            float frac = v - int_part;
            if (frac > 0.000001f) {
                write_char('.');
                for (int i = 0; i < 6; i++) {
                    frac *= 10; int d = (int)frac;
                    write_char('0' + d); frac -= d;
                }
            }
        }

        void write(const char* s) { write_char('"'); write_str(s); write_char('"'); }
        
        void write(const wchar_t* ws) {
            char temp[512];
            WideCharToMultiByte(CP_UTF8, 0, ws, -1, temp, 512, NULL, NULL);
            write(temp);
        }

        void write(const Vector2& v) {
            write_char('{'); write_str("\"x\":"); write(v.x); 
            write_str(",\"y\":"); write(v.y); write_char('}');
        }

        void write(const Vector3& v) {
            write_char('{'); write_str("\"x\":"); write(v.x);
            write_str(",\"y\":"); write(v.y); write_str(",\"z\":"); write(v.z); write_char('}');
        }

        void write(const Color& c) {
            write_char('{'); write_str("\"r\":"); write(c.r); write_str(",\"g\":"); write(c.g);
            write_str(",\"b\":"); write(c.b); write_str(",\"a\":"); write(c.a); write_char('}');
        }

        void write(KeyCode k) { write((int)k); }

        
        template<typename T, int N>
        void write_array(T (&arr)[N]) {
            begin_array();
            for (int i = 0; i < N; i++) {
                write_comma_if_needed();
                write_indent(); write(arr[i]);
            }
            end_array();
        }

       
        template<typename T>
        void field(const char* key, const T& value) {
            write_key(key); write(value);
        }

        template<typename T, int N>
        void field_array(const char* key, T (&arr)[N]) {
            write_key(key); write_array(arr);
        }

        const char* get_json() { buffer[pos] = '\0'; return buffer; }
        int size() const { return pos; }
    };
    class JsonDeserializer {
        const char* json;
        int pos = 0;
        int section_pos = 0; 

        void skip_ws() {
            while (json[pos] == ' ' || json[pos] == '\n' || json[pos] == '\r' || json[pos] == '\t') pos++;
        }

        bool match_str(const char* str) {
            int i = 0;
            while (str[i] && json[pos + i] == str[i]) i++;
            if (str[i] == '\0') { pos += i; return true; }
            return false;
        }

    public:
        JsonDeserializer(const char* j) : json(j) {}

        bool find_key(const char* key) {
            int start = pos;
            int depth = 0; 
            
            while (json[pos]) {
                skip_ws();
                
               
                if (json[pos] == '{' || json[pos] == '[') {
                    depth++;
                    pos++;
                    continue;
                }
                if (json[pos] == '}' || json[pos] == ']') {
                    depth--;
                    if (depth < 0) break;
                    pos++;
                    continue;
                }
                
                if (json[pos] == '"') {
                    pos++; int key_start = pos;
                    while (json[pos] && json[pos] != '"') pos++;
                    int key_len = pos - key_start; pos++;
                    
                    bool match = true;
                    for (int i = 0; i < key_len; i++) {
                        if (key[i] == '\0' || key[i] != json[key_start + i]) { match = false; break; }
                    }
                    if (match && key[key_len] == '\0') {
                        skip_ws();
                        if (json[pos] == ':') { pos++; skip_ws(); return true; }
                    }
                }
                pos++;
            }
            pos = start; 
            return false;
        }

        void read(bool& v) {
            skip_ws();
            v = match_str("true") ? true : (match_str("false"), false);
        }

        void read(int& v) {
            skip_ws();
            int sign = 1;
            if (json[pos] == '-') { sign = -1; pos++; }
            v = 0;
            while (json[pos] >= '0' && json[pos] <= '9') {
                v = v * 10 + (json[pos] - '0'); pos++;
            }
            v *= sign;
        }

        void read(float& v) {
            skip_ws();
            float sign = 1.0f;
            if (json[pos] == '-') { sign = -1.0f; pos++; }
            v = 0.0f;
            while (json[pos] >= '0' && json[pos] <= '9') {
                v = v * 10.0f + (json[pos] - '0'); pos++;
            }
            if (json[pos] == '.') {
                pos++; float frac = 0.1f;
                while (json[pos] >= '0' && json[pos] <= '9') {
                    v += (json[pos] - '0') * frac; frac *= 0.1f; pos++;
                }
            }
            v *= sign;
        }

        void read(char* dest, int max_len) {
            skip_ws();
            if (json[pos] != '"') return;
            pos++; int i = 0;
            while (json[pos] && json[pos] != '"' && i < max_len - 1) {
                dest[i++] = json[pos++];
            }
            dest[i] = '\0';
            if (json[pos] == '"') pos++;
        }

        void read(wchar_t* dest, int max_len) {
            char temp[512]; read(temp, 512);
            MultiByteToWideChar(CP_UTF8, 0, temp, -1, dest, max_len);
        }

        void read(Vector2& v) {
            skip_ws();
            if (json[pos] != '{') return;
            pos++;
            while (json[pos] && json[pos] != '}') {
                skip_ws();
                if (json[pos] == '"') {
                    pos++; char key[8]; int i = 0;
                    while (json[pos] && json[pos] != '"' && i < 7) key[i++] = json[pos++];
                    key[i] = '\0';
                    if (json[pos] == '"') pos++;
                    skip_ws();
                    if (json[pos] == ':') {
                        pos++; float val; read(val);
                        if (key[0] == 'x' && !key[1]) v.x = val;
                        else if (key[0] == 'y' && !key[1]) v.y = val;
                    }
                }
                if (json[pos] == ',') pos++;
                else if (json[pos] != '}') pos++;
            }
            if (json[pos] == '}') pos++;
        }

        void read(Vector3& v) {
            skip_ws();
            if (json[pos] != '{') return;
            pos++;
            while (json[pos] && json[pos] != '}') {
                skip_ws();
                if (json[pos] == '"') {
                    pos++; char key[8]; int i = 0;
                    while (json[pos] && json[pos] != '"' && i < 7) key[i++] = json[pos++];
                    key[i] = '\0';
                    if (json[pos] == '"') pos++;
                    skip_ws();
                    if (json[pos] == ':') {
                        pos++; float val; read(val);
                        if (key[0] == 'x' && !key[1]) v.x = val;
                        else if (key[0] == 'y' && !key[1]) v.y = val;
                        else if (key[0] == 'z' && !key[1]) v.z = val;
                    }
                }
                if (json[pos] == ',') pos++;
                else if (json[pos] != '}') pos++;
            }
            if (json[pos] == '}') pos++;
        }

        void read(Color& c) {
            skip_ws();
            if (json[pos] != '{') return;
            pos++;
            while (json[pos] && json[pos] != '}') {
                skip_ws();
                if (json[pos] == '"') {
                    pos++; char key[8]; int i = 0;
                    while (json[pos] && json[pos] != '"' && i < 7) key[i++] = json[pos++];
                    key[i] = '\0';
                    if (json[pos] == '"') pos++;
                    skip_ws();
                    if (json[pos] == ':') {
                        pos++; float val; read(val);
                        if (key[0] == 'r' && !key[1]) c.r = val;
                        else if (key[0] == 'g' && !key[1]) c.g = val;
                        else if (key[0] == 'b' && !key[1]) c.b = val;
                        else if (key[0] == 'a' && !key[1]) c.a = val;
                    }
                }
                if (json[pos] == ',') pos++;
                else if (json[pos] != '}') pos++;
            }
            if (json[pos] == '}') pos++;
        }

        void read(KeyCode& k) { int v; read(v); k = (KeyCode)v; }

        template<typename T, int N>
        void read_array(T (&arr)[N]) {
            skip_ws();
            if (json[pos] != '[') return;
            pos++;
            for (int i = 0; i < N; i++) {
                skip_ws(); read(arr[i]); skip_ws();
                if (json[pos] == ',') pos++;
            }
            while (json[pos] && json[pos] != ']') pos++;
            if (json[pos] == ']') pos++;
        }

        bool enter_section(const char* name) {
            pos = 0;
            int depth = 0;
            bool in_root = false;
            
            while (json[pos]) {
                skip_ws();
                
               
                if (json[pos] == '{') {
                    if (depth == 0) in_root = true;
                    depth++;
                    pos++;
                    continue;
                }
                if (json[pos] == '}') {
                    depth--;
                    pos++;
                    continue;
                }
                if (json[pos] == '"' && depth == 1 && in_root) {
                    pos++; 
                    int key_start = pos;
                    while (json[pos] && json[pos] != '"') pos++;
                    int key_len = pos - key_start;
                    
                   
                    bool match = true;
                    for (int i = 0; i < key_len; i++) {
                        if (name[i] == '\0' || name[i] != json[key_start + i]) { 
                            match = false; 
                            break; 
                        }
                    }
                    
                    if (match && name[key_len] == '\0') {
                        pos++; 
                        skip_ws();
                        if (json[pos] == ':') {
                            pos++;
                            skip_ws();
                            if (json[pos] == '{') {
                                pos++;
                                section_pos = pos;
                                crash_logger::log_info("Section %s entered successfully at pos %d", name, section_pos);
                                return true;
                            } else {
                                crash_logger::log_error("Section %s: expected '{' but got '%c' at position %d", name, json[pos], pos);
                                return false;
                            }
                        }
                    }
                }
                pos++;
            }
            
            crash_logger::log_error("Section not found: %s", name);
            return false;
        }

        template<typename T>
        bool field(const char* key, T& value) {
            int saved_pos = pos;
            pos = section_pos; 
            if (find_key(key)) { 
                read(value); 
                return true; 
            }
            pos = saved_pos;
            return false;
        }

        
        bool field(const char* key, wchar_t* value, int max_len) {
            int saved_pos = pos;
            pos = section_pos;
            if (find_key(key)) { 
                read(value, max_len); 
                return true; 
            }
            pos = saved_pos;
            return false;
        }

        template<typename T, int N>
        bool field_array(const char* key, T (&arr)[N]) {
            int saved_pos = pos;
            pos = section_pos;
            if (find_key(key)) { 
                read_array(arr); 
                return true; 
            }
            pos = saved_pos;
            return false;
        }

        void reset() { pos = 0; section_pos = 0; }
    };
    #define BEGIN_SAVE_SECTION(name) s.write_key(#name); s.begin_object()
    #define END_SAVE_SECTION() s.end_object()
    #define SAVE_FIELD(section, var) s.field(#var, vars::section::var)
    #define SAVE_FIELD_ARRAY(section, var) s.field_array(#var, vars::section::var)

    #define BEGIN_LOAD_SECTION(name) d.reset(); if (d.enter_section(#name))
    #define LOAD_FIELD(section, var) d.field(#var, vars::section::var)
    #define LOAD_FIELD_ARRAY(section, var) d.field_array(#var, vars::section::var)
    #define LOAD_FIELD_WSTR(section, var) d.field(#var, vars::section::var, 256)
    inline void build_path(wchar_t* dest, const wchar_t* name) {
        int i = 0, j = 0;
        while (CONFIG_FOLDER[i] && i < 400) dest[j++] = CONFIG_FOLDER[i++];
        i = 0;
        while (name[i] && j < 500) dest[j++] = name[i++];
        i = 0;
        while (CONFIG_EXT[i] && j < 511) dest[j++] = CONFIG_EXT[i++];
        dest[j] = '\0';
    }

    inline bool write_file(const wchar_t* path, const char* data, int size) {
        crash_logger::log_info("Writing file: %ls (size: %d bytes)", path, size);
        
        HANDLE h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (h == INVALID_HANDLE_VALUE) {
            crash_logger::log_error("Failed to create file handle, error code: %d", GetLastError());
            return false;
        }
        
        DWORD written;
        bool result = WriteFile(h, data, size, &written, NULL);
        CloseHandle(h);
        
        if (result && written == size) {
            crash_logger::log_info("File written successfully, %d bytes", written);
        } else {
            crash_logger::log_error("File write failed, expected %d bytes, written %d bytes", size, written);
        }
        
        return result && written == size;
    }

    inline bool read_file(const wchar_t* path, char* buffer, int max_size, int& out_size) {
        crash_logger::log_info("Reading file: %ls", path);
        
        HANDLE h = CreateFileW(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (h == INVALID_HANDLE_VALUE) {
            crash_logger::log_error("Failed to open file, error code: %d", GetLastError());
            return false;
        }
        
        DWORD size = GetFileSize(h, NULL);
        crash_logger::log_info("File size: %d bytes", size);
        
        if (size == INVALID_FILE_SIZE || size == 0 || size >= max_size) {
            crash_logger::log_error("Invalid file size (size: %d, max: %d)", size, max_size);
            CloseHandle(h); 
            return false;
        }
        
        DWORD read;
        bool result = ReadFile(h, buffer, size, &read, NULL);
        buffer[read] = '\0';
        out_size = read;
        CloseHandle(h);
        
        if (result) {
            crash_logger::log_info("File read successfully, %d bytes", read);
        } else {
            crash_logger::log_error("File read failed, error code: %d", GetLastError());
        }
        
        return result;
    }
    bool save_config(const wchar_t* config_name) {
        crash_logger::log_info("=== CONFIG SAVE START ===");
        crash_logger::log_info("Config name: %ls", config_name);
        
        wchar_t path[512];
        build_path(path, config_name);
        crash_logger::log_info("Full path: %ls", path);
        
        CreateDirectoryW(CONFIG_FOLDER, NULL);
        crash_logger::log_info("Config directory created/verified");

        JsonSerializer s;
        s.begin_object();
        crash_logger::log_info("JSON serialization started");

     
        crash_logger::log_info("Saving section: antihack");
        BEGIN_SAVE_SECTION(antihack);
        SAVE_FIELD(antihack, flyhack_ind_pos);
        SAVE_FIELD(antihack, maxverticalflyhack);
        SAVE_FIELD(antihack, verticalflyhack);
        SAVE_FIELD(antihack, maxhorisontalflyhack);
        SAVE_FIELD(antihack, horisontalflyhack);
        SAVE_FIELD(antihack, flyhackindicator);
        SAVE_FIELD(antihack, antiflykick);
        SAVE_FIELD(antihack, anti_inside_terrain);
        SAVE_FIELD(antihack, speedhackindicator);
        SAVE_FIELD(antihack, speedhack);
        SAVE_FIELD(antihack, speedhack_cur);
        SAVE_FIELD(antihack, speedhack_pos);
        END_SAVE_SECTION();
        crash_logger::log_info("Section antihack saved");

       
        crash_logger::log_info("Saving section: manipulator");
        BEGIN_SAVE_SECTION(manipulator);
        SAVE_FIELD(manipulator, stopo);
        SAVE_FIELD(manipulator, manipulator);
        SAVE_FIELD(manipulator, maxangle);
        SAVE_FIELD(manipulator, desync);
        SAVE_FIELD(manipulator, m_manipulate);
        SAVE_FIELD(manipulator, manipulatorkey);
        SAVE_FIELD(manipulator, manipulatorind);
        SAVE_FIELD(manipulator, manipulatorind_pos);
        END_SAVE_SECTION();
        crash_logger::log_info("Section manipulator saved");

        
        crash_logger::log_info("Saving section: bulletteleport");
        BEGIN_SAVE_SECTION(bulletteleport);
        SAVE_FIELD(bulletteleport, tp_heli_bullet);
        SAVE_FIELD(bulletteleport, tp_bullet);
        SAVE_FIELD(bulletteleport, hitscan1);
        SAVE_FIELD(bulletteleport, hitscan);
        SAVE_FIELD(bulletteleport, maxangle);
        END_SAVE_SECTION();
        crash_logger::log_info("Section bulletteleport saved");

        
        crash_logger::log_info("Saving section: trasers");
        BEGIN_SAVE_SECTION(trasers);
        SAVE_FIELD(trasers, movement_line);
        SAVE_FIELD(trasers, movement_line_color);
        SAVE_FIELD(trasers, movement_line_time);
        SAVE_FIELD(trasers, bullet_tracers);
        SAVE_FIELD(trasers, bullet_tracers_color);
        SAVE_FIELD(trasers, bullet_tracers_time);
        END_SAVE_SECTION();
        crash_logger::log_info("Section trasers saved");

        
        crash_logger::log_info("Saving section: psilent");
        BEGIN_SAVE_SECTION(psilent);
        SAVE_FIELD(psilent, psilent);
        SAVE_FIELD(psilent, psilentkey);
        SAVE_FIELD(psilent, show_fov);
        SAVE_FIELD(psilent, fov_color);
        SAVE_FIELD(psilent, tarer_fov);
        SAVE_FIELD(psilent, setter_fov);
        SAVE_FIELD(psilent, lags);
        SAVE_FIELD(psilent, target_line);
        SAVE_FIELD(psilent, target_line_color);
        SAVE_FIELD(psilent, HitBone);
        SAVE_FIELD_ARRAY(psilent, ignorepeople);
        SAVE_FIELD(psilent, target_belt);
        SAVE_FIELD(psilent, target_belt_size);
        SAVE_FIELD(psilent, belt_pos);
        SAVE_FIELD(psilent, belt_size);
        END_SAVE_SECTION();
        crash_logger::log_info("Section psilent saved");

   
        crash_logger::log_info("Saving section: esp");
        BEGIN_SAVE_SECTION(esp);
        SAVE_FIELD(esp, oofindicators);
        SAVE_FIELD(esp, skeleton);
        SAVE_FIELD(esp, skeletoncolor);
        SAVE_FIELD(esp, name);
        SAVE_FIELD(esp, namecolor);
        SAVE_FIELD(esp, box_mode);
        SAVE_FIELD(esp, box);
        SAVE_FIELD(esp, boxcolor);
        SAVE_FIELD(esp, weapon);
        SAVE_FIELD(esp, weaponcolor);
        SAVE_FIELD(esp, distance);
        SAVE_FIELD(esp, distancecolor);
        SAVE_FIELD(esp, flags);
        SAVE_FIELD(esp, flagscolor);
        SAVE_FIELD(esp, healthbar);
        SAVE_FIELD(esp, looking_direction);
        SAVE_FIELD(esp, looking_directioncolor);
        SAVE_FIELD(esp, outline);
        SAVE_FIELD_ARRAY(esp, show_choose);
        SAVE_FIELD(esp, radar);
        SAVE_FIELD(esp, radar_size);
        SAVE_FIELD(esp, radar_pos);
        SAVE_FIELD(esp, kill_effect);
        SAVE_FIELD(esp, kill_effect_type);
        SAVE_FIELD(esp, player_chams);
        SAVE_FIELD(esp, player_chams_type);
        SAVE_FIELD(esp, player_chams_color);
        SAVE_FIELD(esp, player_chams_alpha);
        SAVE_FIELD(esp, player_chams_rainbow_speed);
        SAVE_FIELD(esp, player_chams_visible_color);
        SAVE_FIELD(esp, player_chams_invisible_color);
        END_SAVE_SECTION();
        crash_logger::log_info("Section esp saved");

      
        crash_logger::log_info("Saving section: weapon");
        BEGIN_SAVE_SECTION(weapon);
        SAVE_FIELD(weapon, projectile_skip);
        SAVE_FIELD(weapon, stw_enabled);
        SAVE_FIELD(weapon, sphere_hitscan);
        SAVE_FIELD(weapon, sphere_hitscan1);
        SAVE_FIELD(weapon, sphere_RADIUS);
        SAVE_FIELD(weapon, stw_key);
        SAVE_FIELD(weapon, stw_max_distance);
        SAVE_FIELD(weapon, stw_indicator);
        SAVE_FIELD(weapon, stw_indicator_pos);
        SAVE_FIELD(weapon, rapidfire);
        SAVE_FIELD(weapon, rapidfire_speed);
        SAVE_FIELD(weapon, thick_bullet);
        SAVE_FIELD(weapon, bullet_hitbox_size);
        SAVE_FIELD(weapon, norecoil);
        SAVE_FIELD(weapon, norecoil_value_x);
        SAVE_FIELD(weapon, norecoil_value_y);
        SAVE_FIELD(weapon, no_sway);
        SAVE_FIELD(weapon, no_bob);
        SAVE_FIELD(weapon, no_lower);
        SAVE_FIELD(weapon, weaponspam);
        SAVE_FIELD(weapon, weaponspam_key);
        SAVE_FIELD(weapon, weaponspam_delay);
        SAVE_FIELD(weapon, changebulletspeed);
        SAVE_FIELD(weapon, bulletspeed);
        SAVE_FIELD(weapon, bullet_resize);
        SAVE_FIELD(weapon, bullet_size);
        SAVE_FIELD(weapon, alwayshotspot);
        SAVE_FIELD(weapon, silent_melee);
        SAVE_FIELD(weapon, hamerdraw);
        SAVE_FIELD(weapon, show_silent_radius);
        SAVE_FIELD(weapon, piercematerials);
        SAVE_FIELD(weapon, instakill);
        SAVE_FIELD(weapon, nospread);
        SAVE_FIELD(weapon, automatic);
        SAVE_FIELD(weapon, autoreload_pos);
        SAVE_FIELD(weapon, autoreload);
        SAVE_FIELD(weapon, autoreloadindicator);
        SAVE_FIELD(weapon, eokachance);
        SAVE_FIELD(weapon, hit_material);
        SAVE_FIELD(weapon, autofarmore);
        SAVE_FIELD(weapon, autofarmtree);
        END_SAVE_SECTION();
        crash_logger::log_info("Section weapon saved");

       
        crash_logger::log_info("Saving section: localplayer");
        BEGIN_SAVE_SECTION(localplayer);
        SAVE_FIELD(localplayer, chams);
        SAVE_FIELD(localplayer, chams_type);
        SAVE_FIELD(localplayer, autoheal);
        SAVE_FIELD(localplayer, doorspammer);
        SAVE_FIELD(localplayer, silentstash);
        SAVE_FIELD(localplayer, silentcollectiblet);
        SAVE_FIELD(localplayer, silentturret);
        SAVE_FIELD(localplayer, stoprecycler);
        SAVE_FIELD(localplayer, auto_upgrade);
        SAVE_FIELD(localplayer, upgrade);
        SAVE_FIELD(localplayer, gesture_spam);
        SAVE_FIELD(localplayer, gesture);
        SAVE_FIELD(localplayer, suicide);
        SAVE_FIELD(localplayer, suicidekey);
        SAVE_FIELD(localplayer, zoom);
        SAVE_FIELD(localplayer, zoomkey);
        SAVE_FIELD(localplayer, autorefill);
        END_SAVE_SECTION();
        crash_logger::log_info("Section localplayer saved");

        
        crash_logger::log_info("Saving section: misc");
        BEGIN_SAVE_SECTION(misc);
        SAVE_FIELD(misc, namespoofer);
        SAVE_FIELD(misc, randomnick);
        SAVE_FIELD(misc, nick);
        SAVE_FIELD(misc, admin_mode);
        SAVE_FIELD(misc, is_real_admin);
        SAVE_FIELD(misc, gravity);
        SAVE_FIELD(misc, gravity_value);
        SAVE_FIELD(misc, look_allert);
        SAVE_FIELD(misc, antiaim);
        SAVE_FIELD(misc, antiaim_mode);
        SAVE_FIELD(misc, spinspeed);
        SAVE_FIELD(misc, teleport_to_head);
        SAVE_FIELD(misc, teleport_to_headkey);
        SAVE_FIELD(misc, speedhack);
        SAVE_FIELD(misc, speedhackspeed);
        SAVE_FIELD(misc, speedhackkey);
        SAVE_FIELD(misc, fakelag);
        SAVE_FIELD(misc, fakelag_key);
        SAVE_FIELD(misc, fakelag_ticks);
        SAVE_FIELD(misc, fakelag_indicator);
        SAVE_FIELD(misc, fakelag_indicator_pos);
        SAVE_FIELD(misc, bhop);
        SAVE_FIELD(misc, bhopkey);
        SAVE_FIELD(misc, interactivedebug);
        SAVE_FIELD(misc, interactivedebug_speed);
        SAVE_FIELD(misc, interactivedebugkey);
        SAVE_FIELD(misc, no_watercollision);
        SAVE_FIELD(misc, no_playercollision);
        SAVE_FIELD(misc, no_treecollision);
        SAVE_FIELD(misc, attack_on_mountables);
        SAVE_FIELD(misc, always_sprint);
        SAVE_FIELD(misc, inf_jump);
        SAVE_FIELD(misc, always_shoot);
        SAVE_FIELD(misc, spider);
        SAVE_FIELD(misc, no_fall_damage);
        SAVE_FIELD(misc, raycast_sphere);
        SAVE_FIELD(misc, raycast_sphere_color);
        SAVE_FIELD(misc, fastloot);
        SAVE_FIELD(misc, farmbot);
        SAVE_FIELD(misc, sky_color_changer);
        SAVE_FIELD(misc, sky_color);
        SAVE_FIELD(misc, stars_changer);
        SAVE_FIELD(misc, ambient_changer);
        SAVE_FIELD(misc, ambient_color);
        SAVE_FIELD(misc, stars_amount);
        SAVE_FIELD(misc, stars_size);
        SAVE_FIELD(misc, rayleigh_changer);
        SAVE_FIELD(misc, rayleigh);
        SAVE_FIELD(misc, mie_changer);
        SAVE_FIELD(misc, mie);
        SAVE_FIELD(misc, brightness_changer);
        SAVE_FIELD(misc, brightness);
        SAVE_FIELD(misc, time_changer);
        SAVE_FIELD(misc, time_amount);
        SAVE_FIELD(misc, fov_changer);
        SAVE_FIELD(misc, fov_amount);
        SAVE_FIELD(misc, thirdperson_changer);
        SAVE_FIELD(misc, th_dist);
        SAVE_FIELD(misc, th_fov);
        SAVE_FIELD(misc, ratio_changer);
        SAVE_FIELD(misc, ratio_amount);
        SAVE_FIELD(misc, noclouds);
        SAVE_FIELD(misc, atmospherecontrast);
        SAVE_FIELD(misc, nofog);
        SAVE_FIELD(misc, norain);
        SAVE_FIELD(misc, nothunder);
        SAVE_FIELD(misc, nowind);
        SAVE_FIELD(misc, brightcave);
        END_SAVE_SECTION();
        crash_logger::log_info("Section misc saved");
        crash_logger::log_info("Saving section: object");
        BEGIN_SAVE_SECTION(object);
        SAVE_FIELD(object, max_ores_distance);
        SAVE_FIELD(object, show_ores_distance);
        SAVE_FIELD(object, show_ores_ico);
        SAVE_FIELD_ARRAY(object, ores);
        SAVE_FIELD(object, max_berrys_distance);
        SAVE_FIELD(object, show_berrys_distance);
        SAVE_FIELD(object, show_berrys_ico);
        SAVE_FIELD_ARRAY(object, berrys);
        SAVE_FIELD(object, max_others_distance);
        SAVE_FIELD(object, show_others_distance);
        SAVE_FIELD(object, show_others_ico);
        SAVE_FIELD_ARRAY(object, others);
        SAVE_FIELD(object, max_vehicles_distance);
        SAVE_FIELD(object, show_vehicles_distance);
        SAVE_FIELD_ARRAY(object, vehicles);
        SAVE_FIELD(object, max_traps_distance);
        SAVE_FIELD(object, show_traps_distance);
        SAVE_FIELD(object, show_traps_ico);
        SAVE_FIELD_ARRAY(object, traps);
        SAVE_FIELD(object, max_animals_distance);
        SAVE_FIELD(object, show_animals_distance);
        SAVE_FIELD_ARRAY(object, animals);
        SAVE_FIELD(object, max_crates_distance);
        SAVE_FIELD(object, show_crates_distance);
        SAVE_FIELD_ARRAY(object, crates);
        SAVE_FIELD(object, max_homeobjects_distance);
        SAVE_FIELD(object, show_homeobjects_distance);
        SAVE_FIELD(object, show_homeobjects_ico);
        SAVE_FIELD_ARRAY(object, homeobjects);
        SAVE_FIELD(object, max_mainobjects_distance);
        SAVE_FIELD(object, show_mainobjects_distance);
        SAVE_FIELD_ARRAY(object, mainobjects);
        SAVE_FIELD(object, show_dropeeditems_ico);
        SAVE_FIELD(object, debug);
        SAVE_FIELD(object, debug_ent);
        END_SAVE_SECTION();

        s.end_object();
        
        bool result = write_file(path, s.get_json(), s.size());
        return result;
    }
    bool load_config(const wchar_t* config_name) {
        wchar_t path[512];
        build_path(path, config_name);

        char json_buffer[BUFFER_SIZE];
        int size;
        
        if (!read_file(path, json_buffer, BUFFER_SIZE, size)) {
            return false;
        }

        JsonDeserializer d(json_buffer);

       
        BEGIN_LOAD_SECTION(antihack) {
            LOAD_FIELD(antihack, flyhack_ind_pos);
            LOAD_FIELD(antihack, maxverticalflyhack);
            LOAD_FIELD(antihack, verticalflyhack);
            LOAD_FIELD(antihack, maxhorisontalflyhack);
            LOAD_FIELD(antihack, horisontalflyhack);
            LOAD_FIELD(antihack, flyhackindicator);
            LOAD_FIELD(antihack, antiflykick);
            LOAD_FIELD(antihack, anti_inside_terrain);
            LOAD_FIELD(antihack, speedhackindicator);
            LOAD_FIELD(antihack, speedhack);
            LOAD_FIELD(antihack, speedhack_cur);
            LOAD_FIELD(antihack, speedhack_pos);
        }

        BEGIN_LOAD_SECTION(manipulator) {
            LOAD_FIELD(manipulator, stopo);
            LOAD_FIELD(manipulator, manipulator);
            LOAD_FIELD(manipulator, maxangle);
            LOAD_FIELD(manipulator, desync);
            LOAD_FIELD(manipulator, m_manipulate);
            LOAD_FIELD(manipulator, manipulatorkey);
            LOAD_FIELD(manipulator, manipulatorind);
            LOAD_FIELD(manipulator, manipulatorind_pos);
        }

    
        BEGIN_LOAD_SECTION(bulletteleport) {
            crash_logger::log_info("Loading bulletteleport section...");
            LOAD_FIELD(bulletteleport, tp_heli_bullet);
            LOAD_FIELD(bulletteleport, tp_bullet);
            LOAD_FIELD(bulletteleport, hitscan1);
            LOAD_FIELD(bulletteleport, hitscan);
            LOAD_FIELD(bulletteleport, maxangle);
            crash_logger::log_info("Bulletteleport section loaded");
        } else {
            crash_logger::log_error("Failed to enter bulletteleport section");
        }

      
        BEGIN_LOAD_SECTION(trasers) {
            crash_logger::log_info("Loading trasers section...");
            LOAD_FIELD(trasers, movement_line);
            LOAD_FIELD(trasers, movement_line_color);
            LOAD_FIELD(trasers, movement_line_time);
            LOAD_FIELD(trasers, bullet_tracers);
            LOAD_FIELD(trasers, bullet_tracers_color);
            LOAD_FIELD(trasers, bullet_tracers_time);
            crash_logger::log_info("Trasers section loaded");
        } else {
            crash_logger::log_error("Failed to enter trasers section");
        }

    
        BEGIN_LOAD_SECTION(psilent) {
            crash_logger::log_info("Loading psilent section...");
            LOAD_FIELD(psilent, psilent);
            LOAD_FIELD(psilent, psilentkey);
            LOAD_FIELD(psilent, show_fov);
            LOAD_FIELD(psilent, fov_color);
            LOAD_FIELD(psilent, tarer_fov);
            LOAD_FIELD(psilent, setter_fov);
            LOAD_FIELD(psilent, lags);
            LOAD_FIELD(psilent, target_line);
            LOAD_FIELD(psilent, target_line_color);
            LOAD_FIELD(psilent, HitBone);
            LOAD_FIELD_ARRAY(psilent, ignorepeople);
            LOAD_FIELD(psilent, target_belt);
            LOAD_FIELD(psilent, target_belt_size);
            LOAD_FIELD(psilent, belt_pos);
            LOAD_FIELD(psilent, belt_size);
            crash_logger::log_info("Psilent section loaded");
        } else {
            crash_logger::log_error("Failed to enter psilent section");
        }

    
        BEGIN_LOAD_SECTION(esp) {
            crash_logger::log_info("Loading esp section...");
            LOAD_FIELD(esp, oofindicators);
            LOAD_FIELD(esp, skeleton);
            LOAD_FIELD(esp, skeletoncolor);
            LOAD_FIELD(esp, name);
            LOAD_FIELD(esp, namecolor);
            LOAD_FIELD(esp, box_mode);
            LOAD_FIELD(esp, box);
            LOAD_FIELD(esp, boxcolor);
            LOAD_FIELD(esp, weapon);
            LOAD_FIELD(esp, weaponcolor);
            LOAD_FIELD(esp, distance);
            LOAD_FIELD(esp, distancecolor);
            LOAD_FIELD(esp, flags);
            LOAD_FIELD(esp, flagscolor);
            LOAD_FIELD(esp, healthbar);
            LOAD_FIELD(esp, looking_direction);
            LOAD_FIELD(esp, looking_directioncolor);
            LOAD_FIELD(esp, outline);
            LOAD_FIELD_ARRAY(esp, show_choose);
            LOAD_FIELD(esp, radar);
            LOAD_FIELD(esp, radar_size);
            LOAD_FIELD(esp, radar_pos);
            LOAD_FIELD(esp, kill_effect);
            LOAD_FIELD(esp, kill_effect_type);
            LOAD_FIELD(esp, player_chams);
            LOAD_FIELD(esp, player_chams_type);
            LOAD_FIELD(esp, player_chams_color);
            LOAD_FIELD(esp, player_chams_alpha);
            LOAD_FIELD(esp, player_chams_rainbow_speed);
            LOAD_FIELD(esp, player_chams_visible_color);
            LOAD_FIELD(esp, player_chams_invisible_color);
            crash_logger::log_info("Esp section loaded");
        } else {
            crash_logger::log_error("Failed to enter esp section");
        }

       
        BEGIN_LOAD_SECTION(weapon) {
            crash_logger::log_info("Loading weapon section...");
            LOAD_FIELD(weapon, projectile_skip);
            LOAD_FIELD(weapon, stw_enabled);
            LOAD_FIELD(weapon, stw_key);
            LOAD_FIELD(weapon, stw_max_distance);
            LOAD_FIELD(weapon, stw_indicator);
            LOAD_FIELD(weapon, sphere_hitscan);
            LOAD_FIELD(weapon, sphere_hitscan1);
            LOAD_FIELD(weapon, sphere_RADIUS);
            LOAD_FIELD(weapon, stw_indicator_pos);
            LOAD_FIELD(weapon, rapidfire);
            LOAD_FIELD(weapon, rapidfire_speed);
            LOAD_FIELD(weapon, thick_bullet);
            LOAD_FIELD(weapon, bullet_hitbox_size);
            LOAD_FIELD(weapon, norecoil);
            LOAD_FIELD(weapon, norecoil_value_x);
            LOAD_FIELD(weapon, norecoil_value_y);
            LOAD_FIELD(weapon, no_sway);
            LOAD_FIELD(weapon, no_bob);
            LOAD_FIELD(weapon, no_lower);
            LOAD_FIELD(weapon, weaponspam);
            LOAD_FIELD(weapon, weaponspam_key);
            LOAD_FIELD(weapon, weaponspam_delay);
            LOAD_FIELD(weapon, changebulletspeed);
            LOAD_FIELD(weapon, bulletspeed);
            LOAD_FIELD(weapon, bullet_resize);
            LOAD_FIELD(weapon, bullet_size);
            LOAD_FIELD(weapon, alwayshotspot);
            LOAD_FIELD(weapon, silent_melee);
            LOAD_FIELD(weapon, hamerdraw);
            LOAD_FIELD(weapon, show_silent_radius);
            LOAD_FIELD(weapon, piercematerials);
            LOAD_FIELD(weapon, instakill);
            LOAD_FIELD(weapon, nospread);
            LOAD_FIELD(weapon, automatic);
            LOAD_FIELD(weapon, autoreload_pos);
            LOAD_FIELD(weapon, autoreload);
            LOAD_FIELD(weapon, autoreloadindicator);
            LOAD_FIELD(weapon, eokachance);
            LOAD_FIELD(weapon, hit_material);
            LOAD_FIELD(weapon, autofarmore);
            LOAD_FIELD(weapon, autofarmtree);
            crash_logger::log_info("Weapon section loaded");
        } else {
            crash_logger::log_error("Failed to enter weapon section");
        }

        
        BEGIN_LOAD_SECTION(localplayer) {
            crash_logger::log_info("Loading localplayer section...");
            LOAD_FIELD(localplayer, chams);
            LOAD_FIELD(localplayer, chams_type);
            LOAD_FIELD(localplayer, autoheal);
            LOAD_FIELD(localplayer, doorspammer);
            LOAD_FIELD(localplayer, silentstash);
            LOAD_FIELD(localplayer, silentcollectiblet);
            LOAD_FIELD(localplayer, silentturret);
            LOAD_FIELD(localplayer, stoprecycler);
            LOAD_FIELD(localplayer, auto_upgrade);
            LOAD_FIELD(localplayer, upgrade);
            LOAD_FIELD(localplayer, gesture_spam);
            LOAD_FIELD(localplayer, gesture);
            LOAD_FIELD(localplayer, suicide);
            LOAD_FIELD(localplayer, suicidekey);
            LOAD_FIELD(localplayer, zoom);
            LOAD_FIELD(localplayer, zoomkey);
            LOAD_FIELD(localplayer, autorefill);
            crash_logger::log_info("Localplayer section loaded");
        } else {
            crash_logger::log_error("Failed to enter localplayer section");
        }

        
        BEGIN_LOAD_SECTION(misc) {
            crash_logger::log_info("Loading misc section...");
            LOAD_FIELD(misc, namespoofer);
            LOAD_FIELD(misc, randomnick);
            LOAD_FIELD_WSTR(misc, nick);
            LOAD_FIELD(misc, admin_mode);
            LOAD_FIELD(misc, is_real_admin);
            LOAD_FIELD(misc, gravity);
            LOAD_FIELD(misc, gravity_value);
            LOAD_FIELD(misc, look_allert);
            LOAD_FIELD(misc, antiaim);
            LOAD_FIELD(misc, antiaim_mode);
            LOAD_FIELD(misc, spinspeed);
            LOAD_FIELD(misc, teleport_to_head);
            LOAD_FIELD(misc, teleport_to_headkey);
            LOAD_FIELD(misc, speedhack);
            LOAD_FIELD(misc, speedhackspeed);
            LOAD_FIELD(misc, speedhackkey);
            LOAD_FIELD(misc, fakelag);
            LOAD_FIELD(misc, fakelag_key);
            LOAD_FIELD(misc, fakelag_ticks);
            LOAD_FIELD(misc, fakelag_indicator);
            LOAD_FIELD(misc, fakelag_indicator_pos);
            LOAD_FIELD(misc, bhop);
            LOAD_FIELD(misc, bhopkey);
            LOAD_FIELD(misc, interactivedebug);
            LOAD_FIELD(misc, interactivedebug_speed);
            LOAD_FIELD(misc, interactivedebugkey);
            LOAD_FIELD(misc, no_watercollision);
            LOAD_FIELD(misc, no_playercollision);
            LOAD_FIELD(misc, no_treecollision);
            LOAD_FIELD(misc, attack_on_mountables);
            LOAD_FIELD(misc, always_sprint);
            LOAD_FIELD(misc, inf_jump);
            LOAD_FIELD(misc, always_shoot);
            LOAD_FIELD(misc, spider);
            LOAD_FIELD(misc, no_fall_damage);
            LOAD_FIELD(misc, raycast_sphere);
            LOAD_FIELD(misc, raycast_sphere_color);
            LOAD_FIELD(misc, fastloot);
            LOAD_FIELD(misc, farmbot);
            LOAD_FIELD(misc, sky_color_changer);
            LOAD_FIELD(misc, sky_color);
            LOAD_FIELD(misc, stars_changer);
            LOAD_FIELD(misc, ambient_changer);
            LOAD_FIELD(misc, ambient_color);
            LOAD_FIELD(misc, stars_amount);
            LOAD_FIELD(misc, stars_size);
            LOAD_FIELD(misc, rayleigh_changer);
            LOAD_FIELD(misc, rayleigh);
            LOAD_FIELD(misc, mie_changer);
            LOAD_FIELD(misc, mie);
            LOAD_FIELD(misc, brightness_changer);
            LOAD_FIELD(misc, brightness);
            LOAD_FIELD(misc, time_changer);
            LOAD_FIELD(misc, time_amount);
            LOAD_FIELD(misc, fov_changer);
            LOAD_FIELD(misc, fov_amount);
            LOAD_FIELD(misc, thirdperson_changer);
            LOAD_FIELD(misc, th_dist);
            LOAD_FIELD(misc, th_fov);
            LOAD_FIELD(misc, ratio_changer);
            LOAD_FIELD(misc, ratio_amount);
            LOAD_FIELD(misc, noclouds);
            LOAD_FIELD(misc, atmospherecontrast);
            LOAD_FIELD(misc, nofog);
            LOAD_FIELD(misc, norain);
            LOAD_FIELD(misc, nothunder);
            LOAD_FIELD(misc, nowind);
            LOAD_FIELD(misc, brightcave);
            crash_logger::log_info("Misc section loaded");
        } else {
            crash_logger::log_error("Failed to enter misc section");
        }

   
        BEGIN_LOAD_SECTION(object) {
            crash_logger::log_info("Loading object section...");
            LOAD_FIELD(object, max_ores_distance);
            LOAD_FIELD(object, show_ores_distance);
            LOAD_FIELD(object, show_ores_ico);
            LOAD_FIELD_ARRAY(object, ores);
            LOAD_FIELD(object, max_berrys_distance);
            LOAD_FIELD(object, show_berrys_distance);
            LOAD_FIELD(object, show_berrys_ico);
            LOAD_FIELD_ARRAY(object, berrys);
            LOAD_FIELD(object, max_others_distance);
            LOAD_FIELD(object, show_others_distance);
            LOAD_FIELD(object, show_others_ico);
            LOAD_FIELD_ARRAY(object, others);
            LOAD_FIELD(object, max_vehicles_distance);
            LOAD_FIELD(object, show_vehicles_distance);
            LOAD_FIELD_ARRAY(object, vehicles);
            LOAD_FIELD(object, max_traps_distance);
            LOAD_FIELD(object, show_traps_distance);
            LOAD_FIELD(object, show_traps_ico);
            LOAD_FIELD_ARRAY(object, traps);
            LOAD_FIELD(object, max_animals_distance);
            LOAD_FIELD(object, show_animals_distance);
            LOAD_FIELD_ARRAY(object, animals);
            LOAD_FIELD(object, max_crates_distance);
            LOAD_FIELD(object, show_crates_distance);
            LOAD_FIELD_ARRAY(object, crates);
            LOAD_FIELD(object, max_homeobjects_distance);
            LOAD_FIELD(object, show_homeobjects_distance);
            LOAD_FIELD(object, show_homeobjects_ico);
            LOAD_FIELD_ARRAY(object, homeobjects);
            LOAD_FIELD(object, max_mainobjects_distance);
            LOAD_FIELD(object, show_mainobjects_distance);
            LOAD_FIELD_ARRAY(object, mainobjects);
            LOAD_FIELD(object, show_dropeeditems_ico);
            LOAD_FIELD(object, debug);
            LOAD_FIELD(object, debug_ent);
            crash_logger::log_info("Object section loaded");
        } else {
            crash_logger::log_error("Failed to enter object section");
        }

        crash_logger::log_info("=== CONFIG LOADED SUCCESSFULLY ===");
        return true;
    }
    struct ConfigList {
        int count = 0;
        wchar_t names[MAX_CONFIGS][MAX_NAME_LEN];
    };

    bool delete_config(const wchar_t* config_name) {
        crash_logger::log_info("=== CONFIG DELETE START ===");
        crash_logger::log_info("Config name: %ls", config_name);
        
        wchar_t path[512];
        build_path(path, config_name);
        crash_logger::log_info("Full path: %ls", path);
        
        bool result = DeleteFileW(path) != 0;
        
        if (result) {
            crash_logger::log_info("=== CONFIG DELETED SUCCESSFULLY ===");
        } else {
            crash_logger::log_error("=== CONFIG DELETE FAILED ===");
            crash_logger::log_error("Error code: %d", GetLastError());
        }
        
        return result;
    }

    void get_config_list(ConfigList* list) {
        crash_logger::log_info("=== GET CONFIG LIST START ===");
        list->count = 0;
        
        wchar_t search[512];
        int i = 0, j = 0;
        while (CONFIG_FOLDER[i] && i < 400) search[j++] = CONFIG_FOLDER[i++];
        search[j++] = L'*'; i = 0;
        while (CONFIG_EXT[i] && j < 511) search[j++] = CONFIG_EXT[i++];
        search[j] = L'\0';
        
        crash_logger::log_info("Search pattern: %ls", search);

        WIN32_FIND_DATAW fd;
        HANDLE h = FindFirstFileW(search, &fd);
        if (h == INVALID_HANDLE_VALUE) {
            crash_logger::log_error("Failed to open config directory");
            crash_logger::log_error("Error code: %d", GetLastError());
            return;
        }

        crash_logger::log_info("Scanning config directory...");
        do {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && list->count < MAX_CONFIGS) {
                int name_len = 0, ext_len = 0;
                while (fd.cFileName[name_len]) name_len++;
                while (CONFIG_EXT[ext_len]) ext_len++;
                
                if (name_len >= ext_len) {
                    bool match = true;
                    for (int k = 0; k < ext_len; k++) {
                        if (fd.cFileName[name_len - ext_len + k] != CONFIG_EXT[k]) {
                            match = false; break;
                        }
                    }
                    if (match) {
                        int copy_len = name_len - ext_len;
                        if (copy_len > MAX_NAME_LEN - 1) copy_len = MAX_NAME_LEN - 1;
                        for (int k = 0; k < copy_len; k++) {
                            list->names[list->count][k] = fd.cFileName[k];
                        }
                        list->names[list->count][copy_len] = L'\0';
                        crash_logger::log_info("Found config: %ls", list->names[list->count]);
                        list->count++;
                    }
                }
            }
        } while (FindNextFileW(h, &fd) && list->count < MAX_CONFIGS);
        FindClose(h);
        
        crash_logger::log_info("Total configs found: %d", list->count);
        crash_logger::log_info("=== GET CONFIG LIST END ===");
    }
}
