---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/BIT_yosupo-judge.test.cpp
    title: kyopro/test/BIT_yosupo-judge.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/mo_yosupo-judge.test.cpp
    title: kyopro/test/mo_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/BIT.md
    document_title: binary-indexed-tree
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/BIT.cpp\"\n/*\n* @title binary-indexed-tree\n\
    * @docs kyopro/docs/BIT.md\n*/\n\ntemplate<typename T>\n//0-indexed/\u5185\u90E8\
    \u7684\u306B 1-indexed\nstruct BIT {\n\tvector<T> tree;\n\t//\u521D\u671F\u5316\
    \n\tBIT(int n) : tree(n) {\n\t\ttree.assign(n + 1, 0);\n\t}\n\n\tint LSB(int n)\
    \ { return (n & (-n)); }\n\n\t//[0, n) \u306E sum \u3092\u8FD4\u3059/0-indexed\n\
    \tT sum(int n) {\n\t\tT ret = 0;\n\t\t//\u5B9F\u306F 1-indexed \u3060\u304C\u534A\
    \u958B\u533A\u9593\u306A\u306E\u3067\u898B\u305F\u76EE\u304C\u305D\u306E\u307E\
    \u307E\n\t\tfor (; n >= 0; n -= LSB(n)) {\n\t\t\tret += tree[n];\n\t\t\tif (!n)break;\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\n\t//[i, j) \u306E sum \u3092\u8FD4\u3059/0-indexed\n\
    \tT sum(int i, int j) {\n\t\treturn sum(j) - sum(i);\n\t}\n\n\t//n \u756A\u76EE\
    \u306B x \u3092\u8DB3\u3059\n\tvoid add(int n, T x) {\n\t\tint siz = tree.size();\n\
    \t\tfor (++n; n < siz; n += LSB(n))tree[n] += x;\n\t}\n};\n"
  code: "/*\n* @title binary-indexed-tree\n* @docs kyopro/docs/BIT.md\n*/\n\ntemplate<typename\
    \ T>\n//0-indexed/\u5185\u90E8\u7684\u306B 1-indexed\nstruct BIT {\n\tvector<T>\
    \ tree;\n\t//\u521D\u671F\u5316\n\tBIT(int n) : tree(n) {\n\t\ttree.assign(n +\
    \ 1, 0);\n\t}\n\n\tint LSB(int n) { return (n & (-n)); }\n\n\t//[0, n) \u306E\
    \ sum \u3092\u8FD4\u3059/0-indexed\n\tT sum(int n) {\n\t\tT ret = 0;\n\t\t//\u5B9F\
    \u306F 1-indexed \u3060\u304C\u534A\u958B\u533A\u9593\u306A\u306E\u3067\u898B\u305F\
    \u76EE\u304C\u305D\u306E\u307E\u307E\n\t\tfor (; n >= 0; n -= LSB(n)) {\n\t\t\t\
    ret += tree[n];\n\t\t\tif (!n)break;\n\t\t}\n\t\treturn ret;\n\t}\n\n\n\t//[i,\
    \ j) \u306E sum \u3092\u8FD4\u3059/0-indexed\n\tT sum(int i, int j) {\n\t\treturn\
    \ sum(j) - sum(i);\n\t}\n\n\t//n \u756A\u76EE\u306B x \u3092\u8DB3\u3059\n\tvoid\
    \ add(int n, T x) {\n\t\tint siz = tree.size();\n\t\tfor (++n; n < siz; n += LSB(n))tree[n]\
    \ += x;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/BIT.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/mo_yosupo-judge.test.cpp
  - kyopro/test/BIT_yosupo-judge.test.cpp
documentation_of: kyopro/library/datastructure/BIT.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/BIT.cpp
- /library/kyopro/library/datastructure/BIT.cpp.html
title: binary-indexed-tree
---
﻿
## 概要
ある列の区間の和と一点更新が高速にできる  
一応抽象化をしているが二項演算は $+$ と $-$ のままなので実質数列限定  
変なのを乗せるときは segment tree をつかう  

## 使い方
構造体  

#### 宣言
BIT<$T$> bit($n$);  
$T$: 型  
$n$: 大きさ  

#### 一点更新
bit.add($i, a$)  
- $i$: 追加する index  
- $a$: 足す値  

#### 区間取得
bit.sum($l, r$)  
- $l, r$: 区間 $[l, r)$ の和を取得する。  

### 計算量
- 一点更新・区間取得  
${\rm O}(n \log n)$  

