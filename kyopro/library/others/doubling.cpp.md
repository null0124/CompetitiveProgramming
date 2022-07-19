---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: kyopro/docs/doubling.md
    document_title: doubling
    links: []
  bundledCode: "#line 1 \"kyopro/library/others/doubling.cpp\"\n\uFEFF/*\n* @title\
    \ doubling\n* @docs kyopro/docs/doubling.md\n*/\n\nstruct doubling {\n\n\tint\
    \ n, log_k;\n\tvector<vector<int>> a;\n\tconst function<int(int, int)> f1, f2;\n\
    \n\tdoubling(int n, ll k, function<int(int, int)> f1, function<int(int, int)>\
    \ f2) : n(n), f1(f1), f2(f2) {\n\t\tlog_k = ceil(log2(k));\n\t\ta.assign(log_k\
    \ + 1, vector<int>(n, -1));\n\t}\n\n\t//i \u756A\u76EE\u306E\u8981\u7D20\u306E\
    \u30BB\u30C3\u30C8\u3067\u306F\u306A\u304F\u4E00\u3064\u5148\u306E\u8981\u7D20\
    \u306E\u30BB\u30C3\u30C8\u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\n\tvoid\
    \ set(int i, int x) {\n\t\ta[0][i] = x;\n\t}\n\n\tvoid build() {\n\t\tfor (int\
    \ i = 0; i < log_k; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j) {\n\t\t\t\tif (a[i][j]\
    \ == -1) a[i + 1][j] = -1;\n\t\t\t\telse a[i + 1][j] = f1(a[i + 1][j], a[i][a[i][j]]);\n\
    \t\t\t}\n\t\t}\n\t}\n\n\t//k \u756A\u76EE\u306E\u8981\u7D20\u306E x \u500B\u5148\
    \u3092\u6C42\u3081\u308B\n\tint query(int k, ll x) {\n\t\tfor (int i = log_k;\
    \ i >= 0; --i) {\n\t\t\tif (k == -1)break;\n\t\t\telse if ((x >> (ll)i) & 1LL)\
    \ k = f2(k, a[i][k]);\n\t\t}\n\t\treturn k;\n\t}\n\n};\n"
  code: "\uFEFF/*\n* @title doubling\n* @docs kyopro/docs/doubling.md\n*/\n\nstruct\
    \ doubling {\n\n\tint n, log_k;\n\tvector<vector<int>> a;\n\tconst function<int(int,\
    \ int)> f1, f2;\n\n\tdoubling(int n, ll k, function<int(int, int)> f1, function<int(int,\
    \ int)> f2) : n(n), f1(f1), f2(f2) {\n\t\tlog_k = ceil(log2(k));\n\t\ta.assign(log_k\
    \ + 1, vector<int>(n, -1));\n\t}\n\n\t//i \u756A\u76EE\u306E\u8981\u7D20\u306E\
    \u30BB\u30C3\u30C8\u3067\u306F\u306A\u304F\u4E00\u3064\u5148\u306E\u8981\u7D20\
    \u306E\u30BB\u30C3\u30C8\u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\n\tvoid\
    \ set(int i, int x) {\n\t\ta[0][i] = x;\n\t}\n\n\tvoid build() {\n\t\tfor (int\
    \ i = 0; i < log_k; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j) {\n\t\t\t\tif (a[i][j]\
    \ == -1) a[i + 1][j] = -1;\n\t\t\t\telse a[i + 1][j] = f1(a[i + 1][j], a[i][a[i][j]]);\n\
    \t\t\t}\n\t\t}\n\t}\n\n\t//k \u756A\u76EE\u306E\u8981\u7D20\u306E x \u500B\u5148\
    \u3092\u6C42\u3081\u308B\n\tint query(int k, ll x) {\n\t\tfor (int i = log_k;\
    \ i >= 0; --i) {\n\t\t\tif (k == -1)break;\n\t\t\telse if ((x >> (ll)i) & 1LL)\
    \ k = f2(k, a[i][k]);\n\t\t}\n\t\treturn k;\n\t}\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/others/doubling.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/others/doubling.cpp
layout: document
redirect_from:
- /library/kyopro/library/others/doubling.cpp
- /library/kyopro/library/others/doubling.cpp.html
title: doubling
---
﻿