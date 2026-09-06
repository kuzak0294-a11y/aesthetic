String* originalname;
void SteamPlatformUpdate(SteamPlatform* _This)
{
	
	u_hooks::orig::hk_SteamPlatformUpdate(_This);
	if (originalname == NULL) {
		originalname = _This->UserName();
	}
	if (vars::misc::namespoofer)
	{
		if (vars::misc::randomnick) {
			unsigned random_number = (math::rand() % 100) + 1;
			_This->UserName(RandomUsernames().Get((uint64_t)random_number));
		}
		else {
			const char* convertedStr = u_crt::wcharToChar(vars::misc::nick);
			_This->UserName((String*)il2cpp::methods::new_string(convertedStr));
		}
	}
	else {
		_This->UserName(originalname);
	}
}