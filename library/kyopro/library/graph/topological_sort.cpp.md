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


# :x: topological-sort

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-03 02:19:54+09:00




﻿

## Verified with

* :x: <a href="../../../../verify/kyopro/test/topological_sort_aoj.test.cpp.html">kyopro/test/topological_sort_aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title topological-sort
* @docs kyopro/docs/topological_sort.md
*/

template<typename T = int>
vector<int> topological_sort(graph<T>& g, const int& v) {
	vector<int> ret, in(v);

	queue<int> que;
	rep(i, v) for (const auto& aa : g[i])++in[aa.to];
	rep(i, v)if (not in[i])que.push(i);

	while (not que.empty()) {
		int top = que.front();
		que.pop();
		for (const auto& aa : g[top]) {
			--in[aa.to];
			if (not in[aa.to])que.push(aa.to);
		}
		ret.emplace_back(top);
	}
	return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/graph/topological_sort.cpp"
﻿/*
* @title topological-sort
* @docs kyopro/docs/topological_sort.md
*/

template<typename T = int>
vector<int> topological_sort(graph<T>& g, const int& v) {
	vector<int> ret, in(v);

	queue<int> que;
	rep(i, v) for (const auto& aa : g[i])++in[aa.to];
	rep(i, v)if (not in[i])que.push(i);

	while (not que.empty()) {
		int top = que.front();
		que.pop();
		for (const auto& aa : g[top]) {
			--in[aa.to];
			if (not in[aa.to])que.push(aa.to);
		}
		ret.emplace_back(top);
	}
	return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

