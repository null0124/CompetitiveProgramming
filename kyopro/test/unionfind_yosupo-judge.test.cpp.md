---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: kyopro/library/datastructure/unionfind.cpp
    title: unionfind
  - icon: ':question:'
    path: kyopro/library/template/template.cpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"kyopro/test/unionfind_yosupo-judge.test.cpp\"\n\uFEFF#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"kyopro/library/template/template.cpp\"\
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
    \ <stack>\n#include <bitset>\n#include <array>\n#include <chrono>\n\n//#pragma\
    \ GCC target(\"arch=skylake-avx512\")\n//#pragma GCC target (\"avx2\")\n//#pragma\
    \ GCC optimize (\"O3\")\n//#pragma GCC target (\"sse4\")\n//#pragma GCC optimize\
    \ (\"unroll-loops\")\n//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\"\
    )\n#define repeat(i, n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int\
    \ i = 0; i < (n); ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\"\
    )\n#define printyn(a) printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a\
    \ ? \"YES\\n\" : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"\
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
    #line 4 \"kyopro/test/unionfind_yosupo-judge.test.cpp\"\n\n#line 1 \"kyopro/library/datastructure/unionfind.cpp\"\
    \n\uFEFF/*\n* @title unionfind\n* @docs kyopro/docs/unionfind.md\n*/\n\n//0-indexed\n\
    struct unionfind {\n\tvector<int> par, siz;\n\n\tunionfind(int n) : par(n), siz(n)\
    \ {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\t//\u5168\u90E8\u6839\u3067\u521D\
    \u671F\u5316\n\t\t\tpar[i] = i;\n\t\t\t//\u30B5\u30A4\u30BA\u306F1\n\t\t\tsiz[i]\
    \ = 1;\n\t\t}\n\t}\n\n\tvoid init(int n) {\n\t\tpar.resize(n);\n\t\tsiz.resize(n);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\t//\u5168\u90E8\u6839\u3067\u521D\u671F\
    \u5316\n\t\t\tpar[i] = i;\n\t\t\t//\u30B5\u30A4\u30BA\u306F1\n\t\t\tsiz[i] = 1;\n\
    \t\t}\n\t}\n\n\t//\u6839\u3092\u8FD4\u3059\n\tint find(int a) {\n\t\treturn par[a]\
    \ == a ? a : par[a] = find(par[a]);\n\t}\n\n\t//\u304F\u3063\u3064\u3051\u308B\
    \u3002\u5143\u304B\u3089\u540C\u3058\u3060\u3063\u305F\u3089false\u3092\u8FD4\u3059\
    \n\tbool unite(int a, int b) {\n\t\tint x = find(a), y = find(b);\n\t\tif (x ==\
    \ y)return false;\n\t\telse if (siz[x] < siz[y]) {\n\t\t\tpar[x] = y;\n\t\t\t\
    siz[y] += siz[x];\n\t\t}\n\t\telse if (siz[x] > siz[y]) {\n\t\t\tpar[y] = x;\n\
    \t\t\tsiz[x] += siz[y];\n\t\t}\n\t\telse {\n\t\t\tpar[x] = y;\n\t\t\tsiz[y] +=\
    \ siz[x];\n\t\t}\n\t\treturn true;\n\t}\n\n\t//\u540C\u3058\u96C6\u5408\u304B\u5224\
    \u5B9A\u3059\u308B\n\tbool same(int a, int b) {\n\t\treturn find(a) == find(b);\n\
    \t}\n\n\t//\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n\tint size(int a) {\n\t\treturn\
    \ siz[find(a)];\n\t}\n\n};\n#line 6 \"kyopro/test/unionfind_yosupo-judge.test.cpp\"\
    \n\nint main() {\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tunionfind uni(n);\n\
    \twhile (q--) {\n\t\tint t, u, v;\n\t\tscanf(\"%d%d%d\", &t, &u, &v);\n\t\tif\
    \ (t)printf(\"%d\\n\", uni.same(u, v));\n\t\telse uni.unite(u, v);\n\t}\n\n\t\
    Please AC;\n}\n"
  code: "\uFEFF#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../library/template/template.cpp\"\n\n#include \"../library/datastructure/unionfind.cpp\"\
    \n\nint main() {\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tunionfind uni(n);\n\
    \twhile (q--) {\n\t\tint t, u, v;\n\t\tscanf(\"%d%d%d\", &t, &u, &v);\n\t\tif\
    \ (t)printf(\"%d\\n\", uni.same(u, v));\n\t\telse uni.unite(u, v);\n\t}\n\n\t\
    Please AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/datastructure/unionfind.cpp
  isVerificationFile: true
  path: kyopro/test/unionfind_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: kyopro/test/unionfind_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/unionfind_yosupo-judge.test.cpp
- /verify/kyopro/test/unionfind_yosupo-judge.test.cpp.html
title: kyopro/test/unionfind_yosupo-judge.test.cpp
---
