#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../library/template/template.cpp"

#include "../library/others/cumulative-sum.cpp"

int main() {

    int n, q;
    scanf("%d%d", &n, &q);
    vector<ll> a(n);
    rep(i, n)scanf("%lld", &a[i]);
    cumulativesum<ll> cs(a, 0, plus<ll>(), minus<ll>());
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", cs.query(l, r));
    }

	Please AC;
}