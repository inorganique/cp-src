template<typename T>
struct FenwickTree {
    int n;
    vector<T> d;
    FenwickTree() : FenwickTree(0) {
    }
    explicit FenwickTree(int n_) : n(n_), d(n) {
    }
    explicit FenwickTree(const vector<T> &v_) : n(int(v_.size())), d(n) {
        d[0] = v_[0];
        for (int i = 1; i < n; ++i) {
            d[i] = d[i - 1] + v_[i];
        }
        for (int i = n - 1; i != -1; --i) {
            if (int j = (i & (i + 1)) - 1; j != -1) {
                d[i] = d[i] - d[j];
            }
        }
    }
    void add(int p, T v) {
        while (p < n) {
            d[p] = d[p] + v;
            p |= p + 1;
        }
    }
    T get(int p) const {
        T s = {};
        while (p != -1) {
            s = d[p] + s;
            p = (p & (p + 1)) - 1;
        }
        return s;
    }
    T sum(int l, int r) const {
        return get(r) - get(l - 1);
    }
    template<typename Check>
    int min_pref(Check f) const {
        int p = 0;
        T s = {};
        for (int i = bit_floor(uint(n)); i != 0; i >>= 1) {
            if (p + i <= n && !f(s + d[p + i - 1])) {
                s = s + d[p + i - 1];
                p += i;
            }
        }
        return p;
    }
};
