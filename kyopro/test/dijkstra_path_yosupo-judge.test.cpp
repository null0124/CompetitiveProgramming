#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../library/template/template.cpp"
#include "../library/graph/graph_template.cpp"

#include "../library/graph/dijkstra_path.cpp"

int main() {

	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	graph<ll> g(n, true, true);
	g.read(m, false);
	vector<int> path;
	auto ans = dijkstra<ll>(g, path, s, t, n, LINF, false);
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