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


# :heavy_check_mark: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 16:18:51+09:00


* see: <a href="https://yukicoder.me/problems/no/1069">https://yukicoder.me/problems/no/1069</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/graph/kth-shortest-path_yen.cpp.html">kth-shortest-path(yen's algorithm)</a>
* :question: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define PROBLEM "https://yukicoder.me/problems/no/1069"

#define ERROR 1e-4

#include "../library/template/template.cpp"

#include "../library/graph/kth-shortest-path_yen.cpp"

int main() {

	int n, m, k, x, y;
	scanf("%d%d%d%d%d", &n, &m, &k, &x, &y);
	--x; --y;
	vector<vector<pair<int, long double>>> graph(n);
	vector<pair<int, int>> xy(n);
	set<vector<int>> routememo;
	int p, q;
	rep(i, n) {
		scanf("%d%d", &p, &q);
		xy[i] = { p, q };
	}
	rep(i, m) {
		scanf("%d%d", &p, &q);
		--p; --q;
		long double a = xy[p].first, b = xy[p].second, c = xy[q].first, d = xy[q].second;
		graph[p].push_back({ q, sqrt((c - a) * (c - a) + (d - b) * (d - b)) });
		graph[q].push_back({ p, sqrt((c - a) * (c - a) + (d - b) * (d - b)) });
	}
	vector<vector<int>> path(k);
	vector<long double> ans;
	ksp<long double>(graph, n, x, y, k, path, ans, linf);
	rep(i, k)printLdb(ans[i]);

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp"
﻿#define PROBLEM "https://yukicoder.me/problems/no/1069"

#define ERROR 1e-4

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
#line 6 "kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp"

#line 1 "kyopro/library/graph/kth-shortest-path_yen.cpp"
﻿/*
* @title kth-shortest-path(yen's algorithm)
* @docs kyopro/docs/kth-shortest-path_yen.md
*/


template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& graph, vector<int>& path, const int& v, const int& g, const int& n, const T Inf, const vector<vector<bool>>& deleted, set<int> r) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	vector<int> prev(n);
	fill(all(prev), -1);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		for (const auto& aa : graph[top]) {
			if (res[top] + aa.second >= res[aa.first] or deleted[top][aa.first] or r.find(aa.first) != r.end())continue;
			res[aa.first] = aa.second + res[top];
			prev[aa.first] = top;
			priq.push({ res[aa.first], aa.first });
		}
	}

	for (int i = g; i != -1; i = prev[i])path.push_back(i);
	reverse(all(path));

	return res;
}

template<typename T>
void ksp(const vector<vector<pair<int, T>>>& graph, const int& n, const int& start, const int& goal, const int& k, vector<vector<int>>& path, vector<T>& ans, const T& Inf) {
	set<vector<int>> routememo;
	vector<T> res, anstmp;
	vector<vector<bool>> deleted(n, vector<bool>(n));
	ans.resize(k);
	path.resize(k);
	res = dijkstra<T>(graph, path[0], start, goal, n, Inf, deleted, {});
	ans[0] = res[goal];
	anstmp = res;
	routememo.insert(path[0]);
	auto func = [](const tuple<T, vector<int>, vector<T>>& a, const tuple<T, vector<int>, vector<T>>& b) -> bool {
		if (get<0>(a) != get<0>(b))return get<0>(a) > get<0>(b);
		else if (get<1>(a) != get<1>(b))return get<1>(a) > get<1>(b);
		else return get<2>(a) > get<2>(b);
	};
	priority_queue<tuple<T, vector<int>, vector<T>>, vector<tuple<T, vector<int>, vector<T>>>, decltype(func)> priq{ func };
	map<vector<int>, vector<int>> spurnode;
	rep(i, k - 1) {
		int siz = path[i].size();
		vector<int> route;
		set<int> r;
		T cost = 0;
		rep(j, siz - 1) {
			route.push_back(path[i][j]);
			r.insert(path[i][j]);
			spurnode[route].push_back(path[i][j + 1]);
			if (j != 0) {
				for (const auto& aa : graph[path[i][j - 1]]) {
					if (aa.first == path[i][j]) {
						cost += aa.second;
						break;
					}
				}
			}
			for (const auto& aa : spurnode[route])deleted[path[i][j]][aa] = deleted[aa][path[i][j]] = true;
			if (j > 0)deleted[path[i][j - 1]][path[i][j]] = deleted[path[i][j]][path[i][j - 1]] = true;
			res = dijkstra<T>(graph, path[i + 1], path[i][j], goal, n, Inf, deleted, r);
			if (j > 0)deleted[path[i][j - 1]][path[i][j]] = deleted[path[i][j]][path[i][j - 1]] = false;
			for (const auto& aa : spurnode[route])deleted[path[i][j]][aa] = deleted[aa][path[i][j]] = false;
			if (res[goal] >= Inf)continue;
			vector<int> tmp;
			vector<T> tmp2(n);
			for (int l = 0; l <= j; ++l) {
				tmp2[path[i][l]] = anstmp[path[i][l]];
			}
			int l = 0;
			for (; path[i][l] != path[i][j]; ++l) {
				tmp2[path[i][l]] = anstmp[path[i][l]];
				tmp.push_back(path[i][l]);
			}
			for (l = 0; path[i + 1][l] != goal; ++l) {
				tmp2[path[i + 1][l]] = res[path[i + 1][l]];
				tmp.push_back(path[i + 1][l]);
			}
			tmp.push_back(goal);
			int siz2 = path[i + 1].size();
			for (int l = 1; l < siz2; ++l) tmp2[path[i + 1][l]] = res[path[i + 1][l]] + anstmp[path[i][j]];
			priq.push(make_tuple(cost + res[goal], tmp, tmp2));
		}
		if (priq.empty()) {
			for (; i < k - 1; ++i)ans[i + 1] = -1;
			break;
		}
		auto tmp = priq.top();
		priq.pop();
		while (routememo.find(get<1>(tmp)) != routememo.end() and !priq.empty()) {
			tmp = priq.top();
			priq.pop();
		}
		if (routememo.find(get<1>(tmp)) != routememo.end() and priq.empty()) {
			for (; i < k - 1; ++i)ans[i + 1] = -1;
			break;
		}
		path[i + 1] = get<1>(tmp);
		ans[i + 1] = get<0>(tmp);
		routememo.insert(path[i + 1]);
	}
	return;
}
#line 8 "kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp"

int main() {

	int n, m, k, x, y;
	scanf("%d%d%d%d%d", &n, &m, &k, &x, &y);
	--x; --y;
	vector<vector<pair<int, long double>>> graph(n);
	vector<pair<int, int>> xy(n);
	set<vector<int>> routememo;
	int p, q;
	rep(i, n) {
		scanf("%d%d", &p, &q);
		xy[i] = { p, q };
	}
	rep(i, m) {
		scanf("%d%d", &p, &q);
		--p; --q;
		long double a = xy[p].first, b = xy[p].second, c = xy[q].first, d = xy[q].second;
		graph[p].push_back({ q, sqrt((c - a) * (c - a) + (d - b) * (d - b)) });
		graph[q].push_back({ p, sqrt((c - a) * (c - a) + (d - b) * (d - b)) });
	}
	vector<vector<int>> path(k);
	vector<long double> ans;
	ksp<long double>(graph, n, x, y, k, path, ans, linf);
	rep(i, k)printLdb(ans[i]);

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

