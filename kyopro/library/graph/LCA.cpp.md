---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/LCA_yosupo-judge.test.cpp
    title: kyopro/test/LCA_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/LCA.md
    document_title: lowest-common-ancestor
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/LCA.cpp\"\n\uFEFF/*\n* @title lowest-common-ancestor\n\
    * @docs kyopro/docs/LCA.md\n*/\n\n\ntemplate<typename T>\nvoid eulertour(const\
    \ int& now, const int& bef, int& cnt, graph<T>& graph, const int& d, vector<int>&\
    \ vs, vector<int>& depth, vector<int>& id) {\n\tdepth.emplace_back(d);\n\tvs.emplace_back(now);\n\
    \tid[now] = min(id[now], cnt);\n\tfor (const auto& aa : graph[now]) {\n\t\tif\
    \ (aa.to != bef) {\n\t\t\t++cnt;\n\t\t\teulertour(aa.to, now, cnt, graph, d +\
    \ 1, vs, depth, id);\n\t\t\t++cnt;\n\t\t\tdepth.emplace_back(d);\n\t\t\tvs.emplace_back(now);\n\
    \t\t}\n\t}\n}\n\ntemplate<typename T = int>\nstruct LCA {\n\n\tvector<int> vs,\
    \ depth, id, tmp = { 0 };\n\tgraph<T> tree;\n\tsparsetable<int> table{ tmp, 0\
    \ };\n\tint n, root;\n\n\t//\u6728,\u3000\u5927\u304D\u3055, \u6839\n\tLCA(graph<T>\
    \ tree, int n, int root) : tree(tree), n(n), root(root) {\n\t\tid.assign(n, INF);\n\
    \t\tint cnt = 0, d = 0;\n\t\teulertour(root, -1, cnt, tree, d, vs, depth, id);\n\
    \t\ttable.init(depth, depth.size());\n\t\ttable.build();\n\t}\n\n\t//LCA \u3067\
    \u3042\u308B\u9802\u70B9\u3092\u8FD4\u3059\n\tint query(int l, int r) {\n\t\t\
    if (id[l] > id[r])swap(l, r);\n\t\treturn vs[table.query(id[l], id[r] + 1)];\n\
    \t}\n\n\tint depthq(int n) {\n\t\treturn depth[id[n]];\n\t}\n};\n\n"
  code: "\uFEFF/*\n* @title lowest-common-ancestor\n* @docs kyopro/docs/LCA.md\n*/\n\
    \n\ntemplate<typename T>\nvoid eulertour(const int& now, const int& bef, int&\
    \ cnt, graph<T>& graph, const int& d, vector<int>& vs, vector<int>& depth, vector<int>&\
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
    int depthq(int n) {\n\t\treturn depth[id[n]];\n\t}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/LCA.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/LCA_yosupo-judge.test.cpp
documentation_of: kyopro/library/graph/LCA.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/LCA.cpp
- /library/kyopro/library/graph/LCA.cpp.html
title: lowest-common-ancestor
---
﻿