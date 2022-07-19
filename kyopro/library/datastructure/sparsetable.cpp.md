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
    path: kyopro/test/sparsetable_yosupo-judge.test.cpp
    title: kyopro/test/sparsetable_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/sparsetable.md
    document_title: sparse-table
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/sparsetable.cpp\"\n/*\n* @title\
    \ sparse-table\n* @docs kyopro/docs/sparsetable.md\n*/\n\n//RMQ <O(n log n), O(1)>\n\
    template<typename T>\nstruct sparsetable {\n\n\tvector<vector<T>> table;\n\tvector<int>\
    \ logtable;\n\tvector<int> a;\n\tint n;\n\n\t// \u6E21\u3059\u914D\u5217, \u30B5\
    \u30A4\u30BA\n\tsparsetable(const vector<T> a, int siz) : n(siz), a(a) {\n\t\t\
    logtable.assign(n + 1, 0);\n\t\tfor (int i = 2; i <= n; ++i)logtable[i] = logtable[i\
    \ >> 1] + 1;\n\t\ttable.assign(n, vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u30EA\
    \u30B9\u30C8\u30D0\u30FC\u30B8\u30E7\u30F3\n\tsparsetable(initializer_list<T>\
    \ init) {\n\t\ta = init[0];\n\t\tn = init[1];\n\t\tlogtable.assign(n + 1, 0);\n\
    \t\tfor (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n,\
    \ vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u914D\u5217\u3068\u5927\u304D\u3055\
    \u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n\tvoid init(const vector<T> aa, int\
    \ siz) {\n\t\ta = aa;\n\t\tn = siz;\n\t\tlogtable.assign(n + 1, 0);\n\t\tfor (int\
    \ i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n,\
    \ vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u69CB\u7BC9 O(n log n)\n\tvoid\
    \ build() {\n\t\tfor (int k = 0; (1 << k) <= n; ++k) {\n\t\t\tfor (int i = 0;\
    \ i + (1 << k) <= n; ++i) {\n\t\t\t\tif (k) table[i][k] = (a[table[i][k - 1]]\
    \ < a[table[i + (1 << (k - 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k\
    \ - 1))][k - 1]);\n\t\t\t\telse table[i][k] = i;\n\t\t\t}\n\t\t}\n\t}\n\n\t//[l,\
    \ r) \u306E RMQ O(1)\n\tint query(int l, int r) {\n\t\tint k = logtable[r - l];\n\
    \t\treturn (a[table[l][k]] < a[table[r - (1 << k)][k]] ? table[l][k] : table[r\
    \ - (1 << k)][k]);\n\t}\n\n};\n\n"
  code: "/*\n* @title sparse-table\n* @docs kyopro/docs/sparsetable.md\n*/\n\n//RMQ\
    \ <O(n log n), O(1)>\ntemplate<typename T>\nstruct sparsetable {\n\n\tvector<vector<T>>\
    \ table;\n\tvector<int> logtable;\n\tvector<int> a;\n\tint n;\n\n\t// \u6E21\u3059\
    \u914D\u5217, \u30B5\u30A4\u30BA\n\tsparsetable(const vector<T> a, int siz) :\
    \ n(siz), a(a) {\n\t\tlogtable.assign(n + 1, 0);\n\t\tfor (int i = 2; i <= n;\
    \ ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n, vector<T>(logtable[n]\
    \ + 1, 0));\n\t}\n\n\t//\u30EA\u30B9\u30C8\u30D0\u30FC\u30B8\u30E7\u30F3\n\tsparsetable(initializer_list<T>\
    \ init) {\n\t\ta = init[0];\n\t\tn = init[1];\n\t\tlogtable.assign(n + 1, 0);\n\
    \t\tfor (int i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n,\
    \ vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u914D\u5217\u3068\u5927\u304D\u3055\
    \u3092\u6E21\u3057\u3066\u521D\u671F\u5316\n\tvoid init(const vector<T> aa, int\
    \ siz) {\n\t\ta = aa;\n\t\tn = siz;\n\t\tlogtable.assign(n + 1, 0);\n\t\tfor (int\
    \ i = 2; i <= n; ++i)logtable[i] = logtable[i >> 1] + 1;\n\t\ttable.assign(n,\
    \ vector<T>(logtable[n] + 1, 0));\n\t}\n\n\t//\u69CB\u7BC9 O(n log n)\n\tvoid\
    \ build() {\n\t\tfor (int k = 0; (1 << k) <= n; ++k) {\n\t\t\tfor (int i = 0;\
    \ i + (1 << k) <= n; ++i) {\n\t\t\t\tif (k) table[i][k] = (a[table[i][k - 1]]\
    \ < a[table[i + (1 << (k - 1))][k - 1]] ? table[i][k - 1] : table[i + (1 << (k\
    \ - 1))][k - 1]);\n\t\t\t\telse table[i][k] = i;\n\t\t\t}\n\t\t}\n\t}\n\n\t//[l,\
    \ r) \u306E RMQ O(1)\n\tint query(int l, int r) {\n\t\tint k = logtable[r - l];\n\
    \t\treturn (a[table[l][k]] < a[table[r - (1 << k)][k]] ? table[l][k] : table[r\
    \ - (1 << k)][k]);\n\t}\n\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/sparsetable.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/sparsetable_yosupo-judge.test.cpp
  - kyopro/test/LCA_yosupo-judge.test.cpp
  - kyopro/test/LCA_weighted_yukicoder.test.cpp
documentation_of: kyopro/library/datastructure/sparsetable.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/sparsetable.cpp
- /library/kyopro/library/datastructure/sparsetable.cpp.html
title: sparse-table
---
﻿