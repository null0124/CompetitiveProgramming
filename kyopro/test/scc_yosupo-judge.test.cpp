#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../library/template/template.cpp"

#include "../library/graph/graph_template.cpp"
#include "../library/graph/scc.cpp"

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	graph<int> g(n, true, false);
	g.read(m, false);
	stronglyconnectedcomponents s(n, g);
	s.build();
	printf("%d", s.size());
	for (const auto& aa : s.vert) {
		printf("\n%d", aa.size());
		for (const auto& aaa : aa)printf(" %d", aaa);
	}
	puts("");

	Please AC;
}