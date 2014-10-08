const int SIEVE_MAX = 10000000;

// Do a static allocation
bool sieve[SIEVE_MAX] = {true};

sieve[0] = false;
sieve[1] = false;

for (int i = 2; i < (int) ceil(sqrt(SIEVE_MAX)); i++) {
	if (!sieve[i]) {
		continue;
	}
	for (int j = i * i; j < SIEVE_MAX; j += i) {
		sieve[j] = false;
	}
}
