---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
    title: kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: kyopro/docs/kth-shortest-path_yen.md
    document_title: kth-shortest-path(yen's algorithm)
    links: []
  bundledCode: "#line 1 \"kyopro/library/graph/kth-shortest-path_yen.cpp\"\n\uFEFF\
    /*\n* @title kth-shortest-path(yen's algorithm)\n* @docs kyopro/docs/kth-shortest-path_yen.md\n\
    */\n\n\n\ntemplate<typename T>\nvector<T> dijkstra(graph<T>& gh, vector<int>&\
    \ path, const int& v, const int& g, const int& n, const T Inf, const vector<vector<bool>>&\
    \ deleted, set<int> r) {\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> priq;\n\tvector<T> res(n);\n\tvector<int> prev(n);\n\t\
    fill(all(prev), -1);\n\tfill(all(res), Inf);\n\tpriq.push({ 0, v });\n\tres[v]\
    \ = 0;\n\tint top;\n\twhile (!priq.empty()) {\n\t\ttop = priq.top().second;\n\t\
    \tpriq.pop();\n\t\tfor (const auto& aa : gh[top]) {\n\t\t\tif (res[top] + aa.cost\
    \ >= res[aa.to] or deleted[top][aa.to] or r.find(aa.to) != r.end())continue;\n\
    \t\t\tres[aa.to] = aa.cost + res[top];\n\t\t\tprev[aa.to] = top;\n\t\t\tpriq.push({\
    \ res[aa.to], aa.to });\n\t\t}\n\t}\n\n\tfor (int i = g; i != -1; i = prev[i])path.push_back(i);\n\
    \treverse(all(path));\n\n\treturn res;\n}\n\ntemplate<typename T>\nvoid ksp(graph<T>&\
    \ g, const int& n, const int& start, const int& goal, const int& k, vector<vector<int>>&\
    \ path, vector<T>& ans, const T& Inf) {\n\tset<vector<int>> routememo;\n\tvector<T>\
    \ res, anstmp;\n\tvector<vector<bool>> deleted(n, vector<bool>(n));\n\tans.resize(k);\n\
    \tpath.resize(k);\n\tres = dijkstra<T>(g, path[0], start, goal, n, Inf, deleted,\
    \ {});\n\tans[0] = res[goal];\n\tanstmp = res;\n\troutememo.insert(path[0]);\n\
    \tauto func = [](const tuple<T, vector<int>, vector<T>>& a, const tuple<T, vector<int>,\
    \ vector<T>>& b) -> bool {\n\t\tif (get<0>(a) != get<0>(b))return get<0>(a) >\
    \ get<0>(b);\n\t\telse if (get<1>(a) != get<1>(b))return get<1>(a) > get<1>(b);\n\
    \t\telse return get<2>(a) > get<2>(b);\n\t};\n\tpriority_queue<tuple<T, vector<int>,\
    \ vector<T>>, vector<tuple<T, vector<int>, vector<T>>>, decltype(func)> priq{\
    \ func };\n\tmap<vector<int>, vector<int>> spurnode;\n\trep(i, k - 1) {\n\t\t\
    int siz = path[i].size();\n\t\tvector<int> route;\n\t\tset<int> r;\n\t\tT cost\
    \ = 0;\n\t\trep(j, siz - 1) {\n\t\t\troute.push_back(path[i][j]);\n\t\t\tr.insert(path[i][j]);\n\
    \t\t\tspurnode[route].push_back(path[i][j + 1]);\n\t\t\tif (j != 0) {\n\t\t\t\t\
    for (const auto& aa : g[path[i][j - 1]]) {\n\t\t\t\t\tif (aa.to == path[i][j])\
    \ {\n\t\t\t\t\t\tcost += aa.cost;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tfor (const auto& aa : spurnode[route])deleted[path[i][j]][aa] =\
    \ deleted[aa][path[i][j]] = true;\n\t\t\tif (j > 0)deleted[path[i][j - 1]][path[i][j]]\
    \ = deleted[path[i][j]][path[i][j - 1]] = true;\n\t\t\tres = dijkstra<T>(g, path[i\
    \ + 1], path[i][j], goal, n, Inf, deleted, r);\n\t\t\tif (j > 0)deleted[path[i][j\
    \ - 1]][path[i][j]] = deleted[path[i][j]][path[i][j - 1]] = false;\n\t\t\tfor\
    \ (const auto& aa : spurnode[route])deleted[path[i][j]][aa] = deleted[aa][path[i][j]]\
    \ = false;\n\t\t\tif (res[goal] >= Inf)continue;\n\t\t\tvector<int> tmp;\n\t\t\
    \tvector<T> tmp2(n);\n\t\t\tfor (int l = 0; l <= j; ++l) {\n\t\t\t\ttmp2[path[i][l]]\
    \ = anstmp[path[i][l]];\n\t\t\t}\n\t\t\tint l = 0;\n\t\t\tfor (; path[i][l] !=\
    \ path[i][j]; ++l) {\n\t\t\t\ttmp2[path[i][l]] = anstmp[path[i][l]];\n\t\t\t\t\
    tmp.push_back(path[i][l]);\n\t\t\t}\n\t\t\tfor (l = 0; path[i + 1][l] != goal;\
    \ ++l) {\n\t\t\t\ttmp2[path[i + 1][l]] = res[path[i + 1][l]];\n\t\t\t\ttmp.push_back(path[i\
    \ + 1][l]);\n\t\t\t}\n\t\t\ttmp.push_back(goal);\n\t\t\tint siz2 = path[i + 1].size();\n\
    \t\t\tfor (int l = 1; l < siz2; ++l) tmp2[path[i + 1][l]] = res[path[i + 1][l]]\
    \ + anstmp[path[i][j]];\n\t\t\tpriq.push(make_tuple(cost + res[goal], tmp, tmp2));\n\
    \t\t}\n\t\tif (priq.empty()) {\n\t\t\tfor (; i < k - 1; ++i)ans[i + 1] = -1;\n\
    \t\t\tbreak;\n\t\t}\n\t\tauto tmp = priq.top();\n\t\tpriq.pop();\n\t\twhile (routememo.find(get<1>(tmp))\
    \ != routememo.end() and !priq.empty()) {\n\t\t\ttmp = priq.top();\n\t\t\tpriq.pop();\n\
    \t\t}\n\t\tif (routememo.find(get<1>(tmp)) != routememo.end() and priq.empty())\
    \ {\n\t\t\tfor (; i < k - 1; ++i)ans[i + 1] = -1;\n\t\t\tbreak;\n\t\t}\n\t\tpath[i\
    \ + 1] = get<1>(tmp);\n\t\tans[i + 1] = get<0>(tmp);\n\t\troutememo.insert(path[i\
    \ + 1]);\n\t}\n\treturn;\n}\n"
  code: "\uFEFF/*\n* @title kth-shortest-path(yen's algorithm)\n* @docs kyopro/docs/kth-shortest-path_yen.md\n\
    */\n\n\n\ntemplate<typename T>\nvector<T> dijkstra(graph<T>& gh, vector<int>&\
    \ path, const int& v, const int& g, const int& n, const T Inf, const vector<vector<bool>>&\
    \ deleted, set<int> r) {\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> priq;\n\tvector<T> res(n);\n\tvector<int> prev(n);\n\t\
    fill(all(prev), -1);\n\tfill(all(res), Inf);\n\tpriq.push({ 0, v });\n\tres[v]\
    \ = 0;\n\tint top;\n\twhile (!priq.empty()) {\n\t\ttop = priq.top().second;\n\t\
    \tpriq.pop();\n\t\tfor (const auto& aa : gh[top]) {\n\t\t\tif (res[top] + aa.cost\
    \ >= res[aa.to] or deleted[top][aa.to] or r.find(aa.to) != r.end())continue;\n\
    \t\t\tres[aa.to] = aa.cost + res[top];\n\t\t\tprev[aa.to] = top;\n\t\t\tpriq.push({\
    \ res[aa.to], aa.to });\n\t\t}\n\t}\n\n\tfor (int i = g; i != -1; i = prev[i])path.push_back(i);\n\
    \treverse(all(path));\n\n\treturn res;\n}\n\ntemplate<typename T>\nvoid ksp(graph<T>&\
    \ g, const int& n, const int& start, const int& goal, const int& k, vector<vector<int>>&\
    \ path, vector<T>& ans, const T& Inf) {\n\tset<vector<int>> routememo;\n\tvector<T>\
    \ res, anstmp;\n\tvector<vector<bool>> deleted(n, vector<bool>(n));\n\tans.resize(k);\n\
    \tpath.resize(k);\n\tres = dijkstra<T>(g, path[0], start, goal, n, Inf, deleted,\
    \ {});\n\tans[0] = res[goal];\n\tanstmp = res;\n\troutememo.insert(path[0]);\n\
    \tauto func = [](const tuple<T, vector<int>, vector<T>>& a, const tuple<T, vector<int>,\
    \ vector<T>>& b) -> bool {\n\t\tif (get<0>(a) != get<0>(b))return get<0>(a) >\
    \ get<0>(b);\n\t\telse if (get<1>(a) != get<1>(b))return get<1>(a) > get<1>(b);\n\
    \t\telse return get<2>(a) > get<2>(b);\n\t};\n\tpriority_queue<tuple<T, vector<int>,\
    \ vector<T>>, vector<tuple<T, vector<int>, vector<T>>>, decltype(func)> priq{\
    \ func };\n\tmap<vector<int>, vector<int>> spurnode;\n\trep(i, k - 1) {\n\t\t\
    int siz = path[i].size();\n\t\tvector<int> route;\n\t\tset<int> r;\n\t\tT cost\
    \ = 0;\n\t\trep(j, siz - 1) {\n\t\t\troute.push_back(path[i][j]);\n\t\t\tr.insert(path[i][j]);\n\
    \t\t\tspurnode[route].push_back(path[i][j + 1]);\n\t\t\tif (j != 0) {\n\t\t\t\t\
    for (const auto& aa : g[path[i][j - 1]]) {\n\t\t\t\t\tif (aa.to == path[i][j])\
    \ {\n\t\t\t\t\t\tcost += aa.cost;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tfor (const auto& aa : spurnode[route])deleted[path[i][j]][aa] =\
    \ deleted[aa][path[i][j]] = true;\n\t\t\tif (j > 0)deleted[path[i][j - 1]][path[i][j]]\
    \ = deleted[path[i][j]][path[i][j - 1]] = true;\n\t\t\tres = dijkstra<T>(g, path[i\
    \ + 1], path[i][j], goal, n, Inf, deleted, r);\n\t\t\tif (j > 0)deleted[path[i][j\
    \ - 1]][path[i][j]] = deleted[path[i][j]][path[i][j - 1]] = false;\n\t\t\tfor\
    \ (const auto& aa : spurnode[route])deleted[path[i][j]][aa] = deleted[aa][path[i][j]]\
    \ = false;\n\t\t\tif (res[goal] >= Inf)continue;\n\t\t\tvector<int> tmp;\n\t\t\
    \tvector<T> tmp2(n);\n\t\t\tfor (int l = 0; l <= j; ++l) {\n\t\t\t\ttmp2[path[i][l]]\
    \ = anstmp[path[i][l]];\n\t\t\t}\n\t\t\tint l = 0;\n\t\t\tfor (; path[i][l] !=\
    \ path[i][j]; ++l) {\n\t\t\t\ttmp2[path[i][l]] = anstmp[path[i][l]];\n\t\t\t\t\
    tmp.push_back(path[i][l]);\n\t\t\t}\n\t\t\tfor (l = 0; path[i + 1][l] != goal;\
    \ ++l) {\n\t\t\t\ttmp2[path[i + 1][l]] = res[path[i + 1][l]];\n\t\t\t\ttmp.push_back(path[i\
    \ + 1][l]);\n\t\t\t}\n\t\t\ttmp.push_back(goal);\n\t\t\tint siz2 = path[i + 1].size();\n\
    \t\t\tfor (int l = 1; l < siz2; ++l) tmp2[path[i + 1][l]] = res[path[i + 1][l]]\
    \ + anstmp[path[i][j]];\n\t\t\tpriq.push(make_tuple(cost + res[goal], tmp, tmp2));\n\
    \t\t}\n\t\tif (priq.empty()) {\n\t\t\tfor (; i < k - 1; ++i)ans[i + 1] = -1;\n\
    \t\t\tbreak;\n\t\t}\n\t\tauto tmp = priq.top();\n\t\tpriq.pop();\n\t\twhile (routememo.find(get<1>(tmp))\
    \ != routememo.end() and !priq.empty()) {\n\t\t\ttmp = priq.top();\n\t\t\tpriq.pop();\n\
    \t\t}\n\t\tif (routememo.find(get<1>(tmp)) != routememo.end() and priq.empty())\
    \ {\n\t\t\tfor (; i < k - 1; ++i)ans[i + 1] = -1;\n\t\t\tbreak;\n\t\t}\n\t\tpath[i\
    \ + 1] = get<1>(tmp);\n\t\tans[i + 1] = get<0>(tmp);\n\t\troutememo.insert(path[i\
    \ + 1]);\n\t}\n\treturn;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/library/graph/kth-shortest-path_yen.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - kyopro/test/kth-shortest-path_yen_yukicoder.test.cpp
documentation_of: kyopro/library/graph/kth-shortest-path_yen.cpp
layout: document
redirect_from:
- /library/kyopro/library/graph/kth-shortest-path_yen.cpp
- /library/kyopro/library/graph/kth-shortest-path_yen.cpp.html
title: kth-shortest-path(yen's algorithm)
---
﻿