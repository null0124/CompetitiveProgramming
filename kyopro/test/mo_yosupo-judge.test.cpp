#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../library/template/template.cpp"

#include "../library/datastructure/BIT.cpp"
#include "../library/others/mo.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	vector<int> as = a;
	sort(all(as));
	as.erase(unique(all(as)), as.end());
	ll siz = as.size();
	rep(i, n)a[i] = distance(as.begin(), lower_bound(all(as), a[i]));
	BIT<ll> bit(siz);
	auto add_left = [&](const int& idx, ll& ret) {
		ret += bit.sum(0, a[idx]);
		bit.add(a[idx], 1ll);
	};
	auto add_right = [&](const int& idx, ll& ret) {
		ret += bit.sum(a[idx] + 1, siz);
		bit.add(a[idx], 1ll);
	};
	auto del_left = [&](const int& idx, ll& ret) {
		ret -= bit.sum(0, a[idx]);
		bit.add(a[idx], -1ll);
	};
	auto del_right = [&](const int& idx, ll& ret) {
		ret -= bit.sum(a[idx] + 1, siz);
		bit.add(a[idx], -1ll);
	};
	auto rem = [](const int& idx, vector<ll>& ans, const ll& ret) {ans[idx] = ret; };
	mo<decltype(add_left), decltype(del_left), decltype(rem), decltype(add_right), decltype(del_right), ll> m(n, q);
	m.allrun(false, add_left, add_right, del_left, del_right, rem);
	rep(i, q)printf("%lld\n", m[i]);

	Please AC;
}
