bool mark[NODE_MAX];

template <typename F>
void bfs_visit(const unsigned int start, const vector<unsigned int>& buren[], F callback) {
	queue<unsigned int> todo;
	todo.push(start);

	while (!todo.empty()) {
		unsigned int cur = todo.front();
		todo.pop();
		
		if (mark[cur]) { continue; }
		mark[cur] = true;
		callback(cur);

		for(unsigned int buur : buren[cur]) {
			todo.push(buur);
		}
	}
}
