#define PROBLEM "https://yukicoder.me/problems/no/1069"

#include "../library/template/template.cpp"

#include "../library/graph/kth-shortest-path_yen.cpp"

int main() {

	int n, m, k, x, y;
	scanf("%d%d%d%d%d", &n, &m, &k, &x, &y);
	--x; --y;
	vector<vector<pair<int, long double>>> graph(n);
	vector<pair<int, int>> xy(n);
	set<vector<int>> routememo;
	int p, q;
	rep(i, n) {
		scanf("%d%d", &p, &q);
		xy[i] = { p, q };
	}
	rep(i, m) {
		scanf("%d%d", &p, &q);
		--p; --q;
		long double a = xy[p].first, b = xy[p].second, c = xy[q].first, d = xy[q].second;
		graph[p].push_back({ q, sqrt((c - a) * (c - a) + (d - b) * (d - b)) });
		graph[q].push_back({ p, sqrt((c - a) * (c - a) + (d - b) * (d - b)) });
	}
	vector<vector<int>> path(k);
	vector<long double> ans;
	ksp<long double>(graph, n, x, y, k, path, ans, linf);
	rep(i, k)printLdb(ans[i]);

	Please AC;
}