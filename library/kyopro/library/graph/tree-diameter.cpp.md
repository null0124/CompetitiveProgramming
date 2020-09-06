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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: tree diameter(木の直径)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/tree-diameter.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:43:07+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/tree-diameter_aoj.test.cpp.html">kyopro/test/tree-diameter_aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/tree-diameter_yosupo-judge.test.cpp.html">kyopro/test/tree-diameter_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title tree diameter(木の直径)
* @docs kyopro/docs/tree-diameter.md
*/

template<typename T = int>
void diameter1(graph<T>& g, const int& cur, const int& bef, const T& cnt, T& ma, int& idx) {
	if (cnt > ma)ma = cnt, idx = cur;
	for (const auto& aa : g[cur]) if (aa.to != bef)diameter1<T>(g, aa.to, cur, cnt + aa.cost, ma, idx);
}

template<typename T = int>
void diameter2(graph<T>& g, const int& cur, const int& bef, vector<int>& ret, vector<int>& route, const T& cnt, T& cost) {
	route.emplace_back(cur);
	if (g[cur].size() == 1 and cost < cnt) {
		cost = cnt;
		ret = route;
	}
	for (const auto& aa : g[cur])if (aa.to != bef)diameter2<T>(g, aa.to, cur, ret, route, cnt + aa.cost, cost);
	route.pop_back();
}

template<typename T = int>
vector<int> diameter(graph<T>& g, T& cost, const int& cur = 0) {
	T ma = 0;
	int idx = cur;
	diameter1<T>(g, cur, -1, (T)0, ma, idx);
	ma = 0;
	vector<int> ret, route;
	diameter2<T>(g, idx, -1, ret, route, 0, cost);
	reverse(all(ret));
	return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/graph/tree-diameter.cpp"
﻿/*
* @title tree diameter(木の直径)
* @docs kyopro/docs/tree-diameter.md
*/

template<typename T = int>
void diameter1(graph<T>& g, const int& cur, const int& bef, const T& cnt, T& ma, int& idx) {
	if (cnt > ma)ma = cnt, idx = cur;
	for (const auto& aa : g[cur]) if (aa.to != bef)diameter1<T>(g, aa.to, cur, cnt + aa.cost, ma, idx);
}

template<typename T = int>
void diameter2(graph<T>& g, const int& cur, const int& bef, vector<int>& ret, vector<int>& route, const T& cnt, T& cost) {
	route.emplace_back(cur);
	if (g[cur].size() == 1 and cost < cnt) {
		cost = cnt;
		ret = route;
	}
	for (const auto& aa : g[cur])if (aa.to != bef)diameter2<T>(g, aa.to, cur, ret, route, cnt + aa.cost, cost);
	route.pop_back();
}

template<typename T = int>
vector<int> diameter(graph<T>& g, T& cost, const int& cur = 0) {
	T ma = 0;
	int idx = cur;
	diameter1<T>(g, cur, -1, (T)0, ma, idx);
	ma = 0;
	vector<int> ret, route;
	diameter2<T>(g, idx, -1, ret, route, 0, cost);
	reverse(all(ret));
	return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

