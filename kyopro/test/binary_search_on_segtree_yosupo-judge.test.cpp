#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../library/template/template.cpp"

#include "../library/datastructure/segtree.cpp"
#include "../library/others/mo.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n), b;
	rep(i, n)scanf("%d", &a[i]);
	b = a;
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	rep(i, n)a[i] = distance(b.begin(), lower_bound(all(b), a[i]));
	segtree<int, decltype(plus<int>())> seg(200001, 0, plus<int>());
	seg.build();
	auto f = [](const int& a, const int& b) {return a >= b; };
	auto f2 = [](const int& a, const int& b) {return a - b; };
	auto add = [&](const int& idx, int& ret) {
		seg.update(a[idx], seg[a[idx]] + 1);
	};
	auto del = [&](const int& idx, int& ret) {
		seg.update(a[idx], seg[a[idx]] - 1);
	};
	vector<tuple<int, int, int>> query(q);
	auto rem = [&](const int& num, vector<int>& ans, int& ret) {
		ans[num] = b[seg.find_left<decltype(f), decltype(f2)>(0, 200001, f, get<2>(query[num]) + 1, f2)];
	};
	mo<decltype(add), decltype(del), decltype(rem)> m(n, q);
	for (auto& [l, r, k] : query) {
		scanf("%d%d%d", &l, &r, &k);
		m.insert(l, r);
	}
	m.build();
	m.run(add, del, rem);
	rep(i, q)printf("%d\n", m[i]);

	Please AC;
}