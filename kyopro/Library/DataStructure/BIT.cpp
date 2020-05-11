
template<typename T>
//0-indexed/“à•”“I‚É 1-indexed
struct BIT {
	vector<T> tree;
	//‰Šú‰»
	BIT(int n) : tree(n) {
		tree.assign(n + 1, 0);
	}

	int LSB(int n) { return (n & (-n)); }

	//[0, n) ‚Ì sum ‚ð•Ô‚·/0-indexed
	T sum(int n) {
		T ret = 0;
		//ŽÀ‚Í 1-indexed ‚¾‚ª”¼ŠJ‹æŠÔ‚È‚Ì‚ÅŒ©‚½–Ú‚ª‚»‚Ì‚Ü‚Ü
		for (; n >= 0; n -= LSB(n)) {
			ret += tree[n];
			if (!n)break;
		}
		return ret;
	}


	//[i, j) ‚Ì sum ‚ð•Ô‚·/0-indexed
	T sum(int i, int j) {;
		return sum(j) - sum(i);
	}

	//n ”Ô–Ú‚É x ‚ð‘«‚·
	void add(int n, T x) {
		int siz = tree.size();
		for (++n; n < siz; n += LSB(n))tree[n] += x;
	}
};