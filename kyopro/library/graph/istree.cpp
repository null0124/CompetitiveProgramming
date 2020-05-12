void dfs(const vector<vector<int>>& tree, vector<bool>& flag, const int& now, bool& f) {
	if (f)return;
	flag[now] = true;
	int cnt = 0;
	for (const auto& aa : tree[now]) {
		if (flag[aa]) {
			++cnt;
			if (cnt == 2) {
				f = true;
				return;
			}
			continue;
		}
		dfs(tree, flag, aa, f);
	}
}

//depends on unionfind
//グラフ(連結でなくてよい)に含まれる tree の数を返す/graph(隣接リスト)/頂点数
int istree(const vector<vector<int>>& graph, const int& n) {
	unionfind uni(n);
	rep(i, n) {
		for (const auto& aa : graph[i])uni.unite(i, aa);
	}
	bool f = false;
	vector<bool> flag(n);
	int ans = 0;
	rep(i, n) {
		if (flag[uni.find(i)])continue;
		dfs(graph, flag, uni.find(i), f);
		for (const auto& aa : uni.leaf(i)) {
			if (!flag[aa])f = true;
		}
		ans += (!f || uni.size(i) == 1);
		f = false;
	}
	return ans;
}