#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../library/template/template.cpp"

#include "../library/math/prime_factor.cpp"

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		ll a;
		scanf("%lld", &a);
		auto b = prime_factor(a);
		printf("%d\n", (int)b.size());
		for (const auto& [p, q] : b)rep(i, q)printf("%lld\n", p);
	}

	Please AC;
}