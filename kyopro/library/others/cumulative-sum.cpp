template<typename T>
struct cumulativesum {
    vector<T> cs;
    const function<T(T, T)> rev;
    cumulativesum(const vector<T> a, const T e, const function<T(T, T)> f, const function<T(T, T)> rev) : rev(rev) {
        int siz = a.size() + 1;
        cs.assign(siz, e);
        rep(i, siz - 1)cs[i + 1] = f(cs[i], a[i]);
    }

    //0-indexed で [l, r) の和
    T query(int l, int r) {
        return rev(cs[r], cs[l]);
    }
};