#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"

#include "../library/template/template.cpp"

#include "../library/graph/graph_template.cpp"
#include "../library/graph/tree-diameter.cpp"

int main() {

	int n;
	scanf("%d", &n);
	graph<int> g(n, false, true);
	g.read(n - 1, false);
	int ans = 0;
	diameter(g, ans);
	printf("%d\n", ans);

	Please AC;
}