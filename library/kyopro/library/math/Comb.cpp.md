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


# :warning: combination

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ba3c8997ace2fe23a0c99dabed45cad7">kyopro/library/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/math/Comb.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 05:54:24+09:00




﻿

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title combination
* @docs kyopro/docs/comb.md
*/

template<typename T>
struct comb {
	int siz, Mod;

	vector<T> fac, inv, facinv;

	//siz <= 1e7 くらい
	comb(const int& siz, const int& Mod) : siz(siz), Mod(Mod) {
		fac.assign(siz + 1, 0);
		inv.assign(siz + 1, 0);
		facinv.assign(siz + 1, 0);
		fac[0] = fac[1] = facinv[0] = facinv[1] = inv[1] = 1;
		for (int i = 2; i <= siz; ++i) {
			fac[i] = fac[i - 1] * i % Mod;
			inv[i] = Mod - inv[Mod % i] * (Mod / i) % Mod;
			facinv[i] = facinv[i - 1] * inv[i] % Mod;
		}
	}

	T query(const int& n, const int& r) {
		return (n < r or n < 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % Mod)) % Mod);
	}
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/math/Comb.cpp"
﻿/*
* @title combination
* @docs kyopro/docs/comb.md
*/

template<typename T>
struct comb {
	int siz, Mod;

	vector<T> fac, inv, facinv;

	//siz <= 1e7 くらい
	comb(const int& siz, const int& Mod) : siz(siz), Mod(Mod) {
		fac.assign(siz + 1, 0);
		inv.assign(siz + 1, 0);
		facinv.assign(siz + 1, 0);
		fac[0] = fac[1] = facinv[0] = facinv[1] = inv[1] = 1;
		for (int i = 2; i <= siz; ++i) {
			fac[i] = fac[i - 1] * i % Mod;
			inv[i] = Mod - inv[Mod % i] * (Mod / i) % Mod;
			facinv[i] = facinv[i - 1] * inv[i] % Mod;
		}
	}

	T query(const int& n, const int& r) {
		return (n < r or n < 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % Mod)) % Mod);
	}
};


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

