/*
* @title combination
* @docs kyopro/docs/comb.md
*/

template<int mod>
modint<mod> nCr(ll a, ll b) {
	modint ans = 1;
	for (ll i = 0; i < b; i++) {
		ans *= a - i;
	}
	for (ll i = 1; i <= b; i++) {
		ans /= i;
	}
	return ans;
}