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


# :heavy_check_mark: dijkstra

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 18:09:31+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/dijkstra_aoj.test.cpp.html">kyopro/test/dijkstra_aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title dijkstra
* @docs kyopro/docs/dijkstra.md
*/


template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& graph, const int& v, const int& n, const T Inf) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		for (const auto& aa : graph[top]) {
			if (res[top] + aa.second >= res[aa.first])continue;
			res[aa.first] = aa.second + res[top];
			priq.push({ res[aa.first], aa.first });
		}
	}
	return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/graph/dijkstra.cpp"
﻿/*
* @title dijkstra
* @docs kyopro/docs/dijkstra.md
*/


template<typename T>
vector<T> dijkstra(const vector<vector<pair<int, T>>>& graph, const int& v, const int& n, const T Inf) {
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;
	vector<T> res(n);
	fill(all(res), Inf);
	priq.push({ 0, v });
	res[v] = 0;
	int top;
	while (!priq.empty()) {
		top = priq.top().second;
		priq.pop();
		for (const auto& aa : graph[top]) {
			if (res[top] + aa.second >= res[aa.first])continue;
			res[aa.first] = aa.second + res[top];
			priq.push({ res[aa.first], aa.first });
		}
	}
	return res;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

