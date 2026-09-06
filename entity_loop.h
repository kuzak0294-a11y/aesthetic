#pragma once
#include <windows.h>
#include <cmath>
#include <cstdint>
#include <vector>

struct Vector2 {
    float x = 0.0f;
    float y = 0.0f;
};

struct Vector3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    float DistanceTo(const Vector3& other) const noexcept {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};

struct Matrix4x4 {
    float m[4][4]{};
};

struct Camera {
    Matrix4x4 viewProjection{};
    float viewportWidth = 1280.0f;
    float viewportHeight = 720.0f;

    bool WorldToScreen(const Vector3& world, Vector2& screen) const noexcept {
        float clipX = world.x * viewProjection.m[0][0] + world.y * viewProjection.m[1][0] + world.z * viewProjection.m[2][0] + viewProjection.m[3][0];
        float clipY = world.x * viewProjection.m[0][1] + world.y * viewProjection.m[1][1] + world.z * viewProjection.m[2][1] + viewProjection.m[3][1];
        float clipW = world.x * viewProjection.m[0][3] + world.y * viewProjection.m[1][3] + world.z * viewProjection.m[2][3] + viewProjection.m[3][3];

        if (clipW < 0.001f) return false;

        float nx = clipX / clipW;
        float ny = clipY / clipW;
        screen.x = (nx + 1.0f) * 0.5f * viewportWidth;
        screen.y = (1.0f - ny) * 0.5f * viewportHeight;

        return (screen.x >= 0.0f && screen.x <= viewportWidth && screen.y >= 0.0f && screen.y <= viewportHeight);
    }
};

struct BasePlayer {
    std::uint32_t id = 0;
    Vector3 position{};
    float health = 100.0f;

    bool IsValid() const noexcept {
        return health > 0.0f && health <= 100.0f;
    }
};

class EntitySystem {
public:
    std::vector<BasePlayer> players;

    void UpdateMemory() {
        players.clear();
        // ЗДЕСЬ ТЫ ПОТОМ ПРОПИШЕШЬ ЧТЕНИЕ ПАМЯТИ ЧЕРЕЗ ReadProcessMemory ИЛИ УКАЗАТЕЛИ ДЕВБЛОГА
    }
};

inline EntitySystem g_EntitySystem;