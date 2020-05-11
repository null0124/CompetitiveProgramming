#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../Library/template/template.cpp"

#include "../Library/DataStructure/unionfind.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	unionfind uni(n);
	while (q--) {
		int t, v, u;
		scanf("%d%d%d", &t, &v, &u);
		if (t)printf("%d\n", uni.same(v, u));
		else uni.unite(v, u);
	}

	Please AC;
}