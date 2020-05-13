#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C"

#include "../library/template/template.cpp"

#include "../library/math/gcd_lcm.cpp"

int main() {

	int n, ans = 1, a;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		ans = lcm(ans, a);
	}
	printf("%d\n", ans);

	Please AC;
}