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


# :heavy_check_mark: modint

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3f8f1932cca0dd85953a1d1a98528004">kyopro/library/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/others/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 18:09:31+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/segtree_yosupo-judge.test.cpp.html">kyopro/test/segtree_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title modint
* @docs kyopro/docs/modint.md
*/

template<int mod>
struct modint {
	int val;

	modint() : val(0) {};
	modint(ll x) : val(x >= 0 ? x % mod : (mod + x % mod) % mod) {};

	modint& operator=(const modint& x) {
		val = x.val;
		return *this;
	}

	modint& operator+=(const modint& x) {
		val += x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator-=(const modint& x) {
		val += mod - x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator*=(const modint& x) {
		val = (int)((ll)val * (ll)x.val % mod);
		return *this;
	}

	modint& operator/=(const modint& x) {
		int a = x.val, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		*this *= modint(u);
		return *this;
	}

	modint operator+(const modint& x) const {
		return (modint(*this) += x);
	}

	modint operator-(const modint& x) const {
		return (modint(*this) -= x);
	}

	modint operator*(const modint& x) const {
		return (modint(*this) *= x);
	}

	modint operator/(const modint& x) const {
		return (modint(*this) /= x);
	}

	modint pow(ll n) {
		modint ret(1), a(val);
		while (n > 0) {
			if (n % 2) ret *= a;
			a *= a;
			n /= 2;
		}
		return ret;
	}

	static int getmod() { return mod; };
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/others/modint.cpp"
﻿/*
* @title modint
* @docs kyopro/docs/modint.md
*/

template<int mod>
struct modint {
	int val;

	modint() : val(0) {};
	modint(ll x) : val(x >= 0 ? x % mod : (mod + x % mod) % mod) {};

	modint& operator=(const modint& x) {
		val = x.val;
		return *this;
	}

	modint& operator+=(const modint& x) {
		val += x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator-=(const modint& x) {
		val += mod - x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator*=(const modint& x) {
		val = (int)((ll)val * (ll)x.val % mod);
		return *this;
	}

	modint& operator/=(const modint& x) {
		int a = x.val, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		*this *= modint(u);
		return *this;
	}

	modint operator+(const modint& x) const {
		return (modint(*this) += x);
	}

	modint operator-(const modint& x) const {
		return (modint(*this) -= x);
	}

	modint operator*(const modint& x) const {
		return (modint(*this) *= x);
	}

	modint operator/(const modint& x) const {
		return (modint(*this) /= x);
	}

	modint pow(ll n) {
		modint ret(1), a(val);
		while (n > 0) {
			if (n % 2) ret *= a;
			a *= a;
			n /= 2;
		}
		return ret;
	}

	static int getmod() { return mod; };
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

