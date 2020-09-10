#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0366"

#include "../library/template/template.cpp"

#include "../library/graph/graph_template.cpp"
#include "../library/graph/scc.cpp"

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	graph g(n, true, false);
	g.read(m, false);
	stronglyconnectedcomponents st(n, g);
	st.build();
	vector<int> in(st.size()), out(st.size());
	rep(i, st.size()) {
		for (const auto& aa : st.cg[i]) {
			++in[aa.to];
			++out[aa.from];
		}
	}
	int ans1 = 0, ans2 = 0;
	rep(i, st.size()) {
		if (not in[i])++ans1;
		if (not out[i])++ans2;
	}
	if (st.size() == 1)ans1 = ans2 = 0;
	printf("%d\n", max(ans1, ans2));

	Please AC;
}