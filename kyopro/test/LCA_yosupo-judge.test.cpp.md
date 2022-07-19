---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/library/datastructure/sparsetable.cpp
    title: sparse-table
  - icon: ':heavy_check_mark:'
    path: kyopro/library/graph/LCA.cpp
    title: lowest-common-ancestor
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"kyopro/test/LCA_yosupo-judge.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"kyopro/library/template/template.cpp\"\
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
    \ --b;\n\t\t\tadd_edge(a, b, c);\n\t\t}\n\t}\n\n};\n#line 5 \"kyopro/test/LCA_yosupo-judge.test.cpp\"\
    \n\n#line 1 \"kyopro/library/datastructure/sparsetable.cpp\"\n/*\n* @title sparse-table\n\
    * @docs kyopro/docs/sparsetable.md\n*/\n\n//RMQ <O(n log n), O(1)>\ntemplate<typename\
    \ T>\nstruct sparsetable {\n\n\tvector<vector<T>> table;\n\tvector<int> logtable;\n\
    \tvector<int> a;\n\tint n;\n\n\t// \u6E21\u3059\u914D\u5217, \u30B5\u30A4\u30BA\
    \n\tsparsetable(const vector<T> a, int siz) : n(siz), a(a) {\n\t\tlogtable.assign(n\
    \ + 1, 0);\n\t\tfor (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\
    \t\ttable.assign(n, vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u30EA\u30B9\u30C8\
    \u30D0\u30FC\u30B8\u30E7\u30F3\n\tsparsetable(initializer_list<T> init) {\n\t\t\
    a = init[0];\n\t\tn = init[1];\n\t\tlogtable.assign(n + 1, 0);\n\t\tfor (int i\
    \ = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n, vector<T>(logtable[n]\
    \ + 1, 0));\n\t}\n\n\t//\u914D\u5217\u3068\u5927\u304D\u3055\u3092\u6E21\u3057\
    \u3066\u521D\u671F\u5316\n\tvoid init(const vector<T> aa, int siz) {\n\t\ta =\
    \ aa;\n\t\tn = siz;\n\t\tlogtable.assign(n + 1, 0);\n\t\tfor (int i = 2; i <=\
    \ n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n, vector<T>(logtable[n]\
    \ + 1, 0));\n\t}\n\n\t//\u69CB\u7BC9 O(n log n)\n\tvoid build() {\n\t\tfor (int\
    \ k = 0; (1 << k) <= n; ++k) {\n\t\t\tfor (int i = 0; i + (1 << k) <= n; ++i)\
    \ {\n\t\t\t\tif (k) table[i][k] = (a[table[i][k - 1]] < a[table[i + (1 << (k -\
    \ 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k - 1))][k - 1]);\n\t\t\t\t\
    else table[i][k] = i;\n\t\t\t}\n\t\t}\n\t}\n\n\t//[l, r) \u306E RMQ O(1)\n\tint\
    \ query(int l, int r) {\n\t\tint k = logtable[r - l];\n\t\treturn (a[table[l][k]]\
    \ < a[table[r - (1 << k)][k]] ? table[l][k] : table[r - (1 << k)][k]);\n\t}\n\n\
    };\n\n#line 7 \"kyopro/test/LCA_yosupo-judge.test.cpp\"\n\n#line 1 \"kyopro/library/graph/LCA.cpp\"\
    \n\uFEFF/*\n* @title lowest-common-ancestor\n* @docs kyopro/docs/LCA.md\n*/\n\n\
    \ntemplate<typename T>\nvoid eulertour(const int& now, const int& bef, int& cnt,\
    \ graph<T>& graph, const int& d, vector<int>& vs, vector<int>& depth, vector<int>&\
    \ id) {\n\tdepth.emplace_back(d);\n\tvs.emplace_back(now);\n\tid[now] = min(id[now],\
    \ cnt);\n\tfor (const auto& aa : graph[now]) {\n\t\tif (aa.to != bef) {\n\t\t\t\
    ++cnt;\n\t\t\teulertour(aa.to, now, cnt, graph, d + 1, vs, depth, id);\n\t\t\t\
    ++cnt;\n\t\t\tdepth.emplace_back(d);\n\t\t\tvs.emplace_back(now);\n\t\t}\n\t}\n\
    }\n\ntemplate<typename T = int>\nstruct LCA {\n\n\tvector<int> vs, depth, id,\
    \ tmp = { 0 };\n\tgraph<T> tree;\n\tsparsetable<int> table{ tmp, 0 };\n\tint n,\
    \ root;\n\n\t//\u6728,\u3000\u5927\u304D\u3055, \u6839\n\tLCA(graph<T> tree, int\
    \ n, int root) : tree(tree), n(n), root(root) {\n\t\tid.assign(n, INF);\n\t\t\
    int cnt = 0, d = 0;\n\t\teulertour(root, -1, cnt, tree, d, vs, depth, id);\n\t\
    \ttable.init(depth, depth.size());\n\t\ttable.build();\n\t}\n\n\t//LCA \u3067\u3042\
    \u308B\u9802\u70B9\u3092\u8FD4\u3059\n\tint query(int l, int r) {\n\t\tif (id[l]\
    \ > id[r])swap(l, r);\n\t\treturn vs[table.query(id[l], id[r] + 1)];\n\t}\n\n\t\
    int depthq(int n) {\n\t\treturn depth[id[n]];\n\t}\n};\n\n#line 9 \"kyopro/test/LCA_yosupo-judge.test.cpp\"\
    \n\nint main() {\n\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tgraph<int> tree(n,\
    \ true, false);\n\tint p;\n\trep(i, n - 1) {\n\t\tscanf(\"%d\", &p);\n\t\ttree.add_edge(p,\
    \ i + 1);\n\t}\n\tLCA lca(tree, n, 0);\n\tint v;\n\trep(i, q) {\n\t\tscanf(\"\
    %d%d\", &p, &v);\n\t\tprintf(\"%d\\n\", lca.query(p, v));\n\t}\n\n\tPlease AC;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../library/template/template.cpp\"\
    \n#include \"../library/graph/graph_template.cpp\"\n\n#include \"../library/datastructure/sparsetable.cpp\"\
    \n\n#include \"../library/graph/LCA.cpp\"\n\nint main() {\n\n\tint n, q;\n\tscanf(\"\
    %d%d\", &n, &q);\n\tgraph<int> tree(n, true, false);\n\tint p;\n\trep(i, n - 1)\
    \ {\n\t\tscanf(\"%d\", &p);\n\t\ttree.add_edge(p, i + 1);\n\t}\n\tLCA lca(tree,\
    \ n, 0);\n\tint v;\n\trep(i, q) {\n\t\tscanf(\"%d%d\", &p, &v);\n\t\tprintf(\"\
    %d\\n\", lca.query(p, v));\n\t}\n\n\tPlease AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/graph/graph_template.cpp
  - kyopro/library/datastructure/sparsetable.cpp
  - kyopro/library/graph/LCA.cpp
  isVerificationFile: true
  path: kyopro/test/LCA_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/LCA_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/LCA_yosupo-judge.test.cpp
- /verify/kyopro/test/LCA_yosupo-judge.test.cpp.html
title: kyopro/test/LCA_yosupo-judge.test.cpp
---
