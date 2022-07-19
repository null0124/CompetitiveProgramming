---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/library/datastructure/sparsetable.cpp
    title: sparse-table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"kyopro/test/sparsetable_yosupo-judge.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"kyopro/library/template/template.cpp\"\
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
    #line 4 \"kyopro/test/sparsetable_yosupo-judge.test.cpp\"\n\n#line 1 \"kyopro/library/datastructure/sparsetable.cpp\"\
    \n/*\n* @title sparse-table\n* @docs kyopro/docs/sparsetable.md\n*/\n\n//RMQ <O(n\
    \ log n), O(1)>\ntemplate<typename T>\nstruct sparsetable {\n\n\tvector<vector<T>>\
    \ table;\n\tvector<int> logtable;\n\tvector<int> a;\n\tint n;\n\n\t// \u6E21\u3059\
    \u914D\u5217, \u30B5\u30A4\u30BA\n\tsparsetable(const vector<T> a, int siz) :\
    \ n(siz), a(a) {\n\t\tlogtable.assign(n + 1, 0);\n\t\tfor (int i = 2; i <= n;\
    \ ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n, vector<T>(logtable[n]\
    \ + 1, 0));\n\t}\n\n\t//\u30EA\u30B9\u30C8\u30D0\u30FC\u30B8\u30E7\u30F3\n\tsparsetable(initializer_list<T>\
    \ init) {\n\t\ta = init[0];\n\t\tn = init[1];\n\t\tlogtable.assign(n + 1, 0);\n\
    \t\tfor (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n,\
    \ vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u914D\u5217\u3068\u5927\u304D\u3055\
    \u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n\tvoid init(const vector<T> aa, int\
    \ siz) {\n\t\ta = aa;\n\t\tn = siz;\n\t\tlogtable.assign(n + 1, 0);\n\t\tfor (int\
    \ i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n,\
    \ vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u69CB\u7BC9 O(n log n)\n\tvoid\
    \ build() {\n\t\tfor (int k = 0; (1 << k) <= n; ++k) {\n\t\t\tfor (int i = 0;\
    \ i + (1 << k) <= n; ++i) {\n\t\t\t\tif (k) table[i][k] = (a[table[i][k - 1]]\
    \ < a[table[i + (1 << (k - 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k\
    \ - 1))][k - 1]);\n\t\t\t\telse table[i][k] = i;\n\t\t\t}\n\t\t}\n\t}\n\n\t//[l,\
    \ r) \u306E RMQ O(1)\n\tint query(int l, int r) {\n\t\tint k = logtable[r - l];\n\
    \t\treturn (a[table[l][k]] < a[table[r - (1 << k)][k]] ? table[l][k] : table[r\
    \ - (1 << k)][k]);\n\t}\n\n};\n\n#line 6 \"kyopro/test/sparsetable_yosupo-judge.test.cpp\"\
    \n\nint main() {\n\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tvector<int> a(n);\n\
    \trep(i, n)scanf(\"%d\", &a[i]);\n\tsparsetable<int> rmq(a, n);\n\trmq.build();\n\
    \twhile (q--) {\n\t\tint l, r;\n\t\tscanf(\"%d%d\", &l, &r);\n\t\tprintf(\"%d\\\
    n\", a[rmq.query(l, r)]);\n\t}\n\n\tPlease AC;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../library/template/template.cpp\"\n\n#include \"../library/datastructure/sparsetable.cpp\"\
    \n\nint main() {\n\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tvector<int> a(n);\n\
    \trep(i, n)scanf(\"%d\", &a[i]);\n\tsparsetable<int> rmq(a, n);\n\trmq.build();\n\
    \twhile (q--) {\n\t\tint l, r;\n\t\tscanf(\"%d%d\", &l, &r);\n\t\tprintf(\"%d\\\
    n\", a[rmq.query(l, r)]);\n\t}\n\n\tPlease AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/datastructure/sparsetable.cpp
  isVerificationFile: true
  path: kyopro/test/sparsetable_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/sparsetable_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/sparsetable_yosupo-judge.test.cpp
- /verify/kyopro/test/sparsetable_yosupo-judge.test.cpp.html
title: kyopro/test/sparsetable_yosupo-judge.test.cpp
---
