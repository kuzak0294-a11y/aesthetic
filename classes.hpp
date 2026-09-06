class Vector2 {
public:
	float x, y;

	Vector2() {
		x = y = 0.0f;
	}

	Vector2 operator*(float v) const {
		return Vector2(x * v, y * v);
	}

	Vector2 operator/(float v) const {
		return Vector2(x / v, y / v);
	}
	Vector2(float X, float Y) {
		x = X; y = Y;
	}

	Vector2 operator-(const Vector2& v) const {
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 operator+(const Vector2& v) const {
		return Vector2(x + v.x, y + v.y);
	}
	bool operator==(const Vector2& b) const {
		return x == b.x && y == b.y;
	}
	Vector2& operator+=(const Vector2& v) {
		x += v.x; y += v.y; return *this;
	}
	float Length() const {
		return sqrtf((x * x) + (y * y));
	}
	static Vector2 Zero() {
		return Vector2(0.0f, 0.0f);
	}
	inline static float sqrtf(float number)
	{
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y;
		i = 0x5f3759df - (i >> 1);
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));

		return 1 / y;
	}
	static Vector2 Zero2() {
		return Vector2(0.0f, 0.0f);
	}
	inline float Distance(const Vector2& vector)
	{
		return sqrtf((x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y));
	}
};
class Vector3
{
public:
	float x, y, z;

	Vector3() {
		x = y = z = 0.0f;
	}

	Vector3(float X, float Y, float Z) {
		x = X; y = Y; z = Z;
	}

	inline float Dot2(const Vector3& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}

	float operator[](int i) const {
		return ((float*)this)[i];
	}

	Vector3& operator-=(float v) {
		x -= v; y -= v; z -= v; return *this;
	}

	bool is_empty() { return x == 0 && y == 0 && z == 0; }


	Vector3 operator*(float v) const {
		return Vector3(x * v, y * v, z * v);
	}

	Vector3& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		return *this;
	}

	Vector3 operator/(float v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	Vector3& operator+=(const Vector3& v) {
		x += v.x; y += v.y; z += v.z; return *this;
	}

	Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	bool operator==(const Vector3& b) const {
		return x == b.x && y == b.y && z == b.z;
	}
	Vector3& operator-=(const Vector3& v) {
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}
	Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	static Vector3 Zero() {
		return Vector3(0.0f, 0.0f, 0.0f);
	}
	static Vector3 Up() {
		return Vector3(0.0f, 1.0f, 0.0f);
	}
	static Vector3 Forward() {
		return Vector3(0.0f, 0.0f, 1.0f);
	}
	inline static float sqrtf(float number)
	{
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y;
		i = 0x5f3759df - (i >> 1);
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));

		return 1 / y;
	}
	float Length() const
	{
		return sqrtf(x * x + y * y + z * z);
	}
	float length_2d() { return sqrt((x * x) + (z * z)); }
	float Magnitude() {
		return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	Vector3 cross(Vector3 other) const {
		return Vector3(y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
	}
	double sqrt(double d) {
		return rc<double(*)(double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Sqrt"), 1, _(""), _("System"))))(d);
	};
	static Vector3 Down() {
		return Vector3(0.0f, -1.0f, 0.0f);
	}
	static float Clamp01(float value)
	{
		if (value < 0.f)
			return 0.f;
		else if (value > 1.f)
			return 1.f;
		else
			return value;
	}
	Vector3 Cross(Vector3 rhs)
	{
		return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}
	static float InverseLerp(float a, float b, float value)
	{
		float result;
		if (a != b)
		{
			result = Clamp01((value - a) / (b - a));
		}
		else
		{
			result = 0.f;
		}
		return result;
	}
	inline float Magnitude2D()
	{
		return sqrt(this->x * this->x + this->z * this->z);
	}
	inline Vector3 Normalized()
	{
		float m_flLength = Length();
		return Vector3(x / m_flLength, y / m_flLength, z / m_flLength);
	}
	float dot_product(Vector3 input) const {
		return (x * input.x) + (y * input.y) + (z * input.z);
	}
	Vector3 midPoint(Vector3 v2)
	{
		return Vector3((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
	}
	float Distance2D(Vector3 vector) const {
		auto direction = (*this - vector);
		return direction.length_2d();
	}
	inline float UnityDot(Vector3 lhs, Vector3 rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}
	float dot(const Vector3& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}
	float UnityMagnitude()
	{
		return (float)sqrt((double)(this->x * this->x + this->y * this->y + this->z * this->z));
	}

	void UnityNormalize()
	{
		Vector3 tis(x, y, z);
		float num = Vector3(x, y, z).Magnitude();
		if (num > 1E-05f)
		{
			tis /= num;
		}
		else
		{
			tis = Vector3().Zero();
		}
		x = tis.x;
		y = tis.y;
		z = tis.z;
	}

	Vector3 UnityNormalizeVec3()
	{
		Vector3 tis(x, y, z);
		float num = Vector3(x, y, z).Magnitude();
		if (num > 1E-05f)
		{
			tis /= num;
		}
		else
		{
			tis = Vector3(0, 0, 0);
		}
		x = tis.x;
		y = tis.y;
		z = tis.z;

		return { x,y,z };
	}

	bool empty() const {
		return x == 0.f && y == 0.f && z == 0.f;
	}

	inline float Distance(const Vector3& vector)
	{
		return sqrtf((x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z));
	}

	inline float RustDistance(const Vector3& vector)
	{
		return (Vector3(x, y, z) - vector).Magnitude();
	}

};
class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;

	Vector4()
	{}

	Vector4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	Vector3 forward()
	{
		Vector3  point = { 0, 0, 1 };
		float num = x * 2;
		float num2 = y * 2;
		float num3 = z * 2;
		float num4 = x * num;
		float num5 = y * num2;
		float num6 = z * num3;
		float num7 = x * num2;
		float num8 = x * num3;
		float num9 = y * num3;
		float num10 = w * num;
		float num11 = w * num2;
		float num12 = w * num3;
		Vector3  result;
		result.x = (1 - (num5 + num6)) * point.x + (num7 - num12) * point.y +
			(num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1 - (num4 + num6)) * point.y +
			(num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y +
			(1 - (num4 + num5)) * point.z;
		return result;
	}


	inline float dot(const Vector4& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
	}

	inline float distance(const Vector4& vector)
	{
		return sqrtf(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z) +
			(w - vector.w) * (w - vector.w));
	}

	bool operator==(const Vector4& vector) const
	{
		return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
	}

	bool operator!=(const Vector4& vector) const
	{
		return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
	}

	Vector4 operator+(const Vector4& vector) const
	{
		return Vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
	}

	Vector4 operator-(const Vector4& vector) const
	{
		return Vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
	}

	Vector4 operator-() const
	{
		return Vector4(-x, -y, -z, -w);
	}

	Vector4 operator*(float number) const
	{
		return Vector4(x * number, y * number, z * number, w * number);
	}

	Vector4 operator/(float number) const
	{
		return Vector4(x / number, y / number, z / number, w / number);
	}

	Vector4& operator+=(const Vector4& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	Vector4& operator-=(const Vector4& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	Vector4& operator*=(float number)
	{
		x *= number;
		y *= number;
		z *= number;
		w *= number;
		return *this;
	}

	Vector4& operator/=(float number)
	{
		x /= number;
		y /= number;
		z /= number;
		w /= number;
		return *this;
	}

	Vector3 operator*(Vector3 point) const
	{
		float num = x * 2.f;
		float num2 = y * 2.f;
		float num3 = z * 2.f;
		float num4 = x * num;
		float num5 = y * num2;
		float num6 = z * num3;
		float num7 = x * num2;
		float num8 = x * num3;
		float num9 = y * num3;
		float num10 = w * num;
		float num11 = w * num2;
		float num12 = w * num3;
		Vector3 result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}

	inline static float sqrtf(float number)
	{
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y;
		i = 0x5f3759df - (i >> 1);
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));

		return 1 / y;
	}
	static Vector4 QuaternionLookRotation(Vector3 forward, Vector3 up)
	{

		Vector3 vector = forward.UnityNormalizeVec3();
		Vector3 vector2 = (up).Cross(vector).UnityNormalizeVec3();
		Vector3 vector3 = (vector).Cross(vector2);
		auto m00 = vector2.x;
		auto m01 = vector2.y;
		auto m02 = vector2.z;
		auto m10 = vector3.x;
		auto m11 = vector3.y;
		auto m12 = vector3.z;
		auto m20 = vector.x;
		auto m21 = vector.y;
		auto m22 = vector.z;


		float num8 = (m00 + m11) + m22;
		auto quaternion = Vector4();
		if (num8 > 0.f)
		{
			auto num = (float)sqrtf(num8 + 1.f);
			quaternion.w = num * 0.5f;
			num = 0.5f / num;
			quaternion.x = (m12 - m21) * num;
			quaternion.y = (m20 - m02) * num;
			quaternion.z = (m01 - m10) * num;
			return quaternion;
		}
		if ((m00 >= m11) && (m00 >= m22))
		{
			auto num7 = (float)sqrtf(((1.f + m00) - m11) - m22);
			auto num4 = 0.5f / num7;
			quaternion.x = 0.5f * num7;
			quaternion.y = (m01 + m10) * num4;
			quaternion.z = (m02 + m20) * num4;
			quaternion.w = (m12 - m21) * num4;
			return quaternion;
		}
		if (m11 > m22)
		{
			auto num6 = (float)sqrtf(((1.f + m11) - m00) - m22);
			auto num3 = 0.5f / num6;
			quaternion.x = (m10 + m01) * num3;
			quaternion.y = 0.5f * num6;
			quaternion.z = (m21 + m12) * num3;
			quaternion.w = (m20 - m02) * num3;
			return quaternion;
		}
		auto num5 = (float)sqrtf(((1.f + m22) - m00) - m11);
		auto num2 = 0.5f / num5;
		quaternion.x = (m20 + m02) * num2;
		quaternion.y = (m21 + m12) * num2;
		quaternion.z = 0.5f * num5;
		quaternion.w = (m01 - m10) * num2;
		return quaternion;
	}
};
class Quaternion {
public:
	float x, y, z, w;

	Quaternion() {
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Quaternion(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Quaternion operator*(Quaternion rhs) {
		return Quaternion(
			this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y,
			this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z,
			this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x,
			this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z
		);
	}

	float Dot(Quaternion b) {
		return x * x + y * y + z * z + w * w;
	}

	Vector3 operator*(Vector3 point) {
		float num = this->x * 2.f;
		float num2 = this->y * 2.f;
		float num3 = this->z * 2.f;
		float num4 = this->x * num;
		float num5 = this->y * num2;
		float num6 = this->z * num3;
		float num7 = this->x * num2;
		float num8 = this->x * num3;
		float num9 = this->y * num3;
		float num10 = this->w * num;
		float num11 = this->w * num2;
		float num12 = this->w * num3;
		Vector3 result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}
};
class Color {
public:
	float r;
	float g;
	float b;
	float a;
	Color()
	{
		r = 255;
		g = 255;
		b = 255;
		a = 255;
	}
	Color(float rr, float gg, float bb, float aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}
	bool operator==(const Color& xz) const {
		return r == xz.r && g == xz.g && b == xz.b && a == xz.a;
	}
	bool operator/(const Color& xz) const {
		return r / xz.r && g / xz.g && b / xz.b && a / xz.a;
	}
	Color ToUnity()
	{
		return { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f };
	}
};
class Rect {
public:
	float x;
	float y;
	float wid;
	float hei;
	Rect(float x, float y, float x_rightsize, float y_downsize) {
		this->x = x;
		this->y = y;
		wid = x_rightsize;
		hei = y_downsize;
	}
	Rect() {
		this->x = 0;
		this->y = 0;
		wid = 0;
		hei = 0;
	}
	bool Contains(Vector2 point)
	{
		return point.x >= x && point.x < (x + wid) && point.y >= y && point.y < (y + hei);
	}
};
template<typename T>
class List {
public:
	T get(uint32_t idx)
	{
		const auto internal_list = rc<uintptr_t>(this + 0x20);
		return *rc<T*>(internal_list + idx * sizeof(T));
	}

	T get_value(uint32_t idx)
	{
		const auto list = *rc<uintptr_t*>((uintptr_t)this + 0x10);
		const auto internal_list = list + 0x20;
		return *rc<T*>(internal_list + idx * sizeof(T));
	}

	T operator[](uint32_t idx) { return get(idx); }

	const uint32_t get_size() { return *rc<uint32_t*>((uintptr_t)this + 0x18); }

	template<typename F>
	void for_each(const F callback)
	{
		for (auto i = 0; i < get_size(); i++) {
			auto object = this->get(i);
			if (!object)
				continue;
			callback(object, i);
		}
	}

	void add(int idx, T value) {
		if (!this) return;
		*rc<T*>(this + (0x20 + (idx * 0x8))) = value;
	}
	uintptr_t GetBuffer() {
		return *reinterpret_cast<uintptr_t*>(this + 0x10);
	}

	T GetArray(int index) {
		return *reinterpret_cast<T*>(this->GetBuffer() + (0x20 + ((uintptr_t)index * 0x8)));
	}

	__int64 clear()
	{
		static auto Clear = rc<__int64(*)(__int64, __int64, __int64, __int64)>(0);

		if (!Clear)
			Clear = rc<__int64(*)(__int64, __int64, __int64, __int64)>(il2cpp::methods::FindPattern(_("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 41 8B F0 8B"), _("GameAssembly.dll")));
		__int64 v1; // r8
		__int64 result; // rax

		v1 = *(unsigned int*)(this + 24);
		++*(DWORD64*)(this + 28);
		*(DWORD64*)(this + 24) = 0;
		if ((int)v1 > 0)
			return Clear(*(__int64*)(this + 16), 0, v1, 0);

		return result;
	}
};


struct Matrix4x4Line
{
	float m00; float m10; float m20; float m30;
	float m01; float m11; float m21; float m31;
	float m02; float m12; float m22; float m32;
	float m03; float m13; float m23; float m33;

	Matrix4x4Line Identity() {
		this->m00 = 1.f;
		this->m11 = 1.f;
		this->m22 = 1.f;
		this->m33 = 1.f;
		return *this;
	}
};
struct Matrix4x4 {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		}; float m[4][4];
	};
	Matrix4x4 Identity() {
		this->_11 = 1.f;
		this->_21 = 1.f;
		this->_31 = 1.f;
		this->_41 = 1.f;
		return *this;
	}
	Vector3 MultiplyPoint3x4(Vector3 point)
	{
		Vector3 result;
		result.x = m[0][0] * point.x + m[0][1] * point.y + m[0][2] * point.z + m[0][3];
		result.y = m[1][0] * point.x + m[1][1] * point.y + m[1][2] * point.z + m[1][3];
		result.z = m[2][0] * point.x + m[2][1] * point.y + m[2][2] * point.z + m[2][3];
		return result;
	}
};
struct Ray {
public:
	Vector3 m_Origin;
	Vector3 m_Direction;

	Ray() {
		this->m_Origin = Vector3(0, 0, 0);
		this->m_Direction = Vector3(0, 0, 0);
	}

	Ray(Vector3 origin, Vector3 direction) {
		this->m_Origin = origin;
		this->m_Direction = direction;
	}

	Vector3 ClosestPoint(Vector3 pos) {
		return this->m_Origin + this->m_Direction * (pos - this->m_Origin).dot_product(this->m_Direction);
	}
};
struct RaycastHit
{
	Vector3 m_Point;
	Vector3 m_Normal;
	uintptr_t m_FaceID;
	float m_Distance;
	Vector2 m_UV;
	int m_Collider;
};
#include "math.hpp"


struct OBB
{
	Vector4 rotation;
	Vector3 position;
	Vector3 extents;
	Vector3 forward;
	Vector3 right;
	Vector3 up;
};


bool isvalid(uintptr_t _this) { if (!_this || (uintptr_t)_this < 0xFFFFFFFF || (uintptr_t)_this > 0xF000000000000000) return false; return true; }
class BasePlayer; class Transform; class HitTest; class Item; class PlayerWalkMovement; class ModelState; class BaseProjectile; class BaseNetworkable; class GameObject; class String;
class Attack; class AttackEntity; class BaseEntity; class Projectile; class DamageProperties; class Collider; class TOD_Sky; class InputState; class ItemDefinition;
class Type; class ItemContainer; class PlayerInventory; class Stream; class ItemId; class Component; class Shader;
BasePlayer* target_player = nullptr; BasePlayer* big_target_player = nullptr; BasePlayer* target_heli = nullptr; BasePlayer* local_player = nullptr;
uintptr_t cheat_bundle;
uintptr_t fire_a;
uintptr_t ghkghjggh;/*uintptr_t cheat_bundle_2;*/
uintptr_t cheat_bundle222; /*uintptr_t cheat_bundle_2;*/
//uintptr_t pizda; /*uintptr_t cheat_bundle_2;*/
uintptr_t ghost_effect_bundle; // Bundle 
uintptr_t ghost_effect_bundle1; // Второй bundle 
uintptr_t offlinetray_bundle; // Bundle
BoneList target_bone = head;
#include "settings.hpp"
namespace u_sdk {
	static auto IgnoreLayerCollision = rc<void(*)(Layer, Layer, bool)>(il2cpp::methods::resolve_icall(_("UnityEngine.Physics::IgnoreLayerCollision()")));
	static auto set_radius = rc<void(*)(uintptr_t, float)>(il2cpp::methods::resolve_icall(_("UnityEngine.CapsuleCollider::set_radius()")));
	void init_sdk() {
		IgnoreLayerCollision = rc<void(*)(Layer, Layer, bool)>(il2cpp::methods::resolve_icall(_("UnityEngine.Physics::IgnoreLayerCollision()")));
		set_radius = rc<void(*)(uintptr_t, float)>(il2cpp::methods::resolve_icall(_("UnityEngine.CapsuleCollider::set_radius()")));
		values::init_values();
	}
}
class BuildingGrade {
public:
	enum class Enum {
		None = -1,
		Twigs,
		Wood,
		Stone,
		Metal,
		TopTier,
		Count
	};
};

struct TraceInfo {

	bool valid; // 0x0
	float distance; // 0x4
	BaseEntity* entity; // 0x8   //BasePlayer
	Vector3 point; // 0x10
	Vector3 normal; // 0x1C
	DWORD64/*Transform*/ bone; // 0x28
	DWORD64 material; // 0x30
	unsigned int partID; // 0x38
	DWORD64 collider; // 0x40
};
class Renderer_;
#include "co_dump_value.h"

class String
{
public:
	char zpad[0x10]{ };
	int size{ };
	wchar_t buffer[128 + 1];
public:
	String()
	{
		size = min(u_crt::wcslen(_(L"test")), 128);
		for (int idx = 0; idx < size; idx++)
		{
			buffer[idx] = _(L"test")[idx];
		}
		buffer[size] = 0;
	}

	String(const wchar_t* st)
	{
		size = min(u_crt::wcslen((wchar_t*)st), 128);
		for (int idx = 0; idx < size; idx++)
		{
			buffer[idx] = st[idx];
		}
		buffer[size] = 0;
	}

	wchar_t* GetWchar()
	{
		return buffer;
	}

	bool Contains(String* value) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::String_::Contains(this, value); }
};
class Transform {
public:
	Vector3 position() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::Transform::position((uintptr_t)this); }
	void position(Vector3 pos) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Transform::set_position((uintptr_t)this, pos); }

	Vector3 localPosition() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::Transform::get_localPosition((uintptr_t)this); }
	void localPosition(Vector3 pos) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Transform::set_localPosition((uintptr_t)this, pos); }

	Matrix4x4 get_localToWorldMatrix() { if (!isvalid((uintptr_t)this)) return Matrix4x4(); return auto_co_ofsets::Transform::get_localToWorldMatrix((uintptr_t)this); }
	Vector3 get_up() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::Transform::get_up((uintptr_t)this); }
	void rotation(Vector4 rotation) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Transform::set_rotation((uintptr_t)this, rotation); }
	Vector4 rotation() { if (!isvalid((uintptr_t)this)) return Vector4(); return auto_co_ofsets::Transform::get_rotation((uintptr_t)this); }
	void scale(Vector3 value) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Transform::set_localScale((uintptr_t)this, value); }
	Vector3 InverseTransformPoint(Vector3 value) { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::Transform::InverseTransformPoint((uintptr_t)this, value); }
	Vector3 InverseTransformDirection(Vector3 value) { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::Transform::InverseTransformDirection((uintptr_t)this, value); }
};
class DamageTypeList {
public:
	void Scale(DamageType attack, bool serverSide) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::DamageTypeList::Scale((uintptr_t)this, attack, serverSide); }
	float Total() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::DamageTypeList::Total((uintptr_t)this); }

};
class PlayerInventory {
public:
	bool HasAmmo(AmmoTypes ammoType) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::PlayerInventory::HasAmmo((uintptr_t)this, ammoType); }


};
class HitInfo {
public:
	void LoadFromAttack(Attack* attack, bool serverSide) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::HitInfo::LoadFromAttack((uintptr_t)this, (uintptr_t)attack, serverSide); }
	Vector3 PositionOnRay(Vector3 position) { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::HitInfo::PositionOnRay((uintptr_t)this, position); }

	void HitMaterial(uint64_t value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<uint64_t>((DWORD64)this + values::HitInfo::HitMaterial, value); }
	void Initiator(BaseEntity* Initiator) { if (!isvalid((uintptr_t)this)) return; u_mem::write<BaseEntity*>((uintptr_t)this + values::HitInfo::Initiator, Initiator); }
	void ProjectileID(int ProjectileID) { if (!isvalid((uintptr_t)this)) return; u_mem::write<int>((uintptr_t)this + values::HitInfo::ProjectileID, ProjectileID); }
	void ProjectileVelocity(Vector3 ProjectileVelocity) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::HitInfo::ProjectileVelocity, ProjectileVelocity); }
	void ProjectilePrefab(Projectile* ProjectilePrefab) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Projectile*>((uintptr_t)this + values::HitInfo::ProjectilePrefab, ProjectilePrefab); }
	void IsPredicting(bool IsPredicting) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::HitInfo::IsPredicting, IsPredicting); }
	void WeaponPrefab(AttackEntity* WeaponPrefab) { if (!isvalid((uintptr_t)this)) return; u_mem::write<AttackEntity*>((uintptr_t)this + values::HitInfo::WeaponPrefab, WeaponPrefab); }
	void Weapon(AttackEntity* Weapon) { if (!isvalid((uintptr_t)this)) return; u_mem::write<AttackEntity*>((uintptr_t)this + values::HitInfo::Weapon, Weapon); }
	void DoDecals(bool DoDecals) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::HitInfo::DoDecals, DoDecals); }
	DamageTypeList* damageTypes() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<DamageTypeList*>((uintptr_t)this + values::HitInfo::damageTypes); }
	float ProjectileDistance() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::HitInfo::ProjectileDistance); }
	void ProjectileDistance(float ProjectileDistance) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::HitInfo::ProjectileDistance, ProjectileDistance); }
	Vector3 HitPositionWorld() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::HitInfo::HitPositionWorld); }
	Vector3 PointStart() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::HitInfo::PointStart); }

	static HitInfo* New() { return (HitInfo*)il2cpp::methods::object_new(il2cpp::init_class(_("HitInfo"), _(""))); }
};
class InputMessage {
public:
	void aimAngles(Vector3 value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::InputMessage::aimAngles, value); }
	Vector3 aimAngles() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::InputMessage::aimAngles); }
};
class Material {
public:
	//auto_co_ofsets::Material::get_name
	String* get_name() { if (!isvalid((uintptr_t)this)) return nullptr; return (String*)auto_co_ofsets::Material::get_name((uintptr_t)this); }
	Shader* GetShader() { if (!isvalid((uintptr_t)this)) return nullptr; return (Shader*)auto_co_ofsets::Material::getshader((uintptr_t)this); }
	void set_shader(Shader* gogogo) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Material::set_shader((uintptr_t)this, (uintptr_t)gogogo); }
	void SetInt(String* name, int value) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Material::SetInt((uintptr_t)this, name, value); }
	void set_renderQueue(int value) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Material::set_renderQueue((uintptr_t)this, value); }
};
class Renderer_ {
public:
	Material* material() { if (!isvalid((uintptr_t)this)) return 0; return (Material*)auto_co_ofsets::Renderer::get_material((uintptr_t)this); }
	void set_material(Material* value) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Renderer::set_material((uintptr_t)this, (uintptr_t)value); }
};
Vector3 estimatedVelocity;
Material* chams1;
Material* chams2;
Material* chams3;
Material* chams4;
Shader* chams5_shader;
Shader* chams5_shader12;
Material* chams5_material;
Material* chams5_material12;
Material* chams6;
Material* chams7;
Material* chams8;
Material* chams9;
Material* chams10;
Material* chams11;
Material* chams12;
Material* chams13;
Material* chams14;
Material* chams15;

