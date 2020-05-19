#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../library/template/template.cpp"

#include "../library/graph/dijkstra_path.cpp"

int main() {

	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	vector<vector<pair<int, ll>>> graph(n);
	while (m--) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		graph[a].emplace_back(b, c);
	}
	vector<int> path;
	auto ans = dijkstra<ll>(graph, path, s, t, n, LINF, false);
	int siz = (int)path.size() - 1;
	if (ans[t] == LINF) {
		puts("-1");
		return AC;
	}
	printf("%lld %d\n", ans[t], siz);
	rep(i, siz) {
		printf("%d %d\n", path[i], path[i + 1]);
	}

	Please AC;
}