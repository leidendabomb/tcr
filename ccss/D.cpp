#include <iostream>
#include <cstdlib>
#include <queue>
#include <tuple>

using namespace std;

struct square_t {
	bool isWall;
	bool gevisiteerd; // Copyright Bart van Strien 2014.
	bool opPad;
	pair<int,int> parent;
};

square_t maze[500][500];

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	
	while (numEntries--)
	{
		int W, H;
		cin >> H >> W;
		cin.ignore();
		queue<pair<int, int>> todo;
		pair<int, int> you;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				char c = cin.get();
				maze[x][y].isWall = c == '#';
				maze[x][y].opPad = false;
				maze[x][y].gevisiteerd = false;
				if (c == 'Y') {
					you = make_pair(x,y);
					maze[x][y].gevisiteerd = true;
					todo.push(you);
				}
			}
			cin.ignore();
		}
		pair<int, int> uitgang;
		while (true) {
			int x, y;
			tie(x, y) = todo.front();
			if (maze[x][y].isWall) {
				todo.pop();
				continue;
			}
			if (x == 0 || x == W-1 || y == 0 || y == H-1) {
				uitgang = todo.front();
				break;
			}

			for (int i = -1; i <= 1; i+=2) {
				if (!maze[x+i][y].gevisiteerd) {
					maze[x+i][y].parent = todo.front();
					maze[x+i][y].gevisiteerd = true;
					todo.push(make_pair(x+i,y));
				}
				if (!maze[x][y+i].gevisiteerd) {
					maze[x][y + i].parent = todo.front();
					maze[x][y+i].gevisiteerd = true;
					todo.push(make_pair(x,y+i));
				}
			}
			todo.pop();
						
		}
		while (uitgang != you) {
			maze[uitgang.first][uitgang.second].opPad = true;
			uitgang = maze[uitgang.first][uitgang.second].parent;
		}

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (x == you.first && y == you.second) {
					cout << 'Y';
				} else if (maze[x][y].opPad) {
					cout << 'O';
				} else {
					cout << (maze[x][y].isWall ? '#' : '.');
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
