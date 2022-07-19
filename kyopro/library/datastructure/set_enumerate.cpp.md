---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/set_enumerate.test.cpp
    title: kyopro/test/set_enumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/set_enumerate.md
    document_title: set_enumerate
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/set_enumerate.cpp\"\n\uFEFF\
    /*\n* @title set_enumerate\n* @docs kyopro/docs/set_enumerate.md\n*/\n\nstruct\
    \ set_enumerate {\n\n\tint n;\n\tvector<int> next;\n\tunionfind uni;\n\n\tset_enumerate(int\
    \ siz) : n(siz), next(siz), uni(n) {\n\t\tnext.assign(siz, 0);\n\t\trep(i, siz)next[i]\
    \ = i;\n\t}\n\n\tint size() {\n\t\treturn n;\n\t}\n\n\tvector<int> enumerate(const\
    \ int x) {\n\t\tvector<int> ret;\n\t\tint cur = x;\n\t\tdo {\n\t\t\tret.emplace_back(cur);\n\
    \t\t\tcur = next[cur];\n\t\t} while (cur != x);\n\t\treturn ret;\n\t}\n\n\tvector<vector<int>>\
    \ get_all() {\n\t\tvector<vector<int>> ret;\n\t\tvector<bool> visited(n);\n\t\t\
    rep(i, n) {\n\t\t\tif (not visited[i]) {\n\t\t\t\tret.emplace_back(enumerate(i));\n\
    \t\t\t\tfor (const auto& i : ret.back())visited[i] = true;\n\t\t\t}\n\t\t}\n\t\
    \treturn ret;\n\t}\n\n\tvoid unite(const int x, const int y) {\n\t\tif (not uni.same(x,\
    \ y)) swap(next[x], next[y]);\n\t\tuni.unite(x, y);\n\t}\n\n\tbool same(int a,\
    \ int b) { return uni.same(a, b); }\n\n\tint find(int a) { return uni.find(a);\
    \ }\n\n\tint size(int i) { return uni.size(i); }\n\n};\n"
  code: "\uFEFF/*\n* @title set_enumerate\n* @docs kyopro/docs/set_enumerate.md\n\
    */\n\nstruct set_enumerate {\n\n\tint n;\n\tvector<int> next;\n\tunionfind uni;\n\
    \n\tset_enumerate(int siz) : n(siz), next(siz), uni(n) {\n\t\tnext.assign(siz,\
    \ 0);\n\t\trep(i, siz)next[i] = i;\n\t}\n\n\tint size() {\n\t\treturn n;\n\t}\n\
    \n\tvector<int> enumerate(const int x) {\n\t\tvector<int> ret;\n\t\tint cur =\
    \ x;\n\t\tdo {\n\t\t\tret.emplace_back(cur);\n\t\t\tcur = next[cur];\n\t\t} while\
    \ (cur != x);\n\t\treturn ret;\n\t}\n\n\tvector<vector<int>> get_all() {\n\t\t\
    vector<vector<int>> ret;\n\t\tvector<bool> visited(n);\n\t\trep(i, n) {\n\t\t\t\
    if (not visited[i]) {\n\t\t\t\tret.emplace_back(enumerate(i));\n\t\t\t\tfor (const\
    \ auto& i : ret.back())visited[i] = true;\n\t\t\t}\n\t\t}\n\t\treturn ret;\n\t\
    }\n\n\tvoid unite(const int x, const int y) {\n\t\tif (not uni.same(x, y)) swap(next[x],\
    \ next[y]);\n\t\tuni.unite(x, y);\n\t}\n\n\tbool same(int a, int b) { return uni.same(a,\
    \ b); }\n\n\tint find(int a) { return uni.find(a); }\n\n\tint size(int i) { return\
    \ uni.size(i); }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/set_enumerate.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/set_enumerate.test.cpp
documentation_of: kyopro/library/datastructure/set_enumerate.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/set_enumerate.cpp
- /library/kyopro/library/datastructure/set_enumerate.cpp.html
title: set_enumerate
---
﻿