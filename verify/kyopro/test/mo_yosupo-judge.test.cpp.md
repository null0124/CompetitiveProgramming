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


# :heavy_check_mark: kyopro/test/mo_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/mo_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 14:13:21+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_inversions_query">https://judge.yosupo.jp/problem/static_range_inversions_query</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/datastructure/BIT.cpp.html">binary-indexed-tree</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/others/mo.cpp.html">Mo's Algorithm</a>
* :question: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../library/template/template.cpp"

#include "../library/datastructure/BIT.cpp"
#include "../library/others/mo.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	vector<int> as = a;
	sort(all(as));
	as.erase(unique(all(as)), as.end());
	ll siz = as.size();
	rep(i, n)a[i] = distance(as.begin(), lower_bound(all(as), a[i]));
	BIT<ll> bit(siz);
	auto add_left = [&](const int& idx, ll& ret) {
		ret += bit.sum(0, a[idx]);
		bit.add(a[idx], 1ll);
	};
	auto add_right = [&](const int& idx, ll& ret) {
		ret += bit.sum(a[idx] + 1, siz);
		bit.add(a[idx], 1ll);
	};
	auto del_left = [&](const int& idx, ll& ret) {
		ret -= bit.sum(0, a[idx]);
		bit.add(a[idx], -1ll);
	};
	auto del_right = [&](const int& idx, ll& ret) {
		ret -= bit.sum(a[idx] + 1, siz);
		bit.add(a[idx], -1ll);
	};
	auto rem = [](const int& idx, vector<ll>& ans, const ll& ret) {ans[idx] = ret; };
	mo<decltype(add_left), decltype(del_left), decltype(rem), decltype(add_right), decltype(del_right), ll> m(n, q);
	m.allrun(false, add_left, add_right, del_left, del_right, rem);
	rep(i, q)printf("%lld\n", m[i]);

	Please AC;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/mo_yosupo-judge.test.cpp"
﻿#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

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
#line 4 "kyopro/test/mo_yosupo-judge.test.cpp"

#line 1 "kyopro/library/datastructure/BIT.cpp"
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
#line 7 "kyopro/test/mo_yosupo-judge.test.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	vector<int> as = a;
	sort(all(as));
	as.erase(unique(all(as)), as.end());
	ll siz = as.size();
	rep(i, n)a[i] = distance(as.begin(), lower_bound(all(as), a[i]));
	BIT<ll> bit(siz);
	auto add_left = [&](const int& idx, ll& ret) {
		ret += bit.sum(0, a[idx]);
		bit.add(a[idx], 1ll);
	};
	auto add_right = [&](const int& idx, ll& ret) {
		ret += bit.sum(a[idx] + 1, siz);
		bit.add(a[idx], 1ll);
	};
	auto del_left = [&](const int& idx, ll& ret) {
		ret -= bit.sum(0, a[idx]);
		bit.add(a[idx], -1ll);
	};
	auto del_right = [&](const int& idx, ll& ret) {
		ret -= bit.sum(a[idx] + 1, siz);
		bit.add(a[idx], -1ll);
	};
	auto rem = [](const int& idx, vector<ll>& ans, const ll& ret) {ans[idx] = ret; };
	mo<decltype(add_left), decltype(del_left), decltype(rem), decltype(add_right), decltype(del_right), ll> m(n, q);
	m.allrun(false, add_left, add_right, del_left, del_right, rem);
	rep(i, q)printf("%lld\n", m[i]);

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

