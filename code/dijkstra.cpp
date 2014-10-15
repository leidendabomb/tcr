const unsigned MAX_NODES = 100000;
const double INFINITY = numeric_limits<double>::infinity();

typedef pair<double, unsigned> halfpijl; // gewicht en bestemming

vector<halfpijl> buren[MAX_NODES];
double dist[MAX_NODES];

void dijkstra(unsigned start) {
	priority_queue<halfpijl, vector<halfpijl>, greater<halfpijl>> q;

	fill_n(dist, MAX_NODES, INFINITY);

	dist[start] = 0;
	q.push(make_pair(0, start));

	while (!q.empty()) {
		halfpijl cur = q.top();
		q.pop();

		if (dist[cur.second] < cur.first) {
			continue;
		}

		for (auto &buur : buren) {
			if (cur.first + buur.first < dist[buur.second]) {
				dist[buur.second] = cur.first + buur.second;
				q.push(make_pair(dist[buur.second], buur.second));
			}
		}
	}
}
