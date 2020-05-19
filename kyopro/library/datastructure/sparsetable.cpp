/*
* @title sparse-table
* @docs kyopro/docs/sparsetable.md
*/

//RMQ <O(n log n), O(1)>
template<typename T>
struct sparsetable {

	vector<vector<T>> table;
	vector<int> logtable;
	vector<int> a;
	int n;

	// 渡す配列, サイズ
	sparsetable(const vector<T> a, int siz) : n(siz), a(a) {
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//リストバージョン
	sparsetable(initializer_list<T> init) {
		a = init[0];
		n = init[1];
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//配列と大きさを渡して初期化
	void init(const vector<T> aa, int siz) {
		a = aa;
		n = siz;
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//構築 O(n log n)
	void build() {
		for (int k = 0; (1 << k) <= n; ++k) {
			for (int i = 0; i + (1 << k) <= n; ++i) {
				if (k) table[i][k] = (a[table[i][k - 1]] < a[table[i + (1 << (k - 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k - 1))][k - 1]);
				else table[i][k] = i;
			}
		}
	}

	//[l, r) の RMQ O(1)
	int query(int l, int r) {
		int k = logtable[r - l];
		return (a[table[l][k]] < a[table[r - (1 << k)][k]] ? table[l][k] : table[r - (1 << k)][k]);
	}

};

