// primes should be an stl container containing enough primes.
// Afterwards, factorization contains records of prime -> power.
void factorize(unsigned int num, map<unsigned int, unsigned int>& factorization) {
	factorization.clear();

	for (unsigned int prime : primes) {
		while (num % prime == 0) {
			factorization[prime]++;
			num /= prime;
		}
	}
	if (num != 1) {
		factorization[num] = 1;
	}

}
