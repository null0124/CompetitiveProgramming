#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../library/template/template.cpp"
#include "../library/graph/graph_template.cpp"

#include "../library/datastructure/sparsetable.cpp"

#include "../library/graph/LCA.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	graph<int> tree(n, true, false);
	int p;
	rep(i, n - 1) {
		scanf("%d", &p);
		tree.add_edge(p, i + 1);
	}
	LCA lca(tree, n, 0);
	int v;
	rep(i, q) {
		scanf("%d%d", &p, &v);
		printf("%d\n", lca.query(p, v));
	}

	Please AC;
}