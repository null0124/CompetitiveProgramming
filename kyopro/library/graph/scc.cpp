/*
* @title strongly connected components(強連結成分分解)
* @docs kyopro/docs/scc.md
*/

template<typename T = int>
struct stronglyconnectedcomponents {

	int n, cur = 0;
	//g: 元のグラフ, gg: 逆張りグラフ, cg: 強連結成分で圧縮したグラフ, sg: 強連結成分だけのグラフ
	graph<T> g, cg, sg, gg;
	vector<int> num, siz;
	vector<vector<int>> vert;

	stronglyconnectedcomponents(const int& n, graph<T>& g) : n(n), g(g), cg(n, g.directed, g.weighted), sg(n, g.directed, g.weighted), gg(n, g.directed, g.weighted), num(n) {
		rep(i, n) for (const auto& aa : g[i])gg.add_edge(aa.to, aa.from, aa.cost);
	}

	void dfs(const int& now, stack<int>& st, vector<bool>& visited) {
		visited[now] = true;
		for (const auto& aa : g[now])if (not visited[aa.to])dfs(aa.to, st, visited);
		st.push(now);
	}

	void build() {
		stack<int> s, st;
		vector<bool> visited(n);
		rep(i, n) {
			if (not visited[i]) dfs(i, st, visited);
		}
		fill(all(visited), false);
		while (not st.empty()) {
			int v = st.top();
			st.pop();
			if (not visited[v]) {
				s.push(v);
				while (not s.empty()) {
					int ver = s.top();
					s.pop();
					num[ver] = cur;
					for (const auto& aa : gg[ver]) if (not visited[aa.to])s.push(aa.to);
					visited[ver] = true;
				}
				++cur;
			}
		}
		siz.assign(cur, 1);
		vert.assign(cur, {});
		fill(all(visited), false);
		rep(i, n) {
			if (not visited[i])vert[num[i]].push_back(i);
			visited[i] = true;
			for (const auto& aa : g[i]) {
				if (num[aa.to] == num[i]) {
					sg.add_edge(aa.from, aa.to, aa.cost);
					if (not visited[aa.to]) {
						++siz[num[aa.to]];
						visited[aa.to] = true;
						vert[num[i]].push_back(aa.to);
					}
				}
				else {
					cg.add_edge(num[aa.from], num[aa.to], aa.cost);
				}
			}
		}
	}

	int operator[](const int& i) { return num[i]; }

	int size() { return cur; }
	int size(const int& i) { return siz[i]; }

};
