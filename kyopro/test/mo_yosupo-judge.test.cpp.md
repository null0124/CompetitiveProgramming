---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/library/datastructure/BIT.cpp
    title: binary-indexed-tree
  - icon: ':heavy_check_mark:'
    path: kyopro/library/others/mo.cpp
    title: Mo's Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"kyopro/test/mo_yosupo-judge.test.cpp\"\n\uFEFF#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n#line 1\
    \ \"kyopro/library/template/template.cpp\"\n\uFEFF/*\n* @title template\n* @docs\
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
    #line 4 \"kyopro/test/mo_yosupo-judge.test.cpp\"\n\n#line 1 \"kyopro/library/datastructure/BIT.cpp\"\
    \n/*\n* @title binary-indexed-tree\n* @docs kyopro/docs/BIT.md\n*/\n\ntemplate<typename\
    \ T>\n//0-indexed/\u5185\u90E8\u7684\u306B 1-indexed\nstruct BIT {\n\tvector<T>\
    \ tree;\n\t//\u521D\u671F\u5316\n\tBIT(int n) : tree(n) {\n\t\ttree.assign(n +\
    \ 1, 0);\n\t}\n\n\tint LSB(int n) { return (n & (-n)); }\n\n\t//[0, n) \u306E\
    \ sum \u3092\u8FD4\u3059/0-indexed\n\tT sum(int n) {\n\t\tT ret = 0;\n\t\t//\u5B9F\
    \u306F 1-indexed \u3060\u304C\u534A\u958B\u533A\u9593\u306A\u306E\u3067\u898B\u305F\
    \u76EE\u304C\u305D\u306E\u307E\u307E\n\t\tfor (; n >= 0; n -= LSB(n)) {\n\t\t\t\
    ret += tree[n];\n\t\t\tif (!n)break;\n\t\t}\n\t\treturn ret;\n\t}\n\n\n\t//[i,\
    \ j) \u306E sum \u3092\u8FD4\u3059/0-indexed\n\tT sum(int i, int j) {\n\t\treturn\
    \ sum(j) - sum(i);\n\t}\n\n\t//n \u756A\u76EE\u306B x \u3092\u8DB3\u3059\n\tvoid\
    \ add(int n, T x) {\n\t\tint siz = tree.size();\n\t\tfor (++n; n < siz; n += LSB(n))tree[n]\
    \ += x;\n\t}\n};\n#line 1 \"kyopro/library/others/mo.cpp\"\n\uFEFF/*\n* @title\
    \ Mo's Algorithm\n* @docs kyopro/docs/mo.md\n*/\n\ntemplate<typename ADD_LEFT,\
    \ typename DEL_LEFT, typename REM, typename ADD_RIGHT = ADD_LEFT, typename DEL_RIGHT\
    \ = DEL_LEFT, typename T = int>\nstruct mo {\n\tint sqn, q, l, r, p;\n\tT ret;\n\
    \tvector<tuple<int, int, int>> query;\n\tvector<T> ans;\n\n\tmo(const int& n,\
    \ const int& q) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)), query(q),\
    \ ans(q) {}\n\n\tinline void insert(const int& l, const int& r) {\n\t\tquery[p]\
    \ = { l, r, p };\n\t\t++p;\n\t}\n\n\tinline void read(const bool& oneindexed)\
    \ {\n\t\tfor (auto& [left, right, idx] : query) {\n\t\t\tscanf(\"%d%d\", &left,\
    \ &right);\n\t\t\tif (oneindexed)--left;\n\t\t\tidx = p++;\n\t\t}\n\t}\n\n\tvoid\
    \ build() {\n\t\tsort(all(query), [&](const tuple<int, int, int>& a, const tuple<int,\
    \ int, int>& b) {\n\t\t\tif (get<0>(a) / sqn != get<0>(b) / sqn)return get<0>(a)\
    \ < get<0>(b);\n\t\t\treturn get<1>(a) < get<1>(b);\n\t\t\t});\n\t}\n\n\tvoid\
    \ run(const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const DEL_LEFT& del_left,\
    \ const DEL_RIGHT& del_right, const REM& rem) {\n\t\tfor (const auto& [ql, qr,\
    \ qo] : query) {\n\t\t\twhile (l > ql)add_left(--l, ret);\n\t\t\twhile (r < qr)add_right(r++,\
    \ ret);\n\t\t\twhile (l < ql)del_left(l++, ret);\n\t\t\twhile (r > qr)del_right(--r,\
    \ ret);\n\t\t\trem(qo, ans, ret);\n\t\t}\n\t}\n\n\tvoid run(const ADD_LEFT& add,\
    \ const DEL_LEFT& del, const REM& rem) {\n\t\trun(add, add, del, del, rem);\n\t\
    }\n\n\tT operator [](const int& idx) {\n\t\treturn ans[idx];\n\t}\n\n\tvoid allrun(const\
    \ bool& oneindexed, const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const\
    \ DEL_LEFT& del_left, const DEL_RIGHT& del_right, const REM& rem) {\n\t\tread(oneindexed);\n\
    \t\tbuild();\n\t\trun(add_left, add_right, del_left, del_right, rem);\n\t}\n\n\
    \tvoid allrun(const bool& oneindexed, const ADD_LEFT& add, const DEL_LEFT& del,\
    \ const REM& rem) {\n\t\tallrun(oneindexed, add, add, del, del, rem, rem);\n\t\
    }\n\n};\n#line 7 \"kyopro/test/mo_yosupo-judge.test.cpp\"\n\nint main() {\n\n\t\
    int n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tvector<int> a(n);\n\trep(i, n) scanf(\"\
    %d\", &a[i]);\n\tvector<int> as = a;\n\tsort(all(as));\n\tas.erase(unique(all(as)),\
    \ as.end());\n\tll siz = as.size();\n\trep(i, n)a[i] = distance(as.begin(), lower_bound(all(as),\
    \ a[i]));\n\tBIT<ll> bit(siz);\n\tauto add_left = [&](const int& idx, ll& ret)\
    \ {\n\t\tret += bit.sum(0, a[idx]);\n\t\tbit.add(a[idx], 1ll);\n\t};\n\tauto add_right\
    \ = [&](const int& idx, ll& ret) {\n\t\tret += bit.sum(a[idx] + 1, siz);\n\t\t\
    bit.add(a[idx], 1ll);\n\t};\n\tauto del_left = [&](const int& idx, ll& ret) {\n\
    \t\tret -= bit.sum(0, a[idx]);\n\t\tbit.add(a[idx], -1ll);\n\t};\n\tauto del_right\
    \ = [&](const int& idx, ll& ret) {\n\t\tret -= bit.sum(a[idx] + 1, siz);\n\t\t\
    bit.add(a[idx], -1ll);\n\t};\n\tauto rem = [](const int& idx, vector<ll>& ans,\
    \ const ll& ret) {ans[idx] = ret; };\n\tmo<decltype(add_left), decltype(del_left),\
    \ decltype(rem), decltype(add_right), decltype(del_right), ll> m(n, q);\n\tm.allrun(false,\
    \ add_left, add_right, del_left, del_right, rem);\n\trep(i, q)printf(\"%lld\\\
    n\", m[i]);\n\n\tPlease AC;\n}\n"
  code: "\uFEFF#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../library/template/template.cpp\"\n\n#include \"../library/datastructure/BIT.cpp\"\
    \n#include \"../library/others/mo.cpp\"\n\nint main() {\n\n\tint n, q;\n\tscanf(\"\
    %d%d\", &n, &q);\n\tvector<int> a(n);\n\trep(i, n) scanf(\"%d\", &a[i]);\n\tvector<int>\
    \ as = a;\n\tsort(all(as));\n\tas.erase(unique(all(as)), as.end());\n\tll siz\
    \ = as.size();\n\trep(i, n)a[i] = distance(as.begin(), lower_bound(all(as), a[i]));\n\
    \tBIT<ll> bit(siz);\n\tauto add_left = [&](const int& idx, ll& ret) {\n\t\tret\
    \ += bit.sum(0, a[idx]);\n\t\tbit.add(a[idx], 1ll);\n\t};\n\tauto add_right =\
    \ [&](const int& idx, ll& ret) {\n\t\tret += bit.sum(a[idx] + 1, siz);\n\t\tbit.add(a[idx],\
    \ 1ll);\n\t};\n\tauto del_left = [&](const int& idx, ll& ret) {\n\t\tret -= bit.sum(0,\
    \ a[idx]);\n\t\tbit.add(a[idx], -1ll);\n\t};\n\tauto del_right = [&](const int&\
    \ idx, ll& ret) {\n\t\tret -= bit.sum(a[idx] + 1, siz);\n\t\tbit.add(a[idx], -1ll);\n\
    \t};\n\tauto rem = [](const int& idx, vector<ll>& ans, const ll& ret) {ans[idx]\
    \ = ret; };\n\tmo<decltype(add_left), decltype(del_left), decltype(rem), decltype(add_right),\
    \ decltype(del_right), ll> m(n, q);\n\tm.allrun(false, add_left, add_right, del_left,\
    \ del_right, rem);\n\trep(i, q)printf(\"%lld\\n\", m[i]);\n\n\tPlease AC;\n}\n"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/datastructure/BIT.cpp
  - kyopro/library/others/mo.cpp
  isVerificationFile: true
  path: kyopro/test/mo_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/mo_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/mo_yosupo-judge.test.cpp
- /verify/kyopro/test/mo_yosupo-judge.test.cpp.html
title: kyopro/test/mo_yosupo-judge.test.cpp
---
