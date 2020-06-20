template<typename T>
struct SWAG {

	const int n;
	const T e;
	const vector<T> a;
	const function<T(T, T)> f;

	SWAG(int n, vector<T> a, T e, function<T(T, T)> f) : n(n), a(a), e(e), f(f) {

	}

	//クエリは半開区間で、ソートされているとする。
	vector<T> query(const vector<pair<int, int>>& q) {
		vector<T> res;
		int l = 0, r = 0;
		T front = e, back = a[0];

		return res;
	}

};
