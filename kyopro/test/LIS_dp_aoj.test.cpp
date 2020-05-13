#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D"

#include "../library/template/template.cpp"

#include "../library/algorithm/LIS_dp.cpp"

int main() {

	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n)scanf("%d", &a[i]);
	printf("%d\n", lis(n, a, true));

	Please AC;
}