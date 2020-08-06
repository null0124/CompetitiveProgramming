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


# :heavy_check_mark: kyopro/test/sparsetable_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/sparsetable_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 02:04:20+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/datastructure/sparsetable.cpp.html">sparse-table</a>
* :question: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../library/template/template.cpp"

#include "../library/datastructure/sparsetable.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	rep(i, n)scanf("%d", &a[i]);
	sparsetable<int> rmq(a, n);
	rmq.build();
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", a[rmq.query(l, r)]);
	}

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/sparsetable_yosupo-judge.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

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
#line 4 "kyopro/test/sparsetable_yosupo-judge.test.cpp"

#line 1 "kyopro/library/datastructure/sparsetable.cpp"
/*
* @title sparse-table
* @docs kyopro/docs/sparsetable.md
*/

//RMQ <O(n log n), O(1)>
template<typename T>
struct sparsetable {

	vector<vector<T>> table;
	vector<int> logtable;
	vector<int> a;
	int n;

	// 渡す配列, サイズ
	sparsetable(const vector<T> a, int siz) : n(siz), a(a) {
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//リストバージョン
	sparsetable(initializer_list<T> init) {
		a = init[0];
		n = init[1];
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//配列と大きさを渡して初期化
	void init(const vector<T> aa, int siz) {
		a = aa;
		n = siz;
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//構築 O(n log n)
	void build() {
		for (int k = 0; (1 << k) <= n; ++k) {
			for (int i = 0; i + (1 << k) <= n; ++i) {
				if (k) table[i][k] = (a[table[i][k - 1]] < a[table[i + (1 << (k - 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k - 1))][k - 1]);
				else table[i][k] = i;
			}
		}
	}

	//[l, r) の RMQ O(1)
	int query(int l, int r) {
		int k = logtable[r - l];
		return (a[table[l][k]] < a[table[r - (1 << k)][k]] ? table[l][k] : table[r - (1 << k)][k]);
	}

};

#line 6 "kyopro/test/sparsetable_yosupo-judge.test.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	rep(i, n)scanf("%d", &a[i]);
	sparsetable<int> rmq(a, n);
	rmq.build();
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", a[rmq.query(l, r)]);
	}

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

