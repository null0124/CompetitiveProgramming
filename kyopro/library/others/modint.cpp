/*
* @title modint
* @docs kyopro/docs/modint.md
*/

template<int mod>
struct modint {
	int val;

	modint() : val(0) {};
	modint(ll x) : val(x >= 0 ? x % mod : (mod + x % mod) % mod) {};

	modint& operator=(const modint& x) {
		val = x.val;
		return *this;
	}

	modint& operator+=(const modint& x) {
		val += x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator-=(const modint& x) {
		val += mod - x.val;
		if (val >= mod)val -= mod;
		return *this;
	}

	modint& operator*=(const modint& x) {
		val = (int)((ll)val * (ll)x.val % mod);
		return *this;
	}

	modint& operator/=(const modint& x) {
		int a = x.val, b = mod, u = 1, v = 0, t;
		while (b > 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		*this *= modint(u);
		return *this;
	}

	modint operator++() {
		val = (val + 1 == mod ? 0 : val + 1);
		return *this;
	}

	modint operator--() {
		val = (val == 0 ? mod - 1 : val - 1);
		return *this;
	}

	modint operator+(const modint& x) const {
		return (modint(*this) += x);
	}

	modint operator-(const modint& x) const {
		return (modint(*this) -= x);
	}

	modint operator*(const modint& x) const {
		return (modint(*this) *= x);
	}

	modint operator/(const modint& x) const {
		return (modint(*this) /= x);
	}

	bool operator==(const modint& x)const {
		return (val == x.val);
	}

	bool operator!=(const modint& x)const {
		return (val != x.val);
	}

	bool operator<(const modint& x)const {
		return (val < x.val);
	}

	bool operator>(const modint& x)const {
		return (val > x.val);
	}

	modint pow(ll n) {
		modint ret(1), a(val);
		while (n > 0) {
			if (n % 2) ret *= a;
			a *= a;
			n /= 2;
		}
		return ret;
	}

	static int getmod() { return mod; };
};

using ModInt = modint<MOD>;
using Modint = modint<mod>;