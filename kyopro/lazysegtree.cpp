//セグ木/0-indexed/非再帰/n の大きさ, a (単位元), 本体のマージ関数, 遅延ノードの単位元, 遅延ノードのマージ関数, 遅延ノードと本体のマージ関数 で segtree を初期化する
template<typename T, typename U>
struct lazysegtree {
	//木を配列であらわしたもの
	vector<T> seg;
	//遅延ノード
	vector<U> lazy;
	//サイズノード
	vector<int> size;
	//遅延ノードのフラグ管理
	vector<bool> flag;
	//木の1/2の大きさ
	int siz, height;
	//本体の単位元
	const T se;
	//遅延ノードの単位元
	const U le;
	//本体のマージ関数の型
	using F = function<T(T, T)>;
	//遅延ノードのマージ関数の型
	using F2 = function<U(U, U)>;
	//遅延ノードと本体のマージ関数の型
	using F3 = function<T(T, U)>;
	//サイズを使った演算をする関数の型
	using F4 = function<U(U, int)>;
	//本体同士をマージする関数
	const F f;
	//遅延ノード同士をマージする関数
	const F2 f2;
	//遅延ノードと本体をマージする関数
	const F3 f3;
	//サイズを使った演算をする関数
	const F4 f4;

	//n の大きさ, a (単位元), 本体のマージ関数, 遅延ノードの単位元, 遅延ノードのマージ関数, 遅延ノードと本体のマージ関数, サイズを使った演算をする関数 で segtree を初期化する
	lazysegtree(int n, const T se, const F f, const U le, const F2 f2, const F3 f3, const F4 f4) : se(se), f(f), le(le), f2(f2), f3(f3), f4(f4) {
		siz = 1;
		height = 0;
		while (siz < n)siz <<= 1, ++height;
		seg.assign(2 * siz - 1, se);
		lazy.assign(2 * siz - 1, le);
		size.assign(2 * siz - 1, 1);
		flag.assign(2 * siz - 1, false);
		--siz;
	}

	//k (0-indexed) 番目に t を代入
	void set(int k, const T& t) {
		seg[k + siz] = t;
	}

	//f によって木を構築
	void build() {
		for (int i = siz - 1; i >= 0; --i) {
			seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);
			size[i] = size[i * 2 + 1] + size[i * 2 + 2];
		}
	}

	//i 番目の要素を返す
	T operator[](const int i) {
		return query(i, i + 1);
	}

	//k 番目の遅延ノードを伝播する
	inline T merge(int k) {
		return (!flag[k] ? seg[k] : f3(seg[k], f4(lazy[k], size[k])));
	}

	//子に伝播
	inline void eval(int k) {
		if (flag[k]) {
			lazy[k * 2 + 1] = f2(lazy[k * 2 + 1], lazy[k]);
			lazy[k * 2 + 2] = f2(lazy[k * 2 + 2], lazy[k]);
			flag[k * 2 + 1] = flag[k * 2 + 2] = true;
			seg[k] = merge(k);
			lazy[k] = le;
			flag[k] = false;
		}
	}

	inline void bottomup(int k) {
		while (k > 0) {
			k = ((k - 1) >> 1);
			seg[k] = f(merge(2 * k + 1), merge(2 * k + 2));
		}
	}

	inline void topdown(int k) {
		for (int i = height; i > 0; --i) {
			eval(((k + 1) >> i) - 1);
		}
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

	//[l, r) の値を a に更新
	void update(int l, int r, T a) {
		int x = l + siz, y = r + siz - 1;
		topdown(x);
		topdown(y);
		for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
			if (!(l & 1)) {
				lazy[l] = f2(lazy[l], a);
				flag[l] = true;
				++l;
			}
			if (!(r & 1)) {
				--r;
				lazy[r] = f2(lazy[r], a);
				flag[r] = true;
			}
		}
		bottomup(x);
		bottomup(y);
	}

	//[a, b) について f した結果を返す
	T query(int a, int b) {
		topdown(a += siz);
		topdown(b += siz - 1);
		T l = se, r = se;
		for (++b; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1))l = f(l, merge(a++));
			if (!(b & 1))r = f(merge(--b), r);
		}
		return f(l, r);
	}


	////[start, end) について、[l, r) を調べながら k 番目が check を満たすか二分探索 最後が true なら left, false なら right fの逆演算
	//template<typename C>
	//int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const function<T(T, T)> revf) {
	//	//cerr << checknum << '\n';
	//	//範囲外またはそこがすでに満たさないとき
	//	//cerr << k << ',' << checknum << '\n';
	//	if (start <= l && r <= end && !check(seg[k], checknum)) {
	//		checknum = revf(checknum, seg[k]);
	//		return -1;
	//	}
	//	if ((r <= start || l >= end)) {
	//		return -1;
	//	}
	//	//既に葉
	//	if (k >= siz) {
	//		return k - siz;
	//	}
	//	int res;
	//	if (b) {
	//		//左側を調べる
	//		res = find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
	//		//左側が適してたらそれが答え
	//		if (res != -1)return (res);
	//		return find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
	//	}
	//	else {
	//		//右側を調べる
	//		res = find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
	//		//右側が適してたらそれが答え
	//		if (res != -1)return (res);
	//		return find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
	//	}
	//}

	//template<typename C>
	//int find_left(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
	//	return find< C >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	//}

	//template<typename C>
	//int find_right(int start, int end, const C check, T checknum, function<T(T, T)> revf) {
	//	return find< C >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	//}

};
