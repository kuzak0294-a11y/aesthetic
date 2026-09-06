#undef min
#undef max
#define M_PI 3.14159265358979323846f
#define M_PI_2 1.57079632679489661923
#define DEG2RAD(x) ((float)(x) * (float)(M_PI / 180.f))
#define max( a, b ) ( ( ( a ) > ( b ) ) ? ( a ) : ( b ) )
#define min( a, b ) ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
static inline float Max3(float f1, float f2, float f3)
{
	return max(max(f1, f2), f3);
}
unsigned int seed;
namespace math {
	double sqrt(double d) {
		return rc<double(*)(double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Sqrt"), 1, _(""), _("System"))))(d);
	};
	double asin(double d) {
		return rc<double(*)(double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Asin"), 1, _(""), _("System"))))(d);
	}
	double abs(double value) {
		return rc<double(*)(double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Abs"), 1, _(""), _("System"))))(value);
	}
	double atan(double y, double x) {
		return rc<double(*)(double, double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Atan2"), 2, _(""), _("System"))))(y,x);
	}
	double sin(double d) {
		return rc<double(*)(double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Sin"), 1, _(""), _("System"))))(d);
	}
	double cos(double d) {
		return rc<double(*)(double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Cos"), 1, _(""), _("System"))))(d);
	}
	double tan(double a) {
		return rc<double(*)(double)>(*rc<uintptr_t*>(il2cpp::method(_("Math"), _("Tan"), 1, _(""), _("System"))))(a);
	}
	float Dot(const Vector3& Vec1, const Vector3& Vector2) {
		return Vec1[0] * Vector2[0] + Vec1[1] * Vector2[1] + Vec1[2] * Vector2[2];
	}
	template<typename T> 
	static inline T ImClamp(T v, T mn, T mx) { 
		return (v < mn) ? mn : (v > mx) ? mx : v;
	}
	float lerp(float a, float b, float t) {
		return a + t * (b - a);
	}
	int rand() {
		seed = (seed * 1103515245 + 12345) & 0xFFFFFFFF;
		return (seed >> 16) & 0x7FFF;
	}
	inline void Normalize(float& Yaw, float& Pitch)
	{
		if (Pitch < -89)
			Pitch = -89;
		else if (Pitch > 89)
			Pitch = 89;
		if (Yaw < -360)
			Yaw += 360;
		else if (Yaw > 360)
			Yaw -= 360;
	}
	float RandomZeroToOne() {
		unsigned int seed = 0;
		const unsigned int a = 1664525;
		const unsigned int c = 1013904223;
		const unsigned int m = 0xFFFFFFFF;

		seed = (a * seed + c) & m;
		return static_cast<float>(seed) / static_cast<float>(m);
	}
	float normalize_angle(float angle) {
		while (angle > 360.0f) {
			angle -= 360.0f;
		}
		while (angle < 0.0f) {
			angle += 360.0f;
		}
		return angle;
	}
	Vector3 normalize_angles(Vector3 angles) {
		angles.x = normalize_angle(angles.x);
		angles.y = normalize_angle(angles.y);
		angles.z = normalize_angle(angles.z);
		return angles;
	}
	Vector3 euler_angles(Quaternion q1) {
		float num = q1.w * q1.w;
		float num2 = q1.x * q1.x;
		float num3 = q1.y * q1.y;
		float num4 = q1.z * q1.z;
		float num5 = num2 + num3 + num4 + num;
		float num6 = q1.x * q1.w - q1.y * q1.z;
		Vector3 vector;
		if (num6 > 0.4995f * num5) {
			vector.y = 2.0f * math::atan(q1.y, q1.x);
			vector.x = 1.57079637f;
			vector.z = 0.0f;
			return normalize_angles(vector * 57.2958f);
		}
		if (num6 < -0.4995f * num5) {
			vector.y = -2.0f * math::atan(q1.y, q1.x);
			vector.x = -1.57079637f;
			vector.z = 0.0f;
			return normalize_angles(vector * 57.2958f);
		}
		Quaternion quaternion = Quaternion(q1.w, q1.z, q1.x, q1.y);
		vector.y = math::atan(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
		vector.x = math::asin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
		vector.z = math::atan(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
		return normalize_angles(vector * 57.2958f);
	}
	Vector2 calculate_rotation_point(float flAngle, float range, int x, int y, int LineLength) {
		float nigga = flAngle;
		nigga += 45.f;

		float flYaw = (nigga) * (3.14159265358979323846 / 180.0);

		float viewcosyawzzzzzzz = math::cos(flYaw);
		float viewsinyawzzzzzzz = math::sin(flYaw);

		float x2 = range * (-viewcosyawzzzzzzz) + range * viewsinyawzzzzzzz;
		float y2 = range * (-viewcosyawzzzzzzz) - range * viewsinyawzzzzzzz;

		int posonscreenX = x + int(x2 / range * (LineLength));
		int posonscreenY = y + int(y2 / range * (LineLength));

		return Vector2(posonscreenX, posonscreenY);
	}
	double fmod(double dividend, double divisor) {
		if (divisor == 0.0) return 0.0;
		int quotient = static_cast<int>(dividend / divisor);
		double remainder = dividend - static_cast<double>(quotient) * divisor;
		return remainder;
	}
	float NormalizeAngle(float angle) {
		while (angle > 360.0f) {
			angle -= 360.0f;
		}
		while (angle < 0.0f) {
			angle += 360.0f;
		}
		return angle;
	}
	Vector3 NormalizeAngles(Vector3 angles) {
		angles.x = NormalizeAngle(angles.x);
		angles.y = NormalizeAngle(angles.y);
		angles.z = NormalizeAngle(angles.z);
		return angles;
	}
	Vector3 EulerAngles(Quaternion q1) {
		float num = q1.w * q1.w;
		float num2 = q1.x * q1.x;
		float num3 = q1.y * q1.y;
		float num4 = q1.z * q1.z;
		float num5 = num2 + num3 + num4 + num;
		float num6 = q1.x * q1.w - q1.y * q1.z;
		Vector3 vector;
		if (num6 > 0.4995f * num5) {
			vector.y = 2.0f * atan(q1.y, q1.x);
			vector.x = 1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		if (num6 < -0.4995f * num5) {
			vector.y = -2.0f * atan(q1.y, q1.x);
			vector.x = -1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		Quaternion quaternion = Quaternion(q1.w, q1.z, q1.x, q1.y);
		vector.y = atan(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
		vector.x = sin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
		vector.z = atan(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
		return NormalizeAngles(vector * 57.2958f);
	}
}
Vector3 MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta)
{
	float num = target.x - current.x;
	float num2 = target.y - current.y;
	float num3 = target.z - current.z;
	float num4 = num * num + num2 * num2 + num3 * num3;
	bool flag = num4 == 0.f || (maxDistanceDelta >= 0.f && num4 <= maxDistanceDelta * maxDistanceDelta);
	Vector3 result;
	if (flag)
	{
		result = target;
	}
	else
	{
		float num5 = (float)math::sqrt((double)num4);
		result = Vector3(current.x + num / num5 * maxDistanceDelta, current.y + num2 / num5 * maxDistanceDelta, current.z + num3 / num5 * maxDistanceDelta);
	}
	return result;
}
wchar_t* itow(int number, wchar_t* destination, int base)
{
	int count = 0;
	do
	{
		int digit = number % base;
		destination[count++] = (digit > 9) ? digit - 10 + L'A' : digit + L'0';
	} while ((number /= base) != 0);
	destination[count] = 0;
	int i;
	for (i = 0; i < count / 2; ++i)
	{
		wchar_t symbol = destination[i];
		destination[i] = destination[count - i - 1];
		destination[count - i - 1] = symbol;
	}
	return destination;
}
char* itoass(int m_iValue, char* m_pBuffer, int m_iRadix)
{
	auto xtoa = [](int a1, char* a2, int a3, bool a4) -> char
	{
		char* v5; // r10
		char* v6; // r8
		char* v7; // r11
		char* v8; // r9
		unsigned int v9; // edx
		char v10; // al
		char result; // al
		char v12; // cl

		v5 = a2;
		if (a4)
		{
			v5 = a2 + 1;
			*a2 = 45;
			a1 = -a1;
		}
		v6 = v5;
		do
		{
			v7 = v5 + 1;
			v8 = v5;
			v9 = a1 % a3;
			a1 /= a3;
			v10 = 87;
			if (v9 <= 9)
				v10 = 48;
			*v5++ = v9 + v10;
		} while (a1);
		*v7 = 0;
		do
		{
			result = *v6;
			v12 = *v8;
			*v8-- = *v6;
			*v6++ = v12;
		} while (v6 < v8);
		return result;
	};

	bool v3; // r9

	v3 = false;
	if (m_iRadix == 10 && m_iValue < 0)
		v3 = true;
	xtoa(m_iValue, m_pBuffer, m_iRadix, v3);
	return m_pBuffer;
}
char* itoass_float(float m_fValue, char* m_pBuffer, int m_iRadix, int sym)
{

	auto xtoa = [](float a1, char* a2, int a3, bool a4, int syma) -> char
	{
		char* v5; // r10
		char* v6; // r8
		char* v7; // r11
		char* v8; // r9
		unsigned int v9; // edx
		char v10; // al
		char result; // al
		char v12; // cl

		int iValue = (int)a1;
		float fDecimal = a1 - iValue;
		v5 = a2;
		if (a4)
		{
			v5 = a2 + 1;
			*a2 = 45;
			iValue = -iValue;
			fDecimal = -fDecimal;
		}
		v6 = v5;
		do
		{
			v7 = v5 + 1;
			v8 = v5;
			v9 = iValue % a3;
			iValue /= a3;
			v10 = 87;
			if (v9 <= 9)
				v10 = 48;
			*v5++ = v9 + v10;
		} while (iValue);
		if (syma < 3)
		{
			*v7++ = NULL;
		}
		else
		{
			*v7++ = '.';
		}
		
		for (int i = 0; i < 6; i++)
		{
			fDecimal *= a3;
			int iDecimal = (int)fDecimal;
			fDecimal -= iDecimal;
			*v7++ = iDecimal + '0';
		}
		*v7 = 0;
		do
		{
			result = *v6;
			v12 = *v8;
			*v8-- = *v6;
			*v6++ = v12;
		} while (v6 < v8);
		return result;
	};

	bool v3; // r9

	v3 = false;
	if (m_iRadix == 10 && m_fValue < 0)
		v3 = true;
	xtoa(m_fValue, m_pBuffer, m_iRadix, v3, sym);

	// Truncate to maximum of 3 characters
	if (u_crt::strlen(m_pBuffer) > sym)
		m_pBuffer[sym] = '\0';

	return m_pBuffer;
}
inline void AnsiToUnicode(const char* m_szAnsi, wchar_t* m_pBuffer)
{
	for (int i = 0; ; ++i)
	{
		m_pBuffer[i] = static_cast<char>(m_szAnsi[i]);

		if (!m_szAnsi[i])
			return;
	}
}

inline void UnicodeToAnsi(const wchar_t* m_wszUnicode, char* m_pBuffer)
{
	// Используем WinAPI для конвертации
	WideCharToMultiByte(CP_ACP, 0, m_wszUnicode, -1, m_pBuffer, 256, NULL, NULL);
}
struct Line {
	Vector3 point0;
	Vector3 point1;

	Line(Vector3 point0, Vector3 point1) {
		this->point0 = point0;
		this->point1 = point1;
	}

	Line(Vector3 origin, Vector3 direction, float length) {
		this->point0 = origin;
		this->point1 = origin + direction * length;
	}
	Vector3 ClosestPoint(Vector3 pos) {
		Vector3 a = this->point1 - this->point0;
		float magnitude = a.Magnitude();
		Vector3 vector = a / magnitude;
		return this->point0 + (vector * math::ImClamp(Vector3(pos - this->point0).dot_product(vector), 0.f, magnitude));
	}
	float Distance(Vector3 pos) {
		return (pos - this->ClosestPoint(pos)).Magnitude();
	}
};