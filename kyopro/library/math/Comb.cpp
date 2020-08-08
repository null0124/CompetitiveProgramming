/*
* @title combination
* @docs kyopro/docs/comb.md
*/

template<typename T>
struct comb{
	int size;

	vector<T> fac, inv, facinv;

	//siz <= 1e7 くらい
	void cominit(const int siz) {
		size = siz;
		fac.assign(siz + 1, 0);
		inv.assign(siz + 1, 0);
		facinv.assign(siz + 1, 0);
		fac[0] = fac[1] = facinv[0] = facinv[1] = inv[0] = 1;
		for (int i = 2; i <= siz; ++i) {
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod % i] * (mod / i) % mod;
			facinv[i] = facinv[i - 1] * inv[i] % mod;
		}
	}

	T comb(const T& n, const T& r) {
		return (n < r or n < 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % mod)) % mod);
	}
};
