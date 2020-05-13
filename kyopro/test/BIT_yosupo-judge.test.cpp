#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../library/template/template.cpp"

#include "../library/datastructure/BIT.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	BIT<ll> bit(n);
	rep(i, n) {
		ll a;
		scanf("%lld", &a);
		bit.add(i, a);
	}
	while (q--) {
		ll t, a, b;
		scanf("%lld%lld%lld", &t, &a, &b);
		if (t)printf("%lld\n", bit.sum(a, b));
		else bit.add(a, b);
	}

	Please AC;
}