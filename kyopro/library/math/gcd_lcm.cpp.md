---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/lcm_aoj.test.cpp
    title: kyopro/test/lcm_aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/gcd_lcm.md
    document_title: gcd-lcm
    links: []
  bundledCode: "#line 1 \"kyopro/library/math/gcd_lcm.cpp\"\n\uFEFF/*\n* @title gcd-lcm\n\
    * @docs kyopro/docs/gcd_lcm.md\n*/\n\nll gcd(ll a, ll b) {\n\tif (b == 0) return\
    \ a;\n\treturn gcd(b, a % b);\n}\n\nll lcm(ll number1, ll number2) {//lcm\u3092\
    \u6C42\u3081\u308B\n\treturn number1 / gcd(number1, number2) * number2;\n}\n"
  code: "\uFEFF/*\n* @title gcd-lcm\n* @docs kyopro/docs/gcd_lcm.md\n*/\n\nll gcd(ll\
    \ a, ll b) {\n\tif (b == 0) return a;\n\treturn gcd(b, a % b);\n}\n\nll lcm(ll\
    \ number1, ll number2) {//lcm\u3092\u6C42\u3081\u308B\n\treturn number1 / gcd(number1,\
    \ number2) * number2;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/math/gcd_lcm.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/lcm_aoj.test.cpp
documentation_of: kyopro/library/math/gcd_lcm.cpp
layout: document
redirect_from:
- /library/kyopro/library/math/gcd_lcm.cpp
- /library/kyopro/library/math/gcd_lcm.cpp.html
title: gcd-lcm
---
