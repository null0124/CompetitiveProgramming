#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../library/template/template.cpp"

#include "../library/graph/graph_template.cpp"
#include "../library/graph/tree-diameter.cpp"

int main() {

	int n;
	scanf("%d", &n);
	graph<ll> g(n, false, true);
	g.read(n - 1, false, "%lld");
	ll ans = 0;
	auto v = diameter<ll>(g, ans);
	printf("%lld %d\n", ans, (int)v.size());
	for (const auto& aa : v)printf("%d ", aa);

	Please AC;
}