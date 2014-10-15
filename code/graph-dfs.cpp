bool mark[NODE_MAX];

template <typename S, typename F>
void dfs_visit(const unsigned int cur, const vector<unsigned int>& buren[], S start, F finish) {
	if (mark[cur]) { return; }
	mark[cur] = true;

	start(cur);

	for (unsigned int buur : buren[cur]) {
		dfs_visit(buur, buren, start, finish);
	}

	finish(cur);
}
