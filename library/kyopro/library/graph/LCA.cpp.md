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


# :heavy_check_mark: kyopro/library/graph/LCA.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/LCA.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 03:58:00+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/LCA_yosupo-judge.test.cpp.html">kyopro/test/LCA_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