Material* chams16;
Material* player_chams_material;
Shader* player_chams_shader;
Material* player_chams_shader_flat12 = nullptr;
//Shader* player_chams_shader_flat12; // Второй шейдер для плоских чамсов
Shader* player_chams_shader_flat; // Второй шейдер для плоских чамсов
class InputState {
public:
	InputMessage* current() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<InputMessage*>((uintptr_t)this + values::InputState::current); }
	bool WasJustPressed(BUTTON btn) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::InputState::WasJustPressed((uintptr_t)this, btn); }

};
class HitTest {
public:
	Vector3 HitPointWorld() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::HitTest::HitPointWorld((uintptr_t)this); }
	Vector3 HitNormalWorld() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::HitTest::HitNormalWorld((uintptr_t)this); }
	Vector3 HitPoint() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Hittest::HitPoint); }
	Vector3 HitNormal() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Hittest::HitNormal); }
	BaseEntity* HitEntity() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<BaseEntity*>((uintptr_t)this + values::Hittest::HitEntity); }

	Transform* HitTransform() { if (!isvalid((uintptr_t)this)) return nullptr; return u_mem::read<Transform*>((uintptr_t)this + values::Hittest::HitTransform); }
	int HitPart() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<int>((uintptr_t)this + values::Hittest::HitPart); }
	void HitPart(unsigned int value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<unsigned int>((uintptr_t)this + values::Hittest::HitPart, value); }
	void collider(DWORD64 collider) { if (!isvalid((uintptr_t)this)) return; u_mem::write<DWORD64>((uintptr_t)this + values::Hittest::collider, collider); }
	void HitDistance(float HitDistance) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((DWORD64)this + values::Hittest::HitDistance, HitDistance); }
	void BestHit(bool BestHit) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((DWORD64)this + values::Hittest::BestHit, BestHit); }
	void type(int type) { if (!isvalid((uintptr_t)this)) return; u_mem::write<int>((DWORD64)this + values::Hittest::type, type); }
	void Radius(float Radius) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((DWORD64)this + values::Hittest::Radius, Radius); }
	void Forgiveness(float Forgiveness) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((DWORD64)this + values::Hittest::Forgiveness, Forgiveness); }
	void ignoreEntity(BaseEntity* ignoreEntity) { if (!isvalid((uintptr_t)this)) return; u_mem::write<BaseEntity*>((DWORD64)this + values::Hittest::ignoreEntity, ignoreEntity); }
	void HitTest_HitMaterial(String* material) { if (!isvalid((uintptr_t)this)) return; u_mem::write<String*>((DWORD64)this + values::Hittest::HitMaterial, material); }
	void HitMaterial(const char* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<const char*>((uintptr_t)this + values::Hittest::HitMaterial, value); }
	void DidHit(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::Hittest::DidHit, value); }
	void MaxDistance(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Hittest::MaxDistance, value); }
	void HitEntity(BaseNetworkable* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<BaseNetworkable*>((uintptr_t)this + values::Hittest::HitEntity, value); }
	void HitTransform(Transform* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Transform*>((uintptr_t)this + values::Hittest::HitTransform, value); }
	void HitPoint(Vector3 value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Hittest::HitPoint, value); }
	void HitNormal(Vector3 value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Hittest::HitNormal, value); }
	void AttackRay(Ray value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Ray>((uintptr_t)this + values::Hittest::AttackRay, value); }
	void gameObject(GameObject* gameObject) { if (!isvalid((uintptr_t)this)) return; u_mem::write<GameObject*>((uintptr_t)this + values::Hittest::gameObject, gameObject); }
	void damageProperties(DamageProperties* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<DamageProperties*>((uintptr_t)this + values::Hittest::damageProperties, value); }
	Attack* BuildAttackMessage(BasePlayer* attackingEntity) { if (!isvalid((uintptr_t)this)) return 0; return (Attack*)auto_co_ofsets::HitTest::BuildAttackMessage((uintptr_t)this, (uintptr_t)attackingEntity); }
	static HitTest* New() { return (HitTest*)il2cpp::methods::object_new(il2cpp::init_class(_("HitTest"), _(""))); }
};
class GamePhysics {
public:
	static bool LineOfSightRadius(Vector3 p0, Vector3 p1, int layerMask, float padding, BaseEntity* ignoreEntity) { return auto_co_ofsets::GamePhysics::LineOfSightRadius(p0, p1, layerMask, padding, (uintptr_t)ignoreEntity); }
	static bool Trace(Ray ray, float radius, RaycastHit hitInfo, float maxDistance, int layerMask, QueryTriggerInteraction triggerInteraction, BaseEntity* ignoreEntity) { return auto_co_ofsets::GamePhysics::Trace(ray, radius, hitInfo, maxDistance, layerMask, triggerInteraction, (uintptr_t)ignoreEntity); }
};


class Physics {
public:
	static bool Raycast(Ray ray, RaycastHit hitInfo, float maxDistance, int layerMask, QueryTriggerInteraction queryTriggerInteraction) { return auto_co_ofsets::Physics::Raycast(ray, hitInfo, maxDistance, layerMask, queryTriggerInteraction); }
	static bool Raycast2(Vector3 origin, Vector3 direction, float maxDistance, int layerMask, QueryTriggerInteraction queryTriggerInteraction) { return auto_co_ofsets::Physics::Raycast2(origin, direction, maxDistance, layerMask, queryTriggerInteraction); }
	static bool CheckCapsule(Vector3 start, Vector3 end, float radius, int layerMask, QueryTriggerInteraction queryTriggerInteraction) { return auto_co_ofsets::Physics::CheckCapsule(start, end, radius, layerMask, queryTriggerInteraction); }
	static Vector3 gravity() { return auto_co_ofsets::Physics::gravity(); }
};
class AimConeUtil {
public:
	static Vector3 GetModifiedAimConeDirection(float aimCone, Vector3 inputVec, bool anywhereInside = true) { return auto_co_ofsets::AimConeUtil::GetModifiedAimConeDirection(aimCone, inputVec, anywhereInside); }
};
class Time {
public:
	static float time() { return auto_co_ofsets::Time::time(); }
	static float deltaTime() { return auto_co_ofsets::Time::deltaTime(); }
	static float fixedTime() { return auto_co_ofsets::Time::fixedTime(); }
	static float unscaledTime() { return auto_co_ofsets::Time::unscaledTime(); }
	static float unscaledDeltaTime() { return auto_co_ofsets::Time::unscaledDeltaTime(); }
	static float fixedDeltaTime() { return auto_co_ofsets::Time::fixedDeltaTime(); }
	static float maximumDeltaTime() { return auto_co_ofsets::Time::maximumDeltaTime(); }
	static float smoothDeltaTime() { return auto_co_ofsets::Time::smoothDeltaTime(); }
	static float timeScale() { return auto_co_ofsets::Time::timeScale(); }
	static float frameCount() { return auto_co_ofsets::Time::frameCount(); }
	static float renderedFrameCount() { return auto_co_ofsets::Time::renderedFrameCount(); }
	static float realtimeSinceStartup() { return auto_co_ofsets::Time::realtimeSinceStartup(); }
};
class Mathf {
public:
	static float Abs(float x) { return auto_co_ofsets::Mathf::Abs(x); }
	static float Sin(float f) { return auto_co_ofsets::Mathf::Sin(f); }
	static float Cos(float f) { return auto_co_ofsets::Mathf::Cos(f); }
	static float Tan(float f) { return auto_co_ofsets::Mathf::Tan(f); }
	static float Sqrt(float f) { return auto_co_ofsets::Mathf::Sqrt(f); }
	static float Clamp(float value, float min, float max) { return auto_co_ofsets::Mathf::Clamp(value, min, max); }
	static float Lerp(float a, float b, float t) { return auto_co_ofsets::Mathf::Lerp(a, b, t); }
	static float Atan2(float y, float x) { return auto_co_ofsets::Mathf::Atan2(y, x); }

	static float NormalizeAngle(float angle) {
		while (angle > 360.0f) {
			angle -= 360.0f;
		}
		while (angle < 0.0f) {
			angle += 360.0f;
		}
		return angle;
	}
	static Vector3 NormalizeAngles(Vector3 angles) {
		angles.x = NormalizeAngle(angles.x);
		angles.y = NormalizeAngle(angles.y);
		angles.z = NormalizeAngle(angles.z);
		return angles;
	}
	static Vector3 EulerAngles(Quaternion q1) {
		float num = q1.w * q1.w;
		float num2 = q1.x * q1.x;
		float num3 = q1.y * q1.y;
		float num4 = q1.z * q1.z;
		float num5 = num2 + num3 + num4 + num;
		float num6 = q1.x * q1.w - q1.y * q1.z;
		Vector3 vector;
		if (num6 > 0.4995f * num5) {
			vector.y = 2.0f * Atan2(q1.y, q1.x);
			vector.x = 1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		if (num6 < -0.4995f * num5) {
			vector.y = -2.0f * Atan2(q1.y, q1.x);
			vector.x = -1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		Quaternion quaternion = Quaternion(q1.w, q1.z, q1.x, q1.y);
		vector.y = Atan2(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
		vector.x = Sin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
		vector.z = Atan2(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
		return NormalizeAngles(vector * 57.2958f);
	}
};
class Mathx {
public:
	static float Max(float f1, float f2, float f3) { return auto_co_ofsets::Mathx::Max(f1, f2, f3); }
	static float Increment(float f) { return auto_co_ofsets::Mathx::Increment(f); }
	static float Decrement(float f) { return auto_co_ofsets::Mathx::Decrement(f); }
};
class BuildingBlock {
public:
	BuildingGrade::Enum grade() {
		if (!isvalid((uintptr_t)this)) return BuildingGrade::Enum();
		return *rc<BuildingGrade::Enum*>((uintptr_t)this + values::BuildingBlock::grade);
	}
	bool IsUpgradeBlocked() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BuildingBlock::IsUpgradeBlocked((uintptr_t)this); }
	bool CanAffordUpgrade(BuildingGrade::Enum g, int skin, BasePlayer* p) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BuildingBlock::CanAffordUpgrade((uintptr_t)this, g, skin, (uintptr_t)p); }
	bool CanChangeToGrade(BuildingGrade::Enum g, int skin, BasePlayer* p) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BuildingBlock::CanChangeToGrade((uintptr_t)this, g, skin, (uintptr_t)p); }
	bool UpgradeToGrade(BuildingGrade::Enum g, int skin, BasePlayer* p) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BuildingBlock::UpgradeToGrade((uintptr_t)this, g, skin, (uintptr_t)p); }
};
class PlayerProjectileUpdate {
public:
	int projectileID() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<int>((uintptr_t)this + 0x10); }
	void projectileID(int value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<int>((uintptr_t)this + 0x10, value); }
	Vector3 curPosition() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + 0x14); }
	void curPosition(Vector3 value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + 0x14, value); }
	void curVelocity(Vector3 value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + 0x20, value); }
	void travelTime(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + 0x2C, value); }

	static PlayerProjectileUpdate* New() { return (PlayerProjectileUpdate*)il2cpp::methods::object_new(il2cpp::init_class(_("PlayerProjectileUpdate"), _("ProtoBuf"))); }
};

class TerrainHeightMap {
public:
	Vector3 GetNormal(Vector3 worldPos)
	{
		if (!this || worldPos == Vector3::Zero()) return Vector3::Zero();
		return auto_co_ofsets::TerrainHeightMap::GetNormal((uintptr_t)this, worldPos);
	}
	float GetHeight(Vector3 idk)
	{
		if (!this || idk == Vector3::Zero()) return 0.0f;
		return auto_co_ofsets::TerrainHeightMap::GetHeight((uintptr_t)this, idk);
	}
};
class Terrain {
public:
	float SampleHeight(Vector3 schingschongmydickislong)
	{
		if (!this || schingschongmydickislong == Vector3::Zero()) return 0.0f;
		return auto_co_ofsets::Terrain::SampleHeight((uintptr_t)this, schingschongmydickislong);
	}
};

