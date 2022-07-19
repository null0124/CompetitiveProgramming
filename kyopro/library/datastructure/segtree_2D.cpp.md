---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/segtree_2D_yosupo-judge.test.cpp
    title: kyopro/test/segtree_2D_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/segtree_2d.md
    document_title: segment-tree-2D
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/segtree_2D.cpp\"\n\uFEFF/*\n\
    * @title segment-tree-2D\n* @docs kyopro/docs/segtree_2d.md\n*/\n\n\ntemplate<typename\
    \ T, typename F>\nstruct segtree2D {\n\t//\u6728\u3092\u914D\u5217\u3067\u3042\
    \u3089\u308F\u3057\u305F\u3082\u306E\n\tvector<segtree<T, F>> seg;\n\t//\u6728\
    \u306E1/2\u306E\u5927\u304D\u3055\n\tint siz;\n\t//\u5358\u4F4D\u5143\n\tconst\
    \ T e;\n\t////\u6BD4\u8F03\u95A2\u6570\u306E\u578B\n\t//using F = function<T(T,\
    \ T)>;\n\t//\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n\tconst F f;\n\t//\u5EA7\
    \u6A19\n\tvector<vector<int>> pos;\n\n\t//n \u306E\u5927\u304D\u3055, a (\u5358\
    \u4F4D\u5143) \u3067 segtree \u3092\u521D\u671F\u5316\u3059\u308B\n\tsegtree2D(int\
    \ n, const T a, const F f) : e(a), f(f) {\n\t\tsiz = 1;\n\t\twhile (siz < n)siz\
    \ <<= 1;\n\t\tpos.resize(2 * siz - 1);\n\t\t--siz;\n\t}\n\n\t//\u5EA7\u6A19 (x,\
    \ y) \u3092\u6E96\u5099\n\tvoid preset(int x, int y) {\n\t\tx += siz;\n\t\tpos[x].push_back(y);\n\
    \t\twhile (x > 0) {\n\t\t\tx = (x - 1) >> 1;\n\t\t\tpos[x].push_back(y);\n\t\t\
    }\n\t}\n\n\t//f \u306B\u3088\u3063\u3066\u6728\u3092\u69CB\u7BC9\n\tvoid build()\
    \ {\n\t\tfor (auto& aa : pos) {\n\t\t\tsort(all(aa));\n\t\t\taa.erase(unique(all(aa)),\
    \ aa.end());\n\t\t}\n\t\tfor (const auto& aa : pos) {\n\t\t\tseg.emplace_back(get_segtree(aa.size(),\
    \ e, f));\n\t\t\tseg.back().build();\n\t\t}\n\t}\n\n\t//(x, y) \u306E\u5024\u3092\
    \ a \u306B\u66F4\u65B0\n\tvoid update(int x, int y, T a) {\n\t\tx += siz;\n\t\t\
    seg[x].update(distance(pos[x].begin(), lower_bound(all(pos[x]), y)), f(seg[x][distance(pos[x].begin(),\
    \ lower_bound(all(pos[x]), y))], a));\n\t\twhile (x > 0) {\n\t\t\tx = ((x - 1)\
    \ >> 1);\n\t\t\tseg[x].update(distance(pos[x].begin(), lower_bound(all(pos[x]),\
    \ y)), f(seg[x][distance(pos[x].begin(), lower_bound(all(pos[x]), y))], a));\n\
    \t\t}\n\t}\n\n\t//x: [a, b) y: [x, y) \u306B\u3064\u3044\u3066 f \u3057\u305F\u7D50\
    \u679C\u3092\u8FD4\u3059\n\tT query(int a, int b, int x, int y) {\n\t\tT l = e,\
    \ r = e;\n\t\tfor (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {\n\t\t\tif (!(a\
    \ & 1)) {\n\t\t\t\tl = f(l, seg[a].query(distance(pos[a].begin(), lower_bound(all(pos[a]),\
    \ x)), distance(pos[a].begin(), lower_bound(all(pos[a]), y))));\n\t\t\t\t++a;\n\
    \t\t\t}\n\t\t\tif (!(b & 1)) {\n\t\t\t\t--b;\n\t\t\t\tr = f(seg[b].query(distance(pos[b].begin(),\
    \ lower_bound(all(pos[b]), x)), distance(pos[b].begin(), lower_bound(all(pos[b]),\
    \ y))), r);\n\t\t\t}\n\t\t}\n\t\treturn f(l, r);\n\t}\n\n};\n\ntemplate<typename\
    \ T, typename F>\nsegtree2D<T, F> get_segtree2D(int n, const T& e, const F& f)\
    \ {\n\treturn { n, e, f };\n}\n"
  code: "\uFEFF/*\n* @title segment-tree-2D\n* @docs kyopro/docs/segtree_2d.md\n*/\n\
    \n\ntemplate<typename T, typename F>\nstruct segtree2D {\n\t//\u6728\u3092\u914D\
    \u5217\u3067\u3042\u3089\u308F\u3057\u305F\u3082\u306E\n\tvector<segtree<T, F>>\
    \ seg;\n\t//\u6728\u306E1/2\u306E\u5927\u304D\u3055\n\tint siz;\n\t//\u5358\u4F4D\
    \u5143\n\tconst T e;\n\t////\u6BD4\u8F03\u95A2\u6570\u306E\u578B\n\t//using F\
    \ = function<T(T, T)>;\n\t//\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n\tconst\
    \ F f;\n\t//\u5EA7\u6A19\n\tvector<vector<int>> pos;\n\n\t//n \u306E\u5927\u304D\
    \u3055, a (\u5358\u4F4D\u5143) \u3067 segtree \u3092\u521D\u671F\u5316\u3059\u308B\
    \n\tsegtree2D(int n, const T a, const F f) : e(a), f(f) {\n\t\tsiz = 1;\n\t\t\
    while (siz < n)siz <<= 1;\n\t\tpos.resize(2 * siz - 1);\n\t\t--siz;\n\t}\n\n\t\
    //\u5EA7\u6A19 (x, y) \u3092\u6E96\u5099\n\tvoid preset(int x, int y) {\n\t\t\
    x += siz;\n\t\tpos[x].push_back(y);\n\t\twhile (x > 0) {\n\t\t\tx = (x - 1) >>\
    \ 1;\n\t\t\tpos[x].push_back(y);\n\t\t}\n\t}\n\n\t//f \u306B\u3088\u3063\u3066\
    \u6728\u3092\u69CB\u7BC9\n\tvoid build() {\n\t\tfor (auto& aa : pos) {\n\t\t\t\
    sort(all(aa));\n\t\t\taa.erase(unique(all(aa)), aa.end());\n\t\t}\n\t\tfor (const\
    \ auto& aa : pos) {\n\t\t\tseg.emplace_back(get_segtree(aa.size(), e, f));\n\t\
    \t\tseg.back().build();\n\t\t}\n\t}\n\n\t//(x, y) \u306E\u5024\u3092 a \u306B\u66F4\
    \u65B0\n\tvoid update(int x, int y, T a) {\n\t\tx += siz;\n\t\tseg[x].update(distance(pos[x].begin(),\
    \ lower_bound(all(pos[x]), y)), f(seg[x][distance(pos[x].begin(), lower_bound(all(pos[x]),\
    \ y))], a));\n\t\twhile (x > 0) {\n\t\t\tx = ((x - 1) >> 1);\n\t\t\tseg[x].update(distance(pos[x].begin(),\
    \ lower_bound(all(pos[x]), y)), f(seg[x][distance(pos[x].begin(), lower_bound(all(pos[x]),\
    \ y))], a));\n\t\t}\n\t}\n\n\t//x: [a, b) y: [x, y) \u306B\u3064\u3044\u3066 f\
    \ \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\n\tT query(int a, int b, int x, int\
    \ y) {\n\t\tT l = e, r = e;\n\t\tfor (a += siz, b += siz; a < b; a >>= 1, b >>=\
    \ 1) {\n\t\t\tif (!(a & 1)) {\n\t\t\t\tl = f(l, seg[a].query(distance(pos[a].begin(),\
    \ lower_bound(all(pos[a]), x)), distance(pos[a].begin(), lower_bound(all(pos[a]),\
    \ y))));\n\t\t\t\t++a;\n\t\t\t}\n\t\t\tif (!(b & 1)) {\n\t\t\t\t--b;\n\t\t\t\t\
    r = f(seg[b].query(distance(pos[b].begin(), lower_bound(all(pos[b]), x)), distance(pos[b].begin(),\
    \ lower_bound(all(pos[b]), y))), r);\n\t\t\t}\n\t\t}\n\t\treturn f(l, r);\n\t\
    }\n\n};\n\ntemplate<typename T, typename F>\nsegtree2D<T, F> get_segtree2D(int\
    \ n, const T& e, const F& f) {\n\treturn { n, e, f };\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/segtree_2D.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/segtree_2D_yosupo-judge.test.cpp
documentation_of: kyopro/library/datastructure/segtree_2D.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/segtree_2D.cpp
- /library/kyopro/library/datastructure/segtree_2D.cpp.html
title: segment-tree-2D
---
﻿