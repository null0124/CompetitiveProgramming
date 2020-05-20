#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../library/template/template.cpp"

#include "../library/others/modint.cpp"
#include "../library/datastructure/segtree.cpp"

using Modint = modint<998244353>;

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	auto f = [](pair<Modint, Modint> x, pair<Modint, Modint> y) {return make_pair(x.first * y.first, y.second + y.first * x.second); };
	segtree<pair<Modint, Modint>> tree(n, { 1, 0 }, f);
	rep(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		tree.set(i, { a, b });
	}
	tree.build();
	int p, c, d, k;
	rep(i, q) {
		scanf("%d%d%d%d", &k, &p, &c, &d);
		if (k) {
			Modint x = d;
			auto f = tree.query(p, c);
			printf("%d\n", (x * f.first + f.second).val);
		}
		else {
			tree.update(p, { c, d });
		}
	}

	Please AC;
}