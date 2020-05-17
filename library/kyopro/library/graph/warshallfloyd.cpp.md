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


# :heavy_check_mark: kyopro/library/graph/warshallfloyd.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#950d3b5531ccd296b32ebda74bb65534">kyopro/library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/graph/warshallfloyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 02:46:49+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/warshallfloyd_aoj.test.cpp.html">kyopro/test/warshallfloyd_aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿//ワーシャルフロイド
void WarshallFloyd(int n, vector<vector<ll>> & d) {
	rep(i, n) {//経由する頂点
		rep(j, n) {//始点
			rep(k, n) {//終点
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/graph/warshallfloyd.cpp"
﻿//ワーシャルフロイド
void WarshallFloyd(int n, vector<vector<ll>> & d) {
	rep(i, n) {//経由する頂点
		rep(j, n) {//始点
			rep(k, n) {//終点
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

