#include <iostream>
#include <vector>

using namespace std;

inline int getIndex(int D, int x, int y, int z) {
	return D * (D * x + y) + z;
}

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		int D;
		cin >> D;
		cin.ignore();
		int full = D * D * D;
		vector<bool> cube(full, true);
		vector<bool> A(D, false);
		vector<bool> B(D, false);
		vector<bool> C(D, false);

		for (int y = 0; y < D; y++)
		{
			for (int x = 0; x < D; x++)
				A[y*D+x] = cin.get() == '#';
			cin.ignore();
			for (int x = 0; x < D; x++)
				B[y*D+x] = cin.get() == '#';
			cin.ignore();
			for (int x = 0; x < D; x++)
				C[y*D+x] = cin.get() == '#';
			cin.ignore();
		}

		for (int y=0; y < D; y++) {
			for (int x = 0; x < D; x++) {
				if (!A[y*D+x]) {
					for (int z = 0; z < D; z++) {
						int index = getIndex(D, x, y, z);
						full -= cube[index];
						cube[index] = false;
					}
				}
			}
		}

		for (int z=0; z < D; z++) {
			for (int x = 0; x < D; x++) {
				if (!B[z*D+x]) {
					for (int y = 0; y < D; y++) {
						int index = getIndex(D, x, y, z);
						full -= cube[index];
						cube[index] = false;
					}
				}
			}
		}
		for (int z=0; z < D; z++) {
			for (int y = 0; y < D; y++) {
				if (!C[z*D+y]) {
					for (int x = 0; x < D; x++) {
						int index = getIndex(D, x, D - y - 1, z);
						full -= cube[index];
						cube[index] = false;
					}
				}
			}
		}
		cout << full << endl;
	}
	return 0;
}
