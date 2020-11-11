/*
* @title dijkstra
* @docs kyopro/docs/dijkstra.md
*/


template<typename T = int>
vector<T> dijkstra(graph<T>& g, const int& v, const int& n, const T Inf) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		if (cost > res[top])continue;
		for (const auto& aa : g[top]) {
			if (res[top] + aa.cost >= res[aa.to])continue;
			res[aa.to] = aa.cost + res[top];
			priq.push({ res[aa.to], aa.to });
		}
	}
	return res;
}
