extern "C" { int _fltused = 0; }
#include <Windows.h>
#include <winternl.h>
#include <vector>
#define rc reinterpret_cast 
#include "xor.hpp"
#include "u_crt.hpp"
#include "crash_logger.hpp"
#include "memory.hpp"
#include "il2cpp.hpp"
#include "offsets.h"
#include "enums.hpp"
#include "o_dump_value.h"
uintptr_t g_base;
#include "classes.hpp"
#include "render.hpp"
#include "config.hpp"
#include "elements.h"
Vector3 BulletPos = Vector3(0, 0, 0);
#include "matrix.h"
#include "antihack.h"
#include "aim.h"
#include "bullettp.h"
#include "stw.h"
#include "other.h"
#include "kill_effect.h"
#include "chat_spammer.h"
#include "fakelag.h"

#include "init_hooks.hpp"
#include "visuals.h"
#include "entity_loop.h"
#include "menu.h"


