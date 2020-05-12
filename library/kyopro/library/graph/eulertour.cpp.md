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


# :warning: kyopro/library/graph/eulertour.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/eulertour.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 03:56:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿struct eulertour {

	vector<int> depth, child;

private:
	void dfs(const vector<vector<int>>& graph, const int& now, const int& bef, int& cnt) {
		depth[now] = cnt;
		for (const auto& aa : graph[now]) {
			if (aa != bef) {
				dfs(graph, aa, now, ++cnt);
				child[now] += child[aa] + 1;
				--cnt;
			}
		}
	}

public:
	eulertour(const vector<vector<int>>& graph, const int& n, const int& root) {
		depth.assign(n, 0);
		child.assign(n, 0);
		int cnt = 0;
		dfs(graph, root, -1, cnt);
	}

};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/graph/eulertour.cpp"
﻿struct eulertour {

	vector<int> depth, child;

private:
	void dfs(const vector<vector<int>>& graph, const int& now, const int& bef, int& cnt) {
		depth[now] = cnt;
		for (const auto& aa : graph[now]) {
			if (aa != bef) {
				dfs(graph, aa, now, ++cnt);
				child[now] += child[aa] + 1;
				--cnt;
			}
		}
	}

public:
	eulertour(const vector<vector<int>>& graph, const int& n, const int& root) {
		depth.assign(n, 0);
		child.assign(n, 0);
		int cnt = 0;
		dfs(graph, root, -1, cnt);
	}

};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

