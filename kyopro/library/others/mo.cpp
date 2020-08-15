/*
* @title Mo's Algorithm
* @docs kyopro/docs/mo.md
*/

template<typename ADD, typename DEL, typename REM, typename T = int>
struct mo {
	int sqn, q, l, r, p;
	T ret;
	vector<tuple<int, int, int>> query;
	vector<T> ans;
	const ADD add;
	const DEL del;
	const REM rem;

	mo(int n, int q, ADD add, DEL del, REM rem) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)), query(q), ans(q), add(add), del(del), rem(rem) {}

	void insert(int l, int r) {
		query[p] = { l, r, p++ };
	}

	void read(bool oneindexed) {
		for (auto& [left, right, idx] : query) {
			scanf("%d%d", &left, &right);
			if (oneindexed)--left, --right;
			idx = p++;
		}
	}

	void build() {
		sort(all(query), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
			const auto& [al, ar, ao] = a;
			const auto& [bl, br, bo] = b;
			int ab = al / sqn, bb = bl / sqn;
			if (ab != bb)return ab < bb;
			return ar < br;
			});
	}

	void run() {
		for (const auto& [ql, qr, qo] : query) {
			while (l > ql)del(--l, ret);
			while (r < qr)add(r++, ret);
			while (l < ql)add(l++, ret);
			while (r > qr)del(--r, ret);
			rem(qo, ans, ret);
		}
	}

	T operator [](const int& idx) {
		return ans[idx];
	}

	void allrun(const bool& oneindexed) {
		read(oneindexed);
		build();
		run();
	}

};
