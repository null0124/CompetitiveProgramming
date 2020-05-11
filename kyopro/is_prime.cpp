//‘f””»’è
bool is_prime(ll x) {
	if (x == 1)return false;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}