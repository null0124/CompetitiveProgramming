/*
* @title segment-tree-2D
* @docs kyopro/docs/segtree_2d.md
*/


template<typename T, typename F>
struct segtree2D {
	//木を配列であらわしたもの
	vector<segtree<T, F>> seg;
	//木の1/2の大きさ
	int siz;
	//単位元
	const T e;
	////比較関数の型
	//using F = function<T(T, T)>;
	//マージする関数
	const F f;
	//座標
	vector<vector<int>> pos;

	//n の大きさ, a (単位元) で segtree を初期化する
	segtree2D(int n, const T a, const F f) : e(a), f(f) {
		siz = 1;
		while (siz < n)siz <<= 1;
		pos.resize(2 * siz - 1);
		--siz;
	}

	//座標 (x, y) を準備
	void preset(int x, int y) {
		x += siz;
		pos[x].push_back(y);
		while (x > 0) {
			x = (x - 1) >> 1;
			pos[x].push_back(y);
		}
	}

	//f によって木を構築
	void build() {
		for (auto& aa : pos) {
			sort(all(aa));
			aa.erase(unique(all(aa)), aa.end());
		}
		for (const auto& aa : pos) {
			seg.emplace_back(get_segtree(aa.size(), e, f));
			seg.back().build();
		}
	}

	//(x, y) の値を a に更新
	void update(int x, int y, T a) {
		x += siz;
		seg[x].update(distance(pos[x].begin(), lower_bound(all(pos[x]), y)), f(seg[x][distance(pos[x].begin(), lower_bound(all(pos[x]), y))], a));
		while (x > 0) {
			x = ((x - 1) >> 1);
			seg[x].update(distance(pos[x].begin(), lower_bound(all(pos[x]), y)), f(seg[x][distance(pos[x].begin(), lower_bound(all(pos[x]), y))], a));
		}
	}

	//x: [a, b) y: [x, y) について f した結果を返す
	T query(int a, int b, int x, int y) {
		T l = e, r = e;
		for (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1)) {
				l = f(l, seg[a].query(distance(pos[a].begin(), lower_bound(all(pos[a]), x)), distance(pos[a].begin(), lower_bound(all(pos[a]), y))));
				++a;
			}
			if (!(b & 1)) {
				--b;
				r = f(seg[b].query(distance(pos[b].begin(), lower_bound(all(pos[b]), x)), distance(pos[b].begin(), lower_bound(all(pos[b]), y))), r);
			}
		}
		return f(l, r);
	}

};

template<typename T, typename F>
segtree2D<T, F> get_segtree2D(int n, const T& e, const F& f) {
	return { n, e, f };
}