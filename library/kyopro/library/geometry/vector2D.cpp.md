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


# :x: vector(2D)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ca8a31a0bacda461c2e6da1fb48305c8">kyopro/library/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/geometry/vector2D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 00:22:40+09:00




﻿

## Verified with

* :x: <a href="../../../../verify/kyopro/test/vector2D_yukicoder.test.cpp.html">kyopro/test/vector2D_yukicoder.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title vector(2D)
* @docs kyopro/docs/vector2D.md
*/



struct vector2D {

	ll x, y;

	vector2D(ll x, ll y) : x(x), y(y) {}
	vector2D(ll stx, ll sty, ll enx, ll eny) : x(enx - stx), y(eny - sty) {}
	vector2D() : x(0), y(0) {}

	vector2D operator+(const vector2D p) { return vector2D(x + p.x, y + p.y); }
	vector2D operator-(const vector2D p) { return vector2D(x - p.x, y - p.y); }
	// スカラー倍
	vector2D operator*(const ll p) { return vector2D(x * p, y * p); }

};

//外積(のスカラ―)
inline ll vectorproduct(vector2D p, vector2D q) { return abs(p.x * q.y - p.y * q.x); }

//整数のみでの偏角比較関数
inline bool comp(const vector2D& a, const vector2D& b) {
	if (a.x == 0 and a.y == 0)return true;
	else if (b.x == 0 and b.y == 0)return false;
	else if (a.x < 0) {
		if (b.x < 0) {
			return vectorproduct(a, b) > 0;
		}
		else {
			return false;
		}
	}
	else {
		if (b.x < 0) {
			return true;
		}
		else {
			return vectorproduct(a, b) > 0;
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/geometry/vector2D.cpp"
﻿/*
* @title vector(2D)
* @docs kyopro/docs/vector2D.md
*/



struct vector2D {

	ll x, y;

	vector2D(ll x, ll y) : x(x), y(y) {}
	vector2D(ll stx, ll sty, ll enx, ll eny) : x(enx - stx), y(eny - sty) {}
	vector2D() : x(0), y(0) {}

	vector2D operator+(const vector2D p) { return vector2D(x + p.x, y + p.y); }
	vector2D operator-(const vector2D p) { return vector2D(x - p.x, y - p.y); }
	// スカラー倍
	vector2D operator*(const ll p) { return vector2D(x * p, y * p); }

};

//外積(のスカラ―)
inline ll vectorproduct(vector2D p, vector2D q) { return abs(p.x * q.y - p.y * q.x); }

//整数のみでの偏角比較関数
inline bool comp(const vector2D& a, const vector2D& b) {
	if (a.x == 0 and a.y == 0)return true;
	else if (b.x == 0 and b.y == 0)return false;
	else if (a.x < 0) {
		if (b.x < 0) {
			return vectorproduct(a, b) > 0;
		}
		else {
			return false;
		}
	}
	else {
		if (b.x < 0) {
			return true;
		}
		else {
			return vectorproduct(a, b) > 0;
		}
	}
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

