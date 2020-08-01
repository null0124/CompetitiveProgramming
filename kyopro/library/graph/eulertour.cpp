/*
* @title euler-tour
* @docs kyopro/docs/eulertour.md
*/

template<typename T = int>
struct eulertour {

	vector<int> depth, child;

private:
	void dfs(graph<T>& g, const int& now, const int& bef, int& cnt) {
		depth[now] = cnt;
		for (const auto& aa : g[now]) {
			if (aa != bef) {
				dfs(g, aa, now, ++cnt);
				child[now] += child[aa] + 1;
				--cnt;
			}
		}
	}

public:
	eulertour(graph<T>& g, const int& n, const int& root) {
		depth.assign(n, 0);
		child.assign(n, 0);
		int cnt = 0;
		dfs(g, root, -1, cnt);
	}

};
