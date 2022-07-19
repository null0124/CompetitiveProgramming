---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: kyopro/test/vector2D_yukicoder.test.cpp
    title: kyopro/test/vector2D_yukicoder.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: kyopro/docs/vector2D.md
    document_title: vector(2D)
    links: []
  bundledCode: "#line 1 \"kyopro/library/geometry/vector2D.cpp\"\n\uFEFF/*\n* @title\
    \ vector(2D)\n* @docs kyopro/docs/vector2D.md\n*/\n\nstruct vector2D {\n\n\tll\
    \ x, y;\n\n\tvector2D(ll x, ll y) : x(x), y(y) {}\n\tvector2D(ll stx, ll sty,\
    \ ll enx, ll eny) : x(enx - stx), y(eny - sty) {}\n\tvector2D() : x(0), y(0) {}\n\
    \n\tvector2D operator+(const vector2D p) { return vector2D(x + p.x, y + p.y);\
    \ }\n\tvector2D operator-(const vector2D p) { return vector2D(x - p.x, y - p.y);\
    \ }\n\t// \u30B9\u30AB\u30E9\u30FC\u500D\n\tvector2D operator*(const ll p) { return\
    \ vector2D(x * p, y * p); }\n\n};\n\ninline ll vectorproduct(vector2D p, vector2D\
    \ q) { return abs(p.x * q.y - p.y * q.x); }\ninline ll vectorproductcomp(vector2D\
    \ p, vector2D q) { return p.x * q.y - p.y * q.x; }\n\ninline bool comp(const vector2D&\
    \ a, const vector2D& b) {\n\tif (a.x == 0 and a.y == 0)return true;\n\telse if\
    \ (b.x == 0 and b.y == 0)return false;\n\telse if (a.x < 0) {\n\t\tif (b.x < 0)\
    \ {\n\t\t\treturn vectorproductcomp(a, b) > 0;\n\t\t}\n\t\telse {\n\t\t\treturn\
    \ false;\n\t\t}\n\t}\n\telse {\n\t\tif (b.x < 0) {\n\t\t\treturn true;\n\t\t}\n\
    \t\telse {\n\t\t\treturn vectorproductcomp(a, b) > 0;\n\t\t}\n\t}\n}\n"
  code: "\uFEFF/*\n* @title vector(2D)\n* @docs kyopro/docs/vector2D.md\n*/\n\nstruct\
    \ vector2D {\n\n\tll x, y;\n\n\tvector2D(ll x, ll y) : x(x), y(y) {}\n\tvector2D(ll\
    \ stx, ll sty, ll enx, ll eny) : x(enx - stx), y(eny - sty) {}\n\tvector2D() :\
    \ x(0), y(0) {}\n\n\tvector2D operator+(const vector2D p) { return vector2D(x\
    \ + p.x, y + p.y); }\n\tvector2D operator-(const vector2D p) { return vector2D(x\
    \ - p.x, y - p.y); }\n\t// \u30B9\u30AB\u30E9\u30FC\u500D\n\tvector2D operator*(const\
    \ ll p) { return vector2D(x * p, y * p); }\n\n};\n\ninline ll vectorproduct(vector2D\
    \ p, vector2D q) { return abs(p.x * q.y - p.y * q.x); }\ninline ll vectorproductcomp(vector2D\
    \ p, vector2D q) { return p.x * q.y - p.y * q.x; }\n\ninline bool comp(const vector2D&\
    \ a, const vector2D& b) {\n\tif (a.x == 0 and a.y == 0)return true;\n\telse if\
    \ (b.x == 0 and b.y == 0)return false;\n\telse if (a.x < 0) {\n\t\tif (b.x < 0)\
    \ {\n\t\t\treturn vectorproductcomp(a, b) > 0;\n\t\t}\n\t\telse {\n\t\t\treturn\
    \ false;\n\t\t}\n\t}\n\telse {\n\t\tif (b.x < 0) {\n\t\t\treturn true;\n\t\t}\n\
    \t\telse {\n\t\t\treturn vectorproductcomp(a, b) > 0;\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/geometry/vector2D.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - kyopro/test/vector2D_yukicoder.test.cpp
documentation_of: kyopro/library/geometry/vector2D.cpp
layout: document
redirect_from:
- /library/kyopro/library/geometry/vector2D.cpp
- /library/kyopro/library/geometry/vector2D.cpp.html
title: vector(2D)
---
﻿