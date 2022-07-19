---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/library/datastructure/segtree.cpp
    title: segment-tree
  - icon: ':question:'
    path: kyopro/library/others/modint.cpp
    title: modint
  - icon: ':question:'
    path: kyopro/library/template/template.cpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"kyopro/test/segtree_yosupo-judge.test.cpp\"\n\uFEFF#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line\
    \ 1 \"kyopro/library/template/template.cpp\"\n\uFEFF/*\n* @title template\n* @docs\
    \ kyopro/docs/template.md\n*/\n\n\n/*\n\u3053\u306E\u30B3\u30FC\u30C9\u3001\u3068\
    \uFF5E\u304A\u308C!\nBe accepted!\n\u2227\uFF3F\u2227\u3000\n\uFF08\uFF61\uFF65\
    \u03C9\uFF65\uFF61)\u3064\u2501\u2606\u30FB*\u3002\n\u2282\u3000\u3000 \u30CE\
    \ \u3000\u3000\u3000\u30FB\u309C+.\n\u3000\u3057\u30FC\uFF2A\u3000\u3000\u3000\
    \xB0\u3002+ *\xB4\xA8)\n \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\
    .\xB7 \xB4\xB8.\xB7*\xB4\xA8) \xB8.\xB7*\xA8)\n\t\t  \u3000\u3000\u3000\u3000\u3000\
    \u3000\u3000\u3000\u3000\u3000(\xB8.\xB7\xB4 (\xB8.\xB7'* \u2606\n*/\n\n#include\
    \ <cstdio>\n#include <algorithm>\n#include <string>\n#include <cmath>\n#include\
    \ <cstring>\n#include <vector>\n#include <numeric>\n#include <iostream>\n#include\
    \ <random>\n#include <map>\n#include <unordered_map>\n#include <queue>\n#include\
    \ <regex>\n#include <functional>\n#include <complex>\n#include <list>\n#include\
    \ <cassert>\n#include <iomanip>\n#include <set>\n#include <stack>\n#include <bitset>\n\
    #include <array>\n#include <chrono>\n\n//#pragma GCC target(\"arch=skylake-avx512\"\
    )\n//#pragma GCC target (\"avx2\")\n//#pragma GCC optimize (\"O3\")\n//#pragma\
    \ GCC target (\"sse4\")\n//#pragma GCC optimize (\"unroll-loops\")\n//#pragma\
    \ GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\")\n#define\
    \ repeat(i, n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int i =\
    \ 0; i < (n); ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\")\n#define\
    \ printyn(a) printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a ?\
    \ \"YES\\n\" : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"\
    imposible\\n\")\n#define printdb(a) printf(\"%.50lf\\n\", a)\n#define printLdb(a)\
    \ printf(\"%.50Lf\\n\", a)\n#define printdbd(a) printf(\"%.16lf\\n\", a)\n#define\
    \ prints(s) printf(\"%s\\n\", s.c_str())\n#define all(x) (x).begin(), (x).end()\n\
    #define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)\n#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)\n\
    #define Please return\n#define AC 0\n#define manhattan_dist(a, b, c, d) (abs(a\
    \ - c) + abs(b - d))\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \nconstexpr int INF = 1073741823;\nconstexpr int MINF = -1073741823;\nconstexpr\
    \ ll LINF = ll(4661686018427387903);\nconstexpr ll MOD = 1e9 + 7;\nconstexpr ll\
    \ mod = 998244353;\nconstexpr long double eps = 1e-6;\nconst long double PI =\
    \ acosl(-1.0L);\n\nusing namespace std;\n\nvoid scans(string& str) {\n\tchar c;\n\
    \tstr = \"\";\n\tscanf(\"%c\", &c);\n\tif (c == '\\n')scanf(\"%c\", &c);\n\twhile\
    \ (c != '\\n' && c != -1 && c != ' ') {\n\t\tstr += c;\n\t\tscanf(\"%c\", &c);\n\
    \t}\n}\n\nvoid scanc(char& str) {\n\tchar c;\n\tscanf(\"%c\", &c);\n\tif (c ==\
    \ -1)return;\n\twhile (c == '\\n') {\n\t\tscanf(\"%c\", &c);\n\t}\n\tstr = c;\n\
    }\n\ndouble acot(double x) {\n\treturn PI / 2 - atan(x);\n}\n\nll LSB(ll n) {\
    \ return (n & (-n)); }\n\ntemplate<typename T>\ninline T chmin(T& a, const T&\
    \ b) {\n\tif (a > b)a = b;\n\treturn a;\n}\n\ntemplate<typename T>\ninline T chmax(T&\
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n\n////cpp_int\n//#include\
    \ <boost/multiprecision/cpp_int.hpp>\n//#include <boost/multiprecision/cpp_dec_float.hpp>\n\
    //using namespace boost::multiprecision;\n\n//atcoder library\n//#include <atcoder/all>\n\
    //using namespace atcoder;\n\n//random_device seed_gen;\n//mt19937 engine(seed_gen());\n\
    //uniform_distribution dist(-1.0, 1.0);\n\n/*----------------------------------------------------------------------------------*/\n\
    #line 4 \"kyopro/test/segtree_yosupo-judge.test.cpp\"\n\n#line 1 \"kyopro/library/others/modint.cpp\"\
    \n\uFEFF/*\n* @title modint\n* @docs kyopro/docs/modint.md\n*/\n\ntemplate<int\
    \ mod>\nstruct modint {\n\tint val;\n\n\tmodint() : val(0) {};\n\tmodint(ll x)\
    \ : val(x >= 0 ? x % mod : (mod + x % mod) % mod) {};\n\n\tmodint& operator=(const\
    \ modint& x) {\n\t\tval = x.val;\n\t\treturn *this;\n\t}\n\n\tmodint& operator+=(const\
    \ modint& x) {\n\t\tval += x.val;\n\t\tif (val >= mod)val -= mod;\n\t\treturn\
    \ *this;\n\t}\n\n\tmodint& operator-=(const modint& x) {\n\t\tval += mod - x.val;\n\
    \t\tif (val >= mod)val -= mod;\n\t\treturn *this;\n\t}\n\n\tmodint& operator*=(const\
    \ modint& x) {\n\t\tval = (int)((ll)val * (ll)x.val % mod);\n\t\treturn *this;\n\
    \t}\n\n\tmodint& operator/=(const modint& x) {\n\t\tint a = x.val, b = mod, u\
    \ = 1, v = 0, t;\n\t\twhile (b > 0) {\n\t\t\tt = a / b;\n\t\t\tswap(a -= t * b,\
    \ b);\n\t\t\tswap(u -= t * v, v);\n\t\t}\n\t\t*this *= modint(u);\n\t\treturn\
    \ *this;\n\t}\n\n\tmodint operator++() {\n\t\tval = (val + 1 == mod ? 0 : val\
    \ + 1);\n\t\treturn *this;\n\t}\n\n\tmodint operator--() {\n\t\tval = (val ==\
    \ 0 ? mod - 1 : val - 1);\n\t\treturn *this;\n\t}\n\n\tmodint operator+(const\
    \ modint& x) const {\n\t\treturn (modint(*this) += x);\n\t}\n\n\tmodint operator-(const\
    \ modint& x) const {\n\t\treturn (modint(*this) -= x);\n\t}\n\n\tmodint operator*(const\
    \ modint& x) const {\n\t\treturn (modint(*this) *= x);\n\t}\n\n\tmodint operator/(const\
    \ modint& x) const {\n\t\treturn (modint(*this) /= x);\n\t}\n\n\tbool operator==(const\
    \ modint& x)const {\n\t\treturn (val == x.val);\n\t}\n\n\tbool operator!=(const\
    \ modint& x)const {\n\t\treturn (val != x.val);\n\t}\n\n\tbool operator<(const\
    \ modint& x)const {\n\t\treturn (val < x.val);\n\t}\n\n\tbool operator>(const\
    \ modint& x)const {\n\t\treturn (val > x.val);\n\t}\n\n\tmodint pow(ll n) {\n\t\
    \tmodint ret(1), a(val);\n\t\twhile (n > 0) {\n\t\t\tif (n % 2) ret *= a;\n\t\t\
    \ta *= a;\n\t\t\tn /= 2;\n\t\t}\n\t\treturn ret;\n\t}\n\n\tstatic int getmod()\
    \ { return mod; };\n};\n\nusing ModInt = modint<MOD>;\nusing Modint = modint<mod>;\n\
    #line 1 \"kyopro/library/datastructure/segtree.cpp\"\n\uFEFF/*\n* @title segment-tree\n\
    * @docs kyopro/docs/segtree.md\n*/\n\n\n//\u30BB\u30B0\u6728/0-indexed/\u975E\u518D\
    \u5E30/(\u5927\u304D\u3055, \u5358\u4F4D\u5143)\u3067\u521D\u671F\u5316\ntemplate<typename\
    \ T, typename F>\nstruct segtree {\n\t//\u6728\u3092\u914D\u5217\u3067\u3042\u3089\
    \u308F\u3057\u305F\u3082\u306E\n\tvector<T> seg;\n\t//\u6728\u306E1/2\u306E\u5927\
    \u304D\u3055\n\tint siz;\n\t//\u5358\u4F4D\u5143\n\tconst T e;\n\t////\u6BD4\u8F03\
    \u95A2\u6570\u306E\u578B\n\t//using F = function<T(T, T)>;\n\t//\u30DE\u30FC\u30B8\
    \u3059\u308B\u95A2\u6570\n\tconst F f;\n\n\t//n \u306E\u5927\u304D\u3055, a (\u5358\
    \u4F4D\u5143) \u3067 segtree \u3092\u521D\u671F\u5316\u3059\u308B\n\tsegtree(int\
    \ n, const T a, const F f) : e(a), f(f) {\n\t\tsiz = 1;\n\t\twhile (siz < n)siz\
    \ <<= 1;\n\t\tseg.assign(2 * siz - 1, e);\n\t\t--siz;\n\t}\n\n\t//k (0-indexed)\
    \ \u756A\u76EE\u306B t \u3092\u4EE3\u5165\n\tvoid set(int k, const T& t) {\n\t\
    \tseg[k + siz] = t;\n\t}\n\n\t//f \u306B\u3088\u3063\u3066\u6728\u3092\u69CB\u7BC9\
    \n\tvoid build() {\n\t\tfor (int i = siz - 1; i >= 0; --i) seg[i] = f(seg[i *\
    \ 2 + 1], seg[i * 2 + 2]);\n\t}\n\n\t//i \u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\
    \u3059\n\tT operator[](const int i) {\n\t\treturn seg[i + siz];\n\t}\n\n\t//k\
    \ \u756A\u76EE\u306E\u5024\u3092 a \u306B\u66F4\u65B0\n\tvoid update(int k, T\
    \ a) {\n\t\tk += siz;\n\t\t//\u5FC5\u8981\u3067\u3042\u308C\u3070\u3053\u3053\u3092\
    \u5909\u3048\u308B\n\t\tseg[k] = a;\n\t\twhile (k > 0) {\n\t\t\tk = ((k - 1) >>\
    \ 1);\n\t\t\tseg[k] = f(seg[k * 2 + 1], seg[k * 2 + 2]);\n\t\t}\n\t}\n\n\t//[a,\
    \ b) \u306B\u3064\u3044\u3066 f \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\n\t\
    T query(int a, int b) {\n\t\tT l = e, r = e;\n\t\tfor (a += siz, b += siz; a <\
    \ b; a >>= 1, b >>= 1) {\n\t\t\tif (!(a & 1))l = f(l, seg[a++]);\n\t\t\tif (!(b\
    \ & 1))r = f(seg[--b], r);\n\t\t}\n\t\treturn f(l, r);\n\t}\n\n\t//[start, end)\
    \ \u306B\u3064\u3044\u3066\u3001[l, r) \u3092\u8ABF\u3079\u306A\u304C\u3089 k\
    \ \u756A\u76EE\u304C check \u3092\u6E80\u305F\u3059\u304B\u4E8C\u5206\u63A2\u7D22\
    \ \u6700\u5F8C\u304C true \u306A\u3089 left, false \u306A\u3089 right f\u306E\u9006\
    \u6F14\u7B97\n\ttemplate<typename C, typename FT>\n\tint find(const int start,\
    \ const int end, int l, int r, int k, const C check, T& checknum, const bool b,\
    \ const FT revf) {\n\t\t//cerr << checknum << '\\n';\n\t\t//\u7BC4\u56F2\u5916\
    \u307E\u305F\u306F\u305D\u3053\u304C\u3059\u3067\u306B\u6E80\u305F\u3055\u306A\
    \u3044\u3068\u304D\n\t\t//cerr << k << ',' << checknum << '\\n';\n\t\tif (start\
    \ <= l && r <= end && !check(seg[k], checknum)) {\n\t\t\tchecknum = revf(checknum,\
    \ seg[k]);\n\t\t\treturn -1;\n\t\t}\n\t\tif ((r <= start || l >= end)) {\n\t\t\
    \treturn -1;\n\t\t}\n\t\t//\u65E2\u306B\u8449\n\t\tif (k >= siz) {\n\t\t\treturn\
    \ k - siz;\n\t\t}\n\t\tint res;\n\t\tif (b) {\n\t\t\t//\u5DE6\u5074\u3092\u8ABF\
    \u3079\u308B\n\t\t\tres = find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1)\
    \ + 1, check, checknum, b, revf);\n\t\t\t//\u5DE6\u5074\u304C\u9069\u3057\u3066\
    \u305F\u3089\u305D\u308C\u304C\u7B54\u3048\n\t\t\tif (res != -1)return (res);\n\
    \t\t\treturn find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check,\
    \ checknum, b, revf);\n\t\t}\n\t\telse {\n\t\t\t//\u53F3\u5074\u3092\u8ABF\u3079\
    \u308B\n\t\t\tres = find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2,\
    \ check, checknum, b, revf);\n\t\t\t//\u53F3\u5074\u304C\u9069\u3057\u3066\u305F\
    \u3089\u305D\u308C\u304C\u7B54\u3048\n\t\t\tif (res != -1)return (res);\n\t\t\t\
    return find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum,\
    \ b, revf);\n\t\t}\n\t}\n\n\ttemplate<typename C, typename FT>\n\tint find_left(int\
    \ start, int end, const C check, T checknum, FT revf) {\n\t\treturn find< C, FT\
    \ >(start, end, 0, siz + 1, 0, check, checknum, true, revf);\n\t}\n\n\ttemplate<typename\
    \ C, typename FT>\n\tint find_right(int start, int end, const C check, T checknum,\
    \ FT revf) {\n\t\treturn find< C, FT >(start, end, 0, siz + 1, 0, check, checknum,\
    \ false, revf);\n\t}\n\n};\n\ntemplate<typename T, typename F>\nsegtree<T, F>\
    \ get_segtree(int n, const T& e, const F& f) {\n\treturn { n, e, f };\n}\n#line\
    \ 7 \"kyopro/test/segtree_yosupo-judge.test.cpp\"\n\nusing Modint = modint<998244353>;\n\
    \nint main() {\n\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tauto f = [](pair<Modint,\
    \ Modint> x, pair<Modint, Modint> y) {return make_pair(x.first * y.first, y.second\
    \ + y.first * x.second); };\n\tsegtree<pair<Modint, Modint>, decltype(f)> tree(n,\
    \ { 1, 0 }, f);\n\trep(i, n) {\n\t\tint a, b;\n\t\tscanf(\"%d%d\", &a, &b);\n\t\
    \ttree.set(i, { a, b });\n\t}\n\ttree.build();\n\tint p, c, d, k;\n\trep(i, q)\
    \ {\n\t\tscanf(\"%d%d%d%d\", &k, &p, &c, &d);\n\t\tif (k) {\n\t\t\tModint x =\
    \ d;\n\t\t\tauto f = tree.query(p, c);\n\t\t\tprintf(\"%d\\n\", (x * f.first +\
    \ f.second).val);\n\t\t}\n\t\telse {\n\t\t\ttree.update(p, { c, d });\n\t\t}\n\
    \t}\n\n\tPlease AC;\n}\n"
  code: "\uFEFF#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../library/template/template.cpp\"\n\n#include \"../library/others/modint.cpp\"\
    \n#include \"../library/datastructure/segtree.cpp\"\n\nusing Modint = modint<998244353>;\n\
    \nint main() {\n\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tauto f = [](pair<Modint,\
    \ Modint> x, pair<Modint, Modint> y) {return make_pair(x.first * y.first, y.second\
    \ + y.first * x.second); };\n\tsegtree<pair<Modint, Modint>, decltype(f)> tree(n,\
    \ { 1, 0 }, f);\n\trep(i, n) {\n\t\tint a, b;\n\t\tscanf(\"%d%d\", &a, &b);\n\t\
    \ttree.set(i, { a, b });\n\t}\n\ttree.build();\n\tint p, c, d, k;\n\trep(i, q)\
    \ {\n\t\tscanf(\"%d%d%d%d\", &k, &p, &c, &d);\n\t\tif (k) {\n\t\t\tModint x =\
    \ d;\n\t\t\tauto f = tree.query(p, c);\n\t\t\tprintf(\"%d\\n\", (x * f.first +\
    \ f.second).val);\n\t\t}\n\t\telse {\n\t\t\ttree.update(p, { c, d });\n\t\t}\n\
    \t}\n\n\tPlease AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/others/modint.cpp
  - kyopro/library/datastructure/segtree.cpp
  isVerificationFile: true
  path: kyopro/test/segtree_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/segtree_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/segtree_yosupo-judge.test.cpp
- /verify/kyopro/test/segtree_yosupo-judge.test.cpp.html
title: kyopro/test/segtree_yosupo-judge.test.cpp
---
