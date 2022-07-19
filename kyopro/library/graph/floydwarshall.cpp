/*
* @title warshallfloyd
* @docs kyopro/docs/warshallfloyd.md
*/

//ワーシャルフロイド
void WarshallFloyd(int n, vector<vector<ll>> & d) {
	rep(i, n) {//経由する頂点
		rep(j, n) {//始点
			rep(k, n) {//終点
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}

