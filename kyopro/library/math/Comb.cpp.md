---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: kyopro/docs/comb.md
    document_title: combination
    links: []
  bundledCode: "#line 1 \"kyopro/library/math/Comb.cpp\"\n\uFEFF/*\n* @title combination\n\
    * @docs kyopro/docs/comb.md\n*/\n\ntemplate<typename T>\nstruct comb {\n\tint\
    \ siz, Mod;\n\n\tvector<T> fac, inv, facinv;\n\n\t//siz <= 1e7 \u304F\u3089\u3044\
    \n\tcomb(const int& siz, const int& Mod) : siz(siz), Mod(Mod) {\n\t\tfac.assign(siz\
    \ + 1, 0);\n\t\tinv.assign(siz + 1, 0);\n\t\tfacinv.assign(siz + 1, 0);\n\t\t\
    fac[0] = fac[1] = facinv[0] = facinv[1] = inv[1] = 1;\n\t\tfor (int i = 2; i <=\
    \ siz; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % Mod;\n\t\t\tinv[i] = Mod - inv[Mod\
    \ % i] * (Mod / i) % Mod;\n\t\t\tfacinv[i] = facinv[i - 1] * inv[i] % Mod;\n\t\
    \t}\n\t}\n\n\tT query(const int& n, const int& r) {\n\t\treturn (n < r or n <\
    \ 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % Mod)) % Mod);\n\t\
    }\n};\n\n"
  code: "\uFEFF/*\n* @title combination\n* @docs kyopro/docs/comb.md\n*/\n\ntemplate<typename\
    \ T>\nstruct comb {\n\tint siz, Mod;\n\n\tvector<T> fac, inv, facinv;\n\n\t//siz\
    \ <= 1e7 \u304F\u3089\u3044\n\tcomb(const int& siz, const int& Mod) : siz(siz),\
    \ Mod(Mod) {\n\t\tfac.assign(siz + 1, 0);\n\t\tinv.assign(siz + 1, 0);\n\t\tfacinv.assign(siz\
    \ + 1, 0);\n\t\tfac[0] = fac[1] = facinv[0] = facinv[1] = inv[1] = 1;\n\t\tfor\
    \ (int i = 2; i <= siz; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % Mod;\n\t\t\tinv[i]\
    \ = Mod - inv[Mod % i] * (Mod / i) % Mod;\n\t\t\tfacinv[i] = facinv[i - 1] * inv[i]\
    \ % Mod;\n\t\t}\n\t}\n\n\tT query(const int& n, const int& r) {\n\t\treturn (n\
    \ < r or n < 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % Mod)) %\
    \ Mod);\n\t}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/math/Comb.cpp
  requiredBy: []
  timestamp: '2020-08-30 05:54:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/library/math/Comb.cpp
layout: document
redirect_from:
- /library/kyopro/library/math/Comb.cpp
- /library/kyopro/library/math/Comb.cpp.html
title: combination
---
﻿