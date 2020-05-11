


template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& graph, vector<int>& path, const int& v, const int& g, const int& n, const T inf) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	vector<int> prev(n);
	fill(all(prev), -1);
	fill(all(res), inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		for (const auto& aa : graph[top]) {
			if (res[top] + aa.second > res[aa.first])continue;
			else if (res[top] + aa.second == res[aa.first]) {
				prev[aa.first] = min(top, prev[aa.first]);
				continue;
			}
			res[aa.first] = aa.second + res[top];
			prev[aa.first] = top;
			priq.push({ res[aa.first], aa.first });
		}
	}

	for (int i = g; i != -1; i = prev[i])path.push_back(i);

	return res;
}