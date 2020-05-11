
//セグ木/0-indexed/非再帰/(大きさ, 単位元)で初期化
template<typename T>
struct segtree {
	//木を配列であらわしたもの
	vector<T> seg;
	//木の1/2の大きさ
	int siz;
	//単位元
	const T e;
	//比較関数の型
	using F = function<T(T, T)>;
	//マージする関数
	const F f;

	//n の大きさ, a (単位元) で segtree を初期化する
	segtree(int n, const T a, const F f) : e(a), f(f) {
		siz = 1;
		while (siz < n)siz <<= 1;
		seg.assign(2 * siz - 1, e);
		--siz;
	}

	//k (0-indexed) 番目に t を代入
	void set(int k, const T& t) {
		seg[k + siz] = t;
	}

	//f によって木を構築
	void build() {
		for (int i = siz - 1; i >= 0; --i) seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);
	}

	//i 番目の要素を返す
	T operator[](const int i) {
		return seg[i + siz];
	}

	//k 番目の値を a に更新
	void update(int k, T a) {
		k += siz;
		//必要であればここを変える
		seg[k] = a;
		while (k > 0) {
			k = ((k - 1) >> 1);
			seg[k] = f(seg[k * 2 + 1], seg[k * 2 + 2]);
		}
	}

	//[a, b) について f した結果を返す
	T query(int a, int b) {
		T l = e, r = e;
		for (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1))l = f(l, seg[a++]);
			if (!(b & 1))r = f(seg[--b], r);
		}
		return f(l, r);
	}

	//[start, end) について、[l, r) を調べながら k 番目が check を満たすか二分探索 最後が true なら left, false なら right fの逆演算
	template<typename C>
	int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const function<T(T, T)> revf) {
		//cerr << checknum << '\n';
		//範囲外またはそこがすでに満たさないとき
		//cerr << k << ',' << checknum << '\n';
		if (start <= l && r <= end && !check(seg[k], checknum)) {
			checknum = revf(checknum, seg[k]);
			return -1;
		}
		if ((r <= start || l >= end)) {
			return -1;
		}
		//既に葉
		if (k >= siz) {
			return k - siz;
		}
		int res;
		if (b) {
			//左側を調べる
			res = find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
			//左側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
		}
		else {
			//右側を調べる
			res = find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
			//右側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
		}
	}

	template<typename C>
	int find_left(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
		return find< C >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	}

	template<typename C>
	int find_right(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
		return find< C >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	}

};