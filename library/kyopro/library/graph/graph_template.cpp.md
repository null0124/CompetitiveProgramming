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


# :heavy_check_mark: template(graph)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/graph_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-02 04:31:23+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/dijkstra_aoj.test.cpp.html">kyopro/test/dijkstra_aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

