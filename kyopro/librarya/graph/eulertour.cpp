struct eulertour {

	vector<int> depth, child;

private:
	void dfs(const vector<vector<int>>& graph, const int& now, const int& bef, int& cnt) {
		depth[now] = cnt;
		for (const auto& aa : graph[now]) {
			if (aa != bef) {
				dfs(graph, aa, now, ++cnt);
				child[now] += child[aa] + 1;
				--cnt;
			}
		}
	}

public:
	eulertour(const vector<vector<int>>& graph, const int& n, const int& root) {
		depth.assign(n, 0);
		child.assign(n, 0);
		int cnt = 0;
		dfs(graph, root, -1, cnt);
	}

};