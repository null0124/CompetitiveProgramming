﻿/*
* @title lowest-common-ancestor(weighted)
* @docs kyopro/docs/LCA_weighted.md
*/

//重み付き

template<typename T>
void eulertour(const int& now, const int& bef, int& cnt, graph<T>& graph, const int& d, vector<int>& vs, vector<int>& depth, vector<int>& id) {
	depth.emplace_back(d);
	vs.emplace_back(now);
	id[now] = min(id[now], cnt);
	for (const auto& aa : graph[now]) {
		if (aa.to != bef) {
			++cnt;
			eulertour(aa.to, now, cnt, graph, d + aa.cost, vs, depth, id);
			++cnt;
			depth.emplace_back(d);
			vs.emplace_back(now);
		}
	}
}

template<typename T>
struct LCA {

	vector<int> vs, depth, id, tmp = { 0 };
	graph<T> tree;
	sparsetable<int> table{ tmp, 0 };
	int n, root;

	//木,　大きさ, 根
	LCA(graph<T> tree, int n, int root) : tree(tree), n(n), root(root) {
		id.assign(n, INF);
		int cnt = 0, d = 0;
		eulertour(root, -1, cnt, tree, d, vs, depth, id);
		table.init(depth, depth.size());
		table.build();
	}

	//LCA である頂点を返す
	int query(int l, int r) {
		if (id[l] > id[r])swap(l, r);
		return vs[table.query(id[l], id[r] + 1)];
	}

	int depthq(int n) {
		return depth[id[n]];
	}
};