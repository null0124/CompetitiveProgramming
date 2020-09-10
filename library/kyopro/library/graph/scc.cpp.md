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


# :heavy_check_mark: strongly connected components(強連結成分分解)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 14:13:21+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/scc-cg_aoj.test.cpp.html">kyopro/test/scc-cg_aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/scc_aoj.test.cpp.html">kyopro/test/scc_aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/scc_yosupo-judge.test.cpp.html">kyopro/test/scc_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title strongly connected components(強連結成分分解)
* @docs kyopro/docs/scc.md
*/

template<typename T = int>
struct stronglyconnectedcomponents {

	int n, cur = 0;
	//g: 元のグラフ, gg: 逆張りグラフ, cg: 強連結成分で圧縮したグラフ, sg: 強連結成分だけのグラフ
	graph<T> g, cg, sg, gg;
	vector<int> num, siz;
	vector<vector<int>> vert;

	stronglyconnectedcomponents(const int& n, graph<T>& g) : n(n), g(g), cg(n, g.directed, g.weighted), sg(n, g.directed, g.weighted), gg(n, g.directed, g.weighted), num(n) {
		rep(i, n) for (const auto& aa : g[i])gg.add_edge(aa.to, aa.from, aa.cost);
	}

	void dfs(const int& now, stack<int>& st, vector<bool>& visited) {
		visited[now] = true;
		for (const auto& aa : g[now])if (not visited[aa.to])dfs(aa.to, st, visited);
		st.push(now);
	}

	void build() {
		stack<int> s, st;
		vector<bool> visited(n);
		rep(i, n) {
			if (not visited[i]) dfs(i, st, visited);
		}
		fill(all(visited), false);
		while (not st.empty()) {
			int v = st.top();
			st.pop();
			if (not visited[v]) {
				s.push(v);
				while (not s.empty()) {
					int ver = s.top();
					s.pop();
					num[ver] = cur;
					for (const auto& aa : gg[ver]) if (not visited[aa.to])s.push(aa.to);
					visited[ver] = true;
				}
				++cur;
			}
		}
		siz.assign(cur, 1);
		vert.assign(cur, {});
		fill(all(visited), false);
		rep(i, n) {
			if (not visited[i])vert[num[i]].push_back(i);
			visited[i] = true;
			for (const auto& aa : g[i]) {
				if (num[aa.to] == num[i]) {
					sg.add_edge(aa.from, aa.to, aa.cost);
					if (not visited[aa.to]) {
						++siz[num[aa.to]];
						visited[aa.to] = true;
						vert[num[i]].push_back(aa.to);
					}
				}
				else {
					cg.add_edge(num[aa.from], num[aa.to], aa.cost);
				}
			}
		}
	}

	int operator[](const int& i) { return num[i]; }

	int size() { return cur; }
	int size(const int& i) { return siz[i]; }

};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/graph/scc.cpp"
﻿/*
* @title strongly connected components(強連結成分分解)
* @docs kyopro/docs/scc.md
*/

template<typename T = int>
struct stronglyconnectedcomponents {

	int n, cur = 0;
	//g: 元のグラフ, gg: 逆張りグラフ, cg: 強連結成分で圧縮したグラフ, sg: 強連結成分だけのグラフ
	graph<T> g, cg, sg, gg;
	vector<int> num, siz;
	vector<vector<int>> vert;

	stronglyconnectedcomponents(const int& n, graph<T>& g) : n(n), g(g), cg(n, g.directed, g.weighted), sg(n, g.directed, g.weighted), gg(n, g.directed, g.weighted), num(n) {
		rep(i, n) for (const auto& aa : g[i])gg.add_edge(aa.to, aa.from, aa.cost);
	}

	void dfs(const int& now, stack<int>& st, vector<bool>& visited) {
		visited[now] = true;
		for (const auto& aa : g[now])if (not visited[aa.to])dfs(aa.to, st, visited);
		st.push(now);
	}

	void build() {
		stack<int> s, st;
		vector<bool> visited(n);
		rep(i, n) {
			if (not visited[i]) dfs(i, st, visited);
		}
		fill(all(visited), false);
		while (not st.empty()) {
			int v = st.top();
			st.pop();
			if (not visited[v]) {
				s.push(v);
				while (not s.empty()) {
					int ver = s.top();
					s.pop();
					num[ver] = cur;
					for (const auto& aa : gg[ver]) if (not visited[aa.to])s.push(aa.to);
					visited[ver] = true;
				}
				++cur;
			}
		}
		siz.assign(cur, 1);
		vert.assign(cur, {});
		fill(all(visited), false);
		rep(i, n) {
			if (not visited[i])vert[num[i]].push_back(i);
			visited[i] = true;
			for (const auto& aa : g[i]) {
				if (num[aa.to] == num[i]) {
					sg.add_edge(aa.from, aa.to, aa.cost);
					if (not visited[aa.to]) {
						++siz[num[aa.to]];
						visited[aa.to] = true;
						vert[num[i]].push_back(aa.to);
					}
				}
				else {
					cg.add_edge(num[aa.from], num[aa.to], aa.cost);
				}
			}
		}
	}

	int operator[](const int& i) { return num[i]; }

	int size() { return cur; }
	int size(const int& i) { return siz[i]; }

};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

