/*
* @title Fast Fourier Transform
* @docs kyopro/docs/fastfouriertransform.md
*/

template<typename T = double>
struct FastFourierTransform {

    void dft(vector<complex<T>>& a, T inv = 1) {
        int n = a.size();
        if (n == 1)return;
        vector<complex<T>> b, c;
        rep(i, n / 2) {
            b.push_back(a[i * 2]);
            c.push_back(a[i * 2 + 1]);
        }
        dft(b, inv);
        dft(c, inv);
        complex<T> zeta(cos((T)2.0 * PI * inv / n), sin((T)2.0 * PI * inv / n)), cur = 1;
        rep(i, n) {
            a[i] = b[i % (n / 2)] + cur * c[i % (n / 2)];
            cur *= zeta;
        }
    }

    template<typename U>
    vector<T> convolve(const vector<U>& a, const vector<U>& b) {
        int n = 1;
        while (n < a.size() + b.size()) n <<= 1;
        vector<complex<T>> c(n), d(n);
        vector<T> e(n);
        rep(i, a.size())c[i] = a[i];
        rep(i, b.size())d[i] = b[i];
        dft(c);
        dft(d);
        rep(i, n)c[i] *= d[i];
        dft(c, -1);
        rep(i, n)e[i] = c[i].real() / n;
        return e;
    }

    template<typename U>
    vector<ll> convolve2(const vector<U>& a, const vector<U>& b, const ll& p) {
        int n = 1;
        while (n < a.size() + b.size()) n <<= 1;
        vector<ll> a1(n), a2(n), b1(n), b2(n);
        rep(i, n) {
            if (i < a.size()) a1[i] = (a[i] >> 15), a2[i] = a[i] % (1 << 15);
            if (i < b.size()) b1[i] = (b[i] >> 15), b2[i] = b[i] % (1 << 15);
        }
        auto f = convolve(a1, b1), g = convolve(a2, b2);
        rep(i, n)a1[i] += a2[i], b1[i] += b2[i];
        auto h = convolve(a1, b1);
        vector<ll> ff(n), gg(n), hh(n), ret(n);
        rep(i, n) {
            ff[i] = round(f[i]);
            ff[i] %= p;
            gg[i] = round(g[i]);
            gg[i] %= p;
            hh[i] = round(h[i]);
            hh[i] -= ff[i] + gg[i];
            hh[i] += p;
            hh[i] %= p;
        }
        rep(i, n)ret[i] = ((ff[i] << 30) + (hh[i] << 15) + gg[i]) % p;
        return ret;
    }

};