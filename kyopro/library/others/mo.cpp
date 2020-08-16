/*
* @title Mo's Algorithm
* @docs kyopro/docs/mo.md
*/

template<typename ADD_LEFT, typename DEL_LEFT, typename REM, typename ADD_RIGHT = ADD_LEFT, typename DEL_RIGHT = DEL_LEFT, typename T = int>
struct mo {
	int sqn, q, l, r, p;
	T ret;
	vector<tuple<int, int, int>> query;
	vector<T> ans;

	mo(const int& n, const int& q) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)), query(q), ans(q) {}

	inline void insert(const int& l, const int& r) {
		query[p] = { l, r, p++ };
	}

	inline void read(const bool& oneindexed) {
		for (auto& [left, right, idx] : query) {
			scanf("%d%d", &left, &right);
			if (oneindexed)--left;
			idx = p++;
		}
	}

	void build() {
		sort(all(query), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
			if (get<0>(a) / sqn != get<0>(b) / sqn)return get<0>(a) < get<0>(b);
			return get<1>(a) < get<1>(b);
			});
	}

	void run(const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const DEL_LEFT& del_left, const DEL_RIGHT& del_right, const REM& rem) {
		for (const auto& [ql, qr, qo] : query) {
			while (l > ql)add_left(--l, ret);
			while (r < qr)add_right(r++, ret);
			while (l < ql)del_left(l++, ret);
			while (r > qr)del_right(--r, ret);
			rem(qo, ans, ret);
		}
	}

	void run(const ADD_LEFT& add, const DEL_LEFT& del, const REM& rem) {
		run(add, add, del, del, rem);
	}

	T operator [](const int& idx) {
		return ans[idx];
	}

	void allrun(const bool& oneindexed, const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const DEL_LEFT& del_left, const DEL_RIGHT& del_right, const REM& rem) {
		read(oneindexed);
		build();
		run(add_left, add_right, del_left, del_right, rem);
	}

	void allrun(const bool& oneindexed, const ADD_LEFT& add, const DEL_LEFT& del, const REM& rem) {
		allrun(oneindexed, add, add, del, del, rem, rem);
	}

};