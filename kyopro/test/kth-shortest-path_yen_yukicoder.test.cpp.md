---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: kyopro/library/graph/graph_template.cpp
    title: template(graph)
  - icon: ':heavy_check_mark:'
    path: kyopro/library/graph/kth-shortest-path_yen.cpp
    title: kth-shortest-path(yen's algorithm)
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
    ERROR: 1e-4
    PROBLEM: https://yukicoder.me/problems/no/1069
    links:
    - https://yukicoder.me/problems/no/1069
  bundledCode: "#line 1 \"kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp\"\n\
    \uFEFF#define PROBLEM \"https://yukicoder.me/problems/no/1069\"\n\n#define ERROR\
    \ 1e-4\n\n#line 1 \"kyopro/library/template/template.cpp\"\n\uFEFF/*\n* @title\
    \ template\n* @docs kyopro/docs/template.md\n*/\n\n\n/*\n\u3053\u306E\u30B3\u30FC\
    \u30C9\u3001\u3068\uFF5E\u304A\u308C!\nBe accepted!\n\u2227\uFF3F\u2227\u3000\n\
    \uFF08\uFF61\uFF65\u03C9\uFF65\uFF61)\u3064\u2501\u2606\u30FB*\u3002\n\u2282\u3000\
    \u3000 \u30CE \u3000\u3000\u3000\u30FB\u309C+.\n\u3000\u3057\u30FC\uFF2A\u3000\
    \u3000\u3000\xB0\u3002+ *\xB4\xA8)\n \u3000\u3000\u3000\u3000\u3000\u3000\u3000\
    \u3000\u3000.\xB7 \xB4\xB8.\xB7*\xB4\xA8) \xB8.\xB7*\xA8)\n\t\t  \u3000\u3000\u3000\
    \u3000\u3000\u3000\u3000\u3000\u3000\u3000(\xB8.\xB7\xB4 (\xB8.\xB7'* \u2606\n\
    */\n\n#include <cstdio>\n#include <algorithm>\n#include <string>\n#include <cmath>\n\
    #include <cstring>\n#include <vector>\n#include <numeric>\n#include <iostream>\n\
    #include <random>\n#include <map>\n#include <unordered_map>\n#include <queue>\n\
    #include <regex>\n#include <functional>\n#include <complex>\n#include <list>\n\
    #include <cassert>\n#include <iomanip>\n#include <set>\n#include <stack>\n#include\
    \ <bitset>\n#include <array>\n#include <chrono>\n\n//#pragma GCC target(\"arch=skylake-avx512\"\
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
    \ --b;\n\t\t\tadd_edge(a, b, c);\n\t\t}\n\t}\n\n};\n#line 7 \"kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp\"\
    \n\n#line 1 \"kyopro/library/graph/kth-shortest-path_yen.cpp\"\n\uFEFF/*\n* @title\
    \ kth-shortest-path(yen's algorithm)\n* @docs kyopro/docs/kth-shortest-path_yen.md\n\
    */\n\n\n\ntemplate<typename T>\nvector<T> dijkstra(graph<T>& gh, vector<int>&\
    \ path, const int& v, const int& g, const int& n, const T Inf, const vector<vector<bool>>&\
    \ deleted, set<int> r) {\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> priq;\n\tvector<T> res(n);\n\tvector<int> prev(n);\n\t\
    fill(all(prev), -1);\n\tfill(all(res), Inf);\n\tpriq.push({ 0, v });\n\tres[v]\
    \ = 0;\n\tint top;\n\twhile (!priq.empty()) {\n\t\ttop = priq.top().second;\n\t\
    \tpriq.pop();\n\t\tfor (const auto& aa : gh[top]) {\n\t\t\tif (res[top] + aa.cost\
    \ >= res[aa.to] or deleted[top][aa.to] or r.find(aa.to) != r.end())continue;\n\
    \t\t\tres[aa.to] = aa.cost + res[top];\n\t\t\tprev[aa.to] = top;\n\t\t\tpriq.push({\
    \ res[aa.to], aa.to });\n\t\t}\n\t}\n\n\tfor (int i = g; i != -1; i = prev[i])path.push_back(i);\n\
    \treverse(all(path));\n\n\treturn res;\n}\n\ntemplate<typename T>\nvoid ksp(graph<T>&\
    \ g, const int& n, const int& start, const int& goal, const int& k, vector<vector<int>>&\
    \ path, vector<T>& ans, const T& Inf) {\n\tset<vector<int>> routememo;\n\tvector<T>\
    \ res, anstmp;\n\tvector<vector<bool>> deleted(n, vector<bool>(n));\n\tans.resize(k);\n\
    \tpath.resize(k);\n\tres = dijkstra<T>(g, path[0], start, goal, n, Inf, deleted,\
    \ {});\n\tans[0] = res[goal];\n\tanstmp = res;\n\troutememo.insert(path[0]);\n\
    \tauto func = [](const tuple<T, vector<int>, vector<T>>& a, const tuple<T, vector<int>,\
    \ vector<T>>& b) -> bool {\n\t\tif (get<0>(a) != get<0>(b))return get<0>(a) >\
    \ get<0>(b);\n\t\telse if (get<1>(a) != get<1>(b))return get<1>(a) > get<1>(b);\n\
    \t\telse return get<2>(a) > get<2>(b);\n\t};\n\tpriority_queue<tuple<T, vector<int>,\
    \ vector<T>>, vector<tuple<T, vector<int>, vector<T>>>, decltype(func)> priq{\
    \ func };\n\tmap<vector<int>, vector<int>> spurnode;\n\trep(i, k - 1) {\n\t\t\
    int siz = path[i].size();\n\t\tvector<int> route;\n\t\tset<int> r;\n\t\tT cost\
    \ = 0;\n\t\trep(j, siz - 1) {\n\t\t\troute.push_back(path[i][j]);\n\t\t\tr.insert(path[i][j]);\n\
    \t\t\tspurnode[route].push_back(path[i][j + 1]);\n\t\t\tif (j != 0) {\n\t\t\t\t\
    for (const auto& aa : g[path[i][j - 1]]) {\n\t\t\t\t\tif (aa.to == path[i][j])\
    \ {\n\t\t\t\t\t\tcost += aa.cost;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tfor (const auto& aa : spurnode[route])deleted[path[i][j]][aa] =\
    \ deleted[aa][path[i][j]] = true;\n\t\t\tif (j > 0)deleted[path[i][j - 1]][path[i][j]]\
    \ = deleted[path[i][j]][path[i][j - 1]] = true;\n\t\t\tres = dijkstra<T>(g, path[i\
    \ + 1], path[i][j], goal, n, Inf, deleted, r);\n\t\t\tif (j > 0)deleted[path[i][j\
    \ - 1]][path[i][j]] = deleted[path[i][j]][path[i][j - 1]] = false;\n\t\t\tfor\
    \ (const auto& aa : spurnode[route])deleted[path[i][j]][aa] = deleted[aa][path[i][j]]\
    \ = false;\n\t\t\tif (res[goal] >= Inf)continue;\n\t\t\tvector<int> tmp;\n\t\t\
    \tvector<T> tmp2(n);\n\t\t\tfor (int l = 0; l <= j; ++l) {\n\t\t\t\ttmp2[path[i][l]]\
    \ = anstmp[path[i][l]];\n\t\t\t}\n\t\t\tint l = 0;\n\t\t\tfor (; path[i][l] !=\
    \ path[i][j]; ++l) {\n\t\t\t\ttmp2[path[i][l]] = anstmp[path[i][l]];\n\t\t\t\t\
    tmp.push_back(path[i][l]);\n\t\t\t}\n\t\t\tfor (l = 0; path[i + 1][l] != goal;\
    \ ++l) {\n\t\t\t\ttmp2[path[i + 1][l]] = res[path[i + 1][l]];\n\t\t\t\ttmp.push_back(path[i\
    \ + 1][l]);\n\t\t\t}\n\t\t\ttmp.push_back(goal);\n\t\t\tint siz2 = path[i + 1].size();\n\
    \t\t\tfor (int l = 1; l < siz2; ++l) tmp2[path[i + 1][l]] = res[path[i + 1][l]]\
    \ + anstmp[path[i][j]];\n\t\t\tpriq.push(make_tuple(cost + res[goal], tmp, tmp2));\n\
    \t\t}\n\t\tif (priq.empty()) {\n\t\t\tfor (; i < k - 1; ++i)ans[i + 1] = -1;\n\
    \t\t\tbreak;\n\t\t}\n\t\tauto tmp = priq.top();\n\t\tpriq.pop();\n\t\twhile (routememo.find(get<1>(tmp))\
    \ != routememo.end() and !priq.empty()) {\n\t\t\ttmp = priq.top();\n\t\t\tpriq.pop();\n\
    \t\t}\n\t\tif (routememo.find(get<1>(tmp)) != routememo.end() and priq.empty())\
    \ {\n\t\t\tfor (; i < k - 1; ++i)ans[i + 1] = -1;\n\t\t\tbreak;\n\t\t}\n\t\tpath[i\
    \ + 1] = get<1>(tmp);\n\t\tans[i + 1] = get<0>(tmp);\n\t\troutememo.insert(path[i\
    \ + 1]);\n\t}\n\treturn;\n}\n#line 9 \"kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp\"\
    \n\nint main() {\n\n\tint n, m, k, x, y;\n\tscanf(\"%d%d%d%d%d\", &n, &m, &k,\
    \ &x, &y);\n\t--x; --y;\n\tgraph<long double> g(n, false, true);\n\tvector<pair<int,\
    \ int>> xy(n);\n\tset<vector<int>> routememo;\n\tint p, q;\n\trep(i, n) {\n\t\t\
    scanf(\"%d%d\", &p, &q);\n\t\txy[i] = { p, q };\n\t}\n\trep(i, m) {\n\t\tscanf(\"\
    %d%d\", &p, &q);\n\t\t--p; --q;\n\t\tlong double a = xy[p].first, b = xy[p].second,\
    \ c = xy[q].first, d = xy[q].second;\n\t\tg.add_edge(p, q, sqrt((c - a) * (c -\
    \ a) + (d - b) * (d - b)));\n\t}\n\tvector<vector<int>> path(k);\n\tvector<long\
    \ double> ans;\n\tksp<long double>(g, n, x, y, k, path, ans, numeric_limits<double>::infinity());\n\
    \trep(i, k)printLdb(ans[i]);\n\n\tPlease AC;\n}\n"
  code: "\uFEFF#define PROBLEM \"https://yukicoder.me/problems/no/1069\"\n\n#define\
    \ ERROR 1e-4\n\n#include \"../library/template/template.cpp\"\n#include \"../library/graph/graph_template.cpp\"\
    \n\n#include \"../library/graph/kth-shortest-path_yen.cpp\"\n\nint main() {\n\n\
    \tint n, m, k, x, y;\n\tscanf(\"%d%d%d%d%d\", &n, &m, &k, &x, &y);\n\t--x; --y;\n\
    \tgraph<long double> g(n, false, true);\n\tvector<pair<int, int>> xy(n);\n\tset<vector<int>>\
    \ routememo;\n\tint p, q;\n\trep(i, n) {\n\t\tscanf(\"%d%d\", &p, &q);\n\t\txy[i]\
    \ = { p, q };\n\t}\n\trep(i, m) {\n\t\tscanf(\"%d%d\", &p, &q);\n\t\t--p; --q;\n\
    \t\tlong double a = xy[p].first, b = xy[p].second, c = xy[q].first, d = xy[q].second;\n\
    \t\tg.add_edge(p, q, sqrt((c - a) * (c - a) + (d - b) * (d - b)));\n\t}\n\tvector<vector<int>>\
    \ path(k);\n\tvector<long double> ans;\n\tksp<long double>(g, n, x, y, k, path,\
    \ ans, numeric_limits<double>::infinity());\n\trep(i, k)printLdb(ans[i]);\n\n\t\
    Please AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/graph/graph_template.cpp
  - kyopro/library/graph/kth-shortest-path_yen.cpp
  isVerificationFile: true
  path: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
- /verify/kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp.html
title: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
---
