---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/set_enumerate.test.cpp
    title: kyopro/test/set_enumerate.test.cpp
  - icon: ':x:'
    path: kyopro/test/unionfind_yosupo-judge.test.cpp
    title: kyopro/test/unionfind_yosupo-judge.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: kyopro/docs/unionfind.md
    document_title: unionfind
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/unionfind.cpp\"\n\uFEFF/*\n\
    * @title unionfind\n* @docs kyopro/docs/unionfind.md\n*/\n\n//0-indexed\nstruct\
    \ unionfind {\n\tvector<int> par, siz;\n\n\tunionfind(int n) : par(n), siz(n)\
    \ {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\t//\u5168\u90E8\u6839\u3067\u521D\
    \u671F\u5316\n\t\t\tpar[i] = i;\n\t\t\t//\u30B5\u30A4\u30BA\u306F1\n\t\t\tsiz[i]\
    \ = 1;\n\t\t}\n\t}\n\n\tvoid init(int n) {\n\t\tpar.resize(n);\n\t\tsiz.resize(n);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\t//\u5168\u90E8\u6839\u3067\u521D\u671F\
    \u5316\n\t\t\tpar[i] = i;\n\t\t\t//\u30B5\u30A4\u30BA\u306F1\n\t\t\tsiz[i] = 1;\n\
    \t\t}\n\t}\n\n\t//\u6839\u3092\u8FD4\u3059\n\tint find(int a) {\n\t\treturn par[a]\
    \ == a ? a : par[a] = find(par[a]);\n\t}\n\n\t//\u304F\u3063\u3064\u3051\u308B\
    \u3002\u5143\u304B\u3089\u540C\u3058\u3060\u3063\u305F\u3089false\u3092\u8FD4\u3059\
    \n\tbool unite(int a, int b) {\n\t\tint x = find(a), y = find(b);\n\t\tif (x ==\
    \ y)return false;\n\t\telse if (siz[x] < siz[y]) {\n\t\t\tpar[x] = y;\n\t\t\t\
    siz[y] += siz[x];\n\t\t}\n\t\telse if (siz[x] > siz[y]) {\n\t\t\tpar[y] = x;\n\
    \t\t\tsiz[x] += siz[y];\n\t\t}\n\t\telse {\n\t\t\tpar[x] = y;\n\t\t\tsiz[y] +=\
    \ siz[x];\n\t\t}\n\t\treturn true;\n\t}\n\n\t//\u540C\u3058\u96C6\u5408\u304B\u5224\
    \u5B9A\u3059\u308B\n\tbool same(int a, int b) {\n\t\treturn find(a) == find(b);\n\
    \t}\n\n\t//\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n\tint size(int a) {\n\t\treturn\
    \ siz[find(a)];\n\t}\n\n};\n"
  code: "\uFEFF/*\n* @title unionfind\n* @docs kyopro/docs/unionfind.md\n*/\n\n//0-indexed\n\
    struct unionfind {\n\tvector<int> par, siz;\n\n\tunionfind(int n) : par(n), siz(n)\
    \ {\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\t//\u5168\u90E8\u6839\u3067\u521D\
    \u671F\u5316\n\t\t\tpar[i] = i;\n\t\t\t//\u30B5\u30A4\u30BA\u306F1\n\t\t\tsiz[i]\
    \ = 1;\n\t\t}\n\t}\n\n\tvoid init(int n) {\n\t\tpar.resize(n);\n\t\tsiz.resize(n);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\t//\u5168\u90E8\u6839\u3067\u521D\u671F\
    \u5316\n\t\t\tpar[i] = i;\n\t\t\t//\u30B5\u30A4\u30BA\u306F1\n\t\t\tsiz[i] = 1;\n\
    \t\t}\n\t}\n\n\t//\u6839\u3092\u8FD4\u3059\n\tint find(int a) {\n\t\treturn par[a]\
    \ == a ? a : par[a] = find(par[a]);\n\t}\n\n\t//\u304F\u3063\u3064\u3051\u308B\
    \u3002\u5143\u304B\u3089\u540C\u3058\u3060\u3063\u305F\u3089false\u3092\u8FD4\u3059\
    \n\tbool unite(int a, int b) {\n\t\tint x = find(a), y = find(b);\n\t\tif (x ==\
    \ y)return false;\n\t\telse if (siz[x] < siz[y]) {\n\t\t\tpar[x] = y;\n\t\t\t\
    siz[y] += siz[x];\n\t\t}\n\t\telse if (siz[x] > siz[y]) {\n\t\t\tpar[y] = x;\n\
    \t\t\tsiz[x] += siz[y];\n\t\t}\n\t\telse {\n\t\t\tpar[x] = y;\n\t\t\tsiz[y] +=\
    \ siz[x];\n\t\t}\n\t\treturn true;\n\t}\n\n\t//\u540C\u3058\u96C6\u5408\u304B\u5224\
    \u5B9A\u3059\u308B\n\tbool same(int a, int b) {\n\t\treturn find(a) == find(b);\n\
    \t}\n\n\t//\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n\tint size(int a) {\n\t\treturn\
    \ siz[find(a)];\n\t}\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/unionfind.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - kyopro/test/unionfind_yosupo-judge.test.cpp
  - kyopro/test/set_enumerate.test.cpp
documentation_of: kyopro/library/datastructure/unionfind.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/unionfind.cpp
- /library/kyopro/library/datastructure/unionfind.cpp.html
title: unionfind
---
﻿