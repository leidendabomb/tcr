#include <algorithm>
#include <cstring>

unsigned ARRAY_MAX = 1000;

// Vul een array met een specifieke waarde
int ints[ARRAY_MAX];
fill_n(ints, ARRAY_MAX, 9001);

// Booleans en chars met memset, want sneller
char chars[ARRAY_MAX];
memset(chars, 42, ARRAY_MAX);
