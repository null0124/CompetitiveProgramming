/*
* @title topological-sort
* @docs kyopro/docs/topological_sort.md
*/

template<typename T = int>
vector<int> topological_sort(graph<T>& g, const int& v) {
	vector<int> ret, in(v);

	queue<int> que;
	rep(i, v) for (const auto& aa : g[i])++in[aa.to];
	rep(i, v)if (not in[i])que.push(i);

	while (not que.empty()) {
		int top = que.front();
		que.pop();
		for (const auto& aa : g[top]) {
			--in[aa.to];
			if (not in[aa.to])que.push(aa.to);
		}
		ret.emplace_back(top);
	}
	return ret;
}