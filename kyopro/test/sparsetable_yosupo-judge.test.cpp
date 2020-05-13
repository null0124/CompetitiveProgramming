#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../library/template/template.cpp"

#include "../library/datastructure/sparsetable.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	rep(i, n)scanf("%d", &a[i]);
	sparsetable<int> rmq(a, n);
	rmq.build();
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", a[rmq.query(l, r)]);
	}

	Please AC;
}