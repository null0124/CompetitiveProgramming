#define IGNORE
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B"

#include "../library/template/template.cpp"
#include "../library/graph/graph_template.cpp"

#include "../library/graph/topological_sort.cpp"

int main() {

	int v, e;
	scanf("%d%d", &v, &e);
	graph<int> g(v, true, false);
	g.read(e, false);
	for (const auto& ans : topological_sort(g, v))printf("%d\n", ans);

	Please AC;
}