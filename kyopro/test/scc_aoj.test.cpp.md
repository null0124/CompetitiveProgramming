---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: kyopro/library/graph/graph_template.cpp
    title: template(graph)
  - icon: ':heavy_check_mark:'
    path: kyopro/library/graph/scc.cpp
    title: "strongly connected components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C
  bundledCode: "#line 1 \"kyopro/test/scc_aoj.test.cpp\"\n\uFEFF#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\n\n\n#line 1 \"kyopro/library/template/template.cpp\"\
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
    #line 5 \"kyopro/test/scc_aoj.test.cpp\"\n\n#line 1 \"kyopro/library/graph/graph_template.cpp\"\
    \n\uFEFF/*\n* @title template(graph)\n* @docs kyopro/docs/graph_template.md\n\
    */\n\ntemplate<typename T>\nstruct edge {\n\tT cost;\n\tint from, to;\n\n\tedge(int\
    \ from, int to) : from(from), to(to), cost(T(1)) {}\n\tedge(int from, int to,\
    \ T cost) : from(from), to(to), cost(cost) {}\n};\n\ntemplate<typename T = int>\n\
    struct graph {\n\n\tint n;\n\tbool directed, weighted;\n\n\tvector<vector<edge<T>>>\
    \ g;\n\n\tgraph(int n, bool directed, bool weighted) : g(n), n(n), directed(directed),\
    \ weighted(weighted) {}\n\n\tvoid add_edge(int from, int to, T cost = T(1)) {\n\
    \t\tg[from].emplace_back(from, to, cost);\n\t\tif (not directed) {\n\t\t\tg[to].emplace_back(to,\
    \ from, cost);\n\t\t}\n\t}\n\n\tvector<edge<T>>& operator[](const int& idx) {\n\
    \t\treturn g[idx];\n\t}\n\n\tvoid read(int e, bool one_indexed) {\n\t\tint a,\
    \ b, c = 1;\n\t\twhile (e--) {\n\t\t\tscanf(\"%d%d\", &a, &b);\n\t\t\tif (weighted)\
    \ {\n\t\t\t\tscanf(\"%d\", &c);\n\t\t\t}\n\t\t\tif (one_indexed)--a, --b;\n\t\t\
    \tadd_edge(a, b, c);\n\t\t}\n\t}\n\n\tvoid read(int e, bool one_indexed, const\
    \ string& format) {\n\t\tint a, b;\n\t\tT c = T(1);\n\t\twhile (e--) {\n\t\t\t\
    scanf(\"%d%d\", &a, &b);\n\t\t\tif (weighted) {\n\t\t\t\tscanf(format.c_str(),\
    \ &c);\n\t\t\t}\n\t\t\tif (one_indexed)--a, --b;\n\t\t\tadd_edge(a, b, c);\n\t\
    \t}\n\t}\n\n};\n#line 1 \"kyopro/library/graph/scc.cpp\"\n\uFEFF/*\n* @title strongly\
    \ connected components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n* @docs kyopro/docs/scc.md\n\
    */\n\ntemplate<typename T = int>\nstruct stronglyconnectedcomponents {\n\n\tint\
    \ n, cur = 0;\n\t//g: \u5143\u306E\u30B0\u30E9\u30D5, gg: \u9006\u5F35\u308A\u30B0\
    \u30E9\u30D5, cg: \u5F37\u9023\u7D50\u6210\u5206\u3067\u5727\u7E2E\u3057\u305F\
    \u30B0\u30E9\u30D5, sg: \u5F37\u9023\u7D50\u6210\u5206\u3060\u3051\u306E\u30B0\
    \u30E9\u30D5\n\tgraph<T> g, cg, sg, gg;\n\tvector<int> num, siz;\n\tvector<vector<int>>\
    \ vert;\n\n\tstronglyconnectedcomponents(const int& n, graph<T>& g) : n(n), g(g),\
    \ cg(n, g.directed, g.weighted), sg(n, g.directed, g.weighted), gg(n, g.directed,\
    \ g.weighted), num(n) {\n\t\trep(i, n) for (const auto& aa : g[i])gg.add_edge(aa.to,\
    \ aa.from, aa.cost);\n\t}\n\n\tvoid dfs(const int& now, stack<int>& st, vector<bool>&\
    \ visited) {\n\t\tvisited[now] = true;\n\t\tfor (const auto& aa : g[now])if (not\
    \ visited[aa.to])dfs(aa.to, st, visited);\n\t\tst.push(now);\n\t}\n\n\tvoid build()\
    \ {\n\t\tstack<int> s, st;\n\t\tvector<bool> visited(n);\n\t\trep(i, n) {\n\t\t\
    \tif (not visited[i]) dfs(i, st, visited);\n\t\t}\n\t\tfill(all(visited), false);\n\
    \t\twhile (not st.empty()) {\n\t\t\tint v = st.top();\n\t\t\tst.pop();\n\t\t\t\
    if (not visited[v]) {\n\t\t\t\ts.push(v);\n\t\t\t\twhile (not s.empty()) {\n\t\
    \t\t\t\tint ver = s.top();\n\t\t\t\t\ts.pop();\n\t\t\t\t\tnum[ver] = cur;\n\t\t\
    \t\t\tfor (const auto& aa : gg[ver]) if (not visited[aa.to])s.push(aa.to);\n\t\
    \t\t\t\tvisited[ver] = true;\n\t\t\t\t}\n\t\t\t\t++cur;\n\t\t\t}\n\t\t}\n\t\t\
    siz.assign(cur, 1);\n\t\tvert.assign(cur, {});\n\t\tfill(all(visited), false);\n\
    \t\trep(i, n) {\n\t\t\tif (not visited[i])vert[num[i]].push_back(i);\n\t\t\tvisited[i]\
    \ = true;\n\t\t\tfor (const auto& aa : g[i]) {\n\t\t\t\tif (num[aa.to] == num[i])\
    \ {\n\t\t\t\t\tsg.add_edge(aa.from, aa.to, aa.cost);\n\t\t\t\t\tif (not visited[aa.to])\
    \ {\n\t\t\t\t\t\t++siz[num[aa.to]];\n\t\t\t\t\t\tvisited[aa.to] = true;\n\t\t\t\
    \t\t\tvert[num[i]].push_back(aa.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\telse {\n\
    \t\t\t\t\tcg.add_edge(num[aa.from], num[aa.to], aa.cost);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\n\tint operator[](const int& i) { return num[i]; }\n\n\tint size()\
    \ { return cur; }\n\tint size(const int& i) { return siz[i]; }\n\n};\n#line 8\
    \ \"kyopro/test/scc_aoj.test.cpp\"\n\n\nint main() {\n\n\tint v, e;\n\tscanf(\"\
    %d%d\", &v, &e);\n\tgraph<int> g(v, true, false);\n\tg.read(e, false);\n\tstronglyconnectedcomponents<int>\
    \ s(v, g);\n\ts.build();\n\tint q;\n\tscanf(\"%d\", &q);\n\twhile (q--) {\n\t\t\
    scanf(\"%d%d\", &v, &e);\n\t\tprintf(\"%d\\n\", (s[v] == s[e]));\n\t}\n\n\tPlease\
    \ AC;\n}\n"
  code: "\uFEFF#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C\"\
    \n\n\n#include \"../library/template/template.cpp\"\n\n#include \"../library/graph/graph_template.cpp\"\
    \n#include \"../library/graph/scc.cpp\"\n\n\nint main() {\n\n\tint v, e;\n\tscanf(\"\
    %d%d\", &v, &e);\n\tgraph<int> g(v, true, false);\n\tg.read(e, false);\n\tstronglyconnectedcomponents<int>\
    \ s(v, g);\n\ts.build();\n\tint q;\n\tscanf(\"%d\", &q);\n\twhile (q--) {\n\t\t\
    scanf(\"%d%d\", &v, &e);\n\t\tprintf(\"%d\\n\", (s[v] == s[e]));\n\t}\n\n\tPlease\
    \ AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/graph/graph_template.cpp
  - kyopro/library/graph/scc.cpp
  isVerificationFile: true
  path: kyopro/test/scc_aoj.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/scc_aoj.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/scc_aoj.test.cpp
- /verify/kyopro/test/scc_aoj.test.cpp.html
title: kyopro/test/scc_aoj.test.cpp
---