class TerrainCollision {
public:
	bool GetIgnore(Vector3 yourmomsahoe, float flot)
	{
		if (!this || yourmomsahoe == Vector3::Zero() || !flot) return false;
		return auto_co_ofsets::TerrainCollision::GetIgnore((uintptr_t)this, yourmomsahoe, flot);
	}
};
class TerrainMeta {
public:
	static TerrainMeta* New()
	{
		static DWORD64 klazz = 0;
		if (!klazz) klazz = il2cpp::init_class(_("TerrainMeta"), _(""));
		DWORD64 static_fields = u_mem::read<DWORD64>(klazz + 0xB8);
		return *rc<TerrainMeta**>(static_fields + 0x8);
	}
	Vector3 Position() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::TerrainMeta::get_Position((DWORD64)this); }
	TerrainHeightMap* HeightMap() { if (!isvalid((uintptr_t)this)) return nullptr; return (TerrainHeightMap*)auto_co_ofsets::TerrainMeta::get_HeightMap((DWORD64)this); }
	Terrain* terrain() { if (!isvalid((uintptr_t)this)) return nullptr; return (Terrain*)auto_co_ofsets::TerrainMeta::get_Terrain((DWORD64)this); }
	TerrainCollision* Collision() { if (!isvalid((uintptr_t)this)) return nullptr; return (TerrainCollision*)auto_co_ofsets::TerrainMeta::get_Collision((DWORD64)this); }
};
class BaseMovement {
public:
	Vector3 TargetMovement() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::BaseMovement::get_TargetMovement((uintptr_t)this); }
	void TargetMovement(Vector3 value) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseMovement::set_TargetMovement((uintptr_t)this, value); }
	void TeleportTo(Vector3 position, BasePlayer* player) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseMovement::TeleportTo((uintptr_t)this, position, (uintptr_t)player); }
};
class PlayerAttack {
public:
	Attack* attack() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<Attack*>((uintptr_t)this + 0x10); }
	void attack(Attack* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Attack*>((uintptr_t)this + 0x10, value); }
	void projectileID(int value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<int>((uintptr_t)this + 0x18, value); }

	static PlayerAttack* New() { return (PlayerAttack*)il2cpp::methods::object_new(il2cpp::init_class(_("PlayerAttack"), _("ProtoBuf"))); }
};
class BowWeapon {
public:
	static BowWeapon* New() { return (BowWeapon*)il2cpp::methods::object_new(il2cpp::init_class(_("BowWeapon"), _(""))); }
};
class PlayerProjectileAttack {
public:
	PlayerAttack* playerAttack() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<PlayerAttack*>((uintptr_t)this + 0x10); }
	void travelTime(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + 0x28, value); }
	void hitDistance(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + 0x24, value); }
	void hitVelocity(Vector3 value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + 0x18, value); }
	void playerAttack(PlayerAttack* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<PlayerAttack*>((uintptr_t)this + 0x10, value); }
	static PlayerProjectileAttack* New() { return (PlayerProjectileAttack*)il2cpp::methods::object_new(il2cpp::init_class(_("PlayerProjectileAttack"), _("ProtoBuf"))); }
};
class GameTrace {
public:
	static bool TraceAll(uintptr_t test, uintptr_t traces, int layerMask = -5) { return auto_co_ofsets::GameTrace::TraceAll(test, traces, layerMask); }
};
class DDraw {
public:
	static void Text(String* text, Vector3 vPos, Color color, float fDuration = 0.5f, float scaleMulti = 1.f, bool distanceFade = true) { return auto_co_ofsets::DDraw::Text(text, vPos, color, fDuration, scaleMulti, distanceFade); }
	static void Line(Vector3 vPos, Vector3 vPosB, Color color, float fDuration, bool distanceFade, bool ztest) { return auto_co_ofsets::DDraw::Line(vPos, vPosB, color, fDuration, distanceFade, ztest); }
	static void Capsule(Vector3 vPos, Quaternion qua, float fDuration, float ds, Color color, float fs, bool ztest, bool zxc) { return auto_co_ofsets::DDraw::Capsule(vPos, qua, fDuration, ds, color, fs, ztest, zxc); }
	static void Sphere(Vector3 position, float size, Color color, float update, bool ztest, bool zxc) { return auto_co_ofsets::DDraw::Sphere(position, size, color, update, ztest, zxc); }
};
bool LineOfSight(Vector3 a, Vector3 b, bool no_pierce = false) {
	bool result = false;
	int mask = vars::weapon::piercematerials ? 1075904512 | 8388608 | 134217728 : 1075904512 | 8388608 | 1 | 2097152 | 32768 | 65536;
	if (no_pierce) mask = 1075904512 | 8388608 | 1 | 2097152 | 32768 | 65536;
	auto LineOfSight_orig = rc<bool(*)(Vector3, Vector3, int, uintptr_t)>((DWORD64)(g_base + CO::LineOfSight));
	result = LineOfSight_orig(a, b, mask, NULL);
	//if (vars::psilent::test) {
	//if (result)
	//	DDraw::Line(a, b, Color(0, 1, 0, 1), 0.01f, false, true);
	//else
	//	DDraw::Line(a, b, Color(1, 0, 0, 1), 0.01f, false, true);
	//}
	return result;
}
class ItemModProjectile {
public:
	float projectileVelocity() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::ItemModProjectile::projectileVelocity); }
	float GetRandomVelocity() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::ItemModProjectile::GetRandomVelocity((uintptr_t)this); }

	float projectileSpread() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::ItemModProjectile::projectileSpread); }
	void projectileSpread(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ItemModProjectile::projectileSpread, value); }

	float projectileVelocitySpread() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::ItemModProjectile::projectileVelocitySpread); }
	void projectileVelocitySpread(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ItemModProjectile::projectileVelocitySpread, value); }
};
class AssetNameCache {
public:
	static String* GetName(uintptr_t a1) { return auto_co_ofsets::AssetNameCache::GetName(a1); }
};
class Object {
public:
	static void DontDestroyOnLoad(uintptr_t target) { return auto_co_ofsets::Object::DontDestroyOnLoad(target); }
	static Object* FindObjectFromInstanceID(int instanceID) { return (Object*)auto_co_ofsets::Object::FindObjectFromInstanceID(instanceID); }
	static int GetInstanceID(uintptr_t target) { return auto_co_ofsets::Object::GetInstanceID(target); }
};
class Component : public Object {
public:
	static uintptr_t get_component(uintptr_t x1, uintptr_t x2) { return auto_co_ofsets::Component::get_component(x1, x2); }
	GameObject* gameObject() { if (!isvalid((uintptr_t)this)) return nullptr; return (GameObject*)auto_co_ofsets::Component::gameObject((uintptr_t)this); }
	Transform* transform() { if (!isvalid((uintptr_t)this)) return nullptr; return (Transform*)auto_co_ofsets::Component::transform((uintptr_t)this); }
};
class Projectile {
public:
	class ProjectileShoot {
	public:
		Vector3 startPos() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + 0x14); }
		Vector3 startVel() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + 0x20); }
		void startVel(Vector3 startVel) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + 0x20, startVel); }
	};
	Projectile* sourceProjectilePrefab() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<Projectile*>((uintptr_t)this + values::Projectile::sourceProjectilePrefab); }
	bool createDecals() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<Projectile*>((uintptr_t)this + values::Projectile::createDecals); }
	HitTest* hitTest() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<HitTest*>((uintptr_t)this + values::Projectile::hitTest); }
	uintptr_t itemmod() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<uintptr_t>((uintptr_t)this + values::Projectile::mod); }
	ItemModProjectile* mod() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<ItemModProjectile*>((uintptr_t)this + values::Projectile::mod); }
	bool needsLOS() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<bool>((uintptr_t)this + values::Projectile::createDecals); }
	bool invisible() { if (!isvalid((uintptr_t)this)) return false; return u_mem::read<Projectile*>((uintptr_t)this + values::Projectile::invisible); }
	BasePlayer* owner() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<BasePlayer*>((uintptr_t)this + values::Projectile::owner); }
	DamageProperties* damageProperties() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<DamageProperties*>((uintptr_t)this + values::Projectile::damageProperties); }
	AttackEntity* sourceWeaponPrefab() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<AttackEntity*>((uintptr_t)this + values::Projectile::sourceWeaponPrefab); }

	Vector3 sentPosition() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::sentPosition); }
	Vector3 currentPosition() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::currentPosition); }
	Vector3 previousPosition() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::previousPosition); }
	Vector3 currentVelocity() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::currentVelocity); }
	Vector3 swimScale() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::swimScale); }
	Vector3 swimSpeed() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::swimSpeed); }
	Vector3 initialVelocity() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::initialVelocity); }
	Vector3 previousVelocity() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::previousVelocity); }
	Vector3 tumbleAxis() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::Projectile::tumbleAxis); }


	int projectileID() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<int>((uintptr_t)this + values::Projectile::projectileID); }
	int seed() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<int>((uintptr_t)this + values::Projectile::seed); }
	float integrity() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::integrity); }
	float closeFlybyDistance() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::integrity); }
	float tumbleSpeed() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::tumbleSpeed); }
	float maxDistance() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::maxDistance); }
	float traveledTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::traveledTime); }
	float traveledDistance() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::traveledDistance); }
	float drag() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::drag); }
	float gravityModifier() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::gravityModifier); }
	float launchTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::launchTime); }
	float previousTraveledTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::previousTraveledTime); }
	float initialDistance() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::initialDistance); }
	float swimRandom() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::swimRandom); }
	float thickness() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::Projectile::thickness); }


	void projectileID(int projectileID) { if (!isvalid((uintptr_t)this)) return; u_mem::write<int>((uintptr_t)this + values::Projectile::projectileID, projectileID); }
	void sourceWeaponPrefab(Projectile* sourceWeaponPrefab) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Projectile*>((uintptr_t)this + values::Projectile::sourceWeaponPrefab, sourceWeaponPrefab); }
	void owner(BasePlayer* owner) { if (!isvalid((uintptr_t)this)) return; u_mem::write<BasePlayer*>((uintptr_t)this + values::Projectile::owner, owner); }
	void seed(int seed) { if (!isvalid((uintptr_t)this)) return; u_mem::write<int>((uintptr_t)this + values::Projectile::seed, seed); }
	void ricochetChance(float ricochetChance) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::ricochetChance, ricochetChance); }
	void previousTraveledTime(float previousTraveledTime) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::previousTraveledTime, previousTraveledTime); }
	void needsLOS(bool needsLOS) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::createDecals, needsLOS); }
	void invisible(bool invisible) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::Projectile::invisible, invisible); }
	void initialDistance(float initialDistance) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::initialDistance, initialDistance); }
	void launchTime(float launchTime) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::launchTime, launchTime); }
	void integrity(float integrity) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::integrity, integrity); }
	void previousPosition(Vector3 previousPosition) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::previousPosition, previousPosition); }
	void currentPosition(Vector3 currentPosition) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::currentPosition, currentPosition); }
	void sentPosition(Vector3 sentPosition) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::sentPosition, sentPosition); }
	void tumbleAxis(Vector3 tumbleAxis) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::tumbleAxis, tumbleAxis); }
	void currentVelocity(Vector3 currentVelocity) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::currentVelocity, currentVelocity); }
	void initialVelocity(Vector3 initialVelocity) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::initialVelocity, initialVelocity); }
	void previousVelocity(Vector3 previousVelocity) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::previousVelocity, previousVelocity); }
	void swimScale(Vector3 swimScale) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::Projectile::swimScale, swimScale); }
	void traveledTime(float time) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::traveledTime, time); }
	void traveledDistance(float traveledDistance) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::traveledDistance, traveledDistance); }
	void thickness(float thickness) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::Projectile::thickness, thickness); }

	bool isAuthoritative() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::Projectile::get_isAuthoritative((uintptr_t)this); }
	bool isAlive() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::Projectile::get_isAlive((uintptr_t)this); }
	bool DoHit(HitTest* test, Vector3 point, Vector3 normal) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::Projectile::DoHit((uintptr_t)this, (uintptr_t)test, point, normal); }
	void Launch() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Projectile::Launch((uintptr_t)this); }
	void SetEffectScale(float eScale) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Projectile::SetEffectScale((uintptr_t)this, eScale); }
	void UpdateVelocity(float deltaTime) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Projectile::UpdateVelocity((uintptr_t)this, deltaTime); }
	void Retire() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Projectile::Retire((uintptr_t)this); }
	float CalculateEffectScale() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::Projectile::CalculateEffectScale((uintptr_t)this); }
	void DoFlybySound() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Projectile::DoFlybySound((uintptr_t)this); }
	Transform* transform() { if (!isvalid((uintptr_t)this)) return nullptr; return (Transform*)auto_co_ofsets::Projectile::get_transform((uintptr_t)this); }

	void UpdateHitTest(TraceInfo info) {
		HitTest* ht = this->hitTest();

		ht->DidHit(true);
		ht->HitEntity((BaseNetworkable*)info.entity);
		ht->HitDistance(info.distance);


		if (info.material != 0) {
			String* material = (AssetNameCache::GetName(info.material));
			ht->HitTest_HitMaterial(material);
		}
		ht->HitPart(info.partID);
		ht->HitTransform((Transform*)info.bone);
		ht->HitPoint(info.point);
		ht->HitNormal(info.normal);
		ht->collider(info.collider);


		GameObject* go = (info.collider) ? ((Component*)info.collider)->gameObject() : ((Component*)info.bone)->gameObject();
		ht->gameObject(go);
		if (info.bone != 0) {
			auto htt = ht->HitTransform();
			Vector3 hitpoint = htt->InverseTransformPoint(info.point);
			ht->HitPoint(hitpoint);

			Vector3 normalpoint = htt->InverseTransformDirection(info.normal);
			ht->HitNormal(normalpoint);
		}

	}

	bool _DoMovement(float deltaTime) {
		if (this->swimScale() != Vector3::Zero()) {
			this->swimScale(Vector3::Zero());
		}
		Vector3 vector2 = this->currentVelocity() * deltaTime;
		float magnitude = vector2.Magnitude();
		float num2 = 1.f / magnitude;
		Vector3 vector3 = vector2 * num2;
		bool flag = false;
		Vector3 vector4 = this->currentPosition() + vector3 * magnitude;
		float num3 = this->traveledTime() + deltaTime;

		auto ht = this->hitTest();
		if (!ht) return false;

		ht->AttackRay(Ray(this->currentPosition(), vector3));
		ht->MaxDistance(magnitude);
		ht->ignoreEntity((BaseEntity*)this->owner());
		ht->Radius(0.f);
		ht->Forgiveness(this->thickness());

		if (!this->owner()) {
			ht->type(0x2);
		}
		else ht->type(0x1);

		if (this->sourceWeaponPrefab()) {
			ht->BestHit(true);
			ht->damageProperties(this->damageProperties());
		}
	OFFSET:
		typedef DWORD64(__stdcall* Unknown)(DWORD64);

		DWORD64 st = u_mem::read<DWORD64>(g_base + 54534336); //Method$Facepunch.Pool.GetList<TraceInfo>() address
		if (!isvalid((uintptr_t)st)) goto OFFSET;

		Unknown get_list = (Unknown)(g_base + 19069376); //Method$Facepunch.Pool.GetList<TraceInfo>() MethodAddress
		if (!isvalid((uintptr_t)get_list)) goto OFFSET;

		DWORD64 rs = get_list(st);
		if (!isvalid((uintptr_t)rs)) goto OFFSET;

		GameTrace::TraceAll(rc<uintptr_t>(ht), rs, 1269916433);
		int size = u_mem::read<int>(rs + 0x18);
		DWORD64 lst = u_mem::read<DWORD64>(rs + 0x10);

		for (int i = 0; i < size && this->isAlive() && !flag; i++) {
			TraceInfo Trace = u_mem::read<TraceInfo>(lst + 0x20 + (i * sizeof(TraceInfo)));
			if (Trace.valid) {
				this->UpdateHitTest(Trace);

				Vector3 vector5 = ht->HitPointWorld();
				Vector3 normal = ht->HitNormalWorld();

				float magnitude2 = (vector5 - this->currentPosition()).Magnitude();
				float num5 = magnitude2 * num2 * deltaTime;

				this->traveledDistance((this->traveledDistance() + magnitude2));
				this->traveledTime((this->traveledTime() + num5));
				this->currentPosition((vector5));

				if (this->DoHit(ht, vector5, normal))
					flag = true;
			}
		}
		if (this->integrity() > 0.001 && this->maxDistance() > this->traveledDistance())
		{
			if (flag && this->traveledTime() < num3)
			{
				this->_DoMovement(num3 - this->traveledTime());
				return false;
			}

			if (!flag && this->isAlive()) {
				float magnitude3 = (vector4 - this->currentPosition()).Magnitude();
				float num6 = magnitude3 * num2 * deltaTime;
				this->traveledDistance((this->traveledDistance() + magnitude3));
				this->traveledTime((this->traveledTime() + num6));
				this->currentPosition(vector4);
			}
		}
		return false;
	}

	bool _Movement(float deltaTime) {
		if (this->swimScale() != Vector3::Zero()) {
			this->swimScale(Vector3::Zero());
		}
		Vector3 vector2 = this->currentVelocity() * deltaTime;
		float magnitude = vector2.Magnitude();
		float num2 = 1.f / magnitude;
		Vector3 vector3 = vector2 * num2;
		Vector3 vector4 = this->currentPosition() + vector3 * magnitude;
		float num3 = this->traveledTime() + deltaTime;

		if (this->integrity() > 0.001 && this->maxDistance() > this->traveledDistance())
		{
			if (this->isAlive()) {
				float magnitude3 = (vector4 - this->currentPosition()).Magnitude();
				float num6 = magnitude3 * num2 * deltaTime;
				this->traveledDistance((this->traveledDistance() + magnitude3));
				this->traveledTime((this->traveledTime() + num6));
				this->currentPosition(vector4);
			}
		}
		return false;
	}

	void DoVelocityUpdate(float deltaTime) {
		if (!this) return;

		Vector3 tr = (Physics::gravity() * this->gravityModifier() * deltaTime);
		this->currentVelocity((this->currentVelocity() + tr));

		Vector3 dr = (this->currentVelocity() * this->drag() * deltaTime);
		this->currentVelocity((this->currentVelocity() - dr));
	}
};
class Input {
public:
	static Vector2 get_mousePosition() { return auto_co_ofsets::Input::get_mousePosition(); }
	static bool GetKey(KeyCode name) { return auto_co_ofsets::Input::GetKey(name); }
	static bool GetKeyInt(KeyCode name) { return auto_co_ofsets::Input::GetKeyInt(name); }

