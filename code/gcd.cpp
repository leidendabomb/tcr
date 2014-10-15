uint64_t gcd(const uint64_t a, const uint64_t b) {
	if (a < b) {
		return gcd(b, a);
	} else {
		if (a % b == 0) {
			return b;
		} else {
			return gcd(b, a % b);
		}
	}
}
