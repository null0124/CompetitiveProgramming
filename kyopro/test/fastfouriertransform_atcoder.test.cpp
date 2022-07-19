#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/fft_c"

#include "../library/template/template.cpp"

#include "../library/math/fastfouriertransform.cpp"

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> a, b;
    rep(i, n) {
        int p, q;
        scanf("%d%d", &p, &q);
        a.push_back(p);
        b.push_back(q);
    }
    FastFourierTransform fft;
    auto ans = fft.convolve<ll>(a, b);
    puts("0");
    rep(i, n * 2 - 1)printf("%lld\n", (ll)round(ans[i]));

    Please AC;
}