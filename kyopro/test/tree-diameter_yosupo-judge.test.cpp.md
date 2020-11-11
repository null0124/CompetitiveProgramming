---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: kyopro/library/graph/graph_template.cpp
    title: template(graph)
  - icon: ':heavy_check_mark:'
    path: kyopro/library/graph/tree-diameter.cpp
    title: "tree diameter(\u6728\u306E\u76F4\u5F84)"
  - icon: ':question:'
    path: kyopro/library/template/template.cpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"kyopro/test/tree-diameter_yosupo-judge.test.cpp\"\n\uFEFF\
    #define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 1 \"\
    kyopro/library/template/template.cpp\"\n\uFEFF/*\n* @title template\n* @docs kyopro/docs/template.md\n\
    */\n\n\n/*\n\u3053\u306E\u30B3\u30FC\u30C9\u3001\u3068\uFF5E\u304A\u308C!\nBe\
    \ accepted!\n\u2227\uFF3F\u2227\u3000\n\uFF08\uFF61\uFF65\u03C9\uFF65\uFF61)\u3064\
    \u2501\u2606\u30FB*\u3002\n\u2282\u3000\u3000 \u30CE \u3000\u3000\u3000\u30FB\u309C\
    +.\n\u3000\u3057\u30FC\uFF2A\u3000\u3000\u3000\xB0\u3002+ *\xB4\xA8)\n \u3000\u3000\
    \u3000\u3000\u3000\u3000\u3000\u3000\u3000.\xB7 \xB4\xB8.\xB7*\xB4\xA8) \xB8.\xB7\
    *\xA8)\n\t\t  \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000(\xB8\
    .\xB7\xB4 (\xB8.\xB7'* \u2606\n*/\n\n#include <cstdio>\n#include <algorithm>\n\
    #include <string>\n#include <cmath>\n#include <cstring>\n#include <vector>\n#include\
    \ <numeric>\n#include <iostream>\n#include <random>\n#include <map>\n#include\
    \ <unordered_map>\n#include <queue>\n#include <regex>\n#include <functional>\n\
    #include <complex>\n#include <list>\n#include <cassert>\n#include <iomanip>\n\
    #include <set>\n#include <stack>\n#include <bitset>\n\n////\u591A\u500D\u9577\u6574\
    \u6570, cpp_int\u3067\u5BA3\u8A00\n//#include <boost/multiprecision/cpp_int.hpp>\n\
    //using namespace boost::multiprecision;\n\n//#pragma GCC target (\"avx2\")\n\
    //#pragma GCC optimization (\"O3\")\n//#pragma GCC optimization (\"unroll-loops\"\
    )\n//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\"\
    )\n#define repeat(i, n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int\
    \ i = 0; i < (n); ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\"\
    )\n#define printyn(a) printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a\
    \ ? \"YES\\n\" : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"\
    imposible\\n\")\n#define printdb(a) printf(\"%.50lf\\n\", a) //\u5C11\u6570\u51FA\
    \u529B\n#define printLdb(a) printf(\"%.50Lf\\n\", a) //\u5C11\u6570\u51FA\u529B\
    \n#define printdbd(a) printf(\"%.16lf\\n\", a) //\u5C11\u6570\u51FA\u529B(\u6841\
    \u5C11\u306A\u3081)\n#define prints(s) printf(\"%s\\n\", s.c_str()) //string\u51FA\
    \u529B\n#define all(x) (x).begin(), (x).end()\n#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)\n\
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
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n#line 4 \"kyopro/test/tree-diameter_yosupo-judge.test.cpp\"\
    \n\n#line 1 \"kyopro/library/graph/graph_template.cpp\"\n\uFEFF/*\n* @title template(graph)\n\
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
    \ --b;\n\t\t\tadd_edge(a, b, c);\n\t\t}\n\t}\n\n};\n#line 1 \"kyopro/library/graph/tree-diameter.cpp\"\
    \n\uFEFF/*\n* @title tree diameter(\u6728\u306E\u76F4\u5F84)\n* @docs kyopro/docs/tree-diameter.md\n\
    */\n\ntemplate<typename T = int>\nvoid diameter1(graph<T>& g, const int& cur,\
    \ const int& bef, const T& cnt, T& ma, int& idx) {\n\tif (cnt > ma)ma = cnt, idx\
    \ = cur;\n\tfor (const auto& aa : g[cur]) if (aa.to != bef)diameter1<T>(g, aa.to,\
    \ cur, cnt + aa.cost, ma, idx);\n}\n\ntemplate<typename T = int>\nvoid diameter2(graph<T>&\
    \ g, const int& cur, const int& bef, vector<int>& ret, vector<int>& route, const\
    \ T& cnt, T& cost) {\n\troute.emplace_back(cur);\n\tif (g[cur].size() == 1 and\
    \ cost < cnt) {\n\t\tcost = cnt;\n\t\tret = route;\n\t}\n\tfor (const auto& aa\
    \ : g[cur])if (aa.to != bef)diameter2<T>(g, aa.to, cur, ret, route, cnt + aa.cost,\
    \ cost);\n\troute.pop_back();\n}\n\ntemplate<typename T = int>\nvector<int> diameter(graph<T>&\
    \ g, T& cost, const int& cur = 0) {\n\tT ma = 0;\n\tint idx = cur;\n\tdiameter1<T>(g,\
    \ cur, -1, (T)0, ma, idx);\n\tma = 0;\n\tvector<int> ret, route;\n\tdiameter2<T>(g,\
    \ idx, -1, ret, route, 0, cost);\n\treverse(all(ret));\n\treturn ret;\n}\n#line\
    \ 7 \"kyopro/test/tree-diameter_yosupo-judge.test.cpp\"\n\nint main() {\n\n\t\
    int n;\n\tscanf(\"%d\", &n);\n\tgraph<ll> g(n, false, true);\n\tg.read(n - 1,\
    \ false, \"%lld\");\n\tll ans = 0;\n\tauto v = diameter<ll>(g, ans);\n\tprintf(\"\
    %lld %d\\n\", ans, (int)v.size());\n\tfor (const auto& aa : v)printf(\"%d \",\
    \ aa);\n\n\tPlease AC;\n}\n"
  code: "\uFEFF#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\
    \n#include \"../library/template/template.cpp\"\n\n#include \"../library/graph/graph_template.cpp\"\
    \n#include \"../library/graph/tree-diameter.cpp\"\n\nint main() {\n\n\tint n;\n\
    \tscanf(\"%d\", &n);\n\tgraph<ll> g(n, false, true);\n\tg.read(n - 1, false, \"\
    %lld\");\n\tll ans = 0;\n\tauto v = diameter<ll>(g, ans);\n\tprintf(\"%lld %d\\\
    n\", ans, (int)v.size());\n\tfor (const auto& aa : v)printf(\"%d \", aa);\n\n\t\
    Please AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/graph/graph_template.cpp
  - kyopro/library/graph/tree-diameter.cpp
  isVerificationFile: true
  path: kyopro/test/tree-diameter_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '2020-09-07 03:51:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/tree-diameter_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/tree-diameter_yosupo-judge.test.cpp
- /verify/kyopro/test/tree-diameter_yosupo-judge.test.cpp.html
title: kyopro/test/tree-diameter_yosupo-judge.test.cpp
---
