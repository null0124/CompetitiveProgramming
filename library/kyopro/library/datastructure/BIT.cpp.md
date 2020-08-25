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


# :heavy_check_mark: binary-indexed-tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2b68642ad9f56b522be9061078c930ba">kyopro/library/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/datastructure/BIT.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-16 22:28:59+09:00




﻿
## 説明
ある列の区間の和と一点更新が高速にできる  
一応抽象化をしているが二項演算は $+$ と $-$ のままなので実質数列限定  
変なのを乗せるときは segment tree をつかう  

## 使い方
構造体  

#### 宣言
BIT<$T$> bit($n$);  
$T$: 型  
$n$: 大きさ  

#### 一点更新
bit.add($i, a$)  
- $i$: 追加する index  
- $a$: 足す値  

#### 区間取得
bit.sum($l, r$)  
- $l, r$: 区間 $[l, r)$ の和を取得する。  

### 計算量
- 一点更新・区間取得  
${\rm O}(n \log n)$  



## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/BIT_yosupo-judge.test.cpp.html">kyopro/test/BIT_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/mo_yosupo-judge.test.cpp.html">kyopro/test/mo_yosupo-judge.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
* @title binary-indexed-tree
* @docs kyopro/docs/BIT.md
*/

template<typename T>
//0-indexed/内部的に 1-indexed
struct BIT {
	vector<T> tree;
	//初期化
	BIT(int n) : tree(n) {
		tree.assign(n + 1, 0);
	}

	int LSB(int n) { return (n & (-n)); }

	//[0, n) の sum を返す/0-indexed
	T sum(int n) {
		T ret = 0;
		//実は 1-indexed だが半開区間なので見た目がそのまま
		for (; n >= 0; n -= LSB(n)) {
			ret += tree[n];
			if (!n)break;
		}
		return ret;
	}


	//[i, j) の sum を返す/0-indexed
	T sum(int i, int j) {
		return sum(j) - sum(i);
	}

	//n 番目に x を足す
	void add(int n, T x) {
		int siz = tree.size();
		for (++n; n < siz; n += LSB(n))tree[n] += x;
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/datastructure/BIT.cpp"
/*
* @title binary-indexed-tree
* @docs kyopro/docs/BIT.md
*/

template<typename T>
//0-indexed/内部的に 1-indexed
struct BIT {
	vector<T> tree;
	//初期化
	BIT(int n) : tree(n) {
		tree.assign(n + 1, 0);
	}

	int LSB(int n) { return (n & (-n)); }

	//[0, n) の sum を返す/0-indexed
	T sum(int n) {
		T ret = 0;
		//実は 1-indexed だが半開区間なので見た目がそのまま
		for (; n >= 0; n -= LSB(n)) {
			ret += tree[n];
			if (!n)break;
		}
		return ret;
	}


	//[i, j) の sum を返す/0-indexed
	T sum(int i, int j) {
		return sum(j) - sum(i);
	}

	//n 番目に x を足す
	void add(int n, T x) {
		int siz = tree.size();
		for (++n; n < siz; n += LSB(n))tree[n] += x;
	}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

