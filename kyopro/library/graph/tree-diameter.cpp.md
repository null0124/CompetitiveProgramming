---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: kyopro/test/tree-diameter_aoj.test.cpp
    title: kyopro/test/tree-diameter_aoj.test.cpp
  - icon: ':x:'
    path: kyopro/test/tree-diameter_yosupo-judge.test.cpp
    title: kyopro/test/tree-diameter_yosupo-judge.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: kyopro/docs/tree-diameter.md
    document_title: "tree diameter(\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/tree-diameter.cpp\"\n\uFEFF/*\n* @title\
    \ tree diameter(\u6728\u306E\u76F4\u5F84)\n* @docs kyopro/docs/tree-diameter.md\n\
    */\n\ntemplate<typename T = int>\nvoid diameter1(graph<T>& g, const int& cur,\
    \ const int& bef, const T& cnt, T& ma, int& idx) {\n\tif (cnt > ma)ma = cnt, idx\
    \ = cur;\n\tfor (const auto& aa : g[cur]) if (aa.to != bef)diameter1<T>(g, aa.to,\
    \ cur, cnt + aa.cost, ma, idx);\n}\n\ntemplate<typename T = int>\nvoid diameter2(graph<T>&\
    \ g, const int& cur, const int& bef, vector<int>& ret, vector<int>& route, const\
    \ T& cnt, T& cost) {\n\troute.emplace_back(cur);\n\tif (g[cur].size() == 1 and\
    \ cost < cnt) {\n\t\tcost = cnt;\n\t\tret = route;\n\t}\n\tfor (const auto& aa\
    \ : g[cur])if (aa.to != bef)diameter2<T>(g, aa.to, cur, ret, route, cnt + aa.cost,\
    \ cost);\n\troute.pop_back();\n}\n\ntemplate<typename T = int>\nvector<int> diameter(graph<T>&\
    \ g, T& cost, const int& cur = 0) {\n\tT ma = 0;\n\tint idx = cur;\n\tdiameter1<T>(g,\
    \ cur, -1, (T)0, ma, idx);\n\tma = 0;\n\tvector<int> ret, route;\n\tdiameter2<T>(g,\
    \ idx, -1, ret, route, 0, cost);\n\treverse(all(ret));\n\treturn ret;\n}\n"
  code: "\uFEFF/*\n* @title tree diameter(\u6728\u306E\u76F4\u5F84)\n* @docs kyopro/docs/tree-diameter.md\n\
    */\n\ntemplate<typename T = int>\nvoid diameter1(graph<T>& g, const int& cur,\
    \ const int& bef, const T& cnt, T& ma, int& idx) {\n\tif (cnt > ma)ma = cnt, idx\
    \ = cur;\n\tfor (const auto& aa : g[cur]) if (aa.to != bef)diameter1<T>(g, aa.to,\
    \ cur, cnt + aa.cost, ma, idx);\n}\n\ntemplate<typename T = int>\nvoid diameter2(graph<T>&\
    \ g, const int& cur, const int& bef, vector<int>& ret, vector<int>& route, const\
    \ T& cnt, T& cost) {\n\troute.emplace_back(cur);\n\tif (g[cur].size() == 1 and\
    \ cost < cnt) {\n\t\tcost = cnt;\n\t\tret = route;\n\t}\n\tfor (const auto& aa\
    \ : g[cur])if (aa.to != bef)diameter2<T>(g, aa.to, cur, ret, route, cnt + aa.cost,\
    \ cost);\n\troute.pop_back();\n}\n\ntemplate<typename T = int>\nvector<int> diameter(graph<T>&\
    \ g, T& cost, const int& cur = 0) {\n\tT ma = 0;\n\tint idx = cur;\n\tdiameter1<T>(g,\
    \ cur, -1, (T)0, ma, idx);\n\tma = 0;\n\tvector<int> ret, route;\n\tdiameter2<T>(g,\
    \ idx, -1, ret, route, 0, cost);\n\treverse(all(ret));\n\treturn ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/tree-diameter.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - kyopro/test/tree-diameter_aoj.test.cpp
  - kyopro/test/tree-diameter_yosupo-judge.test.cpp
documentation_of: kyopro/library/graph/tree-diameter.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/tree-diameter.cpp
- /library/kyopro/library/graph/tree-diameter.cpp.html
title: "tree diameter(\u6728\u306E\u76F4\u5F84)"
---
﻿