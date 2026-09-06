#pragma once

struct Vector2 {
    float x, y;
};

struct D3DMATRIX {
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};

class Math {
public:
    static bool WorldToScreen(Vector3 worldPos, Vector2& screenPos, D3DMATRIX viewMatrix, int screenWidth, int screenHeight) {
        float w = viewMatrix._14 * worldPos.x + viewMatrix._24 * worldPos.y + viewMatrix._34 * worldPos.z + viewMatrix._44;

        if (w < 0.098f) return false;

        float x = viewMatrix._11 * worldPos.x + viewMatrix._21 * worldPos.y + viewMatrix._31 * worldPos.z + viewMatrix._41;
        float y = viewMatrix._12 * worldPos.x + viewMatrix._22 * worldPos.y + viewMatrix._32 * worldPos.z + viewMatrix._42;

        float invW = 1.0f / w;
        float nx = x * invW;
        float ny = y * invW;

        screenPos.x = (screenWidth / 2.0f) + (nx * screenWidth / 2.0f);
        screenPos.y = (screenHeight / 2.0f) - (ny * screenHeight / 2.0f);

        return true;
    }
};