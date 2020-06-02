/*
* @title kth-shortest-path(yen's algorithm)
* @docs kyopro/docs/kth-shortest-path_yen.md
*/


template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& graph, vector<int>& path, const int& v, const int& g, const int& n, const T Inf, const vector<vector<bool>>& deleted, set<int> r) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	vector<int> prev(n);
	fill(all(prev), -1);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		for (const auto& aa : graph[top]) {
			if (res[top] + aa.second >= res[aa.first] or deleted[top][aa.first] or r.find(aa.first) != r.end())continue;
			res[aa.first] = aa.second + res[top];
			prev[aa.first] = top;
			priq.push({ res[aa.first], aa.first });
		}
	}

	for (int i = g; i != -1; i = prev[i])path.push_back(i);
	reverse(all(path));

	return res;
}

template<typename T>
void ksp(const vector<vector<pair<int, T>>>& graph, const int& n, const int& start, const int& goal, const int& k, vector<vector<int>>& path, vector<T>& ans, const T& Inf) {
	set<vector<int>> routememo;
	vector<T> res, anstmp;
	vector<vector<bool>> deleted(n, vector<bool>(n));
	ans.resize(k);
	path.resize(k);
	res = dijkstra<T>(graph, path[0], start, goal, n, Inf, deleted, {});
	ans[0] = res[goal];
	anstmp = res;
	routememo.insert(path[0]);
	auto func = [](const tuple<T, vector<int>, vector<T>>& a, const tuple<T, vector<int>, vector<T>>& b) -> bool {
		if (get<0>(a) != get<0>(b))return get<0>(a) > get<0>(b);
		else if (get<1>(a) != get<1>(b))return get<1>(a) > get<1>(b);
		else return get<2>(a) > get<2>(b);
	};
	priority_queue<tuple<T, vector<int>, vector<T>>, vector<tuple<T, vector<int>, vector<T>>>, decltype(func)> priq{ func };
	map<vector<int>, vector<int>> spurnode;
	rep(i, k - 1) {
		int siz = path[i].size();
		vector<int> route;
		set<int> r;
		T cost = 0;
		rep(j, siz - 1) {
			route.push_back(path[i][j]);
			r.insert(path[i][j]);
			spurnode[route].push_back(path[i][j + 1]);
			if (j != 0) {
				for (const auto& aa : graph[path[i][j - 1]]) {
					if (aa.first == path[i][j]) {
						cost += aa.second;
						break;
					}
				}
			}
			for (const auto& aa : spurnode[route])deleted[path[i][j]][aa] = deleted[aa][path[i][j]] = true;
			if (j > 0)deleted[path[i][j - 1]][path[i][j]] = deleted[path[i][j]][path[i][j - 1]] = true;
			res = dijkstra<T>(graph, path[i + 1], path[i][j], goal, n, Inf, deleted, r);
			if (j > 0)deleted[path[i][j - 1]][path[i][j]] = deleted[path[i][j]][path[i][j - 1]] = false;
			for (const auto& aa : spurnode[route])deleted[path[i][j]][aa] = deleted[aa][path[i][j]] = false;
			if (res[goal] >= Inf)continue;
			vector<int> tmp;
			vector<T> tmp2(n);
			for (int l = 0; l <= j; ++l) {
				tmp2[path[i][l]] = anstmp[path[i][l]];
			}
			int l = 0;
			for (; path[i][l] != path[i][j]; ++l) {
				tmp2[path[i][l]] = anstmp[path[i][l]];
				tmp.push_back(path[i][l]);
			}
			for (l = 0; path[i + 1][l] != goal; ++l) {
				tmp2[path[i + 1][l]] = res[path[i + 1][l]];
				tmp.push_back(path[i + 1][l]);
			}
			tmp.push_back(goal);
			int siz2 = path[i + 1].size();
			for (int l = 1; l < siz2; ++l) tmp2[path[i + 1][l]] = res[path[i + 1][l]] + anstmp[path[i][j]];
			priq.push(make_tuple(cost + res[goal], tmp, tmp2));
		}
		if (priq.empty()) {
			for (; i < k - 1; ++i)ans[i + 1] = -1;
			break;
		}
		auto tmp = priq.top();
		priq.pop();
		while (routememo.find(get<1>(tmp)) != routememo.end() and !priq.empty()) {
			tmp = priq.top();
			priq.pop();
		}
		if (routememo.find(get<1>(tmp)) != routememo.end() and priq.empty()) {
			for (; i < k - 1; ++i)ans[i + 1] = -1;
			break;
		}
		path[i + 1] = get<1>(tmp);
		ans[i + 1] = get<0>(tmp);
		routememo.insert(path[i + 1]);
	}
	return;
}