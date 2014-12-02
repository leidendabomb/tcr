vector<int> kmp_table(const string& word) {
    vector<int> fallbacks(word.length());
    fallbacks[0] = -1;

    if (word.length() == 1) {
        return fallbacks;
    }

    fallbacks[1] = 0;

    int pos = 2;
    int cnd = 0;

    while (pos < (int) word.length()) {
        if (word[pos - 1] == word[cnd]) {
            cnd++;
            fallbacks[pos] = cnd;
            pos++;
        } else if (cnd > 0) {
            cnd = fallbacks[cnd];
        } else {
            fallbacks[pos] = 0;
            pos++;
        }
    }

    return fallbacks;
}

int kmp(const string& haystack, const string& needle) {
    if (needle.empty()) {
        return 0;
    }

    vector<int> table = kmp_table(needle);
    int i = 0, m = 0;
    while (m + i < (int) haystack.length()) {
        if (needle[i] == haystack[m + i]) {
            if (i == (int) needle.length() - 1) {
                return m;
            } else {
                i++;
            }
        } else {
            if (table[i] > -1) {
                // Fall back on substring match.
                m = m + i - table[i];
                i = table[i];
            } else {
                // Back to square one.
                i = 0;
                m++;
            }
        }
    }

    return -1;
}
