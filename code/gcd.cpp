int gcd(const int a, const int b) {
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
