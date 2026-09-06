#pragma once
#define ToLower(Char) ((Char >= 'A' && Char <= 'Z') ? (Char + 32) : Char)

namespace u_crt
{
	char* __cdecl strstr_d(const char* Str, const char* SubStr)
	{
		char* v3; // r8
		char v5; // al
		signed __int64 i; // r9
		const char* v7; // rdx

		v3 = (char*)Str;
		if (!*SubStr)
			return (char*)Str;
		v5 = *Str;
		if (!*Str)
			return 0i64;
		for (i = Str - SubStr; ; ++i)
		{
			v7 = SubStr;
			if (v5)
				break;
		LABEL_9:
			if (!*v7)
				return v3;
			v5 = *++v3;
			if (!*v3)
				return 0i64;
		}
		while (*v7)
		{
			if (v7[i] == *v7)
			{
				++v7;
				if (v7[i])
					continue;
			}
			goto LABEL_9;
		}
		return v3;
	}
	inline unsigned int wcslen(const wchar_t* str)
	{
		int counter = 0;
		if (!str)
			return 0;
		for (; *str != '\0'; ++str)
			++counter;
		return counter;
	}
	int wcscmp_(const wchar_t* const left, const wchar_t* const right)
	{
		int i = 0;

		while (left[i] == right[i])
		{
			if (left[i] == L'\0')
				return 0;

			i++;
		}

		return (left[i] - right[i]);
	}
	const char* wcharToChar(const wchar_t* src) {
		static char mbstr[256];
		size_t i = 0;
		while (i < 256 - 1 && src[i] != L'\0') {
			mbstr[i] = static_cast<char>(src[i]);
			++i;
		}
		mbstr[i] = '\0';
		return mbstr;
	}
	wchar_t* wcscpy(wchar_t* dest, const wchar_t* src) {
		if (src == nullptr || dest == nullptr) return dest;
		wchar_t* p = dest;
		while ((*p++ = *src++)) {
		}
		return dest;
	}
	void deleteLastCharacter(wchar_t* str) {
		size_t length = wcslen(str);

		if (length > 0) {
			str[length - 1] = L'\0';
		}
	}
	wchar_t* wcscat(wchar_t* dest, const wchar_t* src) {
		if (src == nullptr || dest == nullptr) return dest;
		wcscpy(dest + wcslen(dest), src);
		return dest;
	}
	inline int wcsicmp_insensitive(const wchar_t* cs, const wchar_t* ct)
	{
		const auto len = wcslen(cs);
		if (len != wcslen(ct))
			return false;

		for (size_t i = 0; i < len; i++)
			if ((cs[i] | L' ') != (ct[i] | L' '))
				return false;

		return true;
	}
	inline bool strcmp(const char* a, const char* b) {
		if ((uintptr_t)a == 0x00000000ffffffff || (uintptr_t)b == 0x00000000ffffffff)
			return false;
		if ((uintptr_t)a == 0x000000000000007d || (uintptr_t)b == 0x000000000000007d)
			return false;

		if (!a || !b)
			return !a && !b;

		int ret = 0;
		unsigned char* p1 = (unsigned char*)a;
		unsigned char* p2 = (unsigned char*)b;
		while (!(ret = *p1 - *p2) && *p2)
			++p1, ++p2;

		return ret == 0;
	}
	inline bool m_strcmp(char* a, const char* b) {
		if ((uintptr_t)a == 0x00000000ffffffff || (uintptr_t)b == 0x00000000ffffffff)
			return false;
		if ((uintptr_t)a == 0x000000000000007d || (uintptr_t)b == 0x000000000000007d)
			return false;

		if (!a || !b) return !a && !b;

		int ret = 0;
		unsigned char* p1 = (unsigned char*)a;
		unsigned char* p2 = (unsigned char*)b;
		while (!(ret = *p1 - *p2) && *p2)
			++p1, ++p2;

		return ret == 0;
	}
	char* m_strstr(char* input, const char* find)
	{
		do {
			const char* p, * q;
			for (p = input, q = find; *q != '\0' && *p == *q; p++, q++) {}
			if (*q == '\0') {
				return input;
			}
		} while (*(input++) != '\0');
		return 0;
	}
	template <typename StrType, typename StrType2>
	bool StrCmp(StrType Str, StrType2 InStr, bool Two)
	{
		if (!Str || !InStr) return false;
		wchar_t c1, c2;
		do
		{
			c1 = *Str++; c2 = *InStr++;
			c1 = ToLower(c1); c2 = ToLower(c2);
			if (!c1 && (Two ? !c2 : 1))
				return true;
		} while (c1 == c2); return false;
	}
	void ConvertCharToWchar(const char* charString, wchar_t* wcharBuffer, size_t bufferSize) {
		size_t i = 0;
		while (charString[i] != '\0' && i < bufferSize - 1) {
			wcharBuffer[i] = static_cast<wchar_t>(charString[i]);
			++i;
		}
		wcharBuffer[i] = L'\0';
	}
	unsigned int strlen(const char* str)
	{
		unsigned int len = 0;
		while (*str != '\0')
		{
			len++;
			str++;
		}
		return len;
	}
}