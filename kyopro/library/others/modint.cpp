/*
* @title modint
* @docs kyopro/docs/modint.md
*/

template<int mod>
struct modint {
	int val, size;

	vector<ll> fac, inv, facinv;

	modint() : val(0), size(0) {};
	modint(ll x) : val(x >= 0 ? x % mod : (mod + x % mod) % mod), size(0) {};

	//siz <= 1e7 くらい
	void cominit(const int siz) {
		size = siz;
		fac.assign(siz + 1, 0);
		inv.assign(siz + 1, 0);
		facinv.assign(siz + 1, 0);
		fac[0] = fac[1] = facinv[0] = facinv[1] = inv[0] = 1;
		for (ll i = 2; i <= siz; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod % i] * (mod / i) % mod;
			facinv[i] = facinv[i - 1] * inv[i] % mod;
		}
	}

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
		if (x.val <= size) {
			ll num = x.val;
			num *= inv[x.val];
			num %= mod;
			val = num;
			return *this;
		}
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

	modint comb(const modint& n, const modint& r) {
		return (n < r or n < 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % mod)) % mod);
	}

	static int getmod() { return mod; };
};