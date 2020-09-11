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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: kyopro/test/vector2D_yukicoder.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac19f652707ae266e4690ba676c8f462">kyopro/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/test/vector2D_yukicoder.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 00:34:27+09:00


* see: <a href="https://yukicoder.me/problems/no/1144">https://yukicoder.me/problems/no/1144</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/kyopro/library/geometry/vector2D.cpp.html">vector(2D)</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/others/modint.cpp.html">modint</a>
* :heavy_check_mark: <a href="../../../library/kyopro/library/template/template.cpp.html">template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿#define PROBLEM "https://yukicoder.me/problems/no/1144"

#include "../library/template/template.cpp"
#include "../library/others/modint.cpp"

#include "../library/geometry/vector2D.cpp"

int main() {

	int n;
	scanf("%d", &n);
	vector<pair<int, int>> p(n);
	for (auto& [x, y] : p) scanf("%d%d", &x, &y);
	modint<MOD> ans;
	vector<vector2D> q;
	rep(i, n) {
		q.clear();
		rep(j, n) {
			if (i == j or p[i] == p[j])continue;
			else if (p[j].second - p[i].second >= 0)q.emplace_back(vector2D(p[i].first, p[i].second, p[j].first, p[j].second));
			else q.emplace_back(vector2D(p[i].first, p[i].second, p[j].first, p[j].second) * -1);
		}
		int m = q.size();
		vector2D r;
		sort(all(q), comp);
		for (int j = m - 1; j >= 0; --j) {
			r = r + q[j];
			ans += vectorproduct(q[j], r);
		}
	}
	ans /= 3;
	printf("%d\n", ans.val);

	Please AC;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "kyopro/test/vector2D_yukicoder.test.cpp"
﻿#define PROBLEM "https://yukicoder.me/problems/no/1144"

#line 1 "kyopro/library/template/template.cpp"
﻿/*
* @title template
* @docs kyopro/docs/template.md
*/


/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>
#include <regex>
#include <functional>
#include <complex>
#include <list>
#include <cassert>
#include <iomanip>
#include <set>
#include <stack>
#include <bitset>

////多倍長整数, cpp_intで宣言
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define repeat(i, n, m) for(int i = n; i < (m); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a) //少数出力
#define printLdb(a) printf("%.50Lf\n", a) //少数出力
#define printdbd(a) printf("%.16lf\n", a) //少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str()) //string出力
#define all(x) (x).begin(), (x).end()
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b) から (c, d) のマンハッタン距離 */
#define inf numeric_limits<double>::infinity();
#define linf numeric_limits<long double>::infinity()

using ll = long long;
using ull = unsigned long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1e9 + 7;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-6;
const long double PI = acosl(-1.0L);

using namespace std;

void scans(string& str) {
	char c;
	str = "";
	scanf("%c", &c);
	if (c == '\n')scanf("%c", &c);
	while (c != '\n' && c != -1 && c != ' ') {
		str += c;
		scanf("%c", &c);
	}
}

void scanc(char& str) {
	char c;
	scanf("%c", &c);
	if (c == -1)return;
	while (c == '\n') {
		scanf("%c", &c);
	}
	str = c;
}

double acot(double x) {
	return PI / 2 - atan(x);
}

ll LSB(ll n) { return (n & (-n)); }

template<typename T>
inline T chmin(T& a, const T& b) {
	if (a > b)a = b;
	return a;
}

template<typename T>
inline T chmax(T& a, const T& b) {
	if (a < b)a = b;
	return a;
}
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

	modint operator++() {
		val = (val + 1 == mod ? 0 : val + 1);
		return *this;
	}

	modint operator--() {
		val = (val == 0 ? mod - 1 : val - 1);
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

	bool operator==(const modint& x)const {
		return (val == x.val);
	}

	bool operator!=(const modint& x)const {
		return (val != x.val);
	}

	bool operator<(const modint& x)const {
		return (val < x.val);
	}

	bool operator>(const modint& x)const {
		return (val > x.val);
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

using ModInt = modint<MOD>;
using Modint = modint<mod>;
#line 5 "kyopro/test/vector2D_yukicoder.test.cpp"

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

inline ll vectorproduct(vector2D p, vector2D q) { return abs(p.x * q.y - p.y * q.x); }
inline ll vectorproductcomp(vector2D p, vector2D q) { return p.x * q.y - p.y * q.x; }

inline bool comp(const vector2D& a, const vector2D& b) {
	if (a.x == 0 and a.y == 0)return true;
	else if (b.x == 0 and b.y == 0)return false;
	else if (a.x < 0) {
		if (b.x < 0) {
			return vectorproductcomp(a, b) > 0;
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
			return vectorproductcomp(a, b) > 0;
		}
	}
}
#line 7 "kyopro/test/vector2D_yukicoder.test.cpp"

int main() {

	int n;
	scanf("%d", &n);
	vector<pair<int, int>> p(n);
	for (auto& [x, y] : p) scanf("%d%d", &x, &y);
	modint<MOD> ans;
	vector<vector2D> q;
	rep(i, n) {
		q.clear();
		rep(j, n) {
			if (i == j or p[i] == p[j])continue;
			else if (p[j].second - p[i].second >= 0)q.emplace_back(vector2D(p[i].first, p[i].second, p[j].first, p[j].second));
			else q.emplace_back(vector2D(p[i].first, p[i].second, p[j].first, p[j].second) * -1);
		}
		int m = q.size();
		vector2D r;
		sort(all(q), comp);
		for (int j = m - 1; j >= 0; --j) {
			r = r + q[j];
			ans += vectorproduct(q[j], r);
		}
	}
	ans /= 3;
	printf("%d\n", ans.val);

	Please AC;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

