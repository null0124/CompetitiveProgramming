---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: kyopro/docs/kth_permutation.md
    document_title: kth_permutation
    links: []
  bundledCode: "#line 1 \"kyopro/library/math/kth_permutation.cpp\"\n\uFEFF/*\n* @title\
    \ kth_permutation\n* @docs kyopro/docs/kth_permutation.md\n*/\n\ntemplate<typename\
    \ T = int>\nvector<T> kth_permutation(int n, T k) {\n\tvector<T> a(n), b(n);\n\
    \trep(i, n)b[i] = i + 1;\n\tvector<T> x(n);\n\trep(i, n) {\n\t\tx[i] = (k % (i\
    \ + 1));\n\t\tk /= (i + 1);\n\t}\n\treverse(all(x));\n\trep(i, n) {\n\t\ta[i]\
    \ = b[x[i]];\n\t\tb.erase(b.begin() + x[i]);\n\t}\n\treturn a;\n}\n"
  code: "\uFEFF/*\n* @title kth_permutation\n* @docs kyopro/docs/kth_permutation.md\n\
    */\n\ntemplate<typename T = int>\nvector<T> kth_permutation(int n, T k) {\n\t\
    vector<T> a(n), b(n);\n\trep(i, n)b[i] = i + 1;\n\tvector<T> x(n);\n\trep(i, n)\
    \ {\n\t\tx[i] = (k % (i + 1));\n\t\tk /= (i + 1);\n\t}\n\treverse(all(x));\n\t\
    rep(i, n) {\n\t\ta[i] = b[x[i]];\n\t\tb.erase(b.begin() + x[i]);\n\t}\n\treturn\
    \ a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/math/kth_permutation.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/math/kth_permutation.cpp
layout: document
redirect_from:
- /library/kyopro/library/math/kth_permutation.cpp
- /library/kyopro/library/math/kth_permutation.cpp.html
title: kth_permutation
---
