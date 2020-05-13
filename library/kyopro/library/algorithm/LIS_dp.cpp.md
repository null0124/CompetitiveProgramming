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


# :heavy_check_mark: kyopro/library/algorithm/LIS_dp.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1e7f6f770d19fb8d844d8fd4ade9dc2c">kyopro/library/algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/algorithm/LIS_dp.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 16:40:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/LIS_dp_aoj.test.cpp.html">kyopro/test/LIS_dp_aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿
//st が true の時、狭義単調増加
int lis(const int& n, const vector<int>& a, const bool& st) {
	vector<int> dp(n);
	fill(all(dp), INF);
	vector<int>::iterator ite;
	rep(i, n) {
		if (st)ite = lower_bound(all(dp), a[i]);
		else ite = upper_bound(all(dp), a[i]);
		if (ite != dp.end())*ite = a[i];
	}
	return distance(dp.begin(), lower_bound(all(dp), INF));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/algorithm/LIS_dp.cpp"
﻿
//st が true の時、狭義単調増加
int lis(const int& n, const vector<int>& a, const bool& st) {
	vector<int> dp(n);
	fill(all(dp), INF);
	vector<int>::iterator ite;
	rep(i, n) {
		if (st)ite = lower_bound(all(dp), a[i]);
		else ite = upper_bound(all(dp), a[i]);
		if (ite != dp.end())*ite = a[i];
	}
	return distance(dp.begin(), lower_bound(all(dp), INF));
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

