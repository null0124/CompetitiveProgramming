---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/LCA_weighted_yukicoder.test.cpp
    title: kyopro/test/LCA_weighted_yukicoder.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/LCA_yosupo-judge.test.cpp
    title: kyopro/test/LCA_yosupo-judge.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/dijkstra_aoj.test.cpp
    title: kyopro/test/dijkstra_aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/dijkstra_path_yosupo-judge.test.cpp
    title: kyopro/test/dijkstra_path_yosupo-judge.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
    title: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/scc-cg_aoj.test.cpp
    title: kyopro/test/scc-cg_aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/scc_aoj.test.cpp
    title: kyopro/test/scc_aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/scc_yosupo-judge.test.cpp
    title: kyopro/test/scc_yosupo-judge.test.cpp
  - icon: ':x:'
    path: kyopro/test/tree-diameter_aoj.test.cpp
    title: kyopro/test/tree-diameter_aoj.test.cpp
  - icon: ':x:'
    path: kyopro/test/tree-diameter_yosupo-judge.test.cpp
    title: kyopro/test/tree-diameter_yosupo-judge.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: kyopro/docs/graph_template.md
    document_title: template(graph)
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/graph_template.cpp\"\n\uFEFF/*\n* @title\
    \ template(graph)\n* @docs kyopro/docs/graph_template.md\n*/\n\ntemplate<typename\
    \ T>\nstruct edge {\n\tT cost;\n\tint from, to;\n\n\tedge(int from, int to) :\
    \ from(from), to(to), cost(T(1)) {}\n\tedge(int from, int to, T cost) : from(from),\
    \ to(to), cost(cost) {}\n};\n\ntemplate<typename T = int>\nstruct graph {\n\n\t\
    int n;\n\tbool directed, weighted;\n\n\tvector<vector<edge<T>>> g;\n\n\tgraph(int\
    \ n, bool directed, bool weighted) : g(n), n(n), directed(directed), weighted(weighted)\
    \ {}\n\n\tvoid add_edge(int from, int to, T cost = T(1)) {\n\t\tg[from].emplace_back(from,\
    \ to, cost);\n\t\tif (not directed) {\n\t\t\tg[to].emplace_back(to, from, cost);\n\
    \t\t}\n\t}\n\n\tvector<edge<T>>& operator[](const int& idx) {\n\t\treturn g[idx];\n\
    \t}\n\n\tvoid read(int e, bool one_indexed) {\n\t\tint a, b, c = 1;\n\t\twhile\
    \ (e--) {\n\t\t\tscanf(\"%d%d\", &a, &b);\n\t\t\tif (weighted) {\n\t\t\t\tscanf(\"\
    %d\", &c);\n\t\t\t}\n\t\t\tif (one_indexed)--a, --b;\n\t\t\tadd_edge(a, b, c);\n\
    \t\t}\n\t}\n\n\tvoid read(int e, bool one_indexed, const string& format) {\n\t\
    \tint a, b;\n\t\tT c = T(1);\n\t\twhile (e--) {\n\t\t\tscanf(\"%d%d\", &a, &b);\n\
    \t\t\tif (weighted) {\n\t\t\t\tscanf(format.c_str(), &c);\n\t\t\t}\n\t\t\tif (one_indexed)--a,\
    \ --b;\n\t\t\tadd_edge(a, b, c);\n\t\t}\n\t}\n\n};\n"
  code: "\uFEFF/*\n* @title template(graph)\n* @docs kyopro/docs/graph_template.md\n\
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
    \t}\n\t}\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/graph_template.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - kyopro/test/scc_aoj.test.cpp
  - kyopro/test/dijkstra_path_yosupo-judge.test.cpp
  - kyopro/test/LCA_yosupo-judge.test.cpp
  - kyopro/test/dijkstra_aoj.test.cpp
  - kyopro/test/scc-cg_aoj.test.cpp
  - kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
  - kyopro/test/tree-diameter_aoj.test.cpp
  - kyopro/test/scc_yosupo-judge.test.cpp
  - kyopro/test/LCA_weighted_yukicoder.test.cpp
  - kyopro/test/tree-diameter_yosupo-judge.test.cpp
documentation_of: kyopro/library/graph/graph_template.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/graph_template.cpp
- /library/kyopro/library/graph/graph_template.cpp.html
title: template(graph)
---
﻿