namespace u_mem {
	template<typename t>
	t read(uintptr_t addr) {
		if (addr < 0xffffff)
			return t();
		if (addr > 0x7fffffff0000)
			return t();

		return *rc<t*>(addr);
	}
	template<typename t>
	bool write(uintptr_t addr, t buffer) {
		*rc<t*>(addr) = buffer;
		return true;
	}

}