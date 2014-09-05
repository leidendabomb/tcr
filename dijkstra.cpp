#include <vector>
#include <set>
#include <list>

using namespace std;

struct vertex {
	list<pair<int, int> > connections; // idx −> weight
	unsigned int dist;
	unsigned int prev;
};

int dijkstra(vector<vertex>& graph, int source, int dest)
{
	const unsigned int infinity = -1;

	for (unsigned int i = 0; i < graph.size(); i++)
	{
		graph[i].dist = infinity;
		graph[i].prev = infinity;
	}

	set<int> todo;
	graph[source].dist = 0;
	todo.insert(source);

	while (!todo.empty())
	{
		int index = *todo.begin();
		vertex &cur = graph[index];
		todo.erase(todo.begin());

		for(auto &conn : cur.connections)
		{
			int idx = conn.first;
			int weight = conn.second;

			unsigned int alt = cur.dist + weight;
			if (alt < graph[idx].dist)
			{
				graph[idx].dist = alt;
				graph[idx].prev = index;
				// Reorder
				todo.insert(idx);
			}
		}
	}

	return graph[dest].dist;
}
