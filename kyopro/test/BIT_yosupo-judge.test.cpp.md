---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/library/datastructure/BIT.cpp
    title: binary-indexed-tree
  - icon: ':heavy_check_mark:'
    path: kyopro/library/template/template.cpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"kyopro/test/BIT_yosupo-judge.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"kyopro/library/template/template.cpp\"\
    \n\uFEFF/*\n* @title template\n* @docs kyopro/docs/template.md\n*/\n\n\n/*\n\u3053\
    \u306E\u30B3\u30FC\u30C9\u3001\u3068\uFF5E\u304A\u308C!\nBe accepted!\n\u2227\uFF3F\
    \u2227\u3000\n\uFF08\uFF61\uFF65\u03C9\uFF65\uFF61)\u3064\u2501\u2606\u30FB*\u3002\
    \n\u2282\u3000\u3000 \u30CE \u3000\u3000\u3000\u30FB\u309C+.\n\u3000\u3057\u30FC\
    \uFF2A\u3000\u3000\u3000\xB0\u3002+ *\xB4\xA8)\n \u3000\u3000\u3000\u3000\u3000\
    \u3000\u3000\u3000\u3000.\xB7 \xB4\xB8.\xB7*\xB4\xA8) \xB8.\xB7*\xA8)\n\t\t  \u3000\
    \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000(\xB8.\xB7\xB4 (\xB8.\xB7\
    '* \u2606\n*/\n\n#include <cstdio>\n#include <algorithm>\n#include <string>\n\
    #include <cmath>\n#include <cstring>\n#include <vector>\n#include <numeric>\n\
    #include <iostream>\n#include <random>\n#include <map>\n#include <unordered_map>\n\
    #include <queue>\n#include <regex>\n#include <functional>\n#include <complex>\n\
    #include <list>\n#include <cassert>\n#include <iomanip>\n#include <set>\n#include\
    \ <stack>\n#include <bitset>\n\n////\u591A\u500D\u9577\u6574\u6570, cpp_int\u3067\
    \u5BA3\u8A00\n//#include <boost/multiprecision/cpp_int.hpp>\n//using namespace\
    \ boost::multiprecision;\n\n//#pragma GCC target (\"avx2\")\n//#pragma GCC optimization\
    \ (\"O3\")\n//#pragma GCC optimization (\"unroll-loops\")\n//#pragma GCC target(\"\
    sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\")\n#define repeat(i,\
    \ n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int i = 0; i < (n);\
    \ ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\")\n#define printyn(a)\
    \ printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a ? \"YES\\n\"\
    \ : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"imposible\\\
    n\")\n#define printdb(a) printf(\"%.50lf\\n\", a) //\u5C11\u6570\u51FA\u529B\n\
    #define printLdb(a) printf(\"%.50Lf\\n\", a) //\u5C11\u6570\u51FA\u529B\n#define\
    \ printdbd(a) printf(\"%.16lf\\n\", a) //\u5C11\u6570\u51FA\u529B(\u6841\u5C11\
    \u306A\u3081)\n#define prints(s) printf(\"%s\\n\", s.c_str()) //string\u51FA\u529B\
    \n#define all(x) (x).begin(), (x).end()\n#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)\n\
    #define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)\n#define Please return\n#define\
    \ AC 0\n#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b)\
    \ \u304B\u3089 (c, d) \u306E\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2 */\n\
    #define inf numeric_limits<double>::infinity();\n#define linf numeric_limits<long\
    \ double>::infinity()\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
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
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n#line 4 \"kyopro/test/BIT_yosupo-judge.test.cpp\"\
    \n\n#line 1 \"kyopro/library/datastructure/BIT.cpp\"\n/*\n* @title binary-indexed-tree\n\
    * @docs kyopro/docs/BIT.md\n*/\n\ntemplate<typename T>\n//0-indexed/\u5185\u90E8\
    \u7684\u306B 1-indexed\nstruct BIT {\n\tvector<T> tree;\n\t//\u521D\u671F\u5316\
    \n\tBIT(int n) : tree(n) {\n\t\ttree.assign(n + 1, 0);\n\t}\n\n\tint LSB(int n)\
    \ { return (n & (-n)); }\n\n\t//[0, n) \u306E sum \u3092\u8FD4\u3059/0-indexed\n\
    \tT sum(int n) {\n\t\tT ret = 0;\n\t\t//\u5B9F\u306F 1-indexed \u3060\u304C\u534A\
    \u958B\u533A\u9593\u306A\u306E\u3067\u898B\u305F\u76EE\u304C\u305D\u306E\u307E\
    \u307E\n\t\tfor (; n >= 0; n -= LSB(n)) {\n\t\t\tret += tree[n];\n\t\t\tif (!n)break;\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\n\t//[i, j) \u306E sum \u3092\u8FD4\u3059/0-indexed\n\
    \tT sum(int i, int j) {\n\t\treturn sum(j) - sum(i);\n\t}\n\n\t//n \u756A\u76EE\
    \u306B x \u3092\u8DB3\u3059\n\tvoid add(int n, T x) {\n\t\tint siz = tree.size();\n\
    \t\tfor (++n; n < siz; n += LSB(n))tree[n] += x;\n\t}\n};\n#line 6 \"kyopro/test/BIT_yosupo-judge.test.cpp\"\
    \n\nint main() {\n\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tBIT<ll> bit(n);\n\
    \trep(i, n) {\n\t\tll a;\n\t\tscanf(\"%lld\", &a);\n\t\tbit.add(i, a);\n\t}\n\t\
    while (q--) {\n\t\tll t, a, b;\n\t\tscanf(\"%lld%lld%lld\", &t, &a, &b);\n\t\t\
    if (t)printf(\"%lld\\n\", bit.sum(a, b));\n\t\telse bit.add(a, b);\n\t}\n\n\t\
    Please AC;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../library/template/template.cpp\"\n\n#include \"../library/datastructure/BIT.cpp\"\
    \n\nint main() {\n\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tBIT<ll> bit(n);\n\
    \trep(i, n) {\n\t\tll a;\n\t\tscanf(\"%lld\", &a);\n\t\tbit.add(i, a);\n\t}\n\t\
    while (q--) {\n\t\tll t, a, b;\n\t\tscanf(\"%lld%lld%lld\", &t, &a, &b);\n\t\t\
    if (t)printf(\"%lld\\n\", bit.sum(a, b));\n\t\telse bit.add(a, b);\n\t}\n\n\t\
    Please AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/datastructure/BIT.cpp
  isVerificationFile: true
  path: kyopro/test/BIT_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '2020-09-06 14:13:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/BIT_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/BIT_yosupo-judge.test.cpp
- /verify/kyopro/test/BIT_yosupo-judge.test.cpp.html
title: kyopro/test/BIT_yosupo-judge.test.cpp
---
