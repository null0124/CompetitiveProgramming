---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/dijkstra_aoj.test.cpp
    title: kyopro/test/dijkstra_aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/dijkstra.md
    document_title: dijkstra
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/dijkstra.cpp\"\n\uFEFF/*\n* @title\
    \ dijkstra\n* @docs kyopro/docs/dijkstra.md\n*/\n\n\ntemplate<typename T = int>\n\
    vector<T> dijkstra(graph<T>& g, const int& v, const int& n, const T Inf) {\n\t\
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;\n\
    \tvector<T> res(n);\n\tfill(all(res), Inf);\n\tpriq.push({ 0, v });\n\tres[v]\
    \ = 0;\n\tint top;\n\twhile (!priq.empty()) {\n\t\ttop = priq.top().second;\n\t\
    \tT cost = priq.top().first;\n\t\tpriq.pop();\n\t\tif (cost > res[top])continue;\n\
    \t\tfor (const auto& aa : g[top]) {\n\t\t\tif (res[top] + aa.cost >= res[aa.to])continue;\n\
    \t\t\tres[aa.to] = aa.cost + res[top];\n\t\t\tpriq.push({ res[aa.to], aa.to });\n\
    \t\t}\n\t}\n\treturn res;\n}\n"
  code: "\uFEFF/*\n* @title dijkstra\n* @docs kyopro/docs/dijkstra.md\n*/\n\n\ntemplate<typename\
    \ T = int>\nvector<T> dijkstra(graph<T>& g, const int& v, const int& n, const\
    \ T Inf) {\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> priq;\n\tvector<T> res(n);\n\tfill(all(res), Inf);\n\tpriq.push({ 0,\
    \ v });\n\tres[v] = 0;\n\tint top;\n\twhile (!priq.empty()) {\n\t\ttop = priq.top().second;\n\
    \t\tT cost = priq.top().first;\n\t\tpriq.pop();\n\t\tif (cost > res[top])continue;\n\
    \t\tfor (const auto& aa : g[top]) {\n\t\t\tif (res[top] + aa.cost >= res[aa.to])continue;\n\
    \t\t\tres[aa.to] = aa.cost + res[top];\n\t\t\tpriq.push({ res[aa.to], aa.to });\n\
    \t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/dijkstra_aoj.test.cpp
documentation_of: kyopro/library/graph/dijkstra.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/dijkstra.cpp
- /library/kyopro/library/graph/dijkstra.cpp.html
title: dijkstra
---
﻿