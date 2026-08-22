template<typename Info>
struct Segtree {
    int n;
    int m;
    vector<Info> d;
    Segtree() : Segtree(0) {
    }
    explicit Segtree(int n_) : n(n_), m(bit_ceil(uint(n))), d(2 * m) {
    }
    template<typename T>
    explicit Segtree(const vector<T> &a_)
        : n(int(a_.size())), m(bit_ceil(uint(n))), d(2 * m) {
        for (int i = 0; i < n; ++i) {
            d[m + i] = Info(a_[i]);
        }
        for (int i = m - 1; i > 0; --i) {
            pull(i);
        }
    }
    void set(int p, const Info &s) {
        p += m;
        d[p] = s;
        while (p >>= 1) {
            pull(p);
        }
    }
    Info get(int p) const {
        return d[p + m];
    }
    Info query(int l, int r) const {
        l += m;
        r += m;
        Info sl = {};
        Info sr = {};
        while (l <= r) {
            if (l & 1) {
                sl = sl + d[l++];
            }
            if (~r & 1) {
                sr = d[r--] + sr;
            }
            l >>= 1;
            r >>= 1;
        }
        return sl + sr;
    }
    Info all() const {
        return d[1];
    }
    template<typename Check>
    int min_r(int l, Check g) const {
        if (l == n) {
            return n;
        }
        l += m;
        Info s = {};
        do {
            while (~l & 1) {
                l >>= 1;
            }
            if (g(s + d[l])) {
                while (l < m) {
                    l <<= 1;
                    if (!g(s + d[l])) {
                        s = s + d[l++];
                    }
                }
                return l - m;
            }
            s = s + d[l++];
        } while (l & (l - 1));
        return n;
    }
    template<typename Check>
    int max_l(int r, Check g) const {
        if (r == -1) {
            return -1;
        }
        r += m;
        Info s = {};
        do {
            while ((r & 1) && r > 1) {
                r >>= 1;
            }
            if (g(d[r] + s)) {
                while (r < m) {
                    r = r << 1 | 1;
                    if (!g(d[r] + s)) {
                        s = d[r--] + s;
                    }
                }
                return r - m;
            }
            s = d[r--] + s;
        } while (r & (r + 1));
        return -1;
    }
    void pull(int p) {
        d[p] = d[2 * p] + d[2 * p + 1];
    }
};
