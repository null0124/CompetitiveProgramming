


template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& graph, const int& v, const int& n, const T Inf) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		for (const auto& aa : graph[top]) {
			if (res[top] + aa.second >= res[aa.first])continue;
			res[aa.first] = aa.second + res[top];
			priq.push({ res[aa.first], aa.first });
		}
	}
	return res;
}