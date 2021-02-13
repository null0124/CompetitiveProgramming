/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>
#include <regex>
#include <functional>
#include <complex>
#include <list>
#include <cassert>
#include <iomanip>
#include <set>
#include <stack>
#include <bitset>
#include <array>
#include <chrono>

//#pragma GCC target("arch=skylake-avx512")
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define repeat(i, n, m) for(int i = n; i < (m); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a)
#define printLdb(a) printf("%.50Lf\n", a)
#define printdbd(a) printf("%.16lf\n", a)
#define prints(s) printf("%s\n", s.c_str())
#define all(x) (x).begin(), (x).end()
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d))

using ll = long long;
using ull = unsigned long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1e9 + 7;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-6;
const long double PI = acosl(-1.0L);

using namespace std;

void scans(string& str) {
	char c;
	str = "";
	scanf("%c", &c);
	if (c == '\n')scanf("%c", &c);
	while (c != '\n' && c != -1 && c != ' ') {
		str += c;
		scanf("%c", &c);
	}
}

void scanc(char& str) {
	char c;
	scanf("%c", &c);
	if (c == -1)return;
	while (c == '\n') {
		scanf("%c", &c);
	}
	str = c;
}

double acot(double x) {
	return PI / 2 - atan(x);
}

ll LSB(ll n) { return (n & (-n)); }

template<typename T>
inline T chmin(T& a, const T& b) {
	if (a > b)a = b;
	return a;
}

template<typename T>
inline T chmax(T& a, const T& b) {
	if (a < b)a = b;
	return a;
}

//cpp_int
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;
#else
using cpp_int = ll;
#endif

//atcoder library
#if __has_include(<atcoder/all>)
#include <atcoder/all>
//using namespace atcoder;
#endif

/*
	random_device seed_gen;
	mt19937 engine(seed_gen());
	uniform_int_distribution dist(1, 100);
*/


/*----------------------------------------------------------------------------------*/

/*
* @title segment-tree
* @docs kyopro/docs/segtree.md
*/


//セグ木/0-indexed/非再帰/(大きさ, 単位元)で初期化
template<typename T, typename F>
struct segtree {
	//木を配列であらわしたもの
	vector<T> seg;
	//木の1/2の大きさ
	int siz;
	//単位元
	const T e;
	////比較関数の型
	//using F = function<T(T, T)>;
	//マージする関数
	const F f;

	//n の大きさ, a (単位元) で segtree を初期化する
	segtree(int n, const T a, const F f) : e(a), f(f) {
		siz = 1;
		while (siz < n)siz <<= 1;
		seg.assign(2 * siz - 1, e);
		--siz;
	}

	//k (0-indexed) 番目に t を代入
	void set(int k, const T& t) {
		seg[k + siz] = t;
	}

	//f によって木を構築
	void build() {
		for (int i = siz - 1; i >= 0; --i) seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);
	}

	//i 番目の要素を返す
	T operator[](const int i) {
		return seg[i + siz];
	}

	//k 番目の値を a に更新
	void update(int k, T a) {
		k += siz;
		//必要であればここを変える
		seg[k] = a;
		while (k > 0) {
			k = ((k - 1) >> 1);
			seg[k] = f(seg[k * 2 + 1], seg[k * 2 + 2]);
		}
	}

	//[a, b) について f した結果を返す
	T query(int a, int b) {
		T l = e, r = e;
		for (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1))l = f(l, seg[a++]);
			if (!(b & 1))r = f(seg[--b], r);
		}
		return f(l, r);
	}

	//[start, end) について、[l, r) を調べながら k 番目が check を満たすか二分探索 最後が true なら left, false なら right fの逆演算
	template<typename C, typename FT>
	int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const FT revf) {
		//cerr << checknum << '\n';
		//範囲外またはそこがすでに満たさないとき
		//cerr << k << ',' << checknum << '\n';
		if (start <= l && r <= end && !check(seg[k], checknum)) {
			checknum = revf(checknum, seg[k]);
			return -1;
		}
		if ((r <= start || l >= end)) {
			return -1;
		}
		//既に葉
		if (k >= siz) {
			return k - siz;
		}
		int res;
		if (b) {
			//左側を調べる
			res = find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
			//左側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
		}
		else {
			//右側を調べる
			res = find< C, FT >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
			//右側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C, FT >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
		}
	}

	template<typename C, typename FT>
	int find_left(int start, int end, const C check, T checknum, FT revf) {
		return find< C, FT >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	}

	template<typename C, typename FT>
	int find_right(int start, int end, const C check, T checknum, FT revf) {
		return find< C, FT >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	}

};

template<typename T, typename F>
segtree<T, F> get_segtree(int n, const T& e, const F& f) {
	return { n, e, f };
}

/*
* @title segment-tree-2D
* @docs kyopro/docs/segtree_2d.md
*/


//セグ木/0-indexed/非再帰/(大きさ, 単位元)で初期化
template<typename T, typename F>
struct segtree2D {
	//木を配列であらわしたもの
	vector<segtree<T, F>> seg;
	//木の1/2の大きさ
	int siz;
	//単位元
	const T e;
	////比較関数の型
	//using F = function<T(T, T)>;
	//マージする関数
	const F f;
	//座標
	vector<vector<int>> pos;

	//n の大きさ, a (単位元) で segtree を初期化する
	segtree2D(int n, const T a, const F f) : e(a), f(f) {
		siz = 1;
		while (siz < n)siz <<= 1;
		pos.resize(2 * siz - 1);
		--siz;
	}

	//座標 (x, y) を準備
	void preset(int x, int y) {
		x += siz;
		pos[x].push_back(y);
		while (x > 0) {
			x = (x - 1) >> 1;
			pos[x].push_back(y);
		}
	}

	//f によって木を構築
	void build() {
		for (auto& aa : pos) {
			sort(all(aa));
			aa.erase(unique(all(aa)), aa.end());
		}
		for (const auto& aa : pos) {
			seg.emplace_back(get_segtree(aa.size(), e, f));
			seg.back().build();
		}
	}

	//(x, y) の値を a に更新
	void update(int x, int y, T a) {
		x += siz;
		seg[x].update(distance(pos[x].begin(), lower_bound(all(pos[x]), y)), f(seg[x][distance(pos[x].begin(), lower_bound(all(pos[x]), y))], a));
		while (x > 0) {
			x = ((x - 1) >> 1);
			seg[x].update(distance(pos[x].begin(), lower_bound(all(pos[x]), y)), f(seg[x][distance(pos[x].begin(), lower_bound(all(pos[x]), y))], a));
		}
	}

	//x: [a, b) y: [x, y) について f した結果を返す
	T query(int a, int b, int x, int y) {
		T l = e, r = e;
		for (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1)) {
				l = f(l, seg[a].query(distance(pos[a].begin(), lower_bound(all(pos[a]), x)), distance(pos[a].begin(), lower_bound(all(pos[a]), y))));
				++a;
			}
			if (!(b & 1)) {
				--b;
				r = f(seg[b].query(distance(pos[b].begin(), lower_bound(all(pos[b]), x)), distance(pos[b].begin(), lower_bound(all(pos[b]), y))), r);
			}
		}
		return f(l, r);
	}

};

template<typename T, typename F>
segtree2D<T, F> get_segtree2D(int n, const T& e, const F& f) {
	return { n, e, f };
}

int main() {



	Please AC;
}