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


# :heavy_check_mark: kyopro/test/dijkstra_path_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/dijkstra_path_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:51:47+09:00


* see: <a href="https://judge.yosupo.jp/problem/shortest_path">https://judge.yosupo.jp/problem/shortest_path</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/dijkstra_path.cpp.html">dijkstra(経路復元)</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/graph_template.cpp.html">template(graph)</a>
* :question: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../library/template/template.cpp"
#include "../library/graph/graph_template.cpp"

#include "../library/graph/dijkstra_path.cpp"

int main() {

	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	graph<ll> g(n, true, true);
	g.read(m, false);
	vector<int> path;
	auto ans = dijkstra<ll>(g, path, s, t, n, LINF, false);
	int siz = (int)path.size() - 1;
	if (ans[t] == LINF) {
		puts("-1");
		return AC;
	}
	printf("%lld %d\n", ans[t], siz);
	rep(i, siz) {
		printf("%d %d\n", path[i], path[i + 1]);
	}

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/dijkstra_path_yosupo-judge.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

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

	void read(int e, bool one_indexed, const string& format) {
		int a, b;
		T c = T(1);
		while (e--) {
			scanf("%d%d", &a, &b);
			if (weighted) {
				scanf(format.c_str(), &c);
			}
			if (one_indexed)--a, --b;
			add_edge(a, b, c);
		}
	}

};
#line 5 "kyopro/test/dijkstra_path_yosupo-judge.test.cpp"

#line 1 "kyopro/library/graph/dijkstra_path.cpp"
﻿/*
* @title dijkstra(経路復元)
* @docs kyopro/docs/dijkstra_path.md
*/

template<typename T>
vector<T> dijkstra(graph<T>& gh, vector<int>& path, const int& v, const int& g, const int& n, const T Inf, const bool f) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	vector<int> prev(n);
	fill(all(prev), -1);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		auto now = priq.top();
		top = now.second;
		priq.pop();
		if (res[top] < now.first)continue;
		for (const auto& aa : gh[top]) {
			if (res[top] + aa.cost > res[aa.to])continue;
			else if (res[top] + aa.cost == res[aa.to]) {
				if (f) prev[aa.to] = min(top, prev[aa.to]);
				continue;
			}
			res[aa.to] = aa.cost + res[top];
			prev[aa.to] = top;
			priq.push({ res[aa.to], aa.to });
		}
	}

	for (int i = g; i != -1; i = prev[i])path.push_back(i);

	reverse(all(path));

	return res;
}
#line 7 "kyopro/test/dijkstra_path_yosupo-judge.test.cpp"

int main() {

	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	graph<ll> g(n, true, true);
	g.read(m, false);
	vector<int> path;
	auto ans = dijkstra<ll>(g, path, s, t, n, LINF, false);
	int siz = (int)path.size() - 1;
	if (ans[t] == LINF) {
		puts("-1");
		return AC;
	}
	printf("%lld %d\n", ans[t], siz);
	rep(i, siz) {
		printf("%d %d\n", path[i], path[i + 1]);
	}

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

