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


# :heavy_check_mark: unionfind

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2b68642ad9f56b522be9061078c930ba">kyopro/library/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/datastructure/unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-18 14:56:14+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/unionfind_yosupo-judge.test.cpp.html">kyopro/test/unionfind_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title unionfind
* @docs kyopro/docs/unionfind.md
*/

//0-indexed
struct unionfind {
	vector<ll> par, siz;

	unionfind(ll n) : par(n), siz(n) {
		for (ll i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	void init(ll n) {
		par.resize(n);
		siz.resize(n);
		for (ll i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	//根を返す
	ll find(ll a) {
		return par[a] == a ? a : par[a] = find(par[a]);
	}

	//くっつける。元から同じだったらfalseを返す
	bool unite(ll a, ll b) {
		ll x = find(a), y = find(b);
		if (x == y)return false;
		else if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		}
		else if (siz[x] > siz[y]) {
			par[y] = x;
			siz[x] += siz[y];
		}
		else {
			par[x] = y;
			siz[y] += siz[x];
		}
		return true;
	}

	//同じ集合か判定する
	bool same(ll a, ll b) {
		return find(a) == find(b);
	}

	//サイズを返す
	ll size(ll a) {
		return siz[find(a)];
	}

	//同じ集合に属す葉を纏めて返す
	vector<ll> leaf(ll a) {
		vector<ll> x;
		ll n = par.size();
		for (ll i = 0; i < n; ++i)if (same(a, i))x.push_back(i);
		return x;
	}

};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/datastructure/unionfind.cpp"
﻿/*
* @title unionfind
* @docs kyopro/docs/unionfind.md
*/

//0-indexed
struct unionfind {
	vector<ll> par, siz;

	unionfind(ll n) : par(n), siz(n) {
		for (ll i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	void init(ll n) {
		par.resize(n);
		siz.resize(n);
		for (ll i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	//根を返す
	ll find(ll a) {
		return par[a] == a ? a : par[a] = find(par[a]);
	}

	//くっつける。元から同じだったらfalseを返す
	bool unite(ll a, ll b) {
		ll x = find(a), y = find(b);
		if (x == y)return false;
		else if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		}
		else if (siz[x] > siz[y]) {
			par[y] = x;
			siz[x] += siz[y];
		}
		else {
			par[x] = y;
			siz[y] += siz[x];
		}
		return true;
	}

	//同じ集合か判定する
	bool same(ll a, ll b) {
		return find(a) == find(b);
	}

	//サイズを返す
	ll size(ll a) {
		return siz[find(a)];
	}

	//同じ集合に属す葉を纏めて返す
	vector<ll> leaf(ll a) {
		vector<ll> x;
		ll n = par.size();
		for (ll i = 0; i < n; ++i)if (same(a, i))x.push_back(i);
		return x;
	}

};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

