/*
* @title kth_permutation
* @docs kyopro/docs/kth_permutation.md
*/

template<typename T = int>
vector<T> kth_permutation(int n, T k) {
	vector<T> a(n), b(n);
	rep(i, n)b[i] = i + 1;
	vector<T> x(n);
	rep(i, n) {
		x[i] = (k % (i + 1));
		k /= (i + 1);
	}
	reverse(all(x));
	rep(i, n) {
		a[i] = b[x[i]];
		b.erase(b.begin() + x[i]);
	}
	return a;
}