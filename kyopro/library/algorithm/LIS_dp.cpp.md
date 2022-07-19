---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/LIS_dp_aoj.test.cpp
    title: kyopro/test/LIS_dp_aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/LIS_dp.md
    document_title: longest-increasing-subsequence(dp)
    links: []
  bundledCode: "#line 1 \"kyopro/library/algorithm/LIS_dp.cpp\"\n\uFEFF/*\n* @title\
    \ longest-increasing-subsequence(dp)\n* @docs kyopro/docs/LIS_dp.md\n*/\n\n//st\
    \ \u304C true \u306E\u6642\u3001\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\nint lis(const\
    \ int& n, const vector<int>& a, const bool& st) {\n\tvector<int> dp(n);\n\tfill(all(dp),\
    \ INF);\n\tvector<int>::iterator ite;\n\trep(i, n) {\n\t\tif (st)ite = lower_bound(all(dp),\
    \ a[i]);\n\t\telse ite = upper_bound(all(dp), a[i]);\n\t\tif (ite != dp.end())*ite\
    \ = a[i];\n\t}\n\treturn distance(dp.begin(), lower_bound(all(dp), INF));\n}\n"
  code: "\uFEFF/*\n* @title longest-increasing-subsequence(dp)\n* @docs kyopro/docs/LIS_dp.md\n\
    */\n\n//st \u304C true \u306E\u6642\u3001\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\n\
    int lis(const int& n, const vector<int>& a, const bool& st) {\n\tvector<int> dp(n);\n\
    \tfill(all(dp), INF);\n\tvector<int>::iterator ite;\n\trep(i, n) {\n\t\tif (st)ite\
    \ = lower_bound(all(dp), a[i]);\n\t\telse ite = upper_bound(all(dp), a[i]);\n\t\
    \tif (ite != dp.end())*ite = a[i];\n\t}\n\treturn distance(dp.begin(), lower_bound(all(dp),\
    \ INF));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/algorithm/LIS_dp.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/LIS_dp_aoj.test.cpp
documentation_of: kyopro/library/algorithm/LIS_dp.cpp
layout: document
redirect_from:
- /library/kyopro/library/algorithm/LIS_dp.cpp
- /library/kyopro/library/algorithm/LIS_dp.cpp.html
title: longest-increasing-subsequence(dp)
---
﻿
## 説明
最長増加部分列の長さを求める  

## 使い方
関数  
lis($n, A, f$)

#### 引数
- $n$: 配列の長さ  
- $A$: 配列  
- $f$: 狭義かどうか  

#### 返り値
- 長さ  

### 計算量
${\rm O}(n \log n)$  

