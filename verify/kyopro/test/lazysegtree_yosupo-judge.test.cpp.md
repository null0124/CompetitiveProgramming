---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: kyopro/test/lazysegtree_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/lazysegtree_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 14:13:21+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/datastructure/lazysegtree.cpp.html">lazy-segment-tree</a>
* :question: <a href="../../../library/kyopro/library/others/modint.cpp.html">modint</a>
* :question: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../library/template/template.cpp"

#include "../library/others/modint.cpp"
#include "../library/datastructure/lazysegtree.cpp"

inline auto f2 = [](pair<Modint, Modint> a, pair<Modint, Modint> b) {
	return make_pair(a.first * b.first, a.second * b.first + b.second);
};
inline auto f3 = [](Modint a, pair<Modint, Modint> b) {
	return a * b.first + b.second;
};
inline auto f4 = [](pair<Modint, Modint> a, int siz) {
	return make_pair(a.first, a.second * siz);
};

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	lazysegtree<Modint, pair<Modint, Modint>, decltype(plus<Modint>()), decltype(f2), decltype(f3), decltype(f4)> seg(n, 0, plus<Modint>(), make_pair(1, 0), f2, f3, f4);
	Modint tmp;
	rep(i, n) {
		scanf("%d", &tmp.val);
		seg.set(i, tmp);
	}
	seg.build();
	int type, l, r, b, c;
	while (q--) {
		scanf("%d%d%d", &type, &l, &r);
		if (type) {
			printf("%d\n", seg.query(l, r).val);
		}
		else {
			scanf("%d%d", &b, &c);
			seg.update(l, r, make_pair(b, c));
		}
	}

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/lazysegtree_yosupo-judge.test.cpp"
﻿#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#line 1 "kyopro/library/template/template.cpp"
﻿/*
* @title template
* @docs kyopro/docs/template.md
*/


/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>
#include <regex>
#include <functional>
#include <complex>
#include <list>
#include <cassert>
#include <iomanip>
#include <set>
#include <stack>
#include <bitset>

////多倍長整数, cpp_intで宣言
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define repeat(i, n, m) for(int i = n; i < (m); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a) //少数出力
#define printLdb(a) printf("%.50Lf\n", a) //少数出力
#define printdbd(a) printf("%.16lf\n", a) //少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str()) //string出力
#define all(x) (x).begin(), (x).end()
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b) から (c, d) のマンハッタン距離 */
#define inf numeric_limits<double>::infinity();
#define linf numeric_limits<long double>::infinity()

using ll = long long;
using ull = unsigned long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1e9 + 7;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-6;
const long double PI = acosl(-1.0L);

using namespace std;

void scans(string& str) {
	char c;
	str = "";
	scanf("%c", &c);
	if (c == '\n')scanf("%c", &c);
	while (c != '\n' && c != -1 && c != ' ') {
		str += c;
		scanf("%c", &c);
	}
}

void scanc(char& str) {
	char c;
	scanf("%c", &c);
	if (c == -1)return;
	while (c == '\n') {
		scanf("%c", &c);
	}
	str = c;
}

double acot(double x) {
	return PI / 2 - atan(x);
}

ll LSB(ll n) { return (n & (-n)); }

template<typename T>
inline T chmin(T& a, const T& b) {
	if (a > b)a = b;
	return a;
}

template<typename T>
inline T chmax(T& a, const T& b) {
	if (a < b)a = b;
	return a;
}
#line 4 "kyopro/test/lazysegtree_yosupo-judge.test.cpp"

#line 1 "kyopro/library/others/modint.cpp"
﻿/*
* @title modint
* @docs kyopro/docs/modint.md
*/

template<int mod>
struct modint {
	int val;

	modint() : val(0) {};
	modint(ll x) : val(x >= 0 ? x % mod : (mod + x % mod) % mod) {};

	modint& operator=(const modint& x) {
		val = x.val;
		return *this;
	}

	modint& operator+=(const modint& x) {
		val += x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator-=(const modint& x) {
		val += mod - x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator*=(const modint& x) {
		val = (int)((ll)val * (ll)x.val % mod);
		return *this;
	}

	modint& operator/=(const modint& x) {
		int a = x.val, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		*this *= modint(u);
		return *this;
	}

	modint operator++() {
		val = (val + 1 == mod ? 0 : val + 1);
		return *this;
	}

	modint operator--() {
		val = (val == 0 ? mod - 1 : val - 1);
		return *this;
	}

	modint operator+(const modint& x) const {
		return (modint(*this) += x);
	}

	modint operator-(const modint& x) const {
		return (modint(*this) -= x);
	}

	modint operator*(const modint& x) const {
		return (modint(*this) *= x);
	}

	modint operator/(const modint& x) const {
		return (modint(*this) /= x);
	}

	bool operator==(const modint& x)const {
		return (val == x.val);
	}

	bool operator!=(const modint& x)const {
		return (val != x.val);
	}

	bool operator<(const modint& x)const {
		return (val < x.val);
	}

	bool operator>(const modint& x)const {
		return (val > x.val);
	}

	modint pow(ll n) {
		modint ret(1), a(val);
		while (n > 0) {
			if (n % 2) ret *= a;
			a *= a;
			n /= 2;
		}
		return ret;
	}

	static int getmod() { return mod; };
};

using ModInt = modint<MOD>;
using Modint = modint<mod>;
#line 1 "kyopro/library/datastructure/lazysegtree.cpp"
﻿/*
* @title lazy-segment-tree
* @docs kyopro/docs/lazysegtree.md
*/

//セグ木/0-indexed/非再帰/n の大きさ, a (単位元), 本体のマージ関数, 遅延ノードの単位元, 遅延ノードのマージ関数, 遅延ノードと本体のマージ関数 で segtree を初期化する
template<typename T, typename U, typename F, typename F2, typename F3, typename F4>
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
	////本体のマージ関数の型
	//using F = function<T(T, T)>;
	////遅延ノードのマージ関数の型
	//using F2 = function<U(U, U)>;
	////遅延ノードと本体のマージ関数の型
	//using F3 = function<T(T, U)>;
	////サイズを使った演算をする関数の型
	//using F4 = function<U(U, int)>;
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
	void update(int l, int r, U a) {
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
	//template<typename C, typename FT>
	//int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const FT revf) {
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
	//		res = find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
	//		//左側が適してたらそれが答え
	//		if (res != -1)return (res);
	//		return find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
	//	}
	//	else {
	//		//右側を調べる
	//		res = find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
	//		//右側が適してたらそれが答え
	//		if (res != -1)return (res);
	//		return find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
	//	}
	//}

	//template<typename C, typename FT>
	//int find_left(int start, int end, const C check, T checknum, FT revf) {
	//	return find< C, FT >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	//}

	//template<typename C, typename FT>
	//int find_right(int start, int end, const C check, T checknum, FT revf) {
	//	return find< C, FT >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	//}

};
#line 7 "kyopro/test/lazysegtree_yosupo-judge.test.cpp"

inline auto f2 = [](pair<Modint, Modint> a, pair<Modint, Modint> b) {
	return make_pair(a.first * b.first, a.second * b.first + b.second);
};
inline auto f3 = [](Modint a, pair<Modint, Modint> b) {
	return a * b.first + b.second;
};
inline auto f4 = [](pair<Modint, Modint> a, int siz) {
	return make_pair(a.first, a.second * siz);
};

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	lazysegtree<Modint, pair<Modint, Modint>, decltype(plus<Modint>()), decltype(f2), decltype(f3), decltype(f4)> seg(n, 0, plus<Modint>(), make_pair(1, 0), f2, f3, f4);
	Modint tmp;
	rep(i, n) {
		scanf("%d", &tmp.val);
		seg.set(i, tmp);
	}
	seg.build();
	int type, l, r, b, c;
	while (q--) {
		scanf("%d%d%d", &type, &l, &r);
		if (type) {
			printf("%d\n", seg.query(l, r).val);
		}
		else {
			scanf("%d%d", &b, &c);
			seg.update(l, r, make_pair(b, c));
		}
	}

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