	static float GetAxis(String axisName) { return auto_co_ofsets::Input::GetAxis(axisName); }
	static bool GetMouseButton(int button) { return auto_co_ofsets::Input::GetMouseButton(button); }
};
class ItemIcon {
public:
	void RunTimedAction() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::ItemIcon::RunTimedAction((uintptr_t)this); }
};
class Rigidbody {
public:
	Vector3 velocity() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::Rigidbody::get_velocity((uintptr_t)this); }
	void velocity(Vector3 value) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::Rigidbody::set_velocity((uintptr_t)this, value); }
};
class PlayerWalkMovement : public BaseMovement {
public:
	float Ducking() {
		return *rc<float*>((DWORD64)this + 0x44);
	}
	Rigidbody* body() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<Rigidbody*>((uintptr_t)this + values::PlayerWalkMovement::body); }
	void ladder(void* ladder_) { if (!isvalid((uintptr_t)this)) return; u_mem::write<void*>((uintptr_t)this + values::PlayerWalkMovement::ladder, ladder_); }
	void landtime(float time) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::PlayerWalkMovement::landTime, time); }
	void jumptime(float time) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::PlayerWalkMovement::jumpTime, time); }
	void groundtime(float time) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::PlayerWalkMovement::groundTime, time); }
	void grounded(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::PlayerWalkMovement::grounded, value); }
	void jumping(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::PlayerWalkMovement::jumping, value); }
	void sliding(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::PlayerWalkMovement::sliding, value); }
	void climbing(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::PlayerWalkMovement::climbing, value); }
	void gravityMultiplier(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::PlayerWalkMovement::gravityMultiplier, value); }
	void flying(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::PlayerWalkMovement::flying, value); }

	void Jump(ModelState* x1, bool x2) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::PlayerWalkMovement::Jump((uintptr_t)this, (uintptr_t)x1, x2); }

	void swimming(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::PlayerWalkMovement::flying, value); }
	void gravityMultiplierSwimming(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::PlayerWalkMovement::flying, value); }
};
class ModelState {
public:
	enum class Flag {
		Ducked = 1,
		Jumped,
		OnGround = 4,
		Sleeping = 8,
		Sprinting = 16,
		OnLadder = 32,
		Flying = 64,
		Aiming = 128,
		Prone = 256,
		Mounted = 512,
		Relaxed = 1024,
		OnPhone = 2048,
		Crawling = 4096,
		Loading = 8192,
		HeadLook = 16384,
		HasParachute = 32768
	};

	void set_flag(ModelState::Flag flag) {
		if (!isvalid((uintptr_t)this)) return;
		auto flags = u_mem::read<uintptr_t>((uintptr_t)this + values::ModelState::flags);
		u_mem::write<int>((uintptr_t)this + values::ModelState::flags, flags |= (int)flag);
	}

	void ducked(bool ducked_) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::ModelState::set_ducked((uintptr_t)this, ducked_); }
	void jumped(bool jumped_) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::ModelState::set_jumped((uintptr_t)this, jumped_); }
};
class SkinnedMultiMesh {
public:
	//List<Vector3>* SpawnLocations() { if (!isvalid((uintptr_t)this)) return nullptr; return auto_co_ofsets::MetalDetectorSource::get_SpawnLocations((uintptr_t)this); }
	List<Renderer_*>* Renderers() { if (!isvalid((uintptr_t)this)) return nullptr; return auto_co_ofsets::SkinnedMultiMesh::get_Renderers((uintptr_t)this); }
};
class PlayerModel {
public:
	static void RebuildAll() { return auto_co_ofsets::PlayerModel::RebuildAll(); }

	SkinnedMultiMesh* _multiMesh() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<SkinnedMultiMesh*>((uintptr_t)this + values::PlayerModel::_multiMesh); }
	Vector3 position() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::PlayerModel::position); }
	bool isNpc() { if (!isvalid((uintptr_t)this)) return false; return u_mem::read<bool>((uintptr_t)this + values::PlayerModel::isNpc); }
};
class BaseNetworkable : public Component {
public:
	String* spn_real() { if (!isvalid((uintptr_t)this)) return nullptr; return auto_co_ofsets::BaseNetworkable::get_ShortPrefabName((uintptr_t)this); }

	String ShortPrefabName() {
		auto spn = this->spn_real();
		return spn->buffer;
	}

	bool HasParent() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BaseNetworkable::HasParent((uintptr_t)this); }
};
class BaseEntity : public BaseNetworkable {
public:

	bool HasFlag(baseent_Flags f) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BaseEntity::HasFlag((uintptr_t)this, f); }
	bool IsOutside() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BaseEntity::IsOutside((uintptr_t)this); }
	bool SendSignalBroadcast(Signal signal, String arg) { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BaseEntity::SendSignalBroadcast((uintptr_t)this, signal, arg); }
	Vector3 CenterPoint() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::BaseEntity::CenterPoint((uintptr_t)this); }
	float MaxVelocity() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::BaseEntity::MaxVelocity((uintptr_t)this); }
	Vector3 GetWorldVelocity() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::BaseEntity::GetWorldVelocity((uintptr_t)this); }
	Vector3 GetParentVelocity() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::BaseEntity::GetParentVelocity((uintptr_t)this); }
	float BoundsPadding() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::BaseEntity::BoundsPadding((uintptr_t)this); }
	float Distance(Vector3 position) { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::BaseEntity::Distance((uintptr_t)this, position); }
	void ServerRPC(String funcName) {
		if (!isvalid((uintptr_t)this)) return;
		return auto_co_ofsets::BaseEntity::ServerRPC((uintptr_t)this, funcName);
	}
	void ServerRPC4(String funcName, Vector3 arg1, Vector3 arg2, bool arg3) {
		if (!isvalid((uintptr_t)this)) return;
		return auto_co_ofsets::BaseEntity::ServerRPC4((uintptr_t)this, funcName, arg1, arg2, arg3);
	}
	char* get_class_name() {
		auto bp = *rc<uintptr_t*>(this);
		if (!isvalid((uintptr_t)this)) return _("");
		return (char*)*rc<uintptr_t*>(bp + 0x10);
	}

};
class HeldEntity : public BaseEntity {
public:
	float GetFovOverride() { if (!isvalid((uintptr_t)this)) return 0.f; return auto_co_ofsets::HeldEntity::GetFovOverride((uintptr_t)this); }
};
class MetalDetectorSource : public BaseEntity {
public:
	List<Vector3>* SpawnLocations() { if (!isvalid((uintptr_t)this)) return nullptr; return auto_co_ofsets::MetalDetectorSource::get_SpawnLocations((uintptr_t)this); }
};
class AttackEntity : public HeldEntity {
public:
	float CalculateCooldownTime(float nextTime, float cooldown, bool catchup) { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::AttackEntity::CalculateCooldownTime((uintptr_t)this, nextTime, cooldown, catchup); }
	void StartAttackCooldown(float cooldown) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::AttackEntity::StartAttackCooldown((uintptr_t)this, cooldown); }
	Vector3 GetInheritedVelocity(BasePlayer* player, Vector3 direction) { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::AttackEntity::GetInheritedVelocity((uintptr_t)this, (uintptr_t)player, direction); }
	bool HasAttackCooldown() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::AttackEntity::HasAttackCooldown((uintptr_t)this); }
	float GetAttackCooldown() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::AttackEntity::GetAttackCooldown((uintptr_t)this); }
	float repeatDelay() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::AttackEntity::repeatDelay); }
	float deployDelay() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::AttackEntity::deployDelay); }
	float timeSinceDeploy() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::AttackEntity::timeSinceDeploy); }
	float nextAttackTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::AttackEntity::nextAttackTime); }
};
class ThrownWeapon : public AttackEntity {
public:
	float maxThrowVelocity() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + 0x288); }
};
class BaseProjectile : public AttackEntity {
public:
	class Magazine {
	public:
		struct Definition
		{
			int builtInSize;
			AmmoTypes ammoTypes;
		};
		Definition definition() { return *rc<Definition*>((uintptr_t)this + 0x10); }
		int capacity() { return *rc<int*>((uintptr_t)this + 0x18); }
		int contents() { return *rc<int*>((uintptr_t)this + 0x1C); }
		ItemDefinition* ammoType() { return *rc<ItemDefinition**>((uintptr_t)this + 0x20); }
		bool CanReload(BasePlayer* owner)
		{
			PlayerInventory* Inventory = u_mem::read<PlayerInventory*>((DWORD64)owner + values::BasePlayer::inventory);
			return this->contents() < this->capacity() && Inventory->HasAmmo(this->definition().ammoTypes);
		}
	};
	//float tumbleVelocity() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + 0x28C); }
	//Vector3 overrideAngle() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + 0x290); }
	//bool HasMoreThanOneAmmoType(AmmoTypes ammoType) { if (!isvalid((uintptr_t)this)) return false; return rc<bool(*)(BaseProjectile*, AmmoTypes)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("HasMoreThanOneAmmoType"), 1, _(""), _(""))))(this, ammoType); }
	float GetProjectileVelocityScale(bool getmax) { if (!isvalid((uintptr_t)this)) return 0.f; return auto_co_ofsets::BaseProjectile::GetProjectileVelocityScale((uintptr_t)this, getmax); }
	bool IsSilenced() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BaseProjectile::IsSilenced((uintptr_t)this); }
	void ShotFired() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseProjectile::ShotFired((uintptr_t)this); }
	void UpdateAmmoDisplay() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseProjectile::UpdateAmmoDisplay((uintptr_t)this); }
	void DoAttack() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseProjectile::DoAttack((uintptr_t)this); }
	void LaunchProjectile() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseProjectile::LaunchProjectile((uintptr_t)this); }
	void BeginCycle() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseProjectile::BeginCycle((uintptr_t)this); }
	void DidAttackClientside() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseProjectile::DidAttackClientside((uintptr_t)this); }
	void StartReloadCooldown(float cooldown) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseProjectile::StartReloadCooldown((uintptr_t)this, cooldown); }
	float GetReloadDuration() { if (!isvalid((uintptr_t)this)) return 0.f; return auto_co_ofsets::BaseProjectile::GetReloadDuration((uintptr_t)this); }
	int GetAvailableAmmo() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::BaseProjectile::GetAvailableAmmo((uintptr_t)this); }

	bool fractionalReload() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<bool>((uintptr_t)this + values::BaseProjectile::fractionalReload); }
	float nextReloadTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BaseProjectile::nextReloadTime); }
	float startReloadTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BaseProjectile::startReloadTime); }
	float reloadStartDuration() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BaseProjectile::reloadStartDuration); }
	float reloadFractionDuration() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BaseProjectile::reloadFractionDuration); }
	float lastShotTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BaseProjectile::lastShotTime); }
	DamageProperties* damageProperties() {
		return u_mem::read<DamageProperties*>((uintptr_t)this + 0x68);
	}
	float reloadTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BaseProjectile::reloadTime); }

	bool HasReloadCooldown() {
		return Time::time() < this->nextReloadTime();
	}
	bool StopAttack()
	{
		return Time::time() < this->nextAttackTime();
	}
	List<Projectile*>* createdProjectiles() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<List<Projectile*>*>((uintptr_t)this + values::BaseProjectile::createdProjectiles); }
	uint32_t size() { return *rc<uint32_t*>((uintptr_t)this + 0x18); }
	Magazine* primaryMagazine() { return *rc<Magazine**>((uintptr_t)this + values::BaseProjectile::primaryMagazine); }
	void startshot(bool cooldown) {
		if (!isvalid((uintptr_t)this)) return;
		{
			const auto mag = this->primaryMagazine();
			if (!mag) return;
			auto ammo = mag->contents();
			*rc<int*>(mag + 0x1C) = (ammo - 1);
		}
		this->SendSignalBroadcast(Signal::Attack, _(L""));
		this->LaunchProjectile();
	
		this->UpdateAmmoDisplay();
		this->ShotFired();
		this->DidAttackClientside();
		if (cooldown)
			this->BeginCycle();
		return;
	}
	char* get_class_name() {
		if (!isvalid((uintptr_t)this)) return _("");
		auto bp = *rc<uintptr_t*>(this);
		if (!isvalid((uintptr_t)this)) return _("");
		return (char*)*rc<uintptr_t*>(bp + 0x10);
	}
};
class GUIContent {
public:
	static uintptr_t Temp(String* t) { return auto_co_ofsets::GUIContent::Temp(t); }
};
class GL {
public:
	static void PushMatrix() { return auto_co_ofsets::GL::PushMatrix(); }
	static void MultMatrix(Matrix4x4Line m) { return auto_co_ofsets::GL::MultMatrix(m); }
	static void PopMatrix() { return auto_co_ofsets::GL::PopMatrix(); }

