---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp
    title: kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp
  - icon: ':heavy_check_mark:'
    path: kyopro/test/mo_yosupo-judge.test.cpp
    title: kyopro/test/mo_yosupo-judge.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/mo.md
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 1 \"kyopro/library/others/mo.cpp\"\n\uFEFF/*\n* @title Mo's\
    \ Algorithm\n* @docs kyopro/docs/mo.md\n*/\n\ntemplate<typename ADD_LEFT, typename\
    \ DEL_LEFT, typename REM, typename ADD_RIGHT = ADD_LEFT, typename DEL_RIGHT =\
    \ DEL_LEFT, typename T = int>\nstruct mo {\n\tint sqn, q, l, r, p;\n\tT ret;\n\
    \tvector<tuple<int, int, int>> query;\n\tvector<T> ans;\n\n\tmo(const int& n,\
    \ const int& q) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)), query(q),\
    \ ans(q) {}\n\n\tinline void insert(const int& l, const int& r) {\n\t\tquery[p]\
    \ = { l, r, p };\n\t\t++p;\n\t}\n\n\tinline void read(const bool& oneindexed)\
    \ {\n\t\tfor (auto& [left, right, idx] : query) {\n\t\t\tscanf(\"%d%d\", &left,\
    \ &right);\n\t\t\tif (oneindexed)--left;\n\t\t\tidx = p++;\n\t\t}\n\t}\n\n\tvoid\
    \ build() {\n\t\tsort(all(query), [&](const tuple<int, int, int>& a, const tuple<int,\
    \ int, int>& b) {\n\t\t\tif (get<0>(a) / sqn != get<0>(b) / sqn)return get<0>(a)\
    \ < get<0>(b);\n\t\t\treturn get<1>(a) < get<1>(b);\n\t\t\t});\n\t}\n\n\tvoid\
    \ run(const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const DEL_LEFT& del_left,\
    \ const DEL_RIGHT& del_right, const REM& rem) {\n\t\tfor (const auto& [ql, qr,\
    \ qo] : query) {\n\t\t\twhile (l > ql)add_left(--l, ret);\n\t\t\twhile (r < qr)add_right(r++,\
    \ ret);\n\t\t\twhile (l < ql)del_left(l++, ret);\n\t\t\twhile (r > qr)del_right(--r,\
    \ ret);\n\t\t\trem(qo, ans, ret);\n\t\t}\n\t}\n\n\tvoid run(const ADD_LEFT& add,\
    \ const DEL_LEFT& del, const REM& rem) {\n\t\trun(add, add, del, del, rem);\n\t\
    }\n\n\tT operator [](const int& idx) {\n\t\treturn ans[idx];\n\t}\n\n\tvoid allrun(const\
    \ bool& oneindexed, const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const\
    \ DEL_LEFT& del_left, const DEL_RIGHT& del_right, const REM& rem) {\n\t\tread(oneindexed);\n\
    \t\tbuild();\n\t\trun(add_left, add_right, del_left, del_right, rem);\n\t}\n\n\
    \tvoid allrun(const bool& oneindexed, const ADD_LEFT& add, const DEL_LEFT& del,\
    \ const REM& rem) {\n\t\tallrun(oneindexed, add, add, del, del, rem, rem);\n\t\
    }\n\n};\n"
  code: "\uFEFF/*\n* @title Mo's Algorithm\n* @docs kyopro/docs/mo.md\n*/\n\ntemplate<typename\
    \ ADD_LEFT, typename DEL_LEFT, typename REM, typename ADD_RIGHT = ADD_LEFT, typename\
    \ DEL_RIGHT = DEL_LEFT, typename T = int>\nstruct mo {\n\tint sqn, q, l, r, p;\n\
    \tT ret;\n\tvector<tuple<int, int, int>> query;\n\tvector<T> ans;\n\n\tmo(const\
    \ int& n, const int& q) : sqn((int)sqrt(n)), q(q), l(0), r(0), p(0), ret(T(0)),\
    \ query(q), ans(q) {}\n\n\tinline void insert(const int& l, const int& r) {\n\t\
    \tquery[p] = { l, r, p };\n\t\t++p;\n\t}\n\n\tinline void read(const bool& oneindexed)\
    \ {\n\t\tfor (auto& [left, right, idx] : query) {\n\t\t\tscanf(\"%d%d\", &left,\
    \ &right);\n\t\t\tif (oneindexed)--left;\n\t\t\tidx = p++;\n\t\t}\n\t}\n\n\tvoid\
    \ build() {\n\t\tsort(all(query), [&](const tuple<int, int, int>& a, const tuple<int,\
    \ int, int>& b) {\n\t\t\tif (get<0>(a) / sqn != get<0>(b) / sqn)return get<0>(a)\
    \ < get<0>(b);\n\t\t\treturn get<1>(a) < get<1>(b);\n\t\t\t});\n\t}\n\n\tvoid\
    \ run(const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const DEL_LEFT& del_left,\
    \ const DEL_RIGHT& del_right, const REM& rem) {\n\t\tfor (const auto& [ql, qr,\
    \ qo] : query) {\n\t\t\twhile (l > ql)add_left(--l, ret);\n\t\t\twhile (r < qr)add_right(r++,\
    \ ret);\n\t\t\twhile (l < ql)del_left(l++, ret);\n\t\t\twhile (r > qr)del_right(--r,\
    \ ret);\n\t\t\trem(qo, ans, ret);\n\t\t}\n\t}\n\n\tvoid run(const ADD_LEFT& add,\
    \ const DEL_LEFT& del, const REM& rem) {\n\t\trun(add, add, del, del, rem);\n\t\
    }\n\n\tT operator [](const int& idx) {\n\t\treturn ans[idx];\n\t}\n\n\tvoid allrun(const\
    \ bool& oneindexed, const ADD_LEFT& add_left, const ADD_RIGHT& add_right, const\
    \ DEL_LEFT& del_left, const DEL_RIGHT& del_right, const REM& rem) {\n\t\tread(oneindexed);\n\
    \t\tbuild();\n\t\trun(add_left, add_right, del_left, del_right, rem);\n\t}\n\n\
    \tvoid allrun(const bool& oneindexed, const ADD_LEFT& add, const DEL_LEFT& del,\
    \ const REM& rem) {\n\t\tallrun(oneindexed, add, add, del, del, rem, rem);\n\t\
    }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/others/mo.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/mo_yosupo-judge.test.cpp
  - kyopro/test/binary_search_on_segtree_yosupo-judge.test.cpp
documentation_of: kyopro/library/others/mo.cpp
layout: document
redirect_from:
- /library/kyopro/library/others/mo.cpp
- /library/kyopro/library/others/mo.cpp.html
title: Mo's Algorithm
---
﻿