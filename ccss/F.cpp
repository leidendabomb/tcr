#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	const int q = 123456789;
	
	while (numEntries--)
	{
		int n,m;
		cin >> n >> m;

		if (n < m) {
			cout << n << endl;
			continue;
		}

		int *buffer = new int[m];
		int sum = 0;

		for (int i = 0; i < m; i++) {
			sum += buffer[i] = i;
			sum %= q;
		}

		for (int i = m; i <= n; i++)
		{
			int temp = buffer[i%m];
			sum = (sum + (buffer[i%m] = sum)) % q;
			sum = (sum - temp + q) % q;
		}

		cout << buffer[n%m] << endl;

		delete[] buffer;
	}
	return 0;
}
