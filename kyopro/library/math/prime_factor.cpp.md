---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"kyopro/library/math/prime_factor.cpp\"\n\uFEFFmap<ll, int>\
    \ prime_factor(ll a) {\n\tmap<ll, int> ret;\n\tfor (ll x = 2; x * x <= a; ++x)\
    \ {\n\t\twhile (not(a % x))++ret[x], a /= x;\n\t}\n\tif (a != 1)++ret[a];\n\t\
    return ret;\n}\n"
  code: "\uFEFFmap<ll, int> prime_factor(ll a) {\n\tmap<ll, int> ret;\n\tfor (ll x\
    \ = 2; x * x <= a; ++x) {\n\t\twhile (not(a % x))++ret[x], a /= x;\n\t}\n\tif\
    \ (a != 1)++ret[a];\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/math/prime_factor.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/math/prime_factor.cpp
layout: document
redirect_from:
- /library/kyopro/library/math/prime_factor.cpp
- /library/kyopro/library/math/prime_factor.cpp.html
title: kyopro/library/math/prime_factor.cpp
---
