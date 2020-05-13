#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../library/template/template.cpp"

#include "../library/datastructure/BIT.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	BIT<ll> bit(n);
	rep(i, n) {
		int a;
		scanf("%d", &a);
		bit.add(i, a);
	}
	while (q--) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t)printf("%d\n", bit.sum(a, b));
		else bit.add(a, b);
	}

	Please AC;
}