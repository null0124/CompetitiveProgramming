/*
* @title set_enumerate
* @docs kyopro/docs/set_enumerate.md
*/

struct set_enumerate {

	int n;
	vector<int> next;
	unionfind uni;

	set_enumerate(int siz) : n(siz), next(siz), uni(n) {
		next.assign(siz, 0);
		rep(i, siz)next[i] = i;
	}

	int size() {
		return n;
	}

	vector<int> enumerate(const int x) {
		vector<int> ret;
		int cur = x;
		do {
			ret.emplace_back(cur);
			cur = next[cur];
		} while (cur != x);
		return ret;
	}

	vector<vector<int>> get_all() {
		vector<vector<int>> ret;
		vector<bool> visited(n);
		rep(i, n) {
			if (not visited[i]) {
				ret.emplace_back(enumerate(i));
				for (const auto& i : ret.back())visited[i] = true;
			}
		}
		return ret;
	}

	void unite(const int x, const int y) {
		if (not uni.same(x, y)) swap(next[x], next[y]);
		uni.unite(x, y);
	}

	bool same(int a, int b) { return uni.same(a, b); }

	int find(int a) { return uni.find(a); }

	int size(int i) { return uni.size(i); }

};
