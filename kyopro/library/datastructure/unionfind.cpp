/*
* @title unionfind
* @docs kyopro/docs/unionfind.md
*/

//0-indexed
struct unionfind {
	vector<int> par, siz;

	unionfind(int n) : par(n), siz(n) {
		for (int i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	void init(int n) {
		par.resize(n);
		siz.resize(n);
		for (int i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	//根を返す
	int find(int a) {
		return par[a] == a ? a : par[a] = find(par[a]);
	}

	//くっつける。元から同じだったらfalseを返す
	bool unite(int a, int b) {
		int x = find(a), y = find(b);
		if (x == y)return false;
		else if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		}
		else if (siz[x] > siz[y]) {
			par[y] = x;
			siz[x] += siz[y];
		}
		else {
			par[x] = y;
			siz[y] += siz[x];
		}
		return true;
	}

	//同じ集合か判定する
	bool same(int a, int b) {
		return find(a) == find(b);
	}

	//サイズを返す
	int size(int a) {
		return siz[find(a)];
	}

};
