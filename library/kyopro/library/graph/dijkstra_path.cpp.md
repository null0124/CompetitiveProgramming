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


# :heavy_check_mark: dijkstra(経路復元)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/dijkstra_path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-02 16:46:31+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/dijkstra_path_yosupo-judge.test.cpp.html">kyopro/test/dijkstra_path_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