	static void Begin(int mode) { return auto_co_ofsets::GL::Begin(mode); }
	static void Color(Color color) { return auto_co_ofsets::GL::Color_(color); }
	static void Vertex(Vector3 v) { return auto_co_ofsets::GL::Vertex(v); }
	static void End() { return auto_co_ofsets::GL::End(); }
};
class GUIStyle {
public:
	static void fontsize(uintptr_t target, int size) { return auto_co_ofsets::GUIStyle::set_fontsize(target, size); }
	static void alignment(uintptr_t target, int alignment) { return auto_co_ofsets::GUIStyle::set_alignment(target, alignment); }
	static void set_font(uintptr_t target, uintptr_t font) { return auto_co_ofsets::GUIStyle::set_font(target, font); }
};
class GUI {
public:
	static void Label(Rect position, uintptr_t content, uintptr_t style) { return auto_co_ofsets::GUI::Label(position, content, style); }
	static uintptr_t skin() { return auto_co_ofsets::GUI::get_skin(); }
	static void color(Color color) { return auto_co_ofsets::GUI::set_color(color); }
	static void DrawTexture(Rect position, uintptr_t image, uintptr_t scaleMode, bool alphaBlend, float imageAspect, Color color, Vector4 borderWidths, Vector4 borderRadiuses, bool drawSmoothCorners) { return auto_co_ofsets::GUI::DrawTexture(position, image, scaleMode, alphaBlend, imageAspect, color, borderWidths, borderRadiuses, drawSmoothCorners); }
	static void DrawTexture(Rect position, uintptr_t image) { return auto_co_ofsets::GUI::DrawTexture_min(position, image); }
};
class Texture2D {
public:
	static void Internal_Create(uintptr_t mono, int w, int h, int mipCount, int format, int colorSpace, int flags, __int64 nativeTex, String mipmapLimitGroupName) { return auto_co_ofsets::Texture2D::Internal_Create(mono,w,h, mipCount, format, colorSpace, flags, nativeTex, mipmapLimitGroupName); }
	//Texture2D mono, int w, int h, int mipCount, GraphicsFormat format, TextureColorSpace colorSpace, TextureCreationFlags flags, IntPtr nativeTex, string mipmapLimitGroupName
	//uintptr_t mono, int w, int h, int mipCount, int format, int colorSpace, int flags, __int64 nativeTex, int mipmapLimitGroupName
	static void SetPixel(uintptr_t target, int x, int y, Color color) { return auto_co_ofsets::Texture2D::SetPixel(target, x, y, color); }
	static void Apply(uintptr_t target, bool updateMipmaps) { return auto_co_ofsets::Texture2D::Apply(target, updateMipmaps); }
	static Texture2D* whiteTexture() { return (Texture2D*)auto_co_ofsets::Texture2D::get_whiteTexture(); }
	bool isReadable() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::Texture2D::get_isReadable((uintptr_t)this); }
};
class Sprite : public Object {
public:
	static Texture2D* get_texture(DWORD64 zxc) { return (Texture2D*)auto_co_ofsets::Sprite::get_texture(zxc); }

};
class Shader : public Object {
public:
	static Shader* Find(String name) { return (Shader*)auto_co_ofsets::Shader::Find(name); }
	int passCount() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::Shader::get_passCount((uintptr_t)this); }
};
class GameManifest {
public:
	static Object* GUIDToObject(String* guid) { return (Object*)auto_co_ofsets::GameManifest::GUIDToObject(guid); }
};
class GameObject : public Object {
public:
	static void Internal_CreateGameObject(uintptr_t target, String shader) { return auto_co_ofsets::GameObject::Internal_CreateGameObject(target, shader); }
	static void Internal_AddComponentWithType(uintptr_t target, uintptr_t componentType) { return auto_co_ofsets::GameObject::Internal_AddComponentWithType(target, componentType); }

	static inline uintptr_t GetGameObjectComponent(uintptr_t type, uintptr_t pointer) {
		typedef uintptr_t getComp(uintptr_t, uintptr_t);
		return ((getComp*)(g_base + CO::GetGameObjectComponent))(pointer, type);
	}
};
class AssetBundle : public Object {
public:
	void Unload(bool unloadAllLoadedObjects) { if (!isvalid((uintptr_t)this)) return;  return auto_co_ofsets::AssetBundle::Unload((uintptr_t)this, unloadAllLoadedObjects); }
	static AssetBundle* LoadFromFile(String path) { return (AssetBundle*)auto_co_ofsets::AssetBundle::LoadFromFile(path); }
	static uintptr_t LoadAsset_Internal(uintptr_t target, String path, uintptr_t type) { return auto_co_ofsets::AssetBundle::LoadAsset_Internal(target, path, type); }
	template<typename T = Object>
	static T* LoadAsset(uintptr_t target, String path, uintptr_t type) { return (T*)auto_co_ofsets::AssetBundle::LoadAsset(target, path, type); }
};
inline Object* GetClassObject(UINT_PTR pointer) {
	String* guid = *rc<String**>(pointer + 0x10);
	Object* _cachedObject = GameManifest::GUIDToObject(guid);
	return _cachedObject;
}
class Networkable {
public:
	template<typename T = uintptr_t>
	T* GetComponent(uintptr_t type) {
		if (!this || !type) return nullptr;
		return (T*)Component::get_component((uintptr_t)this, type);
	}
	List<uintptr_t>* GetComponentsInChildren(uintptr_t type) {
		if (!this || !type) return nullptr;
		return reinterpret_cast<List<uintptr_t>*>(auto_co_ofsets::Networkable::get_components_in_children((uintptr_t)this, type));
	}
};
class RenderSettings {
public:
	static void ambientMode(AmbientMode value) { return auto_co_ofsets::RenderSettings::set_ambientMode(value); }
	static void ambientIntensity(float value) { return auto_co_ofsets::RenderSettings::set_ambientIntensity(value); }
	static void ambientLight(Color value) { return auto_co_ofsets::RenderSettings::set_ambientLight(value); }
	static void skybox(Material* value) { return auto_co_ofsets::RenderSettings::set_skybox((uintptr_t)value); }

	static void atmosphere_rayleigh(float value) { return auto_co_ofsets::Weather::set_atmosphere_rayleigh(value); }
	static void atmosphere_mie(float value) { return auto_co_ofsets::Weather::set_atmosphere_mie(value); }
	static void atmosphere_brightness(float value) { return auto_co_ofsets::Weather::set_atmosphere_brightness(value); }
	static void cloud_opacity(float value) { return auto_co_ofsets::Weather::set_cloud_opacity(value); }
	static void atmosphere_contrast(float value) { return auto_co_ofsets::Weather::set_atmosphere_contrast(value); }
	static void fog(float value) { return auto_co_ofsets::Weather::set_fog(value); }
	static void rain(float value) { return auto_co_ofsets::Weather::set_rain(value); }
	static void thunder(float value) { return auto_co_ofsets::Weather::set_thunder(value); }
	static void wind(float value) { return auto_co_ofsets::Weather::set_wind(value); }

};
class ItemDefinition : public Component {
public:
	String* GetDisplayName(Item* item) { if (!isvalid((uintptr_t)this)) return NULL; return (String*)auto_co_ofsets::ItemDefinition::GetDisplayName((uintptr_t)this, (uintptr_t)item); }
	ItemCategory category_item() { if (!isvalid((uintptr_t)this)) return ItemCategory(0); return u_mem::read<ItemCategory>((uintptr_t)this + values::ItemDefinition::category); }
};
class Item {
public:
	bool isBroken() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::Item::get_isBroken((uintptr_t)this); }
	DWORD64 get_iconSprite() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::Item::get_iconSprite((uintptr_t)this); }
	const wchar_t* weapon_name() {
		if (!isvalid((uintptr_t)this)) return _(L"Unknown");
		ItemDefinition* item_def = u_mem::read<ItemDefinition*>((DWORD64)this + values::Item::info);
		if (!item_def || !isvalid((uintptr_t)item_def)) return _(L"Unknown");
		auto display_name = item_def->GetDisplayName(this);
		if (!display_name) return _(L"Unknown");
		return ((pUncStr)display_name)->str;
	}

	Item* uid() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<Item*>((DWORD64)this + values::Item::uid); }
	ItemDefinition* info_item() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<ItemDefinition*>((uintptr_t)this + values::Item::info); }
	int GetAmount() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<int>((UINT64)this + values::Item::amount); }
	int32_t item_def_id()
	{
		if (!isvalid((uintptr_t)this)) return NULL;
		const auto item_definition = u_mem::read<uintptr_t>((uintptr_t)this + values::Item::info);
		if (!item_definition) return 0;
		return u_mem::read<int32_t>(item_definition + values::ItemDefinition::itemid);
	}
	template<typename T = void*>
	T* heldEntity() { if (!isvalid((uintptr_t)this)) return nullptr; return u_mem::read<T*>((uintptr_t)this + values::Item::heldEntity); }
	bool IsWeapon() {
		if (!isvalid((uintptr_t)this)) return false;
		const auto item_definition = u_mem::read<DWORD64>((DWORD64)this + values::Item::info);
		if (!item_definition) return false;
		return u_mem::read<uint32_t>(item_definition + 0x40) == 0;
	}
};
bool stopcamera = false;
class Camera {
public:
	static uintptr_t main_camera() { if (stopcamera) return 0; return rc<uintptr_t(*)()>(il2cpp::methods::resolve_icall(_("UnityEngine.Camera::get_main()")))(); }
	static void aspect(float act) { return rc<void(*)(uintptr_t, float)>(il2cpp::methods::resolve_icall(_("UnityEngine.Camera::set_aspect()")))(main_camera(), act); }
	static float get_aspect(uintptr_t camera) { return rc<float(*)(uintptr_t)>(il2cpp::methods::resolve_icall(_("UnityEngine.Camera::get_aspect()")))(camera); }
	static float get_fov(uintptr_t camera) { return rc<float(*)(uintptr_t)>(il2cpp::methods::resolve_icall(_("UnityEngine.Camera::get_fieldOfView()")))(camera); }
};

struct TimeAverageValueData
{
public:
	int Calculate()
	{
		float realtimeSinceStartup = Time::realtimeSinceStartup();
		float num = realtimeSinceStartup - refreshTime;
		if (num >= 1.0)
		{
			counterPrev = (int)(counterNext / num + 0.5);
			counterNext = 0;
			refreshTime = realtimeSinceStartup;
			num = 0;
		}
		return (int)(counterPrev * (1.0 - num)) + counterNext;
	}

	void Increment()
	{
		this->Calculate();
		counterNext += 1;
	}

	void Reset()
	{
		counterPrev = 0;
		counterNext = 0;
	}

	float refreshTime;

	int counterPrev;

	int counterNext;
};
TimeAverageValueData RPC_Counter = { 0, 0, 0 };
class MainCamera {
public:
	Vector3 position() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::MainCamera::get_position((uintptr_t)this); }
	Quaternion rotation() { if (!isvalid((uintptr_t)this)) return Quaternion(); return auto_co_ofsets::MainCamera::get_rotation((uintptr_t)this); }
	Vector3 forward() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::MainCamera::get_forward((uintptr_t)this); }
	static MainCamera* Camera() { return (MainCamera*)il2cpp::methods::object_new(il2cpp::init_class(_("MainCamera"), _(""))); }
};
class PlayerEyes : public Component {
public:
	Vector3 viewOffset() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::PlayerEyes::viewOffset); }
	Vector3 position() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::PlayerEyes::get_position((uintptr_t)this); }
	Vector3 center() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::PlayerEyes::get_center((uintptr_t)this); }
	Vector3 bodyforward() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::PlayerEyes::BodyForward((uintptr_t)this); }
	Quaternion rotation() { if (!isvalid((uintptr_t)this)) return Quaternion(); return auto_co_ofsets::PlayerEyes::get_rotation((uintptr_t)this); }
};
class BaseCombatEntity : public BaseEntity {
public:
	enum class LifeState {
		Alive = 0,
		Dead = 1
	};
};
class ViewmodelLower
{
public:
	void lowerOnSprint(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::ViewmodelLower::lowerOnSprint, value); }
	void lowerWhenCantAttack(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::ViewmodelLower::lowerWhenCantAttack, value); }
	void lowerScale(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ViewmodelLower::lowerScale, value); }
	void shouldLower(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::ViewmodelLower::shouldLower, value); }
};
class ViewmodelBob {
public:
	void bobSpeedWalk(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ViewmodelBob::bobSpeedWalk, value); }
	void leftOffsetRun(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ViewmodelBob::leftOffsetRun, value); }
	void bobSpeedRun(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ViewmodelBob::bobSpeedRun, value); }
	void bobAmountWalk(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ViewmodelBob::bobAmountWalk, value); }
	void bobAmountRun(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::ViewmodelBob::bobAmountRun, value); }
};
class BaseViewModel {
public:
	static BaseViewModel* ActiveModel() {
		return (BaseViewModel*)auto_co_ofsets::BaseViewModel::get_activemodel();
	}
	ViewmodelBob* bob() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<ViewmodelBob*>((uintptr_t)this + values::BaseViewModel::bob); }
	ViewmodelLower* lower() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<ViewmodelLower*>((uintptr_t)this + values::BaseViewModel::lower); }
	
	void disableBob() {
		if (!isvalid((uintptr_t)this)) return;
		auto model = ActiveModel();
		if (!model) return;
		auto bobi = model->bob();
		if (bobi) {
			bobi->bobAmountRun(0.f);
			bobi->bobAmountWalk(0.f);
			bobi->bobSpeedRun(0.f);
			bobi->bobSpeedWalk(0.f);
			bobi->leftOffsetRun(0.f);
		}
	}
	void disableLower() {
		if (!isvalid((uintptr_t)this)) return;
		auto model = ActiveModel();
		if (!model) return;
		auto lowi = model->lower();
		if (lowi) {
			lowi->lowerOnSprint(false);
			lowi->lowerWhenCantAttack(false);
			lowi->lowerScale(0.f);
			lowi->shouldLower(false);
		}
	}
};
class PlayerTick {
public:
	Vector3 position() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return u_mem::read<Vector3>((uintptr_t)this + values::PlayerTick::position); }
	void position(Vector3 pos) { if (!isvalid((uintptr_t)this)) return; u_mem::write<Vector3>((uintptr_t)this + values::PlayerTick::position, pos); }
};
class ProjectileShoot {
public:
	static inline void(*WriteToStream_)(ProjectileShoot*, Stream*) = nullptr;
};
class Screen {
public:
	static int get_width() { return auto_co_ofsets::Screen::get_width(); }
	static int get_height() { return auto_co_ofsets::Screen::get_height(); }
};
class PlayerNameID {
public:
	String GetUsername() {
		auto username = u_mem::read<String*>((DWORD64)this + 0x10);
		return username->buffer;
	}

	unsigned long UserId()
	{
		return u_mem::read<unsigned long>((DWORD64)this + 0x18);
	}
};
enum EnvironmentType
{
	Underground = 1,
	Building = 2,
	Outdoor = 4,
	Elevator = 8,
	PlayerConstruction = 16,
	TrainTunnels = 32,
	UnderwaterLab = 64,
	Submarine = 128,
	BuildingDark = 256,
	BuildingVeryDark = 512
};

class EnvironmentManager {
public:
	static EnvironmentType Get(Vector3 pos, float radius = 0.01)
	{
		return (EnvironmentType)auto_co_ofsets::EnvironmentManager::Get(pos, radius);
	}
};
class LocalPlayer {
public:
	static void UserName(unsigned int itemid, String command) { return auto_co_ofsets::LocalPlayer::ItemCommand(itemid, command); }
};
class RandomUsernames {
public:
	class DataFile {
	public:

	};

	String* Get(int v) { if (!isvalid((uintptr_t)this)) return nullptr; return auto_co_ofsets::RandomUsernames::Get1((uintptr_t)this, v); }
	String* Get(uint64_t v) { if (!isvalid((uintptr_t)this)) return nullptr; return auto_co_ofsets::RandomUsernames::Get2((uintptr_t)this, v); }
};
class SteamPlatform {
public:
	String* UserName() { if (!isvalid((uintptr_t)this)) return nullptr; return auto_co_ofsets::SteamPlatform::get_UserName((uintptr_t)this); }
	void UserName(String* value) { if (!isvalid((uintptr_t)this)) return; auto_co_ofsets::SteamPlatform::set_UserName((uintptr_t)this, value); }

};
class DecayEntity : public BaseCombatEntity {
public:

};
class StorageContainer : public DecayEntity {
public:

};
class StashContainer : public StorageContainer {
public:
	bool IsHidden() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::StashContainer::IsHidden(); }
};
class BaseMelee : public AttackEntity {
public:
	class MaterialFX {
	public:

	};
	bool CanAttack() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BaseMelee::get_CanAttack((uintptr_t)this); }
	bool CanThrow() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BaseMelee::get_CanThrow((uintptr_t)this); }
	void DoAttack() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseMelee::DoAttack((uintptr_t)this); }
	void DoThrow() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseMelee::DoThrow((uintptr_t)this); }
	void ProcessAttack(HitTest* hit) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BaseMelee::ProcessAttack((uintptr_t)this, (uintptr_t)hit); }

	float maxDistance() { if (!isvalid((uintptr_t)this)) return 0.0f; return u_mem::read<float>((uintptr_t)this + values::BaseMelee::maxDistance); }
	void maxDistance(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::BaseMelee::maxDistance, value); }
	float attackRadius() { if (!isvalid((uintptr_t)this)) return 0.0f; return u_mem::read<float>((uintptr_t)this + values::BaseMelee::attackRadius); }
	void attackRadius(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::BaseMelee::attackRadius, value); }
	bool throwReady() { if (!isvalid((uintptr_t)this)) return false; return u_mem::read<bool>((uintptr_t)this + values::BaseMelee::throwReady); }
	void throwReady(bool value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<bool>((uintptr_t)this + values::BaseMelee::throwReady, value); }
	DamageProperties* damageProperties() { if (!isvalid((uintptr_t)this)) return nullptr; return u_mem::read<DamageProperties*>((uintptr_t)this + values::BaseMelee::damageProperties); }
	void damageProperties(DamageProperties* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<DamageProperties*>((uintptr_t)this + values::BaseMelee::damageProperties, value); }

};
class WaterLevel {
public:
	static bool WaterLevelTest(Vector3 pos, bool waves, BasePlayer* volumes) { return auto_co_ofsets::WaterLevel::Test(pos, waves, (uintptr_t)volumes); }
	static float GetWaterDepth(Vector3 pos, bool waves, bool volumes, BaseEntity* forEntity) { return auto_co_ofsets::WaterLevel::GetWaterDepth(pos, waves, volumes, (uintptr_t)forEntity); }

};
class Event {
public:
	static Event* current() { return (Event*)auto_co_ofsets::Event::get_current(); }
	EventType type() { if (!isvalid((uintptr_t)this)) return EventType(); return auto_co_ofsets::Event::get_type((uintptr_t)this); }
	KeyCode keyCode() { if (!isvalid((uintptr_t)this)) return KeyCode(); return auto_co_ofsets::Event::get_keyCode((uintptr_t)this); }
};
struct rust_str
{
	char zpad[128];
};
class BasePlayer : public BaseCombatEntity {
public:
	void ScaleDamage(HitInfo* info) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BasePlayer::ScaleDamage((uintptr_t)this, (uintptr_t)info); }

	bool IsRunning() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::IsRunning((uintptr_t)this); }
	bool IsDucked() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::IsDucked((uintptr_t)this); }
	bool IsSwimming() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::IsSwimming((uintptr_t)this); }
	bool IsCrawling() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::IsCrawling((uintptr_t)this); }

	float GetSpeed(float running, float ducking, float crawling) { if (!isvalid((uintptr_t)this)) return 0.f; return auto_co_ofsets::BasePlayer::GetSpeed((uintptr_t)this, running, ducking, crawling); }

	bool InGesture() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::InGesture((uintptr_t)this); }
	bool IsOnATugboat() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::IsOnATugboat((uintptr_t)this); }
	void OnLand(float zxc) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BasePlayer::OnLand((uintptr_t)this, zxc); }
	DWORD64 GetMounted() { if (!isvalid((uintptr_t)this)) return NULL; return auto_co_ofsets::BasePlayer::GetMounted((uintptr_t)this); }
	void ForcePositionTo(Vector3 tppos) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BasePlayer::ForcePositionTo((uintptr_t)this, tppos); }
	bool InSafeZone() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::InSafeZone((uintptr_t)this); }
	OBB WorldSpaceBounds() { if (!isvalid((uintptr_t)this)) return {}; return auto_co_ofsets::BasePlayer::WorldSpaceBounds((uintptr_t)this); }
	Vector3 ClosestPoint(Vector3 position) { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::BasePlayer::ClosestPoint((uintptr_t)this, position); }
	Vector3 PivotPoint() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::BasePlayer::PivotPoint((uintptr_t)this); }
	uint64_t userID() { if (!isvalid((uintptr_t)this)) return 0.f; return u_mem::read<uint64_t>((uintptr_t)this + values::BasePlayer::userID); }
	float GetMaxSpeed() { if (!isvalid((uintptr_t)this)) return 0.f; return auto_co_ofsets::BasePlayer::GetMaxSpeed((uintptr_t)this); }
	float GetHeight() { if (!isvalid((uintptr_t)this)) return 0.f; return auto_co_ofsets::BasePlayer::GetHeight((uintptr_t)this); }
	Item* GetHeldItme() { if (!isvalid((uintptr_t)this)) return nullptr; return (Item*)auto_co_ofsets::BasePlayer::GetHeldItem((uintptr_t)this); }
	int NewProjectileID() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::BasePlayer::NewProjectileID((uintptr_t)this); }
	int NewProjectileSeed() { if (!isvalid((uintptr_t)this)) return 0; return auto_co_ofsets::BasePlayer::NewProjectileSeed((uintptr_t)this); }
	Vector3 GetMountVelocity() { if (!isvalid((uintptr_t)this)) return Vector3::Zero(); return auto_co_ofsets::BasePlayer::GetMountVelocity((uintptr_t)this); }
	bool isMounted() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::isMounted((uintptr_t)this); }
	bool OnLadder() { if (!isvalid((uintptr_t)this)) return false; return auto_co_ofsets::BasePlayer::OnLadder((uintptr_t)this); }

	bool ConsoleMessage(String value) { if (!isvalid((uintptr_t)this) || !vars::object::debug) return false; return auto_co_ofsets::BasePlayer::ConsoleMessage((uintptr_t)this, value); }

	float serverTickInterval() { if (!isvalid((uintptr_t)this)) return 0.f; return u_mem::read<float>((uintptr_t)this + values::BasePlayer::serverTickInterval); }
	void serverTickInterval(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::BasePlayer::serverTickInterval, value); }

	float vehiclePauseTime() { if (!isvalid((uintptr_t)this)) return 0.f; return u_mem::read<float>((uintptr_t)this + values::BasePlayer::vehiclePauseTime); }
	LifeState LifeStat() { if (!isvalid((uintptr_t)this)) return LifeState(1); return u_mem::read<LifeState>((uintptr_t)this + values::BaseCombatEntity::lifestate); }
	float maxHealth() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BaseCombatEntity::maxHealth); }
	float clientTickInterval(float tick) { if (!isvalid((uintptr_t)this)) return 0; return u_mem::write<float>((uintptr_t)this + values::BasePlayer::clientTickInterval, tick); }
	PlayerModel* playerModel() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<PlayerModel*>((uintptr_t)this + values::BasePlayer::playerModel); }
	Item* clActiveItem() { if (!isvalid((uintptr_t)this)) return nullptr; return u_mem::read<Item*>((uintptr_t)this + values::BasePlayer::clActiveItem); }
	void clActiveItem(ItemId* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<ItemId*>((uintptr_t)this + values::BasePlayer::clActiveItem, value); }
	String* UserIDString() { if (!isvalid((uintptr_t)this)) return nullptr; return u_mem::read<String*>((uintptr_t)this + values::BasePlayer::UserIDString); }
	void UserIDString(String* value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<String*>((uintptr_t)this + values::BasePlayer::UserIDString, value); }
	float clothingMoveSpeedReduction() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((uintptr_t)this + values::BasePlayer::clothingMoveSpeedReduction); }
	void clothingMoveSpeedReduction(float value) { if (!isvalid((uintptr_t)this)) return; u_mem::write<float>((uintptr_t)this + values::BasePlayer::clothingMoveSpeedReduction, value); }
	void set_flag(int flag) {
		if (!isvalid((uintptr_t)this)) return;
		int def_flag = u_mem::read<int>((uintptr_t)this + values::BasePlayer::playerFlags);
		u_mem::write<int>((uintptr_t)this + values::BasePlayer::playerFlags, def_flag |= flag);
	}
	bool has_flag(int flag) { if (!isvalid((uintptr_t)this)) return false; return(u_mem::read<int>((uintptr_t)this + values::BasePlayer::playerFlags) & flag); }
	bool is_safezone() { if (!isvalid((uintptr_t)this)) return false; return has_flag(131072); }
	bool is_sleeping() { if (!isvalid((uintptr_t)this)) return false; return has_flag(16); }
	bool is_wounded() { if (!isvalid((uintptr_t)this)) return false; return has_flag(64); }
	Transform* transform_pos(BoneList bone_id) {
		if (!isvalid((uintptr_t)this)) return NULL;
		uintptr_t model = u_mem::read<uintptr_t>((uintptr_t)this + values::BaseEntity::model);
		uintptr_t bone_dict = u_mem::read<uintptr_t>(model + values::Model::boneTransforms);
		Transform* BoneValue = u_mem::read<Transform*>(bone_dict + 0x20 + bone_id * 0x8);
		return BoneValue;
	}
	void ClientTick() { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BasePlayer::ClientTick((uintptr_t)this); }
	void SendProjectileUpdate(PlayerProjectileUpdate* a1) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BasePlayer::SendProjectileUpdate((uintptr_t)this, (uintptr_t)a1); }
	void SendProjectileAttack(PlayerProjectileAttack* a1) { if (!isvalid((uintptr_t)this)) return; return auto_co_ofsets::BasePlayer::SendProjectileAttack((uintptr_t)this, (uintptr_t)a1); }
	Transform* GetTransform(int bone) {
		if (!isvalid((uintptr_t)this)) return NULL;
		uintptr_t player_model = u_mem::read<uintptr_t>((uintptr_t)this + values::BaseEntity::model);
		if (!player_model || player_model < 0x10000) return NULL;
		uintptr_t boneTransforms = u_mem::read<uintptr_t>(player_model + values::Model::boneTransforms);//public Transform[] boneTransforms;
		if (!boneTransforms || boneTransforms < 0x10000) return NULL;
		Transform* transform = u_mem::read<Transform*>(boneTransforms + 0x20 + bone * 0x8);
		if (!transform || (uintptr_t)transform < 0x10000) return NULL;
		return transform;
	}
	float health() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((DWORD64)this + values::BaseCombatEntity::health); }
	float lastSentTickTime() { if (!isvalid((uintptr_t)this)) return 0; return u_mem::read<float>((DWORD64)this + values::BasePlayer::lastSentTickTime); }
	Item* weapon_info(int Id) {
		if (!isvalid((uintptr_t)this)) return NULL;
		DWORD64 Inventory = u_mem::read<DWORD64>((DWORD64)this + values::BasePlayer::inventory);
		DWORD64 Belt = u_mem::read<DWORD64>(Inventory + values::PlayerInventory::containerBelt); // containerBelt
		DWORD64 ItemList = u_mem::read<DWORD64>(Belt + values::ItemContainer::itemList);// public List<Item> itemList;
		DWORD64 Items = u_mem::read<DWORD64>(ItemList + 0x10); //	public List<InventoryItem.Amount> items;
		return (Item*)u_mem::read<DWORD64>(Items + 0x20 + (Id * 0x8));
	}
	Item* active_weapon() {
		if (!isvalid((uintptr_t)this)) return NULL;
		auto ActUID = this->clActiveItem();
		if (!ActUID) return nullptr;
		Item* ActiveWeapon;
		for (int i = 0; i < 6; i++)
			if (ActUID == (ActiveWeapon = weapon_info(i))->uid())
				return ActiveWeapon;
		return nullptr;
	}
	template<typename T = HeldEntity>
	T* active_entity() {
		if (!isvalid((uintptr_t)this)) return NULL;
		auto ActUID = this->clActiveItem();
		if (!ActUID) return nullptr;
		Item* ActiveWeapon;
		for (int i = 0; i < 6; i++)
			if (ActUID == (ActiveWeapon = weapon_info(i))->uid())
				return ActiveWeapon->heldEntity<T>();
		return nullptr;
	}
	wchar_t* name() {
		if (!isvalid((uintptr_t)this)) return NULL;
		pUncStr name = u_mem::read<pUncStr>((uintptr_t)this + values::BasePlayer::_displayName);
		return name->str;
	}
	Vector3 GetBoneByID(int32_t bone) {
		if (!isvalid((uintptr_t)this)) return Vector3::Zero();
		DWORD64 player_model = u_mem::read<uintptr_t>((uintptr_t)this + values::BaseEntity::model);
		if (!player_model) return Vector3::Zero();
		DWORD64 boneTransforms = u_mem::read<uintptr_t>(player_model + values::Model::boneTransforms);
		if (!boneTransforms) return Vector3::Zero();
		Transform* BoneValue = u_mem::read<Transform*>(boneTransforms + 0x20 + bone * 0x8);
		if (!BoneValue || (uintptr_t)BoneValue < 0x10000) return Vector3::Zero();
		return BoneValue->position();
	}
	PlayerWalkMovement* movement() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<PlayerWalkMovement*>((uintptr_t)this + values::BasePlayer::movement); }
	ModelState* modelstate() { if (!isvalid((uintptr_t)this)) return NULL; return u_mem::read<ModelState*>((uintptr_t)this + values::BasePlayer::modelState); }
	PlayerEyes* eyes() { if (!isvalid((uintptr_t)this)) return NULL; return *rc<PlayerEyes**>(this + values::BasePlayer::eyes); }
	Vector3 GetVelocity()
	{
		if (!isvalid((uintptr_t)this)) return Vector3::Zero();
		const auto PlayerModel = u_mem::read<uintptr_t>(rc<uintptr_t>(this) + values::BasePlayer::playerModel);
		auto new_velocity = u_mem::read<Vector3>(PlayerModel + values::PlayerModel::newVelocity);
		return new_velocity;
	}
	bool is_teammate(BasePlayer* BasePlayer) {
		if (!isvalid((uintptr_t)this)) return false;
		auto TeamId = u_mem::read<uintptr_t>((uintptr_t)BasePlayer + values::BasePlayer::currentTeam);
		auto LocalTeamId = u_mem::read<uintptr_t>((uintptr_t)this + values::BasePlayer::currentTeam);

		if (LocalTeamId == NULL) return false;
		if (TeamId == LocalTeamId) return true;

		return false;
	}
	bool is_dead() {
		if (this->LifeStat() == BaseCombatEntity::LifeState::Dead)
			return true;
		return false;
	}
	Vector2 GetVA()
	{
		if (!isvalid((uintptr_t)this)) return Vector2(0, 0);
		const auto Input = u_mem::read<uintptr_t>(rc<uintptr_t>(this) + values::BasePlayer::input);
		return u_mem::read<Vector2>(Input + values::PlayerInput::bodyAngles);
	}
	void SetVA(const Vector2& VA)
	{
		if (!isvalid((uintptr_t)this)) return;
		const auto Input = u_mem::read<uintptr_t>(rc<uintptr_t>(this) + values::BasePlayer::input);
		u_mem::write<Vector2>(Input + values::PlayerInput::bodyAngles, VA);
	}
	static Vector3 EyePositionForPlayer(BasePlayer* player)
	{
		bool mounted = player->HasParent();
		if (!mounted)
		{
			return Vector3::Zero();
		}
		return player->eyes()->position();
	}
	Vector3 GetNetworkEyePosition() {
		if (!isvalid((uintptr_t)this)) return Vector3();
		Vector3 viewOffset;

		if (this->IsCrawling())
		{
			viewOffset = Vector3(0.f, -1.15f, 0.175f);
		}
		else if (this->IsDucked())
		{
			viewOffset = Vector3(0.f, -0.6f, 0.f);
		}
		else
		{
			viewOffset = Vector3::Zero();
		}
		//local_player->lastSentTick()->position()
		if (this->isMounted())
		{
			return this->lastSentTick()->position() + this->transform()->rotation() * (Vector3(0.f, 1.5f, 0.f) + viewOffset) + Vector3::Zero();
		}
		Vector3 vector = EyePositionForPlayer(this);
		if (vector != Vector3::Zero())
		{
			return vector;
		}
		return this->lastSentTick()->position() + this->transform()->get_up() * (1.5f + 0) + Vector3::Zero();
	}
	PlayerTick* lastSentTick() { if (!isvalid((uintptr_t)this)) return NULL; return (PlayerTick*)u_mem::read<DWORD64*>((uintptr_t)this + values::BasePlayer::lastSentTick); }
	float GetHeight(bool ducked) { if (!isvalid((uintptr_t)this)) return 0; if (ducked) { return 1.1f; } return 1.8f; }
	float GetRadius() { if (!isvalid((uintptr_t)this)) return 0; return 0.5f; }
	float GetJumpHeight() { if (!isvalid((uintptr_t)this)) return 0; return 1.5f; }
	static void ItemCommand(unsigned int ui, String cmd) { return LocalPlayer::UserName(ui, cmd); }
	Transform* transform() { if (!isvalid((uintptr_t)this)) return nullptr; return (Transform*)auto_co_ofsets::Component::get_transform((uintptr_t)this); }


	template<typename T = Networkable*>
	T find_closest(Networkable* target_entity, float max_distance, const char* class_name = "", const char* object_name = "") {

		auto client_entities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
		auto client_entities_list = u_mem::read<uintptr_t>(client_entities + 0x10);
		auto client_entities_value = u_mem::read<uintptr_t>(client_entities_list + 0x28);
		auto client_entities_count = u_mem::read<int>(client_entities_value + 0x10);
		auto client_entities_buffer = u_mem::read<uintptr_t>(client_entities_value + 0x18);

		auto closest_entity_distance = 9999;
		T best_ent = nullptr;

		for (int i = 1; i < client_entities_count; i++) {
			auto entity = u_mem::read<uintptr_t>(client_entities_buffer + 0x20 + (i * 0x8)); if (entity <= 100000) continue;
			auto object = u_mem::read<uintptr_t>(entity + 0x10); if (object <= 100000) continue;
			auto object_class = u_mem::read<uintptr_t>(object + 0x30); if (object_class <= 100000) continue;
			auto ent = *reinterpret_cast<uintptr_t*>(object + 0x28);
			auto classname = (char*)u_mem::read<DWORD64>(u_mem::read<DWORD64>(u_mem::read<DWORD64>(object + 0x28)) + 0x10);


			auto target_position = ((BaseEntity*)target_entity)->transform()->position();
			auto ent_position = ((BaseEntity*)ent)->transform()->position();
			auto best_position = Vector3(0, 0, 0);
			if (best_ent)
				best_position = ((BaseEntity*)best_ent)->transform()->position();

			if (u_crt::strlen(class_name) > 0)
			{
				if (u_crt::m_strcmp(classname, class_name)
					&& ent_position.Distance(target_position) < max_distance
					&& (!best_ent || ent_position.Distance(target_position) < best_position.Distance(target_position)))
				{
					if (u_crt::strlen(object_name) > 0)
					{
						uintptr_t object_name_ptr = u_mem::read<uintptr_t>(object + 0x60);
						if (!object_name_ptr)
							continue;
						auto obj_name = *reinterpret_cast<rust_str*>(object_name_ptr);
						auto n = obj_name.zpad;
						if (/*std::string(n).find(object_name) != std::string::npos
							&& */ent_position.Distance(target_position) < max_distance
							&& (!best_ent || ent_position.Distance(target_position) < best_position.Distance(target_position)))
						{
							best_ent = reinterpret_cast<T>(ent);
						}
					}
					else
						best_ent = reinterpret_cast<T>(ent);
				}
			}
			else if (u_crt::strlen(object_name) > 0)
			{
				uintptr_t object_name_ptr = u_mem::read<uintptr_t>(object + 0x60);
				if (!object_name_ptr)
					continue;
				auto obj_name = *reinterpret_cast<rust_str*>(object_name_ptr);
				auto n = obj_name.zpad;
				if (/*std::string(n).find(object_name) != std::string::npos
					&& */ent_position.Distance(target_position) < max_distance
					&& (!best_ent || ent_position.Distance(target_position) < best_position.Distance(target_position)))
				{
					best_ent = reinterpret_cast<T>(ent);
				}
			}
		}
		return best_ent;
	}
};

