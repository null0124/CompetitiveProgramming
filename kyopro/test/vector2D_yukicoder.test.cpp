#define PROBLEM "https://yukicoder.me/problems/no/1144"

#include "../library/template/template.cpp"
#include "../library/others/modint.cpp"

#include "../library/geometry/vector2D.cpp"

int main() {

	int n;
	scanf("%d", &n);
	vector<pair<int, int>> p(n);
	for (auto& [x, y] : p) scanf("%d%d", &x, &y);
	modint<MOD> ans;
	vector<vector2D> q;
	rep(i, n) {
		q.clear();
		rep(j, n) {
			if (i == j or p[i] == p[j])continue;
			else if (p[j].second - p[i].second >= 0)q.emplace_back(vector2D(p[i].first, p[i].second, p[j].first, p[j].second));
			else q.emplace_back(vector2D(p[i].first, p[i].second, p[j].first, p[j].second) * -1);
		}
		int m = q.size();
		vector2D r;
		sort(all(q), comp);
		for (int j = m - 1; j >= 0; --j) {
			r = r + q[j];
			ans += vectorproduct(q[j], r);
		}
	}
	ans /= 3;
	printf("%d\n", ans.val);

	Please AC;
}