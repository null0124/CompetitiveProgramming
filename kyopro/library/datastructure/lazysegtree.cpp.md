---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/lazysegtree_yosupo-judge.test.cpp
    title: kyopro/test/lazysegtree_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/lazysegtree.md
    document_title: lazy-segment-tree
    links: []
  bundledCode: "#line 1 \"kyopro/library/datastructure/lazysegtree.cpp\"\n\uFEFF/*\n\
    * @title lazy-segment-tree\n* @docs kyopro/docs/lazysegtree.md\n*/\n\n//\u30BB\
    \u30B0\u6728/0-indexed/\u975E\u518D\u5E30/n \u306E\u5927\u304D\u3055, a (\u5358\
    \u4F4D\u5143), \u672C\u4F53\u306E\u30DE\u30FC\u30B8\u95A2\u6570, \u9045\u5EF6\u30CE\
    \u30FC\u30C9\u306E\u5358\u4F4D\u5143, \u9045\u5EF6\u30CE\u30FC\u30C9\u306E\u30DE\
    \u30FC\u30B8\u95A2\u6570, \u9045\u5EF6\u30CE\u30FC\u30C9\u3068\u672C\u4F53\u306E\
    \u30DE\u30FC\u30B8\u95A2\u6570 \u3067 segtree \u3092\u521D\u671F\u5316\u3059\u308B\
    \ntemplate<typename T, typename U, typename F, typename F2, typename F3, typename\
    \ F4>\nstruct lazysegtree {\n\t//\u6728\u3092\u914D\u5217\u3067\u3042\u3089\u308F\
    \u3057\u305F\u3082\u306E\n\tvector<T> seg;\n\t//\u9045\u5EF6\u30CE\u30FC\u30C9\
    \n\tvector<U> lazy;\n\t//\u30B5\u30A4\u30BA\u30CE\u30FC\u30C9\n\tvector<int> size;\n\
    \t//\u9045\u5EF6\u30CE\u30FC\u30C9\u306E\u30D5\u30E9\u30B0\u7BA1\u7406\n\tvector<bool>\
    \ flag;\n\t//\u6728\u306E1/2\u306E\u5927\u304D\u3055\n\tint siz, height;\n\t//\u672C\
    \u4F53\u306E\u5358\u4F4D\u5143\n\tconst T se;\n\t//\u9045\u5EF6\u30CE\u30FC\u30C9\
    \u306E\u5358\u4F4D\u5143\n\tconst U le;\n\t////\u672C\u4F53\u306E\u30DE\u30FC\u30B8\
    \u95A2\u6570\u306E\u578B\n\t//using F = function<T(T, T)>;\n\t////\u9045\u5EF6\
    \u30CE\u30FC\u30C9\u306E\u30DE\u30FC\u30B8\u95A2\u6570\u306E\u578B\n\t//using\
    \ F2 = function<U(U, U)>;\n\t////\u9045\u5EF6\u30CE\u30FC\u30C9\u3068\u672C\u4F53\
    \u306E\u30DE\u30FC\u30B8\u95A2\u6570\u306E\u578B\n\t//using F3 = function<T(T,\
    \ U)>;\n\t////\u30B5\u30A4\u30BA\u3092\u4F7F\u3063\u305F\u6F14\u7B97\u3092\u3059\
    \u308B\u95A2\u6570\u306E\u578B\n\t//using F4 = function<U(U, int)>;\n\t//\u672C\
    \u4F53\u540C\u58EB\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n\tconst F\
    \ f;\n\t//\u9045\u5EF6\u30CE\u30FC\u30C9\u540C\u58EB\u3092\u30DE\u30FC\u30B8\u3059\
    \u308B\u95A2\u6570\n\tconst F2 f2;\n\t//\u9045\u5EF6\u30CE\u30FC\u30C9\u3068\u672C\
    \u4F53\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n\tconst F3 f3;\n\t//\u30B5\
    \u30A4\u30BA\u3092\u4F7F\u3063\u305F\u6F14\u7B97\u3092\u3059\u308B\u95A2\u6570\
    \n\tconst F4 f4;\n\n\t//n \u306E\u5927\u304D\u3055, a (\u5358\u4F4D\u5143), \u672C\
    \u4F53\u306E\u30DE\u30FC\u30B8\u95A2\u6570, \u9045\u5EF6\u30CE\u30FC\u30C9\u306E\
    \u5358\u4F4D\u5143, \u9045\u5EF6\u30CE\u30FC\u30C9\u306E\u30DE\u30FC\u30B8\u95A2\
    \u6570, \u9045\u5EF6\u30CE\u30FC\u30C9\u3068\u672C\u4F53\u306E\u30DE\u30FC\u30B8\
    \u95A2\u6570, \u30B5\u30A4\u30BA\u3092\u4F7F\u3063\u305F\u6F14\u7B97\u3092\u3059\
    \u308B\u95A2\u6570 \u3067 segtree \u3092\u521D\u671F\u5316\u3059\u308B\n\tlazysegtree(int\
    \ n, const T se, const F f, const U le, const F2 f2, const F3 f3, const F4 f4)\
    \ : se(se), f(f), le(le), f2(f2), f3(f3), f4(f4) {\n\t\tsiz = 1;\n\t\theight =\
    \ 0;\n\t\twhile (siz < n)siz <<= 1, ++height;\n\t\tseg.assign(2 * siz - 1, se);\n\
    \t\tlazy.assign(2 * siz - 1, le);\n\t\tsize.assign(2 * siz - 1, 1);\n\t\tflag.assign(2\
    \ * siz - 1, false);\n\t\t--siz;\n\t}\n\n\t//k (0-indexed) \u756A\u76EE\u306B\
    \ t \u3092\u4EE3\u5165\n\tvoid set(int k, const T& t) {\n\t\tseg[k + siz] = t;\n\
    \t}\n\n\t//f \u306B\u3088\u3063\u3066\u6728\u3092\u69CB\u7BC9\n\tvoid build()\
    \ {\n\t\tfor (int i = siz - 1; i >= 0; --i) {\n\t\t\tseg[i] = f(seg[i * 2 + 1],\
    \ seg[i * 2 + 2]);\n\t\t\tsize[i] = size[i * 2 + 1] + size[i * 2 + 2];\n\t\t}\n\
    \t}\n\n\t//i \u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\n\tT operator[](const\
    \ int i) {\n\t\treturn query(i, i + 1);\n\t}\n\n\t//k \u756A\u76EE\u306E\u9045\
    \u5EF6\u30CE\u30FC\u30C9\u3092\u4F1D\u64AD\u3059\u308B\n\tinline T merge(int k)\
    \ {\n\t\treturn (!flag[k] ? seg[k] : f3(seg[k], f4(lazy[k], size[k])));\n\t}\n\
    \n\t//\u5B50\u306B\u4F1D\u64AD\n\tinline void eval(int k) {\n\t\tif (flag[k])\
    \ {\n\t\t\tlazy[k * 2 + 1] = f2(lazy[k * 2 + 1], lazy[k]);\n\t\t\tlazy[k * 2 +\
    \ 2] = f2(lazy[k * 2 + 2], lazy[k]);\n\t\t\tflag[k * 2 + 1] = flag[k * 2 + 2]\
    \ = true;\n\t\t\tseg[k] = merge(k);\n\t\t\tlazy[k] = le;\n\t\t\tflag[k] = false;\n\
    \t\t}\n\t}\n\n\tinline void bottomup(int k) {\n\t\twhile (k > 0) {\n\t\t\tk =\
    \ ((k - 1) >> 1);\n\t\t\tseg[k] = f(merge(2 * k + 1), merge(2 * k + 2));\n\t\t\
    }\n\t}\n\n\tinline void topdown(int k) {\n\t\tfor (int i = height; i > 0; --i)\
    \ {\n\t\t\teval(((k + 1) >> i) - 1);\n\t\t}\n\t}\n\n\t//k \u756A\u76EE\u306E\u5024\
    \u3092 a \u306B\u66F4\u65B0\n\tvoid update(int k, T a) {\n\t\tk += siz;\n\t\t\
    //\u5FC5\u8981\u3067\u3042\u308C\u3070\u3053\u3053\u3092\u5909\u3048\u308B\n\t\
    \tseg[k] = a;\n\t\twhile (k > 0) {\n\t\t\tk = ((k - 1) >> 1);\n\t\t\tseg[k] =\
    \ f(seg[k * 2 + 1], seg[k * 2 + 2]);\n\t\t}\n\t}\n\n\t//[l, r) \u306E\u5024\u3092\
    \ a \u306B\u66F4\u65B0\n\tvoid update(int l, int r, U a) {\n\t\tint x = l + siz,\
    \ y = r + siz - 1;\n\t\ttopdown(x);\n\t\ttopdown(y);\n\t\tfor (l += siz, r +=\
    \ siz; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (!(l & 1)) {\n\t\t\t\tlazy[l] = f2(lazy[l],\
    \ a);\n\t\t\t\tflag[l] = true;\n\t\t\t\t++l;\n\t\t\t}\n\t\t\tif (!(r & 1)) {\n\
    \t\t\t\t--r;\n\t\t\t\tlazy[r] = f2(lazy[r], a);\n\t\t\t\tflag[r] = true;\n\t\t\
    \t}\n\t\t}\n\t\tbottomup(x);\n\t\tbottomup(y);\n\t}\n\n\t//[a, b) \u306B\u3064\
    \u3044\u3066 f \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\n\tT query(int a, int\
    \ b) {\n\t\ttopdown(a += siz);\n\t\ttopdown(b += siz - 1);\n\t\tT l = se, r =\
    \ se;\n\t\tfor (++b; a < b; a >>= 1, b >>= 1) {\n\t\t\tif (!(a & 1))l = f(l, merge(a++));\n\
    \t\t\tif (!(b & 1))r = f(merge(--b), r);\n\t\t}\n\t\treturn f(l, r);\n\t}\n\n\t\
    ////[start, end) \u306B\u3064\u3044\u3066\u3001[l, r) \u3092\u8ABF\u3079\u306A\
    \u304C\u3089 k \u756A\u76EE\u304C check \u3092\u6E80\u305F\u3059\u304B\u4E8C\u5206\
    \u63A2\u7D22 \u6700\u5F8C\u304C true \u306A\u3089 left, false \u306A\u3089 right\
    \ f\u306E\u9006\u6F14\u7B97\n\t//template<typename C, typename FT>\n\t//int find(const\
    \ int start, const int end, int l, int r, int k, const C check, T& checknum, const\
    \ bool b, const FT revf) {\n\t//\t//cerr << checknum << '\\n';\n\t//\t//\u7BC4\
    \u56F2\u5916\u307E\u305F\u306F\u305D\u3053\u304C\u3059\u3067\u306B\u6E80\u305F\
    \u3055\u306A\u3044\u3068\u304D\n\t//\t//cerr << k << ',' << checknum << '\\n';\n\
    \t//\tif (start <= l && r <= end && !check(seg[k], checknum)) {\n\t//\t\tchecknum\
    \ = revf(checknum, seg[k]);\n\t//\t\treturn -1;\n\t//\t}\n\t//\tif ((r <= start\
    \ || l >= end)) {\n\t//\t\treturn -1;\n\t//\t}\n\t//\t//\u65E2\u306B\u8449\n\t\
    //\tif (k >= siz) {\n\t//\t\treturn k - siz;\n\t//\t}\n\t//\tint res;\n\t//\t\
    if (b) {\n\t//\t\t//\u5DE6\u5074\u3092\u8ABF\u3079\u308B\n\t//\t\tres = find<\
    \ C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);\n\
    \t//\t\t//\u5DE6\u5074\u304C\u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\
    \u3048\n\t//\t\tif (res != -1)return (res);\n\t//\t\treturn find< C, FT >(start,\
    \ end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);\n\t//\t}\n\t\
    //\telse {\n\t//\t\t//\u53F3\u5074\u3092\u8ABF\u3079\u308B\n\t//\t\tres = find<\
    \ C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);\n\
    \t//\t\t//\u53F3\u5074\u304C\u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\
    \u3048\n\t//\t\tif (res != -1)return (res);\n\t//\t\treturn find< C, FT >(start,\
    \ end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);\n\t//\t}\n\t\
    //}\n\n\t//template<typename C, typename FT>\n\t//int find_left(int start, int\
    \ end, const C check, T checknum, FT revf) {\n\t//\treturn find< C, FT >(start,\
    \ end, 0, siz + 1, 0, check, checknum, true, revf);\n\t//}\n\n\t//template<typename\
    \ C, typename FT>\n\t//int find_right(int start, int end, const C check, T checknum,\
    \ FT revf) {\n\t//\treturn find< C, FT >(start, end, 0, siz + 1, 0, check, checknum,\
    \ false, revf);\n\t//}\n\n};\n\ntemplate<typename T, typename U, typename F, typename\
    \ F2, typename F3, typename F4>\nlazysegtree<T, U, F, F2, F3, F4> get_lazy_segtree(int\
    \ n, const T& se, const F& f, const U& le, const F2& f2, const F3& f3, const F4&\
    \ f4) {\n\treturn { n, se, f, le, f2, f3, f4 };\n}\n"
  code: "\uFEFF/*\n* @title lazy-segment-tree\n* @docs kyopro/docs/lazysegtree.md\n\
    */\n\n//\u30BB\u30B0\u6728/0-indexed/\u975E\u518D\u5E30/n \u306E\u5927\u304D\u3055\
    , a (\u5358\u4F4D\u5143), \u672C\u4F53\u306E\u30DE\u30FC\u30B8\u95A2\u6570, \u9045\
    \u5EF6\u30CE\u30FC\u30C9\u306E\u5358\u4F4D\u5143, \u9045\u5EF6\u30CE\u30FC\u30C9\
    \u306E\u30DE\u30FC\u30B8\u95A2\u6570, \u9045\u5EF6\u30CE\u30FC\u30C9\u3068\u672C\
    \u4F53\u306E\u30DE\u30FC\u30B8\u95A2\u6570 \u3067 segtree \u3092\u521D\u671F\u5316\
    \u3059\u308B\ntemplate<typename T, typename U, typename F, typename F2, typename\
    \ F3, typename F4>\nstruct lazysegtree {\n\t//\u6728\u3092\u914D\u5217\u3067\u3042\
    \u3089\u308F\u3057\u305F\u3082\u306E\n\tvector<T> seg;\n\t//\u9045\u5EF6\u30CE\
    \u30FC\u30C9\n\tvector<U> lazy;\n\t//\u30B5\u30A4\u30BA\u30CE\u30FC\u30C9\n\t\
    vector<int> size;\n\t//\u9045\u5EF6\u30CE\u30FC\u30C9\u306E\u30D5\u30E9\u30B0\u7BA1\
    \u7406\n\tvector<bool> flag;\n\t//\u6728\u306E1/2\u306E\u5927\u304D\u3055\n\t\
    int siz, height;\n\t//\u672C\u4F53\u306E\u5358\u4F4D\u5143\n\tconst T se;\n\t\
    //\u9045\u5EF6\u30CE\u30FC\u30C9\u306E\u5358\u4F4D\u5143\n\tconst U le;\n\t////\u672C\
    \u4F53\u306E\u30DE\u30FC\u30B8\u95A2\u6570\u306E\u578B\n\t//using F = function<T(T,\
    \ T)>;\n\t////\u9045\u5EF6\u30CE\u30FC\u30C9\u306E\u30DE\u30FC\u30B8\u95A2\u6570\
    \u306E\u578B\n\t//using F2 = function<U(U, U)>;\n\t////\u9045\u5EF6\u30CE\u30FC\
    \u30C9\u3068\u672C\u4F53\u306E\u30DE\u30FC\u30B8\u95A2\u6570\u306E\u578B\n\t//using\
    \ F3 = function<T(T, U)>;\n\t////\u30B5\u30A4\u30BA\u3092\u4F7F\u3063\u305F\u6F14\
    \u7B97\u3092\u3059\u308B\u95A2\u6570\u306E\u578B\n\t//using F4 = function<U(U,\
    \ int)>;\n\t//\u672C\u4F53\u540C\u58EB\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\
    \u6570\n\tconst F f;\n\t//\u9045\u5EF6\u30CE\u30FC\u30C9\u540C\u58EB\u3092\u30DE\
    \u30FC\u30B8\u3059\u308B\u95A2\u6570\n\tconst F2 f2;\n\t//\u9045\u5EF6\u30CE\u30FC\
    \u30C9\u3068\u672C\u4F53\u3092\u30DE\u30FC\u30B8\u3059\u308B\u95A2\u6570\n\tconst\
    \ F3 f3;\n\t//\u30B5\u30A4\u30BA\u3092\u4F7F\u3063\u305F\u6F14\u7B97\u3092\u3059\
    \u308B\u95A2\u6570\n\tconst F4 f4;\n\n\t//n \u306E\u5927\u304D\u3055, a (\u5358\
    \u4F4D\u5143), \u672C\u4F53\u306E\u30DE\u30FC\u30B8\u95A2\u6570, \u9045\u5EF6\u30CE\
    \u30FC\u30C9\u306E\u5358\u4F4D\u5143, \u9045\u5EF6\u30CE\u30FC\u30C9\u306E\u30DE\
    \u30FC\u30B8\u95A2\u6570, \u9045\u5EF6\u30CE\u30FC\u30C9\u3068\u672C\u4F53\u306E\
    \u30DE\u30FC\u30B8\u95A2\u6570, \u30B5\u30A4\u30BA\u3092\u4F7F\u3063\u305F\u6F14\
    \u7B97\u3092\u3059\u308B\u95A2\u6570 \u3067 segtree \u3092\u521D\u671F\u5316\u3059\
    \u308B\n\tlazysegtree(int n, const T se, const F f, const U le, const F2 f2, const\
    \ F3 f3, const F4 f4) : se(se), f(f), le(le), f2(f2), f3(f3), f4(f4) {\n\t\tsiz\
    \ = 1;\n\t\theight = 0;\n\t\twhile (siz < n)siz <<= 1, ++height;\n\t\tseg.assign(2\
    \ * siz - 1, se);\n\t\tlazy.assign(2 * siz - 1, le);\n\t\tsize.assign(2 * siz\
    \ - 1, 1);\n\t\tflag.assign(2 * siz - 1, false);\n\t\t--siz;\n\t}\n\n\t//k (0-indexed)\
    \ \u756A\u76EE\u306B t \u3092\u4EE3\u5165\n\tvoid set(int k, const T& t) {\n\t\
    \tseg[k + siz] = t;\n\t}\n\n\t//f \u306B\u3088\u3063\u3066\u6728\u3092\u69CB\u7BC9\
    \n\tvoid build() {\n\t\tfor (int i = siz - 1; i >= 0; --i) {\n\t\t\tseg[i] = f(seg[i\
    \ * 2 + 1], seg[i * 2 + 2]);\n\t\t\tsize[i] = size[i * 2 + 1] + size[i * 2 + 2];\n\
    \t\t}\n\t}\n\n\t//i \u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\n\tT operator[](const\
    \ int i) {\n\t\treturn query(i, i + 1);\n\t}\n\n\t//k \u756A\u76EE\u306E\u9045\
    \u5EF6\u30CE\u30FC\u30C9\u3092\u4F1D\u64AD\u3059\u308B\n\tinline T merge(int k)\
    \ {\n\t\treturn (!flag[k] ? seg[k] : f3(seg[k], f4(lazy[k], size[k])));\n\t}\n\
    \n\t//\u5B50\u306B\u4F1D\u64AD\n\tinline void eval(int k) {\n\t\tif (flag[k])\
    \ {\n\t\t\tlazy[k * 2 + 1] = f2(lazy[k * 2 + 1], lazy[k]);\n\t\t\tlazy[k * 2 +\
    \ 2] = f2(lazy[k * 2 + 2], lazy[k]);\n\t\t\tflag[k * 2 + 1] = flag[k * 2 + 2]\
    \ = true;\n\t\t\tseg[k] = merge(k);\n\t\t\tlazy[k] = le;\n\t\t\tflag[k] = false;\n\
    \t\t}\n\t}\n\n\tinline void bottomup(int k) {\n\t\twhile (k > 0) {\n\t\t\tk =\
    \ ((k - 1) >> 1);\n\t\t\tseg[k] = f(merge(2 * k + 1), merge(2 * k + 2));\n\t\t\
    }\n\t}\n\n\tinline void topdown(int k) {\n\t\tfor (int i = height; i > 0; --i)\
    \ {\n\t\t\teval(((k + 1) >> i) - 1);\n\t\t}\n\t}\n\n\t//k \u756A\u76EE\u306E\u5024\
    \u3092 a \u306B\u66F4\u65B0\n\tvoid update(int k, T a) {\n\t\tk += siz;\n\t\t\
    //\u5FC5\u8981\u3067\u3042\u308C\u3070\u3053\u3053\u3092\u5909\u3048\u308B\n\t\
    \tseg[k] = a;\n\t\twhile (k > 0) {\n\t\t\tk = ((k - 1) >> 1);\n\t\t\tseg[k] =\
    \ f(seg[k * 2 + 1], seg[k * 2 + 2]);\n\t\t}\n\t}\n\n\t//[l, r) \u306E\u5024\u3092\
    \ a \u306B\u66F4\u65B0\n\tvoid update(int l, int r, U a) {\n\t\tint x = l + siz,\
    \ y = r + siz - 1;\n\t\ttopdown(x);\n\t\ttopdown(y);\n\t\tfor (l += siz, r +=\
    \ siz; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (!(l & 1)) {\n\t\t\t\tlazy[l] = f2(lazy[l],\
    \ a);\n\t\t\t\tflag[l] = true;\n\t\t\t\t++l;\n\t\t\t}\n\t\t\tif (!(r & 1)) {\n\
    \t\t\t\t--r;\n\t\t\t\tlazy[r] = f2(lazy[r], a);\n\t\t\t\tflag[r] = true;\n\t\t\
    \t}\n\t\t}\n\t\tbottomup(x);\n\t\tbottomup(y);\n\t}\n\n\t//[a, b) \u306B\u3064\
    \u3044\u3066 f \u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\n\tT query(int a, int\
    \ b) {\n\t\ttopdown(a += siz);\n\t\ttopdown(b += siz - 1);\n\t\tT l = se, r =\
    \ se;\n\t\tfor (++b; a < b; a >>= 1, b >>= 1) {\n\t\t\tif (!(a & 1))l = f(l, merge(a++));\n\
    \t\t\tif (!(b & 1))r = f(merge(--b), r);\n\t\t}\n\t\treturn f(l, r);\n\t}\n\n\t\
    ////[start, end) \u306B\u3064\u3044\u3066\u3001[l, r) \u3092\u8ABF\u3079\u306A\
    \u304C\u3089 k \u756A\u76EE\u304C check \u3092\u6E80\u305F\u3059\u304B\u4E8C\u5206\
    \u63A2\u7D22 \u6700\u5F8C\u304C true \u306A\u3089 left, false \u306A\u3089 right\
    \ f\u306E\u9006\u6F14\u7B97\n\t//template<typename C, typename FT>\n\t//int find(const\
    \ int start, const int end, int l, int r, int k, const C check, T& checknum, const\
    \ bool b, const FT revf) {\n\t//\t//cerr << checknum << '\\n';\n\t//\t//\u7BC4\
    \u56F2\u5916\u307E\u305F\u306F\u305D\u3053\u304C\u3059\u3067\u306B\u6E80\u305F\
    \u3055\u306A\u3044\u3068\u304D\n\t//\t//cerr << k << ',' << checknum << '\\n';\n\
    \t//\tif (start <= l && r <= end && !check(seg[k], checknum)) {\n\t//\t\tchecknum\
    \ = revf(checknum, seg[k]);\n\t//\t\treturn -1;\n\t//\t}\n\t//\tif ((r <= start\
    \ || l >= end)) {\n\t//\t\treturn -1;\n\t//\t}\n\t//\t//\u65E2\u306B\u8449\n\t\
    //\tif (k >= siz) {\n\t//\t\treturn k - siz;\n\t//\t}\n\t//\tint res;\n\t//\t\
    if (b) {\n\t//\t\t//\u5DE6\u5074\u3092\u8ABF\u3079\u308B\n\t//\t\tres = find<\
    \ C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);\n\
    \t//\t\t//\u5DE6\u5074\u304C\u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\
    \u3048\n\t//\t\tif (res != -1)return (res);\n\t//\t\treturn find< C, FT >(start,\
    \ end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);\n\t//\t}\n\t\
    //\telse {\n\t//\t\t//\u53F3\u5074\u3092\u8ABF\u3079\u308B\n\t//\t\tres = find<\
    \ C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);\n\
    \t//\t\t//\u53F3\u5074\u304C\u9069\u3057\u3066\u305F\u3089\u305D\u308C\u304C\u7B54\
    \u3048\n\t//\t\tif (res != -1)return (res);\n\t//\t\treturn find< C, FT >(start,\
    \ end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);\n\t//\t}\n\t\
    //}\n\n\t//template<typename C, typename FT>\n\t//int find_left(int start, int\
    \ end, const C check, T checknum, FT revf) {\n\t//\treturn find< C, FT >(start,\
    \ end, 0, siz + 1, 0, check, checknum, true, revf);\n\t//}\n\n\t//template<typename\
    \ C, typename FT>\n\t//int find_right(int start, int end, const C check, T checknum,\
    \ FT revf) {\n\t//\treturn find< C, FT >(start, end, 0, siz + 1, 0, check, checknum,\
    \ false, revf);\n\t//}\n\n};\n\ntemplate<typename T, typename U, typename F, typename\
    \ F2, typename F3, typename F4>\nlazysegtree<T, U, F, F2, F3, F4> get_lazy_segtree(int\
    \ n, const T& se, const F& f, const U& le, const F2& f2, const F3& f3, const F4&\
    \ f4) {\n\treturn { n, se, f, le, f2, f3, f4 };\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/datastructure/lazysegtree.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/lazysegtree_yosupo-judge.test.cpp
documentation_of: kyopro/library/datastructure/lazysegtree.cpp
layout: document
redirect_from:
- /library/kyopro/library/datastructure/lazysegtree.cpp
- /library/kyopro/library/datastructure/lazysegtree.cpp.html
title: lazy-segment-tree
---
﻿