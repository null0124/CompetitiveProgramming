/*
* @title combination
* @docs kyopro/docs/comb.md
*/

struct comb {
	int siz, M;

	vector<ll> fac, inv, facinv;

	//siz <= 1e7 くらい
	comb(const int& siz, const int& M) : siz(siz), M(M) {
		fac.assign(siz + 1, 0);
		inv.assign(siz + 1, 0);
		facinv.assign(siz + 1, 0);
		fac[0] = fac[1] = 1;
		facinv[0] = facinv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < siz; i++) {
			fac[i] = fac[i - 1] * i % M;
			inv[i] = M - inv[M % i] * (M / i) % M;
			facinv[i] = facinv[i - 1] * inv[i] % M;
		}
	}

	ll query(const int& n, const int& r) {
		return (n < r or n < 0 or r < 0) ? 0 : ((fac[n] * (facinv[r] * facinv[n - r] % M)) % M);
	}
};