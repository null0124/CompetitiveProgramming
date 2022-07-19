---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/dijkstra_path_yosupo-judge.test.cpp
    title: kyopro/test/dijkstra_path_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/dijkstra_path.md
    document_title: "dijkstra(\u7D4C\u8DEF\u5FA9\u5143)"
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/dijkstra_path.cpp\"\n\uFEFF/*\n* @title\
    \ dijkstra(\u7D4C\u8DEF\u5FA9\u5143)\n* @docs kyopro/docs/dijkstra_path.md\n*/\n\
    \ntemplate<typename T>\nvector<T> dijkstra(graph<T>& gh, vector<int>& path, const\
    \ int& v, const int& g, const int& n, const T Inf, const bool f) {\n\tpriority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;\n\tvector<T> res(n);\n\
    \tvector<int> prev(n);\n\tfill(all(prev), -1);\n\tfill(all(res), Inf);\n\tpriq.push({\
    \ 0, v });\n\tres[v] = 0;\n\tint top;\n\twhile (!priq.empty()) {\n\t\tauto now\
    \ = priq.top();\n\t\ttop = now.second;\n\t\tpriq.pop();\n\t\tif (res[top] < now.first)continue;\n\
    \t\tfor (const auto& aa : gh[top]) {\n\t\t\tif (res[top] + aa.cost > res[aa.to])continue;\n\
    \t\t\telse if (res[top] + aa.cost == res[aa.to]) {\n\t\t\t\tif (f) prev[aa.to]\
    \ = min(top, prev[aa.to]);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tres[aa.to] = aa.cost\
    \ + res[top];\n\t\t\tprev[aa.to] = top;\n\t\t\tpriq.push({ res[aa.to], aa.to });\n\
    \t\t}\n\t}\n\n\tfor (int i = g; i != -1; i = prev[i])path.push_back(i);\n\n\t\
    reverse(all(path));\n\n\treturn res;\n}\n"
  code: "\uFEFF/*\n* @title dijkstra(\u7D4C\u8DEF\u5FA9\u5143)\n* @docs kyopro/docs/dijkstra_path.md\n\
    */\n\ntemplate<typename T>\nvector<T> dijkstra(graph<T>& gh, vector<int>& path,\
    \ const int& v, const int& g, const int& n, const T Inf, const bool f) {\n\tpriority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> priq;\n\tvector<T> res(n);\n\
    \tvector<int> prev(n);\n\tfill(all(prev), -1);\n\tfill(all(res), Inf);\n\tpriq.push({\
    \ 0, v });\n\tres[v] = 0;\n\tint top;\n\twhile (!priq.empty()) {\n\t\tauto now\
    \ = priq.top();\n\t\ttop = now.second;\n\t\tpriq.pop();\n\t\tif (res[top] < now.first)continue;\n\
    \t\tfor (const auto& aa : gh[top]) {\n\t\t\tif (res[top] + aa.cost > res[aa.to])continue;\n\
    \t\t\telse if (res[top] + aa.cost == res[aa.to]) {\n\t\t\t\tif (f) prev[aa.to]\
    \ = min(top, prev[aa.to]);\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tres[aa.to] = aa.cost\
    \ + res[top];\n\t\t\tprev[aa.to] = top;\n\t\t\tpriq.push({ res[aa.to], aa.to });\n\
    \t\t}\n\t}\n\n\tfor (int i = g; i != -1; i = prev[i])path.push_back(i);\n\n\t\
    reverse(all(path));\n\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/dijkstra_path.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/dijkstra_path_yosupo-judge.test.cpp
documentation_of: kyopro/library/graph/dijkstra_path.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/dijkstra_path.cpp
- /library/kyopro/library/graph/dijkstra_path.cpp.html
title: "dijkstra(\u7D4C\u8DEF\u5FA9\u5143)"
---
﻿