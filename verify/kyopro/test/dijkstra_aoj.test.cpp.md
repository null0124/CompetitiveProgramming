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


# :heavy_check_mark: kyopro/test/dijkstra_aoj.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/dijkstra_aoj.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-14 03:45:21+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/dijkstra.cpp.html">dijkstra</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/graph_template.cpp.html">template(graph)</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../library/template/template.cpp"
#include "../library/graph/graph_template.cpp"

#include "../library/graph/dijkstra.cpp"

int main() {

	int v, e, r;
	scanf("%d%d%d", &v, &e, &r);
	graph<ll> g(v, true, true);
	g.read(e, false);
	for (const auto& aa : dijkstra<ll>(g, r, v, LINF)) {
		if (aa == LINF)puts("INF");
		else printf("%lld\n", aa);
	}


	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/dijkstra_aoj.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

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
constexpr ll mod = 998244353;
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
#line 1 "kyopro/library/graph/graph_template.cpp"
﻿/*
* @title template(graph)
* @docs kyopro/docs/graph_template.md
*/

template<typename T>
struct edge {
	T cost;
	int from, to;

	edge(int from, int to) : from(from), to(to), cost(T(1)) {}
	edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template<typename T = int>
struct graph {

	int n;
	bool directed, weighted;

	vector<vector<edge<T>>> g;

	graph(int n, bool directed, bool weighted) : g(n), n(n), directed(directed), weighted(weighted) {}

	void add_edge(int from, int to, T cost = T(1)) {
		g[from].emplace_back(from, to, cost);
		if (not directed) {
			g[to].emplace_back(to, from, cost);
		}
	}

	vector<edge<T>>& operator[](const int& idx) {
		return g[idx];
	}

	void read(int e, bool one_indexed) {
		int a, b, c = 1;
		while (e--) {
			scanf("%d%d", &a, &b);
			if (weighted) {
				scanf("%d", &c);
			}
			if (one_indexed)--a, --b;
			add_edge(a, b, c);
		}
	}

	void read(int e, bool one_indexed, const string &format) {
		int a, b;
		T c = T(1);
		while (e--) {
			scanf("%d%d", &a, &b);
			if (weighted) {
				scanf(format, &c);
			}
			if (one_indexed)--a, --b;
			add_edge(a, b, c);
		}
	}

};
#line 5 "kyopro/test/dijkstra_aoj.test.cpp"

#line 1 "kyopro/library/graph/dijkstra.cpp"
﻿/*
* @title dijkstra
* @docs kyopro/docs/dijkstra.md
*/


template<typename T = int>
vector<T> dijkstra(graph<T>& g, const int& v, const int& n, const T Inf) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		for (const auto& aa : g[top]) {
			if (res[top] + aa.cost >= res[aa.to])continue;
			res[aa.to] = aa.cost + res[top];
			priq.push({ res[aa.to], aa.to });
		}
	}
	return res;
}
#line 7 "kyopro/test/dijkstra_aoj.test.cpp"

int main() {

	int v, e, r;
	scanf("%d%d%d", &v, &e, &r);
	graph<ll> g(v, true, true);
	g.read(e, false);
	for (const auto& aa : dijkstra<ll>(g, r, v, LINF)) {
		if (aa == LINF)puts("INF");
		else printf("%lld\n", aa);
	}


	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

