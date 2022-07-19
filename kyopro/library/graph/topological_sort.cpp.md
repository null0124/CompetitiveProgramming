---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: kyopro/docs/topological_sort.md
    document_title: topological-sort
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/topological_sort.cpp\"\n\uFEFF/*\n\
    * @title topological-sort\n* @docs kyopro/docs/topological_sort.md\n*/\n\ntemplate<typename\
    \ T = int>\nvector<int> topological_sort(graph<T>& g, const int& v) {\n\tvector<int>\
    \ ret, in(v);\n\n\tqueue<int> que;\n\trep(i, v) for (const auto& aa : g[i])++in[aa.to];\n\
    \trep(i, v) if (not in[i])que.push(i);\n\n\twhile (not que.empty()) {\n\t\tint\
    \ top = que.front();\n\t\tque.pop();\n\t\tfor (const auto& aa : g[top]) {\n\t\t\
    \t--in[aa.to];\n\t\t\tif (not in[aa.to])que.push(aa.to);\n\t\t}\n\t\tret.emplace_back(top);\n\
    \t}\n\treturn ret;\n}\n"
  code: "\uFEFF/*\n* @title topological-sort\n* @docs kyopro/docs/topological_sort.md\n\
    */\n\ntemplate<typename T = int>\nvector<int> topological_sort(graph<T>& g, const\
    \ int& v) {\n\tvector<int> ret, in(v);\n\n\tqueue<int> que;\n\trep(i, v) for (const\
    \ auto& aa : g[i])++in[aa.to];\n\trep(i, v) if (not in[i])que.push(i);\n\n\twhile\
    \ (not que.empty()) {\n\t\tint top = que.front();\n\t\tque.pop();\n\t\tfor (const\
    \ auto& aa : g[top]) {\n\t\t\t--in[aa.to];\n\t\t\tif (not in[aa.to])que.push(aa.to);\n\
    \t\t}\n\t\tret.emplace_back(top);\n\t}\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/graph/topological_sort.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/topological_sort.cpp
- /library/kyopro/library/graph/topological_sort.cpp.html
title: topological-sort
---
﻿