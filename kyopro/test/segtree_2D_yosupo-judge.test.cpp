#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../library/template/template.cpp"

#include "../library/datastructure/segtree.cpp"
#include "../library/datastructure/segtree_2d.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<tuple<int, int, int>> a(n);
	for (auto& [x, y, w] : a)scanf("%d%d%d", &x, &y, &w);
	vector<tuple<int, int, int, int, int>> query(q);
	for (auto& [t, l, d, r, u] : query) {
		scanf("%d%d%d%d", &t, &l, &d, &r);
		if (t) {
			scanf("%d", &u);
		}
	}

	int siz = 0;
	//zaatsu
	{
		vector<int> R;
		for (const auto& [x, y, w] : a)R.emplace_back(x);
		for (const auto& [t, l, d, r, u] : query) {
			R.emplace_back(l);
			if (t) {
				R.emplace_back(r);
			}
		}
		sort(all(R));
		R.erase(unique(all(R)), R.end());
		for (auto& [x, y, w] : a) {
			x = distance(R.begin(), lower_bound(all(R), x));
		}
		for (auto& [t, l, d, r, u] : query) {
			l = distance(R.begin(), lower_bound(all(R), l));
			if (t) {
				r = distance(R.begin(), lower_bound(all(R), r));
			}
		}
		siz = R.size();
	}

	auto seg = get_segtree2D(siz, 0ll, plus<ll>());

	for (const auto& [x, y, w] : a)seg.preset(x, y);
	for (const auto& [t, l, d, r, u] : query) {
		seg.preset(l, d);
		if (t) {
			seg.preset(r, u);
		}
	}
	seg.build();
	for (const auto& [x, y, w] : a) {
		seg.update(x, y, w);
	}
	for (const auto& [t, l, d, r, u] : query) {
		if (t) {
			printf("%lld\n", seg.query(l, r, d, u));
		}
		else {
			seg.update(l, d, r);
		}
	}

	Please AC;
}