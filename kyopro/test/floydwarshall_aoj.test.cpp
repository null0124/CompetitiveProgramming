#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../library/template/template.cpp"
#include "../library/graph/floydwarshall.cpp"

int main() {

	int v, e;
	scanf("%d%d", &v, &e);
	vector<vector<ll>> g(v, vector<ll>(v));
	rep(i, v)fill(all(g[i]), LINF / 2);
	rep(i, v)g[i][i] = 0;
	while (e--) {
		int s, t, d;
		scanf("%d%d%d", &s, &t, &d);
		g[s][t] = d;
	}
	WarshallFloyd(v, g);
	rep(i, v) {
		if (g[i][i] < 0) {
			puts("NEGATIVE CYCLE");
			Please AC;
		}
	}
	rep(i, v) {
		rep(j, v) {
			if (g[i][j] >= LINF / 4)printf("INF");
			else printf("%lld", g[i][j]);
			if (j != v - 1)printf(" ");
			else puts("");
		}
	}

	Please AC;
}