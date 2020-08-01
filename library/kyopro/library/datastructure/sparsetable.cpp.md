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


# :question: sparse-table

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2b68642ad9f56b522be9061078c930ba">kyopro/library/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/datastructure/sparsetable.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 18:09:31+09:00




﻿

## Verified with

* :x: <a href="../../../../verify/kyopro/test/LCA_weighted_yukicoder.test.cpp.html">kyopro/test/LCA_weighted_yukicoder.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/LCA_yosupo-judge.test.cpp.html">kyopro/test/LCA_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/sparsetable_yosupo-judge.test.cpp.html">kyopro/test/sparsetable_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
* @title sparse-table
* @docs kyopro/docs/sparsetable.md
*/

//RMQ <O(n log n), O(1)>
template<typename T>
struct sparsetable {

	vector<vector<T>> table;
	vector<int> logtable;
	vector<int> a;
	int n;

	// 渡す配列, サイズ
	sparsetable(const vector<T> a, int siz) : n(siz), a(a) {
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//リストバージョン
	sparsetable(initializer_list<T> init) {
		a = init[0];
		n = init[1];
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//配列と大きさを渡して初期化
	void init(const vector<T> aa, int siz) {
		a = aa;
		n = siz;
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//構築 O(n log n)
	void build() {
		for (int k = 0; (1 << k) <= n; ++k) {
			for (int i = 0; i + (1 << k) <= n; ++i) {
				if (k) table[i][k] = (a[table[i][k - 1]] < a[table[i + (1 << (k - 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k - 1))][k - 1]);
				else table[i][k] = i;
			}
		}
	}

	//[l, r) の RMQ O(1)
	int query(int l, int r) {
		int k = logtable[r - l];
		return (a[table[l][k]] < a[table[r - (1 << k)][k]] ? table[l][k] : table[r - (1 << k)][k]);
	}

};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/datastructure/sparsetable.cpp"
/*
* @title sparse-table
* @docs kyopro/docs/sparsetable.md
*/

//RMQ <O(n log n), O(1)>
template<typename T>
struct sparsetable {

	vector<vector<T>> table;
	vector<int> logtable;
	vector<int> a;
	int n;

	// 渡す配列, サイズ
	sparsetable(const vector<T> a, int siz) : n(siz), a(a) {
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//リストバージョン
	sparsetable(initializer_list<T> init) {
		a = init[0];
		n = init[1];
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//配列と大きさを渡して初期化
	void init(const vector<T> aa, int siz) {
		a = aa;
		n = siz;
		logtable.assign(n + 1, 0);
		for (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;
		table.assign(n, vector<T>(logtable[n] + 1, 0));
	}

	//構築 O(n log n)
	void build() {
		for (int k = 0; (1 << k) <= n; ++k) {
			for (int i = 0; i + (1 << k) <= n; ++i) {
				if (k) table[i][k] = (a[table[i][k - 1]] < a[table[i + (1 << (k - 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k - 1))][k - 1]);
				else table[i][k] = i;
			}
		}
	}

	//[l, r) の RMQ O(1)
	int query(int l, int r) {
		int k = logtable[r - l];
		return (a[table[l][k]] < a[table[r - (1 << k)][k]] ? table[l][k] : table[r - (1 << k)][k]);
	}

};


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

