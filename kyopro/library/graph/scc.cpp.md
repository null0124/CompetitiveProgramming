---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/scc-cg_aoj.test.cpp
    title: kyopro/test/scc-cg_aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/scc_aoj.test.cpp
    title: kyopro/test/scc_aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/scc_yosupo-judge.test.cpp
    title: kyopro/test/scc_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/scc.md
    document_title: "strongly connected components(\u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3)"
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/scc.cpp\"\n\uFEFF/*\n* @title strongly\
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
    \ { return cur; }\n\tint size(const int& i) { return siz[i]; }\n\n};\n"
  code: "\uFEFF/*\n* @title strongly connected components(\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3)\n* @docs kyopro/docs/scc.md\n*/\n\ntemplate<typename T = int>\n\
    struct stronglyconnectedcomponents {\n\n\tint n, cur = 0;\n\t//g: \u5143\u306E\
    \u30B0\u30E9\u30D5, gg: \u9006\u5F35\u308A\u30B0\u30E9\u30D5, cg: \u5F37\u9023\
    \u7D50\u6210\u5206\u3067\u5727\u7E2E\u3057\u305F\u30B0\u30E9\u30D5, sg: \u5F37\
    \u9023\u7D50\u6210\u5206\u3060\u3051\u306E\u30B0\u30E9\u30D5\n\tgraph<T> g, cg,\
    \ sg, gg;\n\tvector<int> num, siz;\n\tvector<vector<int>> vert;\n\n\tstronglyconnectedcomponents(const\
    \ int& n, graph<T>& g) : n(n), g(g), cg(n, g.directed, g.weighted), sg(n, g.directed,\
    \ g.weighted), gg(n, g.directed, g.weighted), num(n) {\n\t\trep(i, n) for (const\
    \ auto& aa : g[i])gg.add_edge(aa.to, aa.from, aa.cost);\n\t}\n\n\tvoid dfs(const\
    \ int& now, stack<int>& st, vector<bool>& visited) {\n\t\tvisited[now] = true;\n\
    \t\tfor (const auto& aa : g[now])if (not visited[aa.to])dfs(aa.to, st, visited);\n\
    \t\tst.push(now);\n\t}\n\n\tvoid build() {\n\t\tstack<int> s, st;\n\t\tvector<bool>\
    \ visited(n);\n\t\trep(i, n) {\n\t\t\tif (not visited[i]) dfs(i, st, visited);\n\
    \t\t}\n\t\tfill(all(visited), false);\n\t\twhile (not st.empty()) {\n\t\t\tint\
    \ v = st.top();\n\t\t\tst.pop();\n\t\t\tif (not visited[v]) {\n\t\t\t\ts.push(v);\n\
    \t\t\t\twhile (not s.empty()) {\n\t\t\t\t\tint ver = s.top();\n\t\t\t\t\ts.pop();\n\
    \t\t\t\t\tnum[ver] = cur;\n\t\t\t\t\tfor (const auto& aa : gg[ver]) if (not visited[aa.to])s.push(aa.to);\n\
    \t\t\t\t\tvisited[ver] = true;\n\t\t\t\t}\n\t\t\t\t++cur;\n\t\t\t}\n\t\t}\n\t\t\
    siz.assign(cur, 1);\n\t\tvert.assign(cur, {});\n\t\tfill(all(visited), false);\n\
    \t\trep(i, n) {\n\t\t\tif (not visited[i])vert[num[i]].push_back(i);\n\t\t\tvisited[i]\
    \ = true;\n\t\t\tfor (const auto& aa : g[i]) {\n\t\t\t\tif (num[aa.to] == num[i])\
    \ {\n\t\t\t\t\tsg.add_edge(aa.from, aa.to, aa.cost);\n\t\t\t\t\tif (not visited[aa.to])\
    \ {\n\t\t\t\t\t\t++siz[num[aa.to]];\n\t\t\t\t\t\tvisited[aa.to] = true;\n\t\t\t\
    \t\t\tvert[num[i]].push_back(aa.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\telse {\n\
    \t\t\t\t\tcg.add_edge(num[aa.from], num[aa.to], aa.cost);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\n\tint operator[](const int& i) { return num[i]; }\n\n\tint size()\
    \ { return cur; }\n\tint size(const int& i) { return siz[i]; }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/scc.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/scc_aoj.test.cpp
  - kyopro/test/scc-cg_aoj.test.cpp
  - kyopro/test/scc_yosupo-judge.test.cpp
documentation_of: kyopro/library/graph/scc.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/scc.cpp
- /library/kyopro/library/graph/scc.cpp.html
title: "strongly connected components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)"
---
﻿