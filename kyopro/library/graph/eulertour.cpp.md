---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: kyopro/docs/eulertour.md
    document_title: euler-tour
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/eulertour.cpp\"\n\uFEFF/*\n* @title\
    \ euler-tour\n* @docs kyopro/docs/eulertour.md\n*/\n\ntemplate<typename T = int>\n\
    struct eulertour {\n\n\tvector<int> depth, child;\n\nprivate:\n\tvoid dfs(graph<T>&\
    \ g, const int& now, const int& bef, int& cnt) {\n\t\tdepth[now] = cnt;\n\t\t\
    for (const auto& aa : g[now]) {\n\t\t\tif (aa != bef) {\n\t\t\t\tdfs(g, aa, now,\
    \ ++cnt);\n\t\t\t\tchild[now] += child[aa] + 1;\n\t\t\t\t--cnt;\n\t\t\t}\n\t\t\
    }\n\t}\n\npublic:\n\teulertour(graph<T>& g, const int& n, const int& root) {\n\
    \t\tdepth.assign(n, 0);\n\t\tchild.assign(n, 0);\n\t\tint cnt = 0;\n\t\tdfs(g,\
    \ root, -1, cnt);\n\t}\n\n};\n"
  code: "\uFEFF/*\n* @title euler-tour\n* @docs kyopro/docs/eulertour.md\n*/\n\ntemplate<typename\
    \ T = int>\nstruct eulertour {\n\n\tvector<int> depth, child;\n\nprivate:\n\t\
    void dfs(graph<T>& g, const int& now, const int& bef, int& cnt) {\n\t\tdepth[now]\
    \ = cnt;\n\t\tfor (const auto& aa : g[now]) {\n\t\t\tif (aa != bef) {\n\t\t\t\t\
    dfs(g, aa, now, ++cnt);\n\t\t\t\tchild[now] += child[aa] + 1;\n\t\t\t\t--cnt;\n\
    \t\t\t}\n\t\t}\n\t}\n\npublic:\n\teulertour(graph<T>& g, const int& n, const int&\
    \ root) {\n\t\tdepth.assign(n, 0);\n\t\tchild.assign(n, 0);\n\t\tint cnt = 0;\n\
    \t\tdfs(g, root, -1, cnt);\n\t}\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/eulertour.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/graph/eulertour.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/eulertour.cpp
- /library/kyopro/library/graph/eulertour.cpp.html
title: euler-tour
---
﻿