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


# :warning: Mo's Algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3f8f1932cca0dd85953a1d1a98528004">kyopro/library/others</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/others/mo.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 20:57:33+09:00




﻿

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿/*
* @title Mo's Algorithm
* @docs kyopro/docs/mo.md
*/

template<typename ADD, typename DEL, typename REM, typename T = int>
struct mo {
	int sqn, q, l, r, p;
	T ret;
	vector<tuple<int, int, int>> query;
	vector<T> ans;
	const ADD add;
	const DEL del;
	const REM rem;

	mo(int n, int q, ADD add, DEL del, REM rem) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)), query(q), ans(q), add(add), del(del), rem(rem) {}

	void insert(int l, int r) {
		query[p] = { l, r, p++ };
	}

	void read(bool oneindexed) {
		for (auto& [left, right, idx] : query) {
			scanf("%d%d", &left, &right);
			if (oneindexed)--left, --right;
			idx = p++;
		}
	}

	void build() {
		sort(all(query), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
			const auto& [al, ar, ao] = a;
			const auto& [bl, br, bo] = b;
			int ab = al / sqn, bb = bl / sqn;
			if (ab != bb)return ab < bb;
			return ar < br;
			});
	}

	void run() {
		for (const auto& [ql, qr, qo] : query) {
			while (l > ql)del(--l, ret);
			while (r < qr)add(r++, ret);
			while (l < ql)add(l++, ret);
			while (r > qr)del(--r, ret);
			rem(qo, ans, ret);
		}
	}

	T operator [](const int& idx) {
		return ans[idx];
	}

	void allrun(const bool& oneindexed) {
		read(oneindexed);
		build();
		run();
	}

};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/library/others/mo.cpp"
﻿/*
* @title Mo's Algorithm
* @docs kyopro/docs/mo.md
*/

template<typename ADD, typename DEL, typename REM, typename T = int>
struct mo {
	int sqn, q, l, r, p;
	T ret;
	vector<tuple<int, int, int>> query;
	vector<T> ans;
	const ADD add;
	const DEL del;
	const REM rem;

	mo(int n, int q, ADD add, DEL del, REM rem) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)), query(q), ans(q), add(add), del(del), rem(rem) {}

	void insert(int l, int r) {
		query[p] = { l, r, p++ };
	}

	void read(bool oneindexed) {
		for (auto& [left, right, idx] : query) {
			scanf("%d%d", &left, &right);
			if (oneindexed)--left, --right;
			idx = p++;
		}
	}

	void build() {
		sort(all(query), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
			const auto& [al, ar, ao] = a;
			const auto& [bl, br, bo] = b;
			int ab = al / sqn, bb = bl / sqn;
			if (ab != bb)return ab < bb;
			return ar < br;
			});
	}

	void run() {
		for (const auto& [ql, qr, qo] : query) {
			while (l > ql)del(--l, ret);
			while (r < qr)add(r++, ret);
			while (l < ql)add(l++, ret);
			while (r > qr)del(--r, ret);
			rem(qo, ans, ret);
		}
	}

	T operator [](const int& idx) {
		return ans[idx];
	}

	void allrun(const bool& oneindexed) {
		read(oneindexed);
		build();
		run();
	}

};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

