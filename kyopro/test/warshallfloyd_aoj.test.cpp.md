---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: kyopro/library/graph/warshallfloyd.cpp
    title: warshallfloyd
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"kyopro/test/warshallfloyd_aoj.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\n\n#line\
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
    #line 1 \"kyopro/library/graph/warshallfloyd.cpp\"\n\uFEFF/*\n* @title warshallfloyd\n\
    * @docs kyopro/docs/warshallfloyd.md\n*/\n\n//\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\
    \u30ED\u30A4\u30C9\nvoid WarshallFloyd(int n, vector<vector<ll>> & d) {\n\trep(i,\
    \ n) {//\u7D4C\u7531\u3059\u308B\u9802\u70B9\n\t\trep(j, n) {//\u59CB\u70B9\n\t\
    \t\trep(k, n) {//\u7D42\u70B9\n\t\t\t\td[j][k] = min(d[j][k], d[j][i] + d[i][k]);\n\
    \t\t\t}\n\t\t}\n\t}\n}\n\n#line 5 \"kyopro/test/warshallfloyd_aoj.test.cpp\"\n\
    \nint main() {\n\n\tint v, e;\n\tscanf(\"%d%d\", &v, &e);\n\tvector<vector<ll>>\
    \ g(v, vector<ll>(v));\n\trep(i, v)fill(all(g[i]), LINF / 2);\n\trep(i, v)g[i][i]\
    \ = 0;\n\twhile (e--) {\n\t\tint s, t, d;\n\t\tscanf(\"%d%d%d\", &s, &t, &d);\n\
    \t\tg[s][t] = d;\n\t}\n\tWarshallFloyd(v, g);\n\trep(i, v) {\n\t\tif (g[i][i]\
    \ < 0) {\n\t\t\tputs(\"NEGATIVE CYCLE\");\n\t\t\tPlease AC;\n\t\t}\n\t}\n\trep(i,\
    \ v) {\n\t\trep(j, v) {\n\t\t\tif (g[i][j] >= LINF / 4)printf(\"INF\");\n\t\t\t\
    else printf(\"%lld\", g[i][j]);\n\t\t\tif (j != v - 1)printf(\" \");\n\t\t\telse\
    \ puts(\"\");\n\t\t}\n\t}\n\n\tPlease AC;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../library/template/template.cpp\"\n#include \"../library/graph/warshallfloyd.cpp\"\
    \n\nint main() {\n\n\tint v, e;\n\tscanf(\"%d%d\", &v, &e);\n\tvector<vector<ll>>\
    \ g(v, vector<ll>(v));\n\trep(i, v)fill(all(g[i]), LINF / 2);\n\trep(i, v)g[i][i]\
    \ = 0;\n\twhile (e--) {\n\t\tint s, t, d;\n\t\tscanf(\"%d%d%d\", &s, &t, &d);\n\
    \t\tg[s][t] = d;\n\t}\n\tWarshallFloyd(v, g);\n\trep(i, v) {\n\t\tif (g[i][i]\
    \ < 0) {\n\t\t\tputs(\"NEGATIVE CYCLE\");\n\t\t\tPlease AC;\n\t\t}\n\t}\n\trep(i,\
    \ v) {\n\t\trep(j, v) {\n\t\t\tif (g[i][j] >= LINF / 4)printf(\"INF\");\n\t\t\t\
    else printf(\"%lld\", g[i][j]);\n\t\t\tif (j != v - 1)printf(\" \");\n\t\t\telse\
    \ puts(\"\");\n\t\t}\n\t}\n\n\tPlease AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/graph/warshallfloyd.cpp
  isVerificationFile: true
  path: kyopro/test/warshallfloyd_aoj.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: kyopro/test/warshallfloyd_aoj.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/warshallfloyd_aoj.test.cpp
- /verify/kyopro/test/warshallfloyd_aoj.test.cpp.html
title: kyopro/test/warshallfloyd_aoj.test.cpp
---
