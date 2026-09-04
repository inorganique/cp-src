struct EDCC {
    vector<vector<int>> groups;
    vector<int> ids;
    vector<bool> bridge;
};

struct EDCCGraph {
    int n;
    int m;
    vector<pair<int, int>> e;
    vector<vector<int>> g;

    EDCCGraph() : EDCCGraph(0) {
    }
    explicit EDCCGraph(int n_) : n(n_), m(0), e{}, g(n) {
    }

    void add(int u, int v) {
        g[u].push_back(m);
        g[v].push_back(m);
        e.emplace_back(u, v);
        ++m;
    }

    EDCC edcc() const {
        vector<vector<int>> groups;
        vector<int> ids(n, -1);
        vector<bool> bridge(m, false);
        vector<int> dep(n, -1);
        vector<int> low(n, -1);
        stack<int> stk;
        auto dfs = [&](auto &&self, int u, int pe) -> void {
            low[u] = dep[u];
            stk.push(u);
            for (int i : g[u]) {
                if (i == pe) {
                    continue;
                }
                int v = e[i].first ^ e[i].second ^ u;
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    self(self, v, i);
                    low[u] = min(low[u], low[v]);
                } else {
                    low[u] = min(low[u], dep[v]);
                }
            }
            if (dep[u] == low[u]) {
                groups.emplace_back();
                while (ids[u] == -1) {
                    int t = stk.top();
                    stk.pop();
                    groups.back().push_back(t);
                    ids[t] = int(groups.size()) - 1;
                }
                if (pe != -1) {
                    bridge[pe] = true;
                }
            }
        };
        for (int u = 0; u < n; ++u) {
            if (dep[u] == -1) {
                dep[u] = 0;
                dfs(dfs, u, -1);
            }
        }
        return {groups, ids, bridge};
    }
};