Vector3 GetEntityPosition(uint64_t entity) {
	if (!entity) return Vector3::Zero();

	DWORD64 plyVis = u_mem::read<DWORD64>(entity + 0x8);
	if (!plyVis) return Vector3::Zero();

	DWORD64 visualState = u_mem::read<DWORD64>(plyVis + 0x38);
	if (!visualState) return Vector3::Zero();

	Vector3 ret = u_mem::read<Vector3>(visualState + 0x90);
	return ret;
}

namespace objects {
	BasePlayer* closest_turret;
	float closest_turret_dist;
	bool closest_turret_see;
	BasePlayer* closest_recycler;
	float closest_recycler_dist;
	bool closest_recycler_see;

	BasePlayer* closest_OreResourceEntity;
	float closest_OreResourceEntity_dist;
	bool closest_OreResourceEntity_see;
	BasePlayer* closest_OreHotSpot;
	float closest_OreHotSpot_dist;
	bool closest_OreHotSpot_see;
	BasePlayer* closest_TreeEntity;
	float closest_TreeEntity_dist;
	bool closest_TreeEntity_see;
	BasePlayer* closest_TreeMarker;
	float closest_TreeMarker_dist;
	bool closest_TreeMarker_see;

	BasePlayer* closest_BuildingBlock;
	float closest_BuildingBlock_dist;
	bool closest_BuildingBlock_see;
	BasePlayer* closest_CollectibleEntity;
	float closest_CollectibleEntity_dist;
	bool closest_CollectibleEntity_see;
	BasePlayer* closest_Door;
	float closest_Door_dist;
	bool closest_Door_see;
	BasePlayer* closest_Stash;
	float closest_Stash_dist;
	bool closest_Stash_see;

	bool target_heli_see;
}

void initallfuncs() {
	defoultcolorpickercolor = { -1, -1, -1, -1 };
	vars::psilent::fov_color = { 255, 255, 255, 255 };
	vars::trasers::movement_line_color = { 255, 255, 255, 255 };
	vars::trasers::bullet_tracers_color = { 255, 255, 255, 255 };
	vars::esp::looking_directioncolor = { 255, 255, 255, 255 };
	vars::esp::distancecolor = { 255, 255, 255, 255 };
	vars::esp::weaponcolor = { 255, 255, 255, 255 };
	vars::esp::boxcolor = { 255, 255, 255, 255 };
	vars::esp::pidoras = { 255, 255, 255, 255 };
	vars::esp::skeletoncolor = { 255, 255, 255, 255 };
	vars::esp::namecolor = { 255, 255, 255, 255 };
	vars::psilent::target_line_color = { 255, 255, 255, 255 };
	vars::misc::raycast_sphere_color = { 255, 255, 255, 255 };
	vars::esp::flagscolor = { 255, 255, 255, 255 };
	vars::esp::player_chams_color = { 255, 255, 255, 255 };
	vars::esp::player_chams_visible_color = { 0, 255, 0, 255 }; // Зеленый для видимых
	vars::esp::player_chams_invisible_color = { 255, 0, 0, 255 }; // Красный для невидимых
	vars::misc::sky_color = { 255, 255, 255, 255 };
	vars::misc::ambient_color = { 255, 255, 255, 255 };

	vars::weapon::bullet_hitbox_size = 1.f;
	vars::weapon::bulletspeed = 1.f;
	vars::psilent::belt_pos.x = 100;
	vars::psilent::belt_pos.y = 100;
	vars::psilent::belt_size.x = 390;
	vars::psilent::belt_size.y = 60;

	screen_center = { Screen::get_width() / 2.0f, Screen::get_height() / 2.0f };
	vars::antihack::speedhack_pos = Vector2(200, Screen::get_height() - 100);
	vars::esp::radar_pos = Vector2(Screen::get_width() - 200, Screen::get_height() - 150);
	vars::antihack::flyhack_ind_pos = { screen_center.x, 100 };
	vars::weapon::autoreload_pos = { 100, screen_center.y };
	vars::manipulator::manipulatorind_pos = Vector2(Screen::get_width() - 20, Screen::get_height() - 110);
	vars::esp::radar_size = 100;
}