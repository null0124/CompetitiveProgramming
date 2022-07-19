---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: kyopro/library/geometry/vector2D.cpp
    title: vector(2D)
  - icon: ':question:'
    path: kyopro/library/others/modint.cpp
    title: modint
  - icon: ':question:'
    path: kyopro/library/template/template.cpp
    title: template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1144
    links:
    - https://yukicoder.me/problems/no/1144
  bundledCode: "#line 1 \"kyopro/test/vector2D_yukicoder.test.cpp\"\n\uFEFF#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1144\"\n\n#line 1 \"kyopro/library/template/template.cpp\"\
    \n\uFEFF/*\n* @title template\n* @docs kyopro/docs/template.md\n*/\n\n\n/*\n\u3053\
    \u306E\u30B3\u30FC\u30C9\u3001\u3068\uFF5E\u304A\u308C!\nBe accepted!\n\u2227\uFF3F\
    \u2227\u3000\n\uFF08\uFF61\uFF65\u03C9\uFF65\uFF61)\u3064\u2501\u2606\u30FB*\u3002\
    \n\u2282\u3000\u3000 \u30CE \u3000\u3000\u3000\u30FB\u309C+.\n\u3000\u3057\u30FC\
    \uFF2A\u3000\u3000\u3000\xB0\u3002+ *\xB4\xA8)\n \u3000\u3000\u3000\u3000\u3000\
    \u3000\u3000\u3000\u3000.\xB7 \xB4\xB8.\xB7*\xB4\xA8) \xB8.\xB7*\xA8)\n\t\t  \u3000\
    \u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000\u3000(\xB8.\xB7\xB4 (\xB8.\xB7\
    '* \u2606\n*/\n\n#include <cstdio>\n#include <algorithm>\n#include <string>\n\
    #include <cmath>\n#include <cstring>\n#include <vector>\n#include <numeric>\n\
    #include <iostream>\n#include <random>\n#include <map>\n#include <unordered_map>\n\
    #include <queue>\n#include <regex>\n#include <functional>\n#include <complex>\n\
    #include <list>\n#include <cassert>\n#include <iomanip>\n#include <set>\n#include\
    \ <stack>\n#include <bitset>\n#include <array>\n#include <chrono>\n\n//#pragma\
    \ GCC target(\"arch=skylake-avx512\")\n//#pragma GCC target (\"avx2\")\n//#pragma\
    \ GCC optimize (\"O3\")\n//#pragma GCC target (\"sse4\")\n//#pragma GCC optimize\
    \ (\"unroll-loops\")\n//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native\"\
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
    \ mod = 998244353;\nconstexpr long double eps = 1e-6;\nconst long double PI =\
    \ acosl(-1.0L);\n\nusing namespace std;\n\nvoid scans(string& str) {\n\tchar c;\n\
    \tstr = \"\";\n\tscanf(\"%c\", &c);\n\tif (c == '\\n')scanf(\"%c\", &c);\n\twhile\
    \ (c != '\\n' && c != -1 && c != ' ') {\n\t\tstr += c;\n\t\tscanf(\"%c\", &c);\n\
    \t}\n}\n\nvoid scanc(char& str) {\n\tchar c;\n\tscanf(\"%c\", &c);\n\tif (c ==\
    \ -1)return;\n\twhile (c == '\\n') {\n\t\tscanf(\"%c\", &c);\n\t}\n\tstr = c;\n\
    }\n\ndouble acot(double x) {\n\treturn PI / 2 - atan(x);\n}\n\nll LSB(ll n) {\
    \ return (n & (-n)); }\n\ntemplate<typename T>\ninline T chmin(T& a, const T&\
    \ b) {\n\tif (a > b)a = b;\n\treturn a;\n}\n\ntemplate<typename T>\ninline T chmax(T&\
    \ a, const T& b) {\n\tif (a < b)a = b;\n\treturn a;\n}\n\n////cpp_int\n//#include\
    \ <boost/multiprecision/cpp_int.hpp>\n//#include <boost/multiprecision/cpp_dec_float.hpp>\n\
    //using namespace boost::multiprecision;\n\n//atcoder library\n//#include <atcoder/all>\n\
    //using namespace atcoder;\n\n//random_device seed_gen;\n//mt19937 engine(seed_gen());\n\
    //uniform_distribution dist(-1.0, 1.0);\n\n/*----------------------------------------------------------------------------------*/\n\
    #line 1 \"kyopro/library/others/modint.cpp\"\n\uFEFF/*\n* @title modint\n* @docs\
    \ kyopro/docs/modint.md\n*/\n\ntemplate<int mod>\nstruct modint {\n\tint val;\n\
    \n\tmodint() : val(0) {};\n\tmodint(ll x) : val(x >= 0 ? x % mod : (mod + x %\
    \ mod) % mod) {};\n\n\tmodint& operator=(const modint& x) {\n\t\tval = x.val;\n\
    \t\treturn *this;\n\t}\n\n\tmodint& operator+=(const modint& x) {\n\t\tval +=\
    \ x.val;\n\t\tif (val >= mod)val -= mod;\n\t\treturn *this;\n\t}\n\n\tmodint&\
    \ operator-=(const modint& x) {\n\t\tval += mod - x.val;\n\t\tif (val >= mod)val\
    \ -= mod;\n\t\treturn *this;\n\t}\n\n\tmodint& operator*=(const modint& x) {\n\
    \t\tval = (int)((ll)val * (ll)x.val % mod);\n\t\treturn *this;\n\t}\n\n\tmodint&\
    \ operator/=(const modint& x) {\n\t\tint a = x.val, b = mod, u = 1, v = 0, t;\n\
    \t\twhile (b > 0) {\n\t\t\tt = a / b;\n\t\t\tswap(a -= t * b, b);\n\t\t\tswap(u\
    \ -= t * v, v);\n\t\t}\n\t\t*this *= modint(u);\n\t\treturn *this;\n\t}\n\n\t\
    modint operator++() {\n\t\tval = (val + 1 == mod ? 0 : val + 1);\n\t\treturn *this;\n\
    \t}\n\n\tmodint operator--() {\n\t\tval = (val == 0 ? mod - 1 : val - 1);\n\t\t\
    return *this;\n\t}\n\n\tmodint operator+(const modint& x) const {\n\t\treturn\
    \ (modint(*this) += x);\n\t}\n\n\tmodint operator-(const modint& x) const {\n\t\
    \treturn (modint(*this) -= x);\n\t}\n\n\tmodint operator*(const modint& x) const\
    \ {\n\t\treturn (modint(*this) *= x);\n\t}\n\n\tmodint operator/(const modint&\
    \ x) const {\n\t\treturn (modint(*this) /= x);\n\t}\n\n\tbool operator==(const\
    \ modint& x)const {\n\t\treturn (val == x.val);\n\t}\n\n\tbool operator!=(const\
    \ modint& x)const {\n\t\treturn (val != x.val);\n\t}\n\n\tbool operator<(const\
    \ modint& x)const {\n\t\treturn (val < x.val);\n\t}\n\n\tbool operator>(const\
    \ modint& x)const {\n\t\treturn (val > x.val);\n\t}\n\n\tmodint pow(ll n) {\n\t\
    \tmodint ret(1), a(val);\n\t\twhile (n > 0) {\n\t\t\tif (n % 2) ret *= a;\n\t\t\
    \ta *= a;\n\t\t\tn /= 2;\n\t\t}\n\t\treturn ret;\n\t}\n\n\tstatic int getmod()\
    \ { return mod; };\n};\n\nusing ModInt = modint<MOD>;\nusing Modint = modint<mod>;\n\
    #line 5 \"kyopro/test/vector2D_yukicoder.test.cpp\"\n\n#line 1 \"kyopro/library/geometry/vector2D.cpp\"\
    \n\uFEFF/*\n* @title vector(2D)\n* @docs kyopro/docs/vector2D.md\n*/\n\nstruct\
    \ vector2D {\n\n\tll x, y;\n\n\tvector2D(ll x, ll y) : x(x), y(y) {}\n\tvector2D(ll\
    \ stx, ll sty, ll enx, ll eny) : x(enx - stx), y(eny - sty) {}\n\tvector2D() :\
    \ x(0), y(0) {}\n\n\tvector2D operator+(const vector2D p) { return vector2D(x\
    \ + p.x, y + p.y); }\n\tvector2D operator-(const vector2D p) { return vector2D(x\
    \ - p.x, y - p.y); }\n\t// \u30B9\u30AB\u30E9\u30FC\u500D\n\tvector2D operator*(const\
    \ ll p) { return vector2D(x * p, y * p); }\n\n};\n\ninline ll vectorproduct(vector2D\
    \ p, vector2D q) { return abs(p.x * q.y - p.y * q.x); }\ninline ll vectorproductcomp(vector2D\
    \ p, vector2D q) { return p.x * q.y - p.y * q.x; }\n\ninline bool comp(const vector2D&\
    \ a, const vector2D& b) {\n\tif (a.x == 0 and a.y == 0)return true;\n\telse if\
    \ (b.x == 0 and b.y == 0)return false;\n\telse if (a.x < 0) {\n\t\tif (b.x < 0)\
    \ {\n\t\t\treturn vectorproductcomp(a, b) > 0;\n\t\t}\n\t\telse {\n\t\t\treturn\
    \ false;\n\t\t}\n\t}\n\telse {\n\t\tif (b.x < 0) {\n\t\t\treturn true;\n\t\t}\n\
    \t\telse {\n\t\t\treturn vectorproductcomp(a, b) > 0;\n\t\t}\n\t}\n}\n#line 7\
    \ \"kyopro/test/vector2D_yukicoder.test.cpp\"\n\nint main() {\n\n\tint n;\n\t\
    scanf(\"%d\", &n);\n\tvector<pair<int, int>> p(n);\n\tfor (auto& [x, y] : p) scanf(\"\
    %d%d\", &x, &y);\n\tmodint<MOD> ans;\n\tvector<vector2D> q;\n\trep(i, n) {\n\t\
    \tq.clear();\n\t\trep(j, n) {\n\t\t\tif (i == j or p[i] == p[j])continue;\n\t\t\
    \telse if (p[j].second - p[i].second >= 0)q.emplace_back(vector2D(p[i].first,\
    \ p[i].second, p[j].first, p[j].second));\n\t\t\telse q.emplace_back(vector2D(p[i].first,\
    \ p[i].second, p[j].first, p[j].second) * -1);\n\t\t}\n\t\tint m = q.size();\n\
    \t\tvector2D r;\n\t\tsort(all(q), comp);\n\t\tfor (int j = m - 1; j >= 0; --j)\
    \ {\n\t\t\tr = r + q[j];\n\t\t\tans += vectorproduct(q[j], r);\n\t\t}\n\t}\n\t\
    ans /= 3;\n\tprintf(\"%d\\n\", ans.val);\n\n\tPlease AC;\n}\n"
  code: "\uFEFF#define PROBLEM \"https://yukicoder.me/problems/no/1144\"\n\n#include\
    \ \"../library/template/template.cpp\"\n#include \"../library/others/modint.cpp\"\
    \n\n#include \"../library/geometry/vector2D.cpp\"\n\nint main() {\n\n\tint n;\n\
    \tscanf(\"%d\", &n);\n\tvector<pair<int, int>> p(n);\n\tfor (auto& [x, y] : p)\
    \ scanf(\"%d%d\", &x, &y);\n\tmodint<MOD> ans;\n\tvector<vector2D> q;\n\trep(i,\
    \ n) {\n\t\tq.clear();\n\t\trep(j, n) {\n\t\t\tif (i == j or p[i] == p[j])continue;\n\
    \t\t\telse if (p[j].second - p[i].second >= 0)q.emplace_back(vector2D(p[i].first,\
    \ p[i].second, p[j].first, p[j].second));\n\t\t\telse q.emplace_back(vector2D(p[i].first,\
    \ p[i].second, p[j].first, p[j].second) * -1);\n\t\t}\n\t\tint m = q.size();\n\
    \t\tvector2D r;\n\t\tsort(all(q), comp);\n\t\tfor (int j = m - 1; j >= 0; --j)\
    \ {\n\t\t\tr = r + q[j];\n\t\t\tans += vectorproduct(q[j], r);\n\t\t}\n\t}\n\t\
    ans /= 3;\n\tprintf(\"%d\\n\", ans.val);\n\n\tPlease AC;\n}"
  dependsOn:
  - kyopro/library/template/template.cpp
  - kyopro/library/others/modint.cpp
  - kyopro/library/geometry/vector2D.cpp
  isVerificationFile: true
  path: kyopro/test/vector2D_yukicoder.test.cpp
  requiredBy: []
  timestamp: '2022-07-20 00:04:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: kyopro/test/vector2D_yukicoder.test.cpp
layout: document
redirect_from:
- /verify/kyopro/test/vector2D_yukicoder.test.cpp
- /verify/kyopro/test/vector2D_yukicoder.test.cpp.html
title: kyopro/test/vector2D_yukicoder.test.cpp
---
