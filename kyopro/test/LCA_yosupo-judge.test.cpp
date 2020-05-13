#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../library/template/template.cpp"

#include "../library/datastructure/sparsetable.cpp"

#include "../library/graph/LCA.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<vector<int>> tree(n);
	int p;
	rep(i, n - 1) {
		scanf("%d", &p);
		tree[p].emplace_back(i + 1);
	}
	LCA lca(tree, n, 0);
	int v;
	rep(i, q) {
		scanf("%d%d", &p, &v);
		printf("%d\n", lca.query(p, v));
	}

	Please AC;
}