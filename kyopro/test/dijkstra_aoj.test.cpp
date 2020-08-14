#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../library/template/template.cpp"
#include "../library/graph/graph_template.cpp"

#include "../library/graph/dijkstra.cpp"

int main() {

	int v, e, r;
	scanf("%d%d%d", &v, &e, &r);
	graph<ll> g(v, true, true);
	g.read(e, false);
	for (const auto& aa : dijkstra<ll>(g, r, v, LINF)) {
		if (aa == LINF)puts("INF");
		else printf("%lld\n", aa);
	}


	Please AC;
}