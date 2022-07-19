---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp
    title: kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/segtree_2D_yosupo-judge.test.cpp
    title: kyopro/test/segtree_2D_yosupo-judge.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/segtree_yosupo-judge.test.cpp
    title: kyopro/test/segtree_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/segtree.md
    document_title: segment-tree
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/segtree.cpp\"\n\uFEFF/*\n*\
    \ @title segment-tree\n* @docs kyopro/docs/segtree.md\n*/\n\n\n//\u30BB\u30B0\u6728\
    /0-indexed/\u975E\u518D\u5E30/(\u5927\u304D\u3055, \u5358\u4F4D\u5143)\u3067\u521D\
    \u671F\u5316\ntemplate<typename T, typename F>\nstruct segtree {\n\t//\u6728\u3092\
    \u914D\u5217\u3067\u3042\u3089\u308F\u3057\u305F\u3082\u306E\n\tvector<T> seg;\n\
    \t//\u6728\u306E1/2\u306E\u5927\u304D\u3055\n\tint siz;\n\t//\u5358\u4F4D\u5143\
    \n\tconst T e;\n\t////\u6BD4\u8F03\u95A2\u6570\u306E\u578B\n\t//using F = function<T(T,\
    \ T)>;\n\t//\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n\tconst F f;\n\n\t//n\
    \ \u306E\u5927\u304D\u3055, a (\u5358\u4F4D\u5143) \u3067 segtree \u3092\u521D\
    \u671F\u5316\u3059\u308B\n\tsegtree(int n, const T a, const F f) : e(a), f(f)\
    \ {\n\t\tsiz = 1;\n\t\twhile (siz < n)siz <<= 1;\n\t\tseg.assign(2 * siz - 1,\
    \ e);\n\t\t--siz;\n\t}\n\n\t//k (0-indexed) \u756A\u76EE\u306B t \u3092\u4EE3\u5165\
    \n\tvoid set(int k, const T& t) {\n\t\tseg[k + siz] = t;\n\t}\n\n\t//f \u306B\u3088\
    \u3063\u3066\u6728\u3092\u69CB\u7BC9\n\tvoid build() {\n\t\tfor (int i = siz -\
    \ 1; i >= 0; --i) seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);\n\t}\n\n\t//i \u756A\
    \u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\n\tT operator[](const int i) {\n\t\t\
    return seg[i + siz];\n\t}\n\n\t//k \u756A\u76EE\u306E\u5024\u3092 a \u306B\u66F4\
    \u65B0\n\tvoid update(int k, T a) {\n\t\tk += siz;\n\t\t//\u5FC5\u8981\u3067\u3042\
    \u308C\u3070\u3053\u3053\u3092\u5909\u3048\u308B\n\t\tseg[k] = a;\n\t\twhile (k\
    \ > 0) {\n\t\t\tk = ((k - 1) >> 1);\n\t\t\tseg[k] = f(seg[k * 2 + 1], seg[k *\
    \ 2 + 2]);\n\t\t}\n\t}\n\n\t//[a, b) \u306B\u3064\u3044\u3066 f \u3057\u305F\u7D50\
    \u679C\u3092\u8FD4\u3059\n\tT query(int a, int b) {\n\t\tT l = e, r = e;\n\t\t\
    for (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {\n\t\t\tif (!(a & 1))l = f(l,\
    \ seg[a++]);\n\t\t\tif (!(b & 1))r = f(seg[--b], r);\n\t\t}\n\t\treturn f(l, r);\n\
    \t}\n\n\t//[start, end) \u306B\u3064\u3044\u3066\u3001[l, r) \u3092\u8ABF\u3079\
    \u306A\u304C\u3089 k \u756A\u76EE\u304C check \u3092\u6E80\u305F\u3059\u304B\u4E8C\
    \u5206\u63A2\u7D22 \u6700\u5F8C\u304C true \u306A\u3089 left, false \u306A\u3089\
    \ right f\u306E\u9006\u6F14\u7B97\n\ttemplate<typename C, typename FT>\n\tint\
    \ find(const int start, const int end, int l, int r, int k, const C check, T&\
    \ checknum, const bool b, const FT revf) {\n\t\t//cerr << checknum << '\\n';\n\
    \t\t//\u7BC4\u56F2\u5916\u307E\u305F\u306F\u305D\u3053\u304C\u3059\u3067\u306B\
    \u6E80\u305F\u3055\u306A\u3044\u3068\u304D\n\t\t//cerr << k << ',' << checknum\
    \ << '\\n';\n\t\tif (start <= l && r <= end && !check(seg[k], checknum)) {\n\t\
    \t\tchecknum = revf(checknum, seg[k]);\n\t\t\treturn -1;\n\t\t}\n\t\tif ((r <=\
    \ start || l >= end)) {\n\t\t\treturn -1;\n\t\t}\n\t\t//\u65E2\u306B\u8449\n\t\
    \tif (k >= siz) {\n\t\t\treturn k - siz;\n\t\t}\n\t\tint res;\n\t\tif (b) {\n\t\
    \t\t//\u5DE6\u5074\u3092\u8ABF\u3079\u308B\n\t\t\tres = find< C, FT >(start, end,\
    \ l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);\n\t\t\t//\u5DE6\u5074\
    \u304C\u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\u3048\n\t\t\tif (res\
    \ != -1)return (res);\n\t\t\treturn find< C, FT >(start, end, ((l + r) >> 1),\
    \ r, (k << 1) + 2, check, checknum, b, revf);\n\t\t}\n\t\telse {\n\t\t\t//\u53F3\
    \u5074\u3092\u8ABF\u3079\u308B\n\t\t\tres = find< C, FT >(start, end, ((l + r)\
    \ >> 1), r, (k << 1) + 2, check, checknum, b, revf);\n\t\t\t//\u53F3\u5074\u304C\
    \u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\u3048\n\t\t\tif (res !=\
    \ -1)return (res);\n\t\t\treturn find< C, FT >(start, end, l, ((l + r) >> 1),\
    \ (k << 1) + 1, check, checknum, b, revf);\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ C, typename FT>\n\tint find_left(int start, int end, const C check, T checknum,\
    \ FT revf) {\n\t\treturn find< C, FT >(start, end, 0, siz + 1, 0, check, checknum,\
    \ true, revf);\n\t}\n\n\ttemplate<typename C, typename FT>\n\tint find_right(int\
    \ start, int end, const C check, T checknum, FT revf) {\n\t\treturn find< C, FT\
    \ >(start, end, 0, siz + 1, 0, check, checknum, false, revf);\n\t}\n\n};\n\ntemplate<typename\
    \ T, typename F>\nsegtree<T, F> get_segtree(int n, const T& e, const F& f) {\n\
    \treturn { n, e, f };\n}\n"
  code: "\uFEFF/*\n* @title segment-tree\n* @docs kyopro/docs/segtree.md\n*/\n\n\n\
    //\u30BB\u30B0\u6728/0-indexed/\u975E\u518D\u5E30/(\u5927\u304D\u3055, \u5358\u4F4D\
    \u5143)\u3067\u521D\u671F\u5316\ntemplate<typename T, typename F>\nstruct segtree\
    \ {\n\t//\u6728\u3092\u914D\u5217\u3067\u3042\u3089\u308F\u3057\u305F\u3082\u306E\
    \n\tvector<T> seg;\n\t//\u6728\u306E1/2\u306E\u5927\u304D\u3055\n\tint siz;\n\t\
    //\u5358\u4F4D\u5143\n\tconst T e;\n\t////\u6BD4\u8F03\u95A2\u6570\u306E\u578B\
    \n\t//using F = function<T(T, T)>;\n\t//\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\
    \n\tconst F f;\n\n\t//n \u306E\u5927\u304D\u3055, a (\u5358\u4F4D\u5143) \u3067\
    \ segtree \u3092\u521D\u671F\u5316\u3059\u308B\n\tsegtree(int n, const T a, const\
    \ F f) : e(a), f(f) {\n\t\tsiz = 1;\n\t\twhile (siz < n)siz <<= 1;\n\t\tseg.assign(2\
    \ * siz - 1, e);\n\t\t--siz;\n\t}\n\n\t//k (0-indexed) \u756A\u76EE\u306B t \u3092\
    \u4EE3\u5165\n\tvoid set(int k, const T& t) {\n\t\tseg[k + siz] = t;\n\t}\n\n\t\
    //f \u306B\u3088\u3063\u3066\u6728\u3092\u69CB\u7BC9\n\tvoid build() {\n\t\tfor\
    \ (int i = siz - 1; i >= 0; --i) seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);\n\
    \t}\n\n\t//i \u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\n\tT operator[](const\
    \ int i) {\n\t\treturn seg[i + siz];\n\t}\n\n\t//k \u756A\u76EE\u306E\u5024\u3092\
    \ a \u306B\u66F4\u65B0\n\tvoid update(int k, T a) {\n\t\tk += siz;\n\t\t//\u5FC5\
    \u8981\u3067\u3042\u308C\u3070\u3053\u3053\u3092\u5909\u3048\u308B\n\t\tseg[k]\
    \ = a;\n\t\twhile (k > 0) {\n\t\t\tk = ((k - 1) >> 1);\n\t\t\tseg[k] = f(seg[k\
    \ * 2 + 1], seg[k * 2 + 2]);\n\t\t}\n\t}\n\n\t//[a, b) \u306B\u3064\u3044\u3066\
    \ f \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\n\tT query(int a, int b) {\n\t\t\
    T l = e, r = e;\n\t\tfor (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {\n\t\t\
    \tif (!(a & 1))l = f(l, seg[a++]);\n\t\t\tif (!(b & 1))r = f(seg[--b], r);\n\t\
    \t}\n\t\treturn f(l, r);\n\t}\n\n\t//[start, end) \u306B\u3064\u3044\u3066\u3001\
    [l, r) \u3092\u8ABF\u3079\u306A\u304C\u3089 k \u756A\u76EE\u304C check \u3092\u6E80\
    \u305F\u3059\u304B\u4E8C\u5206\u63A2\u7D22 \u6700\u5F8C\u304C true \u306A\u3089\
    \ left, false \u306A\u3089 right f\u306E\u9006\u6F14\u7B97\n\ttemplate<typename\
    \ C, typename FT>\n\tint find(const int start, const int end, int l, int r, int\
    \ k, const C check, T& checknum, const bool b, const FT revf) {\n\t\t//cerr <<\
    \ checknum << '\\n';\n\t\t//\u7BC4\u56F2\u5916\u307E\u305F\u306F\u305D\u3053\u304C\
    \u3059\u3067\u306B\u6E80\u305F\u3055\u306A\u3044\u3068\u304D\n\t\t//cerr << k\
    \ << ',' << checknum << '\\n';\n\t\tif (start <= l && r <= end && !check(seg[k],\
    \ checknum)) {\n\t\t\tchecknum = revf(checknum, seg[k]);\n\t\t\treturn -1;\n\t\
    \t}\n\t\tif ((r <= start || l >= end)) {\n\t\t\treturn -1;\n\t\t}\n\t\t//\u65E2\
    \u306B\u8449\n\t\tif (k >= siz) {\n\t\t\treturn k - siz;\n\t\t}\n\t\tint res;\n\
    \t\tif (b) {\n\t\t\t//\u5DE6\u5074\u3092\u8ABF\u3079\u308B\n\t\t\tres = find<\
    \ C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);\n\
    \t\t\t//\u5DE6\u5074\u304C\u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\
    \u3048\n\t\t\tif (res != -1)return (res);\n\t\t\treturn find< C, FT >(start, end,\
    \ ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);\n\t\t}\n\t\telse\
    \ {\n\t\t\t//\u53F3\u5074\u3092\u8ABF\u3079\u308B\n\t\t\tres = find< C, FT >(start,\
    \ end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);\n\t\t\t//\u53F3\
    \u5074\u304C\u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\u3048\n\t\t\
    \tif (res != -1)return (res);\n\t\t\treturn find< C, FT >(start, end, l, ((l +\
    \ r) >> 1), (k << 1) + 1, check, checknum, b, revf);\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ C, typename FT>\n\tint find_left(int start, int end, const C check, T checknum,\
    \ FT revf) {\n\t\treturn find< C, FT >(start, end, 0, siz + 1, 0, check, checknum,\
    \ true, revf);\n\t}\n\n\ttemplate<typename C, typename FT>\n\tint find_right(int\
    \ start, int end, const C check, T checknum, FT revf) {\n\t\treturn find< C, FT\
    \ >(start, end, 0, siz + 1, 0, check, checknum, false, revf);\n\t}\n\n};\n\ntemplate<typename\
    \ T, typename F>\nsegtree<T, F> get_segtree(int n, const T& e, const F& f) {\n\
    \treturn { n, e, f };\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/segtree.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/segtree_2D_yosupo-judge.test.cpp
  - kyopro/test/segtree_yosupo-judge.test.cpp
  - kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp
documentation_of: kyopro/library/datastructure/segtree.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/segtree.cpp
- /library/kyopro/library/datastructure/segtree.cpp.html
title: segment-tree
---
﻿