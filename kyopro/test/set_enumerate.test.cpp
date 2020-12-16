#define PROBLEM "https://yukicoder.me/problems/no/1293"

#include "../library/template/template.cpp"

#include "../library/datastructure/unionfind.cpp"
#include "../library/datastructure/set_enumerate.cpp"

int main() {

	int n, d, w;
	scanf("%d%d%d", &n, &d, &w);
	set_enumerate car(n), walk(n);
	ll ans = 0;
	rep(i, d) {
		int a, b;
		scanf("%d%d", &a, &b);
		car.unite(a - 1, b - 1);
	}
	rep(i, w) {
		int a, b;
		scanf("%d%d", &a, &b);
		walk.unite(a - 1, b - 1);
	}
	vector<bool> flag(n);
	rep(i, n) {
		if (not flag[i]) {
			auto ushi = car.enumerate(i);
			ll m = 0, x = car.size(i);
			set<int> b;
			for (const auto& aa : ushi)b.insert(walk.find(aa)), flag[aa] = true;
			for (const auto& aa : b)m += walk.size(aa);
			ans += m * x;
			flag[i] = true;
		}
	}
	printf("%lld\n", ans - (ll)n);

	Please AC;
}