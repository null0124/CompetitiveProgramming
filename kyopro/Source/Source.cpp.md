---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"kyopro/Source/Source.cpp\"\n\uFEFF/*\n\u3053\u306E\u30B3\
    \u30FC\u30C9\u3001\u3068\uFF5E\u304A\u308C!\nBe accepted!\n\u2227\uFF3F\u2227\u3000\
    \n\uFF08\uFF61\uFF65\u03C9\uFF65\uFF61)\u3064\u2501\u2606\u30FB*\u3002\n\u2282\
    \u3000\u3000 \u30CE \u3000\u3000\u3000\u30FB\u309C+.\n\u3000\u3057\u30FC\uFF2A\
    \u3000\u3000\u3000\xB0\u3002+ *\xB4\xA8)\n \u3000\u3000\u3000\u3000\u3000\u3000\
    \u3000\u3000\u3000.\xB7 \xB4\xB8.\xB7*\xB4\xA8) \xB8.\xB7*\xA8)\n\t\t  \u3000\u3000\
    \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000(\xB8.\xB7\xB4 (\xB8.\xB7'* \u2606\
    \n*/\n\n#include <cstdio>\n#include <algorithm>\n#include <string>\n#include <cmath>\n\
    #include <cstring>\n#include <vector>\n#include <numeric>\n#include <iostream>\n\
    #include <random>\n#include <map>\n#include <unordered_map>\n#include <queue>\n\
    #include <regex>\n#include <functional>\n#include <complex>\n#include <list>\n\
    #include <cassert>\n#include <iomanip>\n#include <set>\n#include <stack>\n#include\
    \ <bitset>\n#include <array>\n#include <chrono>\n\n//#pragma GCC target(\"arch=skylake-avx512\"\
    )\n//#pragma GCC target(\"avx2\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC\
    \ optimize(\"Ofast\")\n//#pragma GCC target(\"sse4\")\n//#pragma GCC optimize(\"\
    unroll-loops\")\n//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\"\
    )\n#define repeat(i, n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int\
    \ i = 0; i < (n); ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\"\
    )\n#define printyn(a) printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a\
    \ ? \"YES\\n\" : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"\
    imposible\\n\")\n#define printdb(a) printf(\"%.50lf\\n\", a)\n#define printLdb(a)\
    \ printf(\"%.50Lf\\n\", a)\n#define printdbd(a) printf(\"%.16lf\\n\", a)\n#define\
    \ prints(s) printf(\"%s\\n\", s.c_str())\n#define all(x) (x).begin(), (x).end()\n\
    #define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)\n#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)\n\
    #define Please return\n#define AC 0\n#define manhattan_dist(a, b, c, d) (abs(a\
    \ - c) + abs(b - d))\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \nconstexpr int INF = 1073741823;\nconstexpr int MINF = -1073741823;\nconstexpr\
    \ ll LINF = ll(4661686018427387903);\nconstexpr ll MOD = 1e9 + 7;\nconstexpr ll\
    \ mod = 998244353;\nconstexpr long double eps = 1e-14;\nconst long double PI =\
    \ acosl(-1.0L);\n\nusing namespace std;\n\nvoid scans(string& str) {\n\tchar c;\n\
    \tstr = \"\";\n\tscanf(\"%c\", &c);\n\tif (c == '\\n')scanf(\"%c\", &c);\n\twhile\
    \ (c != '\\n' && c != -1 && c != ' ') {\n\t\tstr += c;\n\t\tscanf(\"%c\", &c);\n\
    \t}\n}\n\nvoid scanc(char& str) {\n\tchar c;\n\tscanf(\"%c\", &c);\n\tif (c ==\
    \ -1)return;\n\twhile (c == '\\n') {\n\t\tscanf(\"%c\", &c);\n\t}\n\tstr = c;\n\
    }\n\ndouble acot(double x) {\n\treturn PI / 2 - atan(x);\n}\n\nll LSB(ll n) {\
    \ return (n & (-n)); }\n\ntemplate<typename T>\ninline T chmin(T& a, const T&\
    \ b) {\n\tif (a > b)a = b;\n\treturn a;\n}\n\ntemplate<typename T>\ninline T chmax(T&\
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n\n//cpp_int\n#if __has_include(<boost/multiprecision/cpp_int.hpp>)\n\
    #include <boost/multiprecision/cpp_int.hpp>\n#include <boost/multiprecision/cpp_dec_float.hpp>\n\
    using namespace boost::multiprecision;\n#else\nusing cpp_int = ll;\n#endif\n\n\
    //atcoder library\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\n\
    //using namespace atcoder;\n#endif\n\n/*\n\trandom_device seed_gen;\n\tmt19937\
    \ engine(seed_gen());\n\tuniform_int_distribution dist(1, 100);\n*/\n\n\n/*----------------------------------------------------------------------------------*/\n\
    \n\n\nint main() {\n \n\t\n\n\tPlease AC;\n}\n"
  code: "\uFEFF/*\n\u3053\u306E\u30B3\u30FC\u30C9\u3001\u3068\uFF5E\u304A\u308C!\n\
    Be accepted!\n\u2227\uFF3F\u2227\u3000\n\uFF08\uFF61\uFF65\u03C9\uFF65\uFF61)\u3064\
    \u2501\u2606\u30FB*\u3002\n\u2282\u3000\u3000 \u30CE \u3000\u3000\u3000\u30FB\u309C\
    +.\n\u3000\u3057\u30FC\uFF2A\u3000\u3000\u3000\xB0\u3002+ *\xB4\xA8)\n \u3000\u3000\
    \u3000\u3000\u3000\u3000\u3000\u3000\u3000.\xB7 \xB4\xB8.\xB7*\xB4\xA8) \xB8.\xB7\
    *\xA8)\n\t\t  \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000(\xB8\
    .\xB7\xB4 (\xB8.\xB7'* \u2606\n*/\n\n#include <cstdio>\n#include <algorithm>\n\
    #include <string>\n#include <cmath>\n#include <cstring>\n#include <vector>\n#include\
    \ <numeric>\n#include <iostream>\n#include <random>\n#include <map>\n#include\
    \ <unordered_map>\n#include <queue>\n#include <regex>\n#include <functional>\n\
    #include <complex>\n#include <list>\n#include <cassert>\n#include <iomanip>\n\
    #include <set>\n#include <stack>\n#include <bitset>\n#include <array>\n#include\
    \ <chrono>\n\n//#pragma GCC target(\"arch=skylake-avx512\")\n//#pragma GCC target(\"\
    avx2\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC optimize(\"Ofast\")\n//#pragma\
    \ GCC target(\"sse4\")\n//#pragma GCC optimize(\"unroll-loops\")\n//#pragma GCC\
    \ target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\")\n#define\
    \ repeat(i, n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int i =\
    \ 0; i < (n); ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\")\n#define\
    \ printyn(a) printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a ?\
    \ \"YES\\n\" : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"\
    imposible\\n\")\n#define printdb(a) printf(\"%.50lf\\n\", a)\n#define printLdb(a)\
    \ printf(\"%.50Lf\\n\", a)\n#define printdbd(a) printf(\"%.16lf\\n\", a)\n#define\
    \ prints(s) printf(\"%s\\n\", s.c_str())\n#define all(x) (x).begin(), (x).end()\n\
    #define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)\n#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)\n\
    #define Please return\n#define AC 0\n#define manhattan_dist(a, b, c, d) (abs(a\
    \ - c) + abs(b - d))\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \nconstexpr int INF = 1073741823;\nconstexpr int MINF = -1073741823;\nconstexpr\
    \ ll LINF = ll(4661686018427387903);\nconstexpr ll MOD = 1e9 + 7;\nconstexpr ll\
    \ mod = 998244353;\nconstexpr long double eps = 1e-14;\nconst long double PI =\
    \ acosl(-1.0L);\n\nusing namespace std;\n\nvoid scans(string& str) {\n\tchar c;\n\
    \tstr = \"\";\n\tscanf(\"%c\", &c);\n\tif (c == '\\n')scanf(\"%c\", &c);\n\twhile\
    \ (c != '\\n' && c != -1 && c != ' ') {\n\t\tstr += c;\n\t\tscanf(\"%c\", &c);\n\
    \t}\n}\n\nvoid scanc(char& str) {\n\tchar c;\n\tscanf(\"%c\", &c);\n\tif (c ==\
    \ -1)return;\n\twhile (c == '\\n') {\n\t\tscanf(\"%c\", &c);\n\t}\n\tstr = c;\n\
    }\n\ndouble acot(double x) {\n\treturn PI / 2 - atan(x);\n}\n\nll LSB(ll n) {\
    \ return (n & (-n)); }\n\ntemplate<typename T>\ninline T chmin(T& a, const T&\
    \ b) {\n\tif (a > b)a = b;\n\treturn a;\n}\n\ntemplate<typename T>\ninline T chmax(T&\
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n\n//cpp_int\n#if __has_include(<boost/multiprecision/cpp_int.hpp>)\n\
    #include <boost/multiprecision/cpp_int.hpp>\n#include <boost/multiprecision/cpp_dec_float.hpp>\n\
    using namespace boost::multiprecision;\n#else\nusing cpp_int = ll;\n#endif\n\n\
    //atcoder library\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\n\
    //using namespace atcoder;\n#endif\n\n/*\n\trandom_device seed_gen;\n\tmt19937\
    \ engine(seed_gen());\n\tuniform_int_distribution dist(1, 100);\n*/\n\n\n/*----------------------------------------------------------------------------------*/\n\
    \n\n\nint main() {\n \n\t\n\n\tPlease AC;\n}"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/Source/Source.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/Source/Source.cpp
layout: document
redirect_from:
- /library/kyopro/Source/Source.cpp
- /library/kyopro/Source/Source.cpp.html
title: kyopro/Source/Source.cpp
---
