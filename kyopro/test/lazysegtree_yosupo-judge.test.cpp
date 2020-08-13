#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../library/template/template.cpp"

#include "../library/others/modint.cpp"
#include "../library/datastructure/lazysegtree.cpp"

inline auto f2 = [](pair<Modint, Modint> a, pair<Modint, Modint> b) {
	return make_pair(a.first * b.first, a.second * b.first + b.second);
};
inline auto f3 = [](Modint a, pair<Modint, Modint> b) {
	return a * b.first + b.second;
};
inline auto f4 = [](pair<Modint, Modint> a, int siz) {
	return make_pair(a.first, a.second * siz);
};

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	lazysegtree<Modint, pair<Modint, Modint>, decltype(plus<Modint>()), decltype(f2), decltype(f3), decltype(f4)> seg(n, 0, plus<Modint>(), make_pair(1, 0), f2, f3, f4);
	Modint tmp;
	rep(i, n) {
		scanf("%d", &tmp.val);
		seg.set(i, tmp);
	}
	seg.build();
	int type, l, r, b, c;
	while (q--) {
		scanf("%d%d%d", &type, &l, &r);
		if (type) {
			printf("%d\n", seg.query(l, r).val);
		}
		else {
			scanf("%d%d", &b, &c);
			seg.update(l, r, make_pair(b, c));
		}
	}

	Please AC;
}