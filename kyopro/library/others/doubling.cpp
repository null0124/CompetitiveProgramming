struct doubling {

	int n, log_k;
	vector<vector<int>> a;
	const function<int(int, int)> f1, f2;

	doubling(int n, ll k, function<int(int, int)> f1, function<int(int, int)> f2) : n(n), f1(f1), f2(f2) {
		log_k = ceil(log2(k));
		a.assign(log_k + 1, vector<int>(n, -1));
	}

	//i 番目の要素のセットではなく一つ先の要素のセットであることに注意
	void set(int i, int x) {
		a[0][i] = x;
	}

	void build() {
		for (int i = 0; i < log_k; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == -1) a[i + 1][j] = -1;
				else a[i + 1][j] = f1(a[i + 1][j], a[i][a[i][j]]);
			}
		}
	}

	//k 番目の要素の x 個先を求める
	int query(int k, ll x) {
		for (int i = log_k; i >= 0; --i) {
			if (k == -1)break;
			else if ((x >> (ll)i) & 1LL) k = f2(k, a[i][k]);
		}
		return k;
	}

};
