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


# :heavy_check_mark: kyopro/test/LCA_yosupo-judge.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/LCA_yosupo-judge.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 16:40:44+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :question: <a href="../../../library/kyopro/library/datastructure/sparsetable.cpp.html">kyopro/library/datastructure/sparsetable.cpp</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/LCA.cpp.html">kyopro/library/graph/LCA.cpp</a>
* :question: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../library/template/template.cpp"

#include "../library/datastructure/sparsetable.cpp"

#include "../library/graph/LCA.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<vector<int>> tree(n);
	int p;
	rep(i, n - 1) {
		scanf("%d", &p);
		tree[p].emplace_back(i + 1);
	}
	LCA lca(tree, n, 0);
	int v;
	rep(i, q) {
		scanf("%d%d", &p, &v);
		printf("%d\n", lca.query(p, v));
	}

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/LCA_yosupo-judge.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#line 1 "kyopro/library/template/template.cpp"
﻿/*
* @title template
*
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
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a) //少数出力
#define printLdb(a) printf("%.50Lf\n", a) //少数出力
#define printdbd(a) printf("%.16lf\n", a) //少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str()) //string出力
#define all(x) (x).begin(), (x).end()
#define allsum(a, b, c) ((a + b) * c / 2LL) //等差数列の和、初項,末項,項数
#define pb push_back
#define rpriq priq<int, vector<int>, greater<int>>
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b) から (c, d) のマンハッタン距離 */
#define inf numeric_limits<double>::infinity();
#define linf numeric_limits<long double>::infinity()


using ll = long long;

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
#line 4 "kyopro/test/LCA_yosupo-judge.test.cpp"

#line 1 "kyopro/library/datastructure/sparsetable.cpp"
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

#line 6 "kyopro/test/LCA_yosupo-judge.test.cpp"

#line 1 "kyopro/library/graph/LCA.cpp"
﻿void eulertour(const int& now, const int& bef, int& cnt, const vector<vector<int>>& graph, const int& d, vector<int>& vs, vector<int>& depth, vector<int>& id) {
	depth.emplace_back(d);
	vs.emplace_back(now);
	id[now] = min(id[now], cnt);
	for (const auto& aa : graph[now]) {
		if (aa != bef) {
			++cnt;
			eulertour(aa, now, cnt, graph, d + 1, vs, depth, id);
			++cnt;
			depth.emplace_back(d);
			vs.emplace_back(now);
		}
	}
}

struct LCA {

	vector<int> vs, depth, id, tmp = { 0 };
	vector<vector<int>> tree;
	sparsetable<int> table{ tmp, 0 };
	int n, root;

	//木,　大きさ, 根
	LCA(vector<vector<int>> tree, int n, int root) : tree(tree), n(n), root(root) {
		id.assign(n, INF);
		int cnt = 0, d = 0;
		eulertour(root, -1, cnt, tree, d, vs, depth, id);
		table.init(depth, depth.size());
		table.build();
	}

	//LCA である頂点を返す
	int query(int l, int r) {
		if (id[l] > id[r])swap(l, r);
		return vs[table.query(id[l], id[r] + 1)];
	}

	int depthq(int n) {
		return depth[id[n]];
	}
};

#line 8 "kyopro/test/LCA_yosupo-judge.test.cpp"

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector<vector<int>> tree(n);
	int p;
	rep(i, n - 1) {
		scanf("%d", &p);
		tree[p].emplace_back(i + 1);
	}
	LCA lca(tree, n, 0);
	int v;
	rep(i, q) {
		scanf("%d%d", &p, &v);
		printf("%d\n", lca.query(p, v));
	}

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

