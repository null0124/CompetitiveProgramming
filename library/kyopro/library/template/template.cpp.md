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


# :question: template

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#555f11034b492b610373485649bb8a76">kyopro/library/template</a>
* <a href="{{ site.github.repository_url }}/blob/master/kyopro/library/template/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 23:17:59+09:00




﻿
## なに
テンプレート  

## 使い方
ソースコードの上に貼る  

## 計算量
ない  



## Verified with

* :heavy_check_mark: <a href="../../../../verify/kyopro/test/BIT_yosupo-judge.test.cpp.html">kyopro/test/BIT_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/LCA_yosupo-judge.test.cpp.html">kyopro/test/LCA_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/LIS_dp_aoj.test.cpp.html">kyopro/test/LIS_dp_aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/dijkstra_aoj.test.cpp.html">kyopro/test/dijkstra_aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/dijkstra_path_yosupo-judge.test.cpp.html">kyopro/test/dijkstra_path_yosupo-judge.test.cpp</a>
* :x: <a href="../../../../verify/kyopro/test/kth-shortest-path_yen.test.cpp.html">kyopro/test/kth-shortest-path_yen.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/lcm_aoj.test.cpp.html">kyopro/test/lcm_aoj.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/segtree_yosupo-judge.test.cpp.html">kyopro/test/segtree_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/sparsetable_yosupo-judge.test.cpp.html">kyopro/test/sparsetable_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/template_yosupo-judge.test.cpp.html">kyopro/test/template_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/unionfind_yosupo-judge.test.cpp.html">kyopro/test/unionfind_yosupo-judge.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/kyopro/test/warshallfloyd_aoj.test.cpp.html">kyopro/test/warshallfloyd_aoj.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
/*
多倍長整数, cpp_intで宣言
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
*/

//#pragma gcc target ("avx2")
//#pragma gcc optimization ("o3")
//#pragma gcc optimization ("unroll-loops")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a) //少数出力
#define printLdb(a) printf("%.50Lf\n", a) //少数出力
#define printdbd(a) printf("%.16lf\n", a) //少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str()) //string出力
#define all(x) (x).begin(), (x).end()
#define allsum(a, b, c) ((a + b) * c / 2LL) //等差数列の和、初項,末項,項数
#define pb push_back
#define rpriq priq<int, vector<int>, greater<int>>
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b) から (c, d) のマンハッタン距離 */
#define inf numeric_limits<double>::infinity();
#define linf numeric_limits<long double>::infinity()


using ll = long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1000000007;
constexpr long double eps = 1e-9;
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
/*
多倍長整数, cpp_intで宣言
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
*/

//#pragma gcc target ("avx2")
//#pragma gcc optimization ("o3")
//#pragma gcc optimization ("unroll-loops")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a) //少数出力
#define printLdb(a) printf("%.50Lf\n", a) //少数出力
#define printdbd(a) printf("%.16lf\n", a) //少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str()) //string出力
#define all(x) (x).begin(), (x).end()
#define allsum(a, b, c) ((a + b) * c / 2LL) //等差数列の和、初項,末項,項数
#define pb push_back
#define rpriq priq<int, vector<int>, greater<int>>
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b) から (c, d) のマンハッタン距離 */
#define inf numeric_limits<double>::infinity();
#define linf numeric_limits<long double>::infinity()


using ll = long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1000000007;
constexpr long double eps = 1e-9;
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

