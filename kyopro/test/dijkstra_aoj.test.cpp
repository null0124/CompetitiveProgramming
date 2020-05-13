#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../library/template/template.cpp"

#include "../library/graph/dijkstra.cpp"

int main() {

	int v, e, r;
	scanf("%d%d%d", &v, &e, &r);
	vector<vector<pair<int, ll>>> graph(v);
	while (e--) {
		int s, t, d;
		scanf("%d%d%d", &s, &t, &d);
		graph[s].emplace_back(t, d);
	}
	for (const auto& aa : dijkstra<ll>(graph, r, v, LINF)) {
		if (aa == LINF)puts("INF");
		else printf("%lld\n", aa);
	}

	Please AC;
}