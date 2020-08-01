/*
* @title dijkstra(経路復元)
* @docs kyopro/docs/dijkstra_path.md
*/

template<typename T>
vector<T> dijkstra(graph<T>& g, vector<int>& path, const int& v, const int& g, const int& n, const T Inf, const bool f) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	vector<int> prev(n);
	fill(all(prev), -1);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		auto now = priq.top();
		top = now.second;
		priq.pop();
		if (res[top] < now.first)continue;
		for (const auto& aa : g[top]) {
			if (res[top] + aa.cost > res[aa.to])continue;
			else if (res[top] + aa.cost == res[aa.to]) {
				if (f) prev[aa.to] = min(top, prev[aa.to]);
				continue;
			}
			res[aa.to] = aa.cost + res[top];
			prev[aa.to] = top;
			priq.push({ res[aa.to], aa.to });
		}
	}

	for (int i = g; i != -1; i = prev[i])path.push_back(i);

	reverse(all(path));

	return res;
}
