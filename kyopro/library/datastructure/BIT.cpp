/*
* @title binary-indexed-tree
* @docs kyopro/docs/BIT.md
*/

template<typename T>
//0-indexed/内部的に 1-indexed
struct BIT {
	vector<T> tree;
	//初期化
	BIT(int n) : tree(n) {
		tree.assign(n + 1, 0);
	}

	int LSB(int n) { return (n & (-n)); }

	//[0, n) の sum を返す/0-indexed
	T sum(int n) {
		T ret = 0;
		//実は 1-indexed だが半開区間なので見た目がそのまま
		for (; n >= 0; n -= LSB(n)) {
			ret += tree[n];
			if (!n)break;
		}
		return ret;
	}


	//[i, j) の sum を返す/0-indexed
	T sum(int i, int j) {
		return sum(j) - sum(i);
	}

	//n 番目に x を足す
	void add(int n, T x) {
		int siz = tree.size();
		for (++n; n < siz; n += LSB(n))tree[n] += x;
	}
};
