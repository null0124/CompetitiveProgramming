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


# :warning: kyopro/library/math/comb.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ba3c8997ace2fe23a0c99dabed45cad7">kyopro/library/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/math/comb.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 03:56:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿template<int mod>
modint<mod> nCr(ll a, ll b) {
	modint ans = 1;
	for (ll i = 0; i < b; i++) {
		ans *= a - i;
	}
	for (ll i = 1; i <= b; i++) {
		ans /= i;
	}
	return ans;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/math/comb.cpp"
﻿template<int mod>
modint<mod> nCr(ll a, ll b) {
	modint ans = 1;
	for (ll i = 0; i < b; i++) {
		ans *= a - i;
	}
	for (ll i = 1; i <= b; i++) {
		ans /= i;
	}
	return ans;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

