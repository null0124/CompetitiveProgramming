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


# :heavy_check_mark: kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-21 21:46:23+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_kth_smallest">https://judge.yosupo.jp/problem/range_kth_smallest</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/datastructure/segtree.cpp.html">segment-tree</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/others/mo.cpp.html">Mo's Algorithm</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../library/template/template.cpp"

#include "../library/datastructure/segtree.cpp"
#include "../library/others/mo.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n), b;
	rep(i, n)scanf("%d", &a[i]);
	b = a;
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	rep(i, n)a[i] = distance(b.begin(), lower_bound(all(b), a[i]));
	segtree<int, decltype(plus<int>())> seg(200001, 0, plus<int>());
	seg.build();
	auto f = [](const int& a, const int& b) {return a >= b; };
	auto f2 = [](const int& a, const int& b) {return a - b; };
	auto add = [&](const int& idx, int& ret) {
		seg.update(a[idx], seg[a[idx]] + 1);
	};
	auto del = [&](const int& idx, int& ret) {
		seg.update(a[idx], seg[a[idx]] - 1);
	};
	vector<tuple<int, int, int>> query(q);
	auto rem = [&](const int& num, vector<int>& ans, int& ret) {
		ans[num] = b[seg.find_left<decltype(f), decltype(f2)>(0, 200001, f, get<2>(query[num]) + 1, f2)];
	};
	mo<decltype(add), decltype(del), decltype(rem)> m(n, q);
	for (auto& [l, r, k] : query) {
		scanf("%d%d%d", &l, &r, &k);
		m.insert(l, r);
	}
	m.build();
	m.run(add, del, rem);
	rep(i, q)printf("%d\n", m[i]);

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp"
﻿#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

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
#line 4 "kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp"

#line 1 "kyopro/library/datastructure/segtree.cpp"
﻿/*
* @title segment-tree
* @docs kyopro/docs/segtree.md
*/


//セグ木/0-indexed/非再帰/(大きさ, 単位元)で初期化
template<typename T, typename F>
struct segtree {
	//木を配列であらわしたもの
	vector<T> seg;
	//木の1/2の大きさ
	int siz;
	//単位元
	const T e;
	////比較関数の型
	//using F = function<T(T, T)>;
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
	template<typename C, typename FT>
	int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const FT revf) {
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
			res = find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
			//左側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
		}
		else {
			//右側を調べる
			res = find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
			//右側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
		}
	}

	template<typename C, typename FT>
	int find_left(int start, int end, const C check, T checknum, FT revf) {
		return find< C, FT >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	}

	template<typename C, typename FT>
	int find_right(int start, int end, const C check, T checknum, FT revf) {
		return find< C, FT >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	}

};
#line 1 "kyopro/library/others/mo.cpp"
﻿/*
* @title Mo's Algorithm
* @docs kyopro/docs/mo.md
*/

template<typename ADD_LEFT, typename DEL_LEFT, typename REM, typename ADD_RIGHT = ADD_LEFT, typename DEL_RIGHT = DEL_LEFT, typename T = int>
struct mo {
	int sqn, q, l, r, p;
	T ret;
	vector<tuple<int, int, int>> query;
	vector<T> ans;

	mo(const int& n, const int& q) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)), query(q), ans(q) {}

	inline void insert(const int& l, const int& r) {
		query[p] = { l, r, p };
		++p;
	}

	inline void read(const bool& oneindexed) {
		for (auto& [left, right, idx] : query) {
			scanf("%d%d", &left, &right);
			if (oneindexed)--left;
			idx = p++;
		}
	}

	void build() {
		sort(all(query), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
			if (get<0>(a) / sqn != get<0>(b) / sqn)return get<0>(a) < get<0>(b);
			return get<1>(a) < get<1>(b);
			});
	}

	void run(const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const DEL_LEFT& del_left, const DEL_RIGHT& del_right, const REM& rem) {
		for (const auto& [ql, qr, qo] : query) {
			while (l > ql)add_left(--l, ret);
			while (r < qr)add_right(r++, ret);
			while (l < ql)del_left(l++, ret);
			while (r > qr)del_right(--r, ret);
			rem(qo, ans, ret);
		}
	}

	void run(const ADD_LEFT& add, const DEL_LEFT& del, const REM& rem) {
		run(add, add, del, del, rem);
	}

	T operator [](const int& idx) {
		return ans[idx];
	}

	void allrun(const bool& oneindexed, const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const DEL_LEFT& del_left, const DEL_RIGHT& del_right, const REM& rem) {
		read(oneindexed);
		build();
		run(add_left, add_right, del_left, del_right, rem);
	}

	void allrun(const bool& oneindexed, const ADD_LEFT& add, const DEL_LEFT& del, const REM& rem) {
		allrun(oneindexed, add, add, del, del, rem, rem);
	}

};
#line 7 "kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n), b;
	rep(i, n)scanf("%d", &a[i]);
	b = a;
	sort(all(b));
	b.erase(unique(all(b)), b.end());
	rep(i, n)a[i] = distance(b.begin(), lower_bound(all(b), a[i]));
	segtree<int, decltype(plus<int>())> seg(200001, 0, plus<int>());
	seg.build();
	auto f = [](const int& a, const int& b) {return a >= b; };
	auto f2 = [](const int& a, const int& b) {return a - b; };
	auto add = [&](const int& idx, int& ret) {
		seg.update(a[idx], seg[a[idx]] + 1);
	};
	auto del = [&](const int& idx, int& ret) {
		seg.update(a[idx], seg[a[idx]] - 1);
	};
	vector<tuple<int, int, int>> query(q);
	auto rem = [&](const int& num, vector<int>& ans, int& ret) {
		ans[num] = b[seg.find_left<decltype(f), decltype(f2)>(0, 200001, f, get<2>(query[num]) + 1, f2)];
	};
	mo<decltype(add), decltype(del), decltype(rem)> m(n, q);
	for (auto& [l, r, k] : query) {
		scanf("%d%d%d", &l, &r, &k);
		m.insert(l, r);
	}
	m.build();
	m.run(add, del, rem);
	rep(i, q)printf("%d\n", m[i]);

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

