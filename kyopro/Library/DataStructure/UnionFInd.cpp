//0-indexed
struct unionfind {
	vector<ll> par, siz;

	unionfind(ll n) : par(n), siz(n) {
		for (ll i = 0; i < n; ++i) {
			//�S�����ŏ�����
			par[i] = i;
			//�T�C�Y��1
			siz[i] = 1;
		}
	}

	void init(ll n) {
		par.resize(n);
		siz.resize(n);
		for (ll i = 0; i < n; ++i) {
			//�S�����ŏ�����
			par[i] = i;
			//�T�C�Y��1
			siz[i] = 1;
		}
	}

	//����Ԃ�
	ll find(ll a) {
		return par[a] == a ? a : par[a] = find(par[a]);
	}

	//��������B�����瓯����������false��Ԃ�
	bool unite(ll a, ll b) {
		ll x = find(a), y = find(b);
		if (x == y)return false;
		else if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		}
		else if (siz[x] > siz[y]) {
			par[y] = x;
			siz[x] += siz[y];
		}
		else {
			par[x] = y;
			siz[y] += siz[x];
		}
		return true;
	}

	//�����W�������肷��
	bool same(ll a, ll b) {
		return find(a) == find(b);
	}

	//�T�C�Y��Ԃ�
	ll size(ll a) {
		return siz[find(a)];
	}

	//�����W���ɑ����t��Z�߂ĕԂ�
	vector<ll> leaf(ll a) {
		vector<ll> x;
		ll n = par.size();
		for (ll i = 0; i < n; ++i)if (same(a, i))x.pb(i);
		return x;
	}

};