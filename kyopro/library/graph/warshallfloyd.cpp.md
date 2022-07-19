---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: kyopro/test/warshallfloyd_aoj.test.cpp
    title: kyopro/test/warshallfloyd_aoj.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: kyopro/docs/warshallfloyd.md
    document_title: warshallfloyd
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/warshallfloyd.cpp\"\n\uFEFF/*\n* @title\
    \ warshallfloyd\n* @docs kyopro/docs/warshallfloyd.md\n*/\n\n//\u30EF\u30FC\u30B7\
    \u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\nvoid WarshallFloyd(int n, vector<vector<ll>>\
    \ & d) {\n\trep(i, n) {//\u7D4C\u7531\u3059\u308B\u9802\u70B9\n\t\trep(j, n) {//\u59CB\
    \u70B9\n\t\t\trep(k, n) {//\u7D42\u70B9\n\t\t\t\td[j][k] = min(d[j][k], d[j][i]\
    \ + d[i][k]);\n\t\t\t}\n\t\t}\n\t}\n}\n\n"
  code: "\uFEFF/*\n* @title warshallfloyd\n* @docs kyopro/docs/warshallfloyd.md\n\
    */\n\n//\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\nvoid WarshallFloyd(int\
    \ n, vector<vector<ll>> & d) {\n\trep(i, n) {//\u7D4C\u7531\u3059\u308B\u9802\u70B9\
    \n\t\trep(j, n) {//\u59CB\u70B9\n\t\t\trep(k, n) {//\u7D42\u70B9\n\t\t\t\td[j][k]\
    \ = min(d[j][k], d[j][i] + d[i][k]);\n\t\t\t}\n\t\t}\n\t}\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/warshallfloyd.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - kyopro/test/warshallfloyd_aoj.test.cpp
documentation_of: kyopro/library/graph/warshallfloyd.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/warshallfloyd.cpp
- /library/kyopro/library/graph/warshallfloyd.cpp.html
title: warshallfloyd
---
