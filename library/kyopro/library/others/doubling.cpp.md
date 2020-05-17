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


# :warning: kyopro/library/others/doubling.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3f8f1932cca0dd85953a1d1a98528004">kyopro/library/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/others/doubling.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 20:30:00+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿struct doubling {

	int n, log_k;
	vector<vector<int>> a;
	const function<int(int, int)> f1, f2;

	doubling(int n, ll k, function<int(int, int)> f1, function<int(int, int)> f2) : n(n), f1(f1), f2(f2) {
		log_k = ceil(log2(k));
		a.assign(log_k + 1, vector<int>(n, -1));
	}

	//i 番目の要素のセットではなく一つ先の要素のセットであることに注意
	void set(int i, int x) {
		a[0][i] = x;
	}

	void build() {
		for (int i = 0; i < log_k; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == -1) a[i + 1][j] = -1;
				else a[i + 1][j] = f1(a[i + 1][j], a[i][a[i][j]]);
			}
		}
	}

	//k 番目の要素の x 個先を求める
	int query(int k, ll x) {
		for (int i = log_k; i >= 0; --i) {
			if (k == -1)break;
			else if ((x >> (ll)i) & 1LL) k = f2(k, a[i][k]);
		}
		return k;
	}

};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/others/doubling.cpp"
﻿struct doubling {

	int n, log_k;
	vector<vector<int>> a;
	const function<int(int, int)> f1, f2;

	doubling(int n, ll k, function<int(int, int)> f1, function<int(int, int)> f2) : n(n), f1(f1), f2(f2) {
		log_k = ceil(log2(k));
		a.assign(log_k + 1, vector<int>(n, -1));
	}

	//i 番目の要素のセットではなく一つ先の要素のセットであることに注意
	void set(int i, int x) {
		a[0][i] = x;
	}

	void build() {
		for (int i = 0; i < log_k; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == -1) a[i + 1][j] = -1;
				else a[i + 1][j] = f1(a[i + 1][j], a[i][a[i][j]]);
			}
		}
	}

	//k 番目の要素の x 個先を求める
	int query(int k, ll x) {
		for (int i = log_k; i >= 0; --i) {
			if (k == -1)break;
			else if ((x >> (ll)i) & 1LL) k = f2(k, a[i][k]);
		}
		return k;
	}

};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

