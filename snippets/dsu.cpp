struct DSU {
    int n;
    vector<int> f;
    DSU() : DSU(0) {
    }
    explicit DSU(int n_) : n(n_), f(n, -1) {
    }
    int leader(int x) {
        return f[x] < 0 ? x : (f[x] = leader(f[x]));
    }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        if (-f[x] < -f[y]) {
            swap(x, y);
        }
        f[x] += f[y];
        f[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    int size(int x) {
        return -f[leader(x)];
    }
    vector<vector<int>> groups() {
        vector<int> buf(n);
        vector<int> siz(n);
        for (int i = 0; i < n; ++i) {
            buf[i] = leader(i);
            ++siz[buf[i]];
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            res[i].reserve(siz[i]);
        }
        for (int i = 0; i < n; ++i) {
            res[buf[i]].push_back(i);
        }
        erase_if(res, [](const vector<int> &v) {
            return v.empty();
        });
        return res;
    }
};
