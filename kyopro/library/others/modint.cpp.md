---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/lazysegtree_yosupo-judge.test.cpp
    title: kyopro/test/lazysegtree_yosupo-judge.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/segtree_yosupo-judge.test.cpp
    title: kyopro/test/segtree_yosupo-judge.test.cpp
  - icon: ':x:'
    path: kyopro/test/vector2D_yukicoder.test.cpp
    title: kyopro/test/vector2D_yukicoder.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: kyopro/docs/modint.md
    document_title: modint
    links: []
  bundledCode: "#line 1 \"kyopro/library/others/modint.cpp\"\n\uFEFF/*\n* @title modint\n\
    * @docs kyopro/docs/modint.md\n*/\n\ntemplate<int mod>\nstruct modint {\n\tint\
    \ val;\n\n\tmodint() : val(0) {};\n\tmodint(ll x) : val(x >= 0 ? x % mod : (mod\
    \ + x % mod) % mod) {};\n\n\tmodint& operator=(const modint& x) {\n\t\tval = x.val;\n\
    \t\treturn *this;\n\t}\n\n\tmodint& operator+=(const modint& x) {\n\t\tval +=\
    \ x.val;\n\t\tif (val >= mod)val -= mod;\n\t\treturn *this;\n\t}\n\n\tmodint&\
    \ operator-=(const modint& x) {\n\t\tval += mod - x.val;\n\t\tif (val >= mod)val\
    \ -= mod;\n\t\treturn *this;\n\t}\n\n\tmodint& operator*=(const modint& x) {\n\
    \t\tval = (int)((ll)val * (ll)x.val % mod);\n\t\treturn *this;\n\t}\n\n\tmodint&\
    \ operator/=(const modint& x) {\n\t\tint a = x.val, b = mod, u = 1, v = 0, t;\n\
    \t\twhile (b > 0) {\n\t\t\tt = a / b;\n\t\t\tswap(a -= t * b, b);\n\t\t\tswap(u\
    \ -= t * v, v);\n\t\t}\n\t\t*this *= modint(u);\n\t\treturn *this;\n\t}\n\n\t\
    modint operator++() {\n\t\tval = (val + 1 == mod ? 0 : val + 1);\n\t\treturn *this;\n\
    \t}\n\n\tmodint operator--() {\n\t\tval = (val == 0 ? mod - 1 : val - 1);\n\t\t\
    return *this;\n\t}\n\n\tmodint operator+(const modint& x) const {\n\t\treturn\
    \ (modint(*this) += x);\n\t}\n\n\tmodint operator-(const modint& x) const {\n\t\
    \treturn (modint(*this) -= x);\n\t}\n\n\tmodint operator*(const modint& x) const\
    \ {\n\t\treturn (modint(*this) *= x);\n\t}\n\n\tmodint operator/(const modint&\
    \ x) const {\n\t\treturn (modint(*this) /= x);\n\t}\n\n\tbool operator==(const\
    \ modint& x)const {\n\t\treturn (val == x.val);\n\t}\n\n\tbool operator!=(const\
    \ modint& x)const {\n\t\treturn (val != x.val);\n\t}\n\n\tbool operator<(const\
    \ modint& x)const {\n\t\treturn (val < x.val);\n\t}\n\n\tbool operator>(const\
    \ modint& x)const {\n\t\treturn (val > x.val);\n\t}\n\n\tmodint pow(ll n) {\n\t\
    \tmodint ret(1), a(val);\n\t\twhile (n > 0) {\n\t\t\tif (n % 2) ret *= a;\n\t\t\
    \ta *= a;\n\t\t\tn /= 2;\n\t\t}\n\t\treturn ret;\n\t}\n\n\tstatic int getmod()\
    \ { return mod; };\n};\n\nusing ModInt = modint<MOD>;\nusing Modint = modint<mod>;\n"
  code: "\uFEFF/*\n* @title modint\n* @docs kyopro/docs/modint.md\n*/\n\ntemplate<int\
    \ mod>\nstruct modint {\n\tint val;\n\n\tmodint() : val(0) {};\n\tmodint(ll x)\
    \ : val(x >= 0 ? x % mod : (mod + x % mod) % mod) {};\n\n\tmodint& operator=(const\
    \ modint& x) {\n\t\tval = x.val;\n\t\treturn *this;\n\t}\n\n\tmodint& operator+=(const\
    \ modint& x) {\n\t\tval += x.val;\n\t\tif (val >= mod)val -= mod;\n\t\treturn\
    \ *this;\n\t}\n\n\tmodint& operator-=(const modint& x) {\n\t\tval += mod - x.val;\n\
    \t\tif (val >= mod)val -= mod;\n\t\treturn *this;\n\t}\n\n\tmodint& operator*=(const\
    \ modint& x) {\n\t\tval = (int)((ll)val * (ll)x.val % mod);\n\t\treturn *this;\n\
    \t}\n\n\tmodint& operator/=(const modint& x) {\n\t\tint a = x.val, b = mod, u\
    \ = 1, v = 0, t;\n\t\twhile (b > 0) {\n\t\t\tt = a / b;\n\t\t\tswap(a -= t * b,\
    \ b);\n\t\t\tswap(u -= t * v, v);\n\t\t}\n\t\t*this *= modint(u);\n\t\treturn\
    \ *this;\n\t}\n\n\tmodint operator++() {\n\t\tval = (val + 1 == mod ? 0 : val\
    \ + 1);\n\t\treturn *this;\n\t}\n\n\tmodint operator--() {\n\t\tval = (val ==\
    \ 0 ? mod - 1 : val - 1);\n\t\treturn *this;\n\t}\n\n\tmodint operator+(const\
    \ modint& x) const {\n\t\treturn (modint(*this) += x);\n\t}\n\n\tmodint operator-(const\
    \ modint& x) const {\n\t\treturn (modint(*this) -= x);\n\t}\n\n\tmodint operator*(const\
    \ modint& x) const {\n\t\treturn (modint(*this) *= x);\n\t}\n\n\tmodint operator/(const\
    \ modint& x) const {\n\t\treturn (modint(*this) /= x);\n\t}\n\n\tbool operator==(const\
    \ modint& x)const {\n\t\treturn (val == x.val);\n\t}\n\n\tbool operator!=(const\
    \ modint& x)const {\n\t\treturn (val != x.val);\n\t}\n\n\tbool operator<(const\
    \ modint& x)const {\n\t\treturn (val < x.val);\n\t}\n\n\tbool operator>(const\
    \ modint& x)const {\n\t\treturn (val > x.val);\n\t}\n\n\tmodint pow(ll n) {\n\t\
    \tmodint ret(1), a(val);\n\t\twhile (n > 0) {\n\t\t\tif (n % 2) ret *= a;\n\t\t\
    \ta *= a;\n\t\t\tn /= 2;\n\t\t}\n\t\treturn ret;\n\t}\n\n\tstatic int getmod()\
    \ { return mod; };\n};\n\nusing ModInt = modint<MOD>;\nusing Modint = modint<mod>;\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/others/modint.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - kyopro/test/segtree_yosupo-judge.test.cpp
  - kyopro/test/lazysegtree_yosupo-judge.test.cpp
  - kyopro/test/vector2D_yukicoder.test.cpp
documentation_of: kyopro/library/others/modint.cpp
layout: document
redirect_from:
- /library/kyopro/library/others/modint.cpp
- /library/kyopro/library/others/modint.cpp.html
title: modint
---
﻿