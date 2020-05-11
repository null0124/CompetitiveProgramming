

//st ‚ª true ‚ÌA‹·‹`’P’²‘‰Á
int lis(const int& n, const vector<int>& a, const bool& st) {
	vector<int> dp(n);
	fill(all(dp), INF);
	vector<int>::iterator ite;
	rep(i, n) {
		if (st)ite = lower_bound(all(dp), a[i]);
		else ite = upper_bound(all(dp), a[i]);
		if (ite != dp.end())*ite = a[i];
	}
	return distance(dp.begin(), lower_bound(all(dp), INF));
}