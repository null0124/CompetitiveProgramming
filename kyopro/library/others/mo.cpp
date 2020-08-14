/*
* @title Mo's Algorithm
* @docs kyopro/docs/mo.md
*/

template<typename ADD, typename DEL, typename REM, typename T = int>
struct mo {
	int sqn, q, l, r, p;
	vector<tuple<int, int, int>> query;
	vector<T> ans;

	mo(int n, int q) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), query(q), ans(q) {}

	void insert(int l, int r) {
		query[p++] = { l, r, p };
	}

	void read() {
		for (auto& [left, right, idx] : query) {
			scanf("%d%d", &left, &right);
			idx = p++;
		}
	}



};