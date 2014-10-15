uint64_t lcm(const uint64_t a, const uint64_t b) {
	return (a * b) / gcd(a, b);
}
