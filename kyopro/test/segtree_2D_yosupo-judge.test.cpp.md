---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../library/datastructure/segtree_2d.cpp:\
    \ line -1: no such header\n"
  code: "\uFEFF#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../library/template/template.cpp\"\n\n#include \"../library/datastructure/segtree.cpp\"\
    \n#include \"../library/datastructure/segtree_2d.cpp\"\n\nint main() {\n\n\tint\
    \ n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tvector<tuple<int, int, int>> a(n);\n\t\
    for (auto& [x, y, w] : a)scanf(\"%d%d%d\", &x, &y, &w);\n\tvector<tuple<int, int,\
    \ int, int, int>> query(q);\n\tfor (auto& [t, l, d, r, u] : query) {\n\t\tscanf(\"\
    %d%d%d%d\", &t, &l, &d, &r);\n\t\tif (t) {\n\t\t\tscanf(\"%d\", &u);\n\t\t}\n\t\
    }\n\n\tint siz = 0;\n\t//zaatsu\n\t{\n\t\tvector<int> R;\n\t\tfor (const auto&\
    \ [x, y, w] : a)R.emplace_back(x);\n\t\tfor (const auto& [t, l, d, r, u] : query)\
    \ {\n\t\t\tR.emplace_back(l);\n\t\t\tif (t) {\n\t\t\t\tR.emplace_back(r);\n\t\t\
    \t}\n\t\t}\n\t\tsort(all(R));\n\t\tR.erase(unique(all(R)), R.end());\n\t\tfor\
    \ (auto& [x, y, w] : a) {\n\t\t\tx = distance(R.begin(), lower_bound(all(R), x));\n\
    \t\t}\n\t\tfor (auto& [t, l, d, r, u] : query) {\n\t\t\tl = distance(R.begin(),\
    \ lower_bound(all(R), l));\n\t\t\tif (t) {\n\t\t\t\tr = distance(R.begin(), lower_bound(all(R),\
    \ r));\n\t\t\t}\n\t\t}\n\t\tsiz = R.size();\n\t}\n\n\tauto seg = get_segtree2D(siz,\
    \ 0ll, plus<ll>());\n\n\tfor (const auto& [x, y, w] : a)seg.preset(x, y);\n\t\
    for (const auto& [t, l, d, r, u] : query) {\n\t\tseg.preset(l, d);\n\t\tif (t)\
    \ {\n\t\t\tseg.preset(r, u);\n\t\t}\n\t}\n\tseg.build();\n\tfor (const auto& [x,\
    \ y, w] : a) {\n\t\tseg.update(x, y, w);\n\t}\n\tfor (const auto& [t, l, d, r,\
    \ u] : query) {\n\t\tif (t) {\n\t\t\tprintf(\"%lld\\n\", seg.query(l, r, d, u));\n\
    \t\t}\n\t\telse {\n\t\t\tseg.update(l, d, r);\n\t\t}\n\t}\n\n\tPlease AC;\n}"
  dependsOn: []
  isVerificationFile: true
  path: kyopro/test/segtree_2D_yosupo-judge.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: kyopro/test/segtree_2D_yosupo-judge.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/segtree_2D_yosupo-judge.test.cpp
- /verify/kyopro/test/segtree_2D_yosupo-judge.test.cpp.html
title: kyopro/test/segtree_2D_yosupo-judge.test.cpp
---
