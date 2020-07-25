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


# :heavy_check_mark: kyopro/test/segtree_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/segtree_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 01:06:15+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/datastructure/segtree.cpp.html">segment-tree</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/others/modint.cpp.html">modint</a>
* :question: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../library/template/template.cpp"

#include "../library/others/modint.cpp"
#include "../library/datastructure/segtree.cpp"

using Modint = modint<998244353>;

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	auto f = [](pair<Modint, Modint> x, pair<Modint, Modint> y) {return make_pair(x.first * y.first, y.second + y.first * x.second); };
	segtree<pair<Modint, Modint>> tree(n, { 1, 0 }, f);
	rep(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		tree.set(i, { a, b });
	}
	tree.build();
	int p, c, d, k;
	rep(i, q) {
		scanf("%d%d%d%d", &k, &p, &c, &d);
		if (k) {
			Modint x = d;
			auto f = tree.query(p, c);
			printf("%d\n", (x * f.first + f.second).val);
		}
		else {
			tree.update(p, { c, d });
		}
	}

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/segtree_yosupo-judge.test.cpp"
﻿#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

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
/*
多倍長整数, cpp_intで宣言
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
*/

//#pragma gcc target ("avx2")
//#pragma gcc optimization ("o3")
//#pragma gcc optimization ("unroll-loops")

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
constexpr ll MOD = 1000000007;
constexpr long double eps = 1e-9;
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
T chmin(T& a, const T& b) {
	if (a > b)a = b;
	return a;
}

template<typename T>
T chmax(T& a, const T& b) {
	if (a < b)a = b;
	return a;
}
#line 4 "kyopro/test/segtree_yosupo-judge.test.cpp"

#line 1 "kyopro/library/others/modint.cpp"
﻿/*
* @title modint
* @docs kyopro/docs/modint.md
*/

template<int mod>
struct modint {
	int val, size;

	vector<ll> fac, inv, facinv;

	modint() : val(0), size(0) {};
	modint(ll x) : val(x >= 0 ? x % mod : (mod + x % mod) % mod), size(0) {};

	//siz <= 1e7 くらい
	void cominit(const int siz) {
		size = siz;
		fac.assign(siz + 1, 0);
		inv.assign(siz + 1, 0);
		facinv.assign(siz + 1, 0);
		fac[0] = fac[1] = facinv[0] = facinv[1] = inv[0] = 1;
		for (ll i = 2; i <= siz; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod % i] * (mod / i) % mod;
			facinv[i] = facinv[i - 1] * inv[i] % mod;
		}
	}

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
		if (x.val <= size) {
			ll num = x.val;
			num *= inv[x.val];
			num %= mod;
			val = num;
			return *this;
		}
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

	modint comb(const modint& n, const modint& r) {
		return (n < r or n < 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % mod)) % mod);
	}

	static int getmod() { return mod; };
};
#line 1 "kyopro/library/datastructure/segtree.cpp"
﻿/*
* @title segment-tree
* @docs kyopro/docs/segtree.md
*/


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
#line 7 "kyopro/test/segtree_yosupo-judge.test.cpp"

using Modint = modint<998244353>;

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	auto f = [](pair<Modint, Modint> x, pair<Modint, Modint> y) {return make_pair(x.first * y.first, y.second + y.first * x.second); };
	segtree<pair<Modint, Modint>> tree(n, { 1, 0 }, f);
	rep(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		tree.set(i, { a, b });
	}
	tree.build();
	int p, c, d, k;
	rep(i, q) {
		scanf("%d%d%d%d", &k, &p, &c, &d);
		if (k) {
			Modint x = d;
			auto f = tree.query(p, c);
			printf("%d\n", (x * f.first + f.second).val);
		}
		else {
			tree.update(p, { c, d });
		}
	}

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

