#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"


#include "../library/template/template.cpp"

#include "../library/graph/graph_template.cpp"
#include "../library/graph/scc.cpp"


int main() {

	int v, e;
	scanf("%d%d", &v, &e);
	graph<int> g(v, true, false);
	g.read(e, false);
	stronglyconnectedcomponents<int> s(v, g);
	s.build();
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &v, &e);
		printf("%d\n", (s[v] == s[e]));
	}

	Please AC;
}