---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/library/graph/dijkstra.cpp
    title: dijkstra
  - icon: ':question:'
    path: kyopro/library/graph/graph_template.cpp
    title: template(graph)
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"kyopro/test/dijkstra_aoj.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\n\n#line 1\
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
    #line 1 \"kyopro/library/graph/graph_template.cpp\"\n\uFEFF/*\n* @title template(graph)\n\
    * @docs kyopro/docs/graph_template.md\n*/\n\ntemplate<typename T>\nstruct edge\
    \ {\n\tT cost;\n\tint from, to;\n\n\tedge(int from, int to) : from(from), to(to),\
    \ cost(T(1)) {}\n\tedge(int from, int to, T cost) : from(from), to(to), cost(cost)\
    \ {}\n};\n\ntemplate<typename T = int>\nstruct graph {\n\n\tint n;\n\tbool directed,\
    \ weighted;\n\n\tvector<vector<edge<T>>> g;\n\n\tgraph(int n, bool directed, bool\
    \ weighted) : g(n), n(n), directed(directed), weighted(weighted) {}\n\n\tvoid\
    \ add_edge(int from, int to, T cost = T(1)) {\n\t\tg[from].emplace_back(from,\
    \ to, cost);\n\t\tif (not directed) {\n\t\t\tg[to].emplace_back(to, from, cost);\n\
    \t\t}\n\t}\n\n\tvector<edge<T>>& operator[](const int& idx) {\n\t\treturn g[idx];\n\
    \t}\n\n\tvoid read(int e, bool one_indexed) {\n\t\tint a, b, c = 1;\n\t\twhile\
    \ (e--) {\n\t\t\tscanf(\"%d%d\", &a, &b);\n\t\t\tif (weighted) {\n\t\t\t\tscanf(\"\
    %d\", &c);\n\t\t\t}\n\t\t\tif (one_indexed)--a, --b;\n\t\t\tadd_edge(a, b, c);\n\
    \t\t}\n\t}\n\n\tvoid read(int e, bool one_indexed, const string& format) {\n\t\
    \tint a, b;\n\t\tT c = T(1);\n\t\twhile (e--) {\n\t\t\tscanf(\"%d%d\", &a, &b);\n\
    \t\t\tif (weighted) {\n\t\t\t\tscanf(format.c_str(), &c);\n\t\t\t}\n\t\t\tif (one_indexed)--a,\
    \ --b;\n\t\t\tadd_edge(a, b, c);\n\t\t}\n\t}\n\n};\n#line 5 \"kyopro/test/dijkstra_aoj.test.cpp\"\
    \n\n#line 1 \"kyopro/library/graph/dijkstra.cpp\"\n\uFEFF/*\n* @title dijkstra\n\
    * @docs kyopro/docs/dijkstra.md\n*/\n\n\ntemplate<typename T = int>\nvector<T>\
    \ dijkstra(graph<T>& g, const int& v, const int& n, const T Inf) {\n\tpriority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;\n\tvector<T> res(n);\n\
    \tfill(all(res), Inf);\n\tpriq.push({ 0, v });\n\tres[v] = 0;\n\tint top;\n\t\
    while (!priq.empty()) {\n\t\ttop = priq.top().second;\n\t\tT cost = priq.top().first;\n\
    \t\tpriq.pop();\n\t\tif (cost > res[top])continue;\n\t\tfor (const auto& aa :\
    \ g[top]) {\n\t\t\tif (res[top] + aa.cost >= res[aa.to])continue;\n\t\t\tres[aa.to]\
    \ = aa.cost + res[top];\n\t\t\tpriq.push({ res[aa.to], aa.to });\n\t\t}\n\t}\n\
    \treturn res;\n}\n#line 7 \"kyopro/test/dijkstra_aoj.test.cpp\"\n\nint main()\
    \ {\n\n\tint v, e, r;\n\tscanf(\"%d%d%d\", &v, &e, &r);\n\tgraph<ll> g(v, true,\
    \ true);\n\tg.read(e, false);\n\tfor (const auto& aa : dijkstra<ll>(g, r, v, LINF))\
    \ {\n\t\tif (aa == LINF)puts(\"INF\");\n\t\telse printf(\"%lld\\n\", aa);\n\t\
    }\n\n\n\tPlease AC;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../library/template/template.cpp\"\n#include \"../library/graph/graph_template.cpp\"\
    \n\n#include \"../library/graph/dijkstra.cpp\"\n\nint main() {\n\n\tint v, e,\
    \ r;\n\tscanf(\"%d%d%d\", &v, &e, &r);\n\tgraph<ll> g(v, true, true);\n\tg.read(e,\
    \ false);\n\tfor (const auto& aa : dijkstra<ll>(g, r, v, LINF)) {\n\t\tif (aa\
    \ == LINF)puts(\"INF\");\n\t\telse printf(\"%lld\\n\", aa);\n\t}\n\n\n\tPlease\
    \ AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/graph/graph_template.cpp
  - kyopro/library/graph/dijkstra.cpp
  isVerificationFile: true
  path: kyopro/test/dijkstra_aoj.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/dijkstra_aoj.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/dijkstra_aoj.test.cpp
- /verify/kyopro/test/dijkstra_aoj.test.cpp.html
title: kyopro/test/dijkstra_aoj.test.cpp
---
