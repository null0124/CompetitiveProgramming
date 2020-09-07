/*
* @title tree diameter(木の直径)
* @docs kyopro/docs/tree-diameter.md
*/

template<typename T = int>
void diameter1(graph<T>& g, const int& cur, const int& bef, const T& cnt, T& ma, int& idx) {
	if (cnt > ma)ma = cnt, idx = cur;
	for (const auto& aa : g[cur]) if (aa.to != bef)diameter1<T>(g, aa.to, cur, cnt + aa.cost, ma, idx);
}

template<typename T = int>
void diameter2(graph<T>& g, const int& cur, const int& bef, vector<int>& ret, vector<int>& route, const T& cnt, T& cost) {
	route.emplace_back(cur);
	if (g[cur].size() == 1 and cost < cnt) {
		cost = cnt;
		ret = route;
	}
	for (const auto& aa : g[cur])if (aa.to != bef)diameter2<T>(g, aa.to, cur, ret, route, cnt + aa.cost, cost);
	route.pop_back();
}

template<typename T = int>
vector<int> diameter(graph<T>& g, T& cost, const int& cur = 0) {
	T ma = 0;
	int idx = cur;
	diameter1<T>(g, cur, -1, (T)0, ma, idx);
	ma = 0;
	vector<int> ret, route;
	diameter2<T>(g, idx, -1, ret, route, 0, cost);
	reverse(all(ret));
	return ret;
}