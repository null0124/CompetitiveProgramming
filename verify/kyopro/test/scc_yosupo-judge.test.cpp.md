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


# :heavy_check_mark: kyopro/test/scc_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/scc_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 14:13:21+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/graph_template.cpp.html">template(graph)</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/scc.cpp.html">strongly connected components(強連結成分分解)</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../library/template/template.cpp"

#include "../library/graph/graph_template.cpp"
#include "../library/graph/scc.cpp"

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	graph<int> g(n, true, false);
	g.read(m, false);
	stronglyconnectedcomponents s(n, g);
	s.build();
	printf("%d", s.size());
	for (const auto& aa : s.vert) {
		printf("\n%d", aa.size());
		for (const auto& aaa : aa)printf(" %d", aaa);
	}
	puts("");

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/scc_yosupo-judge.test.cpp"
﻿#define PROBLEM "https://judge.yosupo.jp/problem/scc"

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
#line 4 "kyopro/test/scc_yosupo-judge.test.cpp"

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
				scanf(format, &c);
			}
			if (one_indexed)--a, --b;
			add_edge(a, b, c);
		}
	}

};
#line 1 "kyopro/library/graph/scc.cpp"
﻿/*
* @title strongly connected components(強連結成分分解)
* @docs kyopro/docs/scc.md
*/

template<typename T = int>
struct stronglyconnectedcomponents {

	int n, cur = 0;
	//g: 元のグラフ, gg: 逆張りグラフ, cg: 強連結成分で圧縮したグラフ, sg: 強連結成分だけのグラフ
	graph<T> g, cg, sg, gg;
	vector<int> num, siz;
	vector<vector<int>> vert;

	stronglyconnectedcomponents(const int& n, graph<T>& g) : n(n), g(g), cg(n, g.directed, g.weighted), sg(n, g.directed, g.weighted), gg(n, g.directed, g.weighted), num(n) {
		rep(i, n) for (const auto& aa : g[i])gg.add_edge(aa.to, aa.from, aa.cost);
	}

	void dfs(const int& now, stack<int>& st, vector<bool>& visited) {
		visited[now] = true;
		for (const auto& aa : g[now])if (not visited[aa.to])dfs(aa.to, st, visited);
		st.push(now);
	}

	void build() {
		stack<int> s, st;
		vector<bool> visited(n);
		rep(i, n) {
			if (not visited[i]) dfs(i, st, visited);
		}
		fill(all(visited), false);
		while (not st.empty()) {
			int v = st.top();
			st.pop();
			if (not visited[v]) {
				s.push(v);
				while (not s.empty()) {
					int ver = s.top();
					s.pop();
					num[ver] = cur;
					for (const auto& aa : gg[ver]) if (not visited[aa.to])s.push(aa.to);
					visited[ver] = true;
				}
				++cur;
			}
		}
		siz.assign(cur, 1);
		vert.assign(cur, {});
		fill(all(visited), false);
		rep(i, n) {
			if (not visited[i])vert[num[i]].push_back(i);
			visited[i] = true;
			for (const auto& aa : g[i]) {
				if (num[aa.to] == num[i]) {
					sg.add_edge(aa.from, aa.to, aa.cost);
					if (not visited[aa.to]) {
						++siz[num[aa.to]];
						visited[aa.to] = true;
						vert[num[i]].push_back(aa.to);
					}
				}
				else {
					cg.add_edge(num[aa.from], num[aa.to], aa.cost);
				}
			}
		}
	}

	int operator[](const int& i) { return num[i]; }

	int size() { return cur; }
	int size(const int& i) { return siz[i]; }

};
#line 7 "kyopro/test/scc_yosupo-judge.test.cpp"

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	graph<int> g(n, true, false);
	g.read(m, false);
	stronglyconnectedcomponents s(n, g);
	s.build();
	printf("%d", s.size());
	for (const auto& aa : s.vert) {
		printf("\n%d", aa.size());
		for (const auto& aaa : aa)printf(" %d", aaa);
	}
	puts("");

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

