template<typename T, typename Op>
struct SparseTable {
    int n;
    vector<int> lg;
    vector<vector<T>> d;
    Op op;
    SparseTable() : n(0), lg{}, d{}, op{} {
    }
    explicit SparseTable(const vector<T> &v_, Op op_)
        : n(int(v_.size())), lg(n), d{}, op(op_) {
        if (n == 0) {
            return;
        }
        for (int i = 1; i < n; ++i) {
            lg[i] = lg[(i - 1) >> 1] + 1;
        }
        d.resize(lg[n - 1] + 1);
        d[0] = v_;
        for (int k = 1; k <= lg[n - 1]; ++k) {
            d[k].resize(n - (1 << k) + 1);
            for (int i = 0; i <= n - (1 << k); ++i) {
                d[k][i] = op(d[k - 1][i], d[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    T query(int l, int r) const {
        int k = lg[r - l];
        return op(d[k][l], d[k][r - (1 << k) + 1]);
    }
};
