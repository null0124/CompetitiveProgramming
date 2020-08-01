/*
* @title template(graph)
* @docs kyopro/docs/graph_template.md
*/

template<typename T = int>
struct graph {

	int n;
	bool directed, weighted;

	struct edge {
		T cost;
		int from, to;

		edge(int from, int to) : from(from), to(to), cost(T(1)) {}
		edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
	};

	vector<vector<edge>> g;

	graph(int n, bool directed, bool weighted) : g(n), n(n), directed(directed), weighted(weighted) {}

	void add_edge(int from, int to, T cost = T(1)) {
		g[from].emplace_back(from, to, cost);
		if (not directed) {
			g[to].emplace_back(to, from, cost);
		}
	}

	void read(int e, bool one_indexed) {
		int a, b, c = 1;
		while (e--) {
			scanf("%d%d", &a, &b);
			if (weighted) {
				scanf("%d", &c);
			}
			if (one_indexed)--a, --b;
			add_edge(a, b, c);
		}
	}

};