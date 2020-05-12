#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "..\Library\template\template.cpp"

#include "..\Library\DataStructure\unionfind.cpp"

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	unionfind uni(n);
	while (q--) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t)printf("%d\n", uni.same(u, v));
		else uni.unite(u, v);
	}
}