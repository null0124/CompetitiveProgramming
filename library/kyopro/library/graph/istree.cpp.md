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


# :warning: kyopro/library/graph/istree.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/istree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 03:56:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿void dfs(const vector<vector<int>>& tree, vector<bool>& flag, const int& now, bool& f) {
	if (f)return;
	flag[now] = true;
	int cnt = 0;
	for (const auto& aa : tree[now]) {
		if (flag[aa]) {
			++cnt;
			if (cnt == 2) {
				f = true;
				return;
			}
			continue;
		}
		dfs(tree, flag, aa, f);
	}
}

//depends on unionfind
//グラフ(連結でなくてよい)に含まれる tree の数を返す/graph(隣接リスト)/頂点数
int istree(const vector<vector<int>>& graph, const int& n) {
	unionfind uni(n);
	rep(i, n) {
		for (const auto& aa : graph[i])uni.unite(i, aa);
	}
	bool f = false;
	vector<bool> flag(n);
	int ans = 0;
	rep(i, n) {
		if (flag[uni.find(i)])continue;
		dfs(graph, flag, uni.find(i), f);
		for (const auto& aa : uni.leaf(i)) {
			if (!flag[aa])f = true;
		}
		ans += (!f || uni.size(i) == 1);
		f = false;
	}
	return ans;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/graph/istree.cpp"
﻿void dfs(const vector<vector<int>>& tree, vector<bool>& flag, const int& now, bool& f) {
	if (f)return;
	flag[now] = true;
	int cnt = 0;
	for (const auto& aa : tree[now]) {
		if (flag[aa]) {
			++cnt;
			if (cnt == 2) {
				f = true;
				return;
			}
			continue;
		}
		dfs(tree, flag, aa, f);
	}
}

//depends on unionfind
//グラフ(連結でなくてよい)に含まれる tree の数を返す/graph(隣接リスト)/頂点数
int istree(const vector<vector<int>>& graph, const int& n) {
	unionfind uni(n);
	rep(i, n) {
		for (const auto& aa : graph[i])uni.unite(i, aa);
	}
	bool f = false;
	vector<bool> flag(n);
	int ans = 0;
	rep(i, n) {
		if (flag[uni.find(i)])continue;
		dfs(graph, flag, uni.find(i), f);
		for (const auto& aa : uni.leaf(i)) {
			if (!flag[aa])f = true;
		}
		ans += (!f || uni.size(i) == 1);
		f = false;
	}
	return ans;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

