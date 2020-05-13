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


# :heavy_check_mark: kyopro/library/math/gcd_lcm.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ba3c8997ace2fe23a0c99dabed45cad7">kyopro/library/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/math/gcd_lcm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 03:56:30+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/lcm_aoj.test.cpp.html">kyopro/test/lcm_aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll number1, ll number2) {//lcmを求める
	return number1 / gcd(number1, number2) * number2;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/math/gcd_lcm.cpp"
﻿ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll number1, ll number2) {//lcmを求める
	return number1 / gcd(number1, number2) * number2;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

