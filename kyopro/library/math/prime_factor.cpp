map<ll, int> prime_factor(ll a) {
	map<ll, int> ret;
	for (ll x = 2; x * x <= a; ++x) {
		while (not(a % x))++ret[x], a /= x;
	}
	if (a != 1)++ret[a];
	return ret;
}