#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		int N, D, L;
		cin >> N >> D >> L;
		int pos = -D;
		int needed = 0;
		for (int i = 0; i <= N; i++) {
			int next = L + D;
			if (i < N)
				cin >> next;
			int gap = next-pos-2*D;
			pos = next;
			if (gap > 0)
				needed += ceil(gap/(2.0*D));
		}

		cout << needed << endl;
	}
	return 0;
}
