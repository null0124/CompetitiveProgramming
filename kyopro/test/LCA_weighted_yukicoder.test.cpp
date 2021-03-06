﻿#define PROBLEM "https://yukicoder.me/problems/no/1094"

#include "../library/template/template.cpp"
#include "../library/graph/graph_template.cpp"

#include "../library/datastructure/sparsetable.cpp"

#include "../library/graph/LCA_weighted.cpp"

int main() {

	int n, q;
	scanf("%d", &n);
	graph tree(n, false, true);
	tree.read(n - 1, true);
	LCA lca(tree, n, 0);
	int v, p;
	scanf("%d", &q);
	rep(i, q) {
		scanf("%d%d", &p, &v);
		--p, --v;
		printf("%d\n", lca.depthq(p) + lca.depthq(v) - 2 * lca.depthq(lca.query(p, v)));
	}

	Please AC;
}
