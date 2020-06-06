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


# :heavy_check_mark: 累積和

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3f8f1932cca0dd85953a1d1a98528004">kyopro/library/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/others/cumulative-sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 13:57:11+09:00




﻿

## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/cumulative-sum_yosupo-judge.test.cpp.html">kyopro/test/cumulative-sum_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title 累積和
* @docs kyopro/docs/cumulative-sum.md
*/

template<typename T>
struct cumulativesum {
    vector<T> cs;
    const function<T(T, T)> rev;
    cumulativesum(const vector<T> a, const T e, const function<T(T, T)> f, const function<T(T, T)> rev) : rev(rev) {
        int siz = a.size() + 1;
        cs.assign(siz, e);
        rep(i, siz - 1)cs[i + 1] = f(cs[i], a[i]);
    }

    //0-indexed で [l, r) の和
    T query(int l, int r) {
        return rev(cs[r], cs[l]);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/others/cumulative-sum.cpp"
﻿/*
* @title 累積和
* @docs kyopro/docs/cumulative-sum.md
*/

template<typename T>
struct cumulativesum {
    vector<T> cs;
    const function<T(T, T)> rev;
    cumulativesum(const vector<T> a, const T e, const function<T(T, T)> f, const function<T(T, T)> rev) : rev(rev) {
        int siz = a.size() + 1;
        cs.assign(siz, e);
        rep(i, siz - 1)cs[i + 1] = f(cs[i], a[i]);
    }

    //0-indexed で [l, r) の和
    T query(int l, int r) {
        return rev(cs[r], cs[l]);
    }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

