#include <queue>
#include <tuple>

using namespace std;

const int grid_w = 10;
const int grid_h = 10;
const unsigned int inf = -1;
struct tile
{
	enum 
	{
		OPEN,
		CLOSED,
		END
	} type;
	unsigned int dist;
	tile()
		: dist(inf)
	{
	}
} grid[grid_w][grid_h];

int main()
{
	typedef pair<int, int> coordinate;
	queue<coordinate> openList;

	// Insert initial coordinate
	// with distance 0 (obviously)

	while (!openList.empty())
	{
		int curx, cury;
		tie(curx, cury) = openList.front();

		tile &curtile = grid[curx][cury];
		if (curtile.type == tile::END)
			break;
		for (int x = curx-1; x <= curx+1; ++x)
			for (int y = cury-1; y <= cury+1; ++y)
				if ((x-curx) * (y-cury) == 0 && 
						x > 0 && y > 0 &&
						x < grid_w && y < grid_h &&
						grid[x][y].type != tile::CLOSED &&
						grid[x][y].dist == inf)
				{
					grid[x][y].dist = curtile.dist+1;
					openList.push(make_pair(x, y));
				}

		openList.pop();
	}

	bool success = !openList.empty();
	//tile result = openList.front();

	return success;
}
