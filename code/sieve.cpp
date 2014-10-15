const unsigned int SIEVE_MAX = 10000000;

// Do a static allocation
bool sieve[SIEVE_MAX];
memset(sieve, true, SIEVE_MAX);

sieve[0] = false;
sieve[1] = false;

for (unsigned int i = 2; i < (unsigned int) ceil(sqrt(SIEVE_MAX)); i++) {
	if (!sieve[i]) {
		continue;
	}
	for (unsigned int j = i * i; j < SIEVE_MAX; j += i) {
		sieve[j] = false;
	}
}
