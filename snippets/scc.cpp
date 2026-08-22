struct SCC {
    vector<vector<int>> groups;
    vector<int> ids;
};

struct SCCGraph {
    int n;
    vector<vector<int>> g;
    SCCGraph() : SCCGraph(0) {
    }
    explicit SCCGraph(int n_) : n(n_), g(n) {
    }
    void add_edge(int u, int v) {
        g[u].push_back(v);
    }
    pair<int, vector<int>> scc_ids() const {
        int num = 0;
        vector<int> ids(n);
        int ts = 0;
        stack<int> stk;
        vector<int> dfn(n, -1);
        vector<int> low(n);
        auto dfs = [&](auto &&self, int u) -> void {
            stk.push(u);
            dfn[u] = low[u] = ts++;
            for (int v : g[u]) {
                if (dfn[v] == -1) {
                    self(self, v);
                    low[u] = min(low[u], low[v]);
                } else {
                    low[u] = min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                while (true) {
                    int t = stk.top();
                    stk.pop();
                    dfn[t] = n;
                    ids[t] = num;
                    if (t == u) {
                        break;
                    }
                }
                ++num;
            }
        };
        for (int u = 0; u < n; ++u) {
            if (dfn[u] == -1) {
                dfs(dfs, u);
            }
        }
        for (int &x : ids) {
            x = num - 1 - x;
        }
        return {num, ids};
    }
    SCC scc() const {
        auto [num, ids] = scc_ids();
        vector<int> siz(num);
        for (int u = 0; u < n; ++u) {
            ++siz[ids[u]];
        }
        vector<vector<int>> groups(num);
        for (int i = 0; i < num; ++i) {
            groups[i].reserve(siz[i]);
        }
        for (int u = 0; u < n; ++u) {
            groups[ids[u]].push_back(u);
        }
        return {groups, ids};
    }
};
