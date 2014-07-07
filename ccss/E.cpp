#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		int white = 0, yolk = 0;
		char c;
		while ((c = cin.get()) != '\n')
			switch(c)
			{
				case 'W':
					++white;
					break;
				case 'Y':
					++yolk;
					break;
			}

		cout << max(white, yolk) << endl;
	}
	return 0;
}
