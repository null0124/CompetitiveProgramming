struct doubling {

	int n, log_k;
	vector<vector<int>> a;

	doubling(int n, ll k) : n(n) {
		log_k = ceil(log2(k));
		a.assign(log_k + 1, vector<int>(n, -1));
	}

	//i �Ԗڂ̗v�f�̃Z�b�g�ł͂Ȃ����̗v�f�̃Z�b�g�ł��邱�Ƃɒ���
	void set(int i, int x) {
		a[0][i] = x;
	}

	void build() {
		for (int i = 0; i < log_k; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == -1) a[i + 1][j] = -1;
				else a[i + 1][j] = a[i][a[i][j]];
			}
		}
	}

	//k �Ԗڂ̗v�f�� x ������߂�
	int query(int k, ll x) {
		for (int i = log_k; i >= 0; --i) {
			if (k == -1)break;
			else if ((x >> (ll)i) & 1LL) k = a[i][k];
		}
		return k;
	}

};