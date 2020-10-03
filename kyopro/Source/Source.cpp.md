---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ <bitset>\n\n////\u591A\u500D\u9577\u6574\u6570, cpp_int\u3067\u5BA3\u8A00\n\
    //#include <boost/multiprecision/cpp_int.hpp>\n//using namespace boost::multiprecision;\n\
    //\n#pragma GCC target (\"avx2\")\n#pragma GCC optimization (\"O3\")\n#pragma\
    \ GCC optimization (\"unroll-loops\")\n//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\"\
    )\n#define repeat(i, n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int\
    \ i = 0; i < (n); ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\"\
    )\n#define printyn(a) printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a\
    \ ? \"YES\\n\" : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"\
    imposible\\n\")\n#define printdb(a) printf(\"%.50lf\\n\", a) //\u5C11\u6570\u51FA\
    \u529B\n#define printLdb(a) printf(\"%.50Lf\\n\", a) //\u5C11\u6570\u51FA\u529B\
    \n#define printdbd(a) printf(\"%.16lf\\n\", a) //\u5C11\u6570\u51FA\u529B(\u6841\
    \u5C11\u306A\u3081)\n#define prints(s) printf(\"%s\\n\", s.c_str()) //string\u51FA\
    \u529B\n#define all(x) (x).begin(), (x).end()\n#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)\n\
    #define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)\n#define Please return\n#define\
    \ AC 0\n#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b)\
    \ \u304B\u3089 (c, d) \u306E\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2 */\n\
    #define inf numeric_limits<double>::infinity();\n#define linf numeric_limits<long\
    \ double>::infinity()\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \nconstexpr int INF = 1073741823;\nconstexpr int MINF = -1073741823;\nconstexpr\
    \ ll LINF = ll(4661686018427387903);\nconstexpr ll MOD = 1e9 + 7;\nconstexpr ll\
    \ mod = 998244353;\nconstexpr long double eps = 1e-6;\nconst long double PI =\
    \ acosl(-1.0L);\n\nusing namespace std;\n\nvoid scans(string& str) {\n\tchar c;\n\
    \tstr = \"\";\n\tscanf(\"%c\", &c);\n\tif (c == '\\n')scanf(\"%c\", &c);\n\twhile\
    \ (c != '\\n' && c != -1 && c != ' ') {\n\t\tstr += c;\n\t\tscanf(\"%c\", &c);\n\
    \t}\n}\n\nvoid scanc(char& str) {\n\tchar c;\n\tscanf(\"%c\", &c);\n\tif (c ==\
    \ -1)return;\n\twhile (c == '\\n') {\n\t\tscanf(\"%c\", &c);\n\t}\n\tstr = c;\n\
    }\n\ndouble acot(double x) {\n\treturn PI / 2 - atan(x);\n}\n\nll LSB(ll n) {\
    \ return (n & (-n)); }\n\ntemplate<typename T>\ninline T chmin(T& a, const T&\
    \ b) {\n\tif (a > b)a = b;\n\treturn a;\n}\n\ntemplate<typename T>\ninline T chmax(T&\
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n\n////atcoder library\n\
    //#include <atcoder/all>\n//using namespace atcoder;\n\n/*-----------------------------------------\u3053\
    \u3053\u304B\u3089\u30B3\u30FC\u30C9-----------------------------------------*/\n\
    \n\n\nint main() {\n\n\n\n\tPlease AC;\n}\n"
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
    #include <set>\n#include <stack>\n#include <bitset>\n\n////\u591A\u500D\u9577\u6574\
    \u6570, cpp_int\u3067\u5BA3\u8A00\n//#include <boost/multiprecision/cpp_int.hpp>\n\
    //using namespace boost::multiprecision;\n//\n#pragma GCC target (\"avx2\")\n\
    #pragma GCC optimization (\"O3\")\n#pragma GCC optimization (\"unroll-loops\"\
    )\n//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\"\
    )\n#define repeat(i, n, m) for(int i = n; i < (m); ++i)\n#define rep(i, n) for(int\
    \ i = 0; i < (n); ++i)\n#define printynl(a) printf(a ? \"yes\\n\" : \"no\\n\"\
    )\n#define printyn(a) printf(a ? \"Yes\\n\" : \"No\\n\")\n#define printYN(a) printf(a\
    \ ? \"YES\\n\" : \"NO\\n\")\n#define printim(a) printf(a ? \"possible\\n\" : \"\
    imposible\\n\")\n#define printdb(a) printf(\"%.50lf\\n\", a) //\u5C11\u6570\u51FA\
    \u529B\n#define printLdb(a) printf(\"%.50Lf\\n\", a) //\u5C11\u6570\u51FA\u529B\
    \n#define printdbd(a) printf(\"%.16lf\\n\", a) //\u5C11\u6570\u51FA\u529B(\u6841\
    \u5C11\u306A\u3081)\n#define prints(s) printf(\"%s\\n\", s.c_str()) //string\u51FA\
    \u529B\n#define all(x) (x).begin(), (x).end()\n#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)\n\
    #define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)\n#define Please return\n#define\
    \ AC 0\n#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b)\
    \ \u304B\u3089 (c, d) \u306E\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2 */\n\
    #define inf numeric_limits<double>::infinity();\n#define linf numeric_limits<long\
    \ double>::infinity()\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \nconstexpr int INF = 1073741823;\nconstexpr int MINF = -1073741823;\nconstexpr\
    \ ll LINF = ll(4661686018427387903);\nconstexpr ll MOD = 1e9 + 7;\nconstexpr ll\
    \ mod = 998244353;\nconstexpr long double eps = 1e-6;\nconst long double PI =\
    \ acosl(-1.0L);\n\nusing namespace std;\n\nvoid scans(string& str) {\n\tchar c;\n\
    \tstr = \"\";\n\tscanf(\"%c\", &c);\n\tif (c == '\\n')scanf(\"%c\", &c);\n\twhile\
    \ (c != '\\n' && c != -1 && c != ' ') {\n\t\tstr += c;\n\t\tscanf(\"%c\", &c);\n\
    \t}\n}\n\nvoid scanc(char& str) {\n\tchar c;\n\tscanf(\"%c\", &c);\n\tif (c ==\
    \ -1)return;\n\twhile (c == '\\n') {\n\t\tscanf(\"%c\", &c);\n\t}\n\tstr = c;\n\
    }\n\ndouble acot(double x) {\n\treturn PI / 2 - atan(x);\n}\n\nll LSB(ll n) {\
    \ return (n & (-n)); }\n\ntemplate<typename T>\ninline T chmin(T& a, const T&\
    \ b) {\n\tif (a > b)a = b;\n\treturn a;\n}\n\ntemplate<typename T>\ninline T chmax(T&\
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n\n////atcoder library\n\
    //#include <atcoder/all>\n//using namespace atcoder;\n\n/*-----------------------------------------\u3053\
    \u3053\u304B\u3089\u30B3\u30FC\u30C9-----------------------------------------*/\n\
    \n\n\nint main() {\n\n\n\n\tPlease AC;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/Source/Source.cpp
  requiredBy: []
  timestamp: '2020-10-04 03:14:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/Source/Source.cpp
layout: document
redirect_from:
- /library/kyopro/Source/Source.cpp
- /library/kyopro/Source/Source.cpp.html
title: kyopro/Source/Source.cpp
---
