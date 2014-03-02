size_t strstr_libc(const char* s, size_t n, const char* neddle) {
	auto ret = strstr(s, neddle);

	if (ret == nullptr)
		return NOT_FOUND;
	else
		return ret - s;
}

