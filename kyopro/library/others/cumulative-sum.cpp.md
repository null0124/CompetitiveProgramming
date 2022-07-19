---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/cumulative-sum_yosupo-judge.test.cpp
    title: kyopro/test/cumulative-sum_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/cumulative-sum.md
    document_title: "\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"kyopro/library/others/cumulative-sum.cpp\"\n\uFEFF/*\n*\
    \ @title \u7D2F\u7A4D\u548C\n* @docs kyopro/docs/cumulative-sum.md\n*/\n\ntemplate<typename\
    \ T>\nstruct cumulativesum {\n    vector<T> cs;\n    const function<T(T, T)> rev;\n\
    \    cumulativesum(const vector<T> a, const T e, const function<T(T, T)> f, const\
    \ function<T(T, T)> rev) : rev(rev) {\n        int siz = a.size() + 1;\n     \
    \   cs.assign(siz, e);\n        rep(i, siz - 1)cs[i + 1] = f(cs[i], a[i]);\n \
    \   }\n\n    //0-indexed \u3067 [l, r) \u306E\u548C\n    T query(int l, int r)\
    \ {\n        return rev(cs[r], cs[l]);\n    }\n};\n"
  code: "\uFEFF/*\n* @title \u7D2F\u7A4D\u548C\n* @docs kyopro/docs/cumulative-sum.md\n\
    */\n\ntemplate<typename T>\nstruct cumulativesum {\n    vector<T> cs;\n    const\
    \ function<T(T, T)> rev;\n    cumulativesum(const vector<T> a, const T e, const\
    \ function<T(T, T)> f, const function<T(T, T)> rev) : rev(rev) {\n        int\
    \ siz = a.size() + 1;\n        cs.assign(siz, e);\n        rep(i, siz - 1)cs[i\
    \ + 1] = f(cs[i], a[i]);\n    }\n\n    //0-indexed \u3067 [l, r) \u306E\u548C\n\
    \    T query(int l, int r) {\n        return rev(cs[r], cs[l]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/others/cumulative-sum.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/cumulative-sum_yosupo-judge.test.cpp
documentation_of: kyopro/library/others/cumulative-sum.cpp
layout: document
redirect_from:
- /library/kyopro/library/others/cumulative-sum.cpp
- /library/kyopro/library/others/cumulative-sum.cpp.html
title: "\u7D2F\u7A4D\u548C"
---
﻿