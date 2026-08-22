struct TwoSAT {
    int n;
    SCCGraph g;
    TwoSAT() : TwoSAT(0) {
    }
    explicit TwoSAT(int n_) : n(n_), g(2 * n) {
    }
    void add_clause(int x, bool vx) {
        g.add_edge(2 * x + !vx, 2 * x + vx);
    }
    void add_clause(int x, bool vx, int y, bool vy) {
        g.add_edge(2 * x + !vx, 2 * y + vy);
        g.add_edge(2 * y + !vy, 2 * x + vx);
    }
    optional<vector<bool>> solve() const {
        vector<int> ids = g.scc_ids().second;
        vector<bool> res(n);
        for (int i = 0; i < n; ++i) {
            if (ids[2 * i] == ids[2 * i + 1]) {
                return nullopt;
            }
            res[i] = ids[2 * i] < ids[2 * i + 1];
        }
        return res;
    }
};
