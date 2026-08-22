struct HLDTree {
    int n;
    vector<vector<int>> g;
    vector<int> par;
    vector<int> dep;
    vector<int> siz;
    vector<int> lnk;
    vector<int> dfn;
    vector<int> ord;
    vector<int> top;

    HLDTree() : n(0) {
    }
    HLDTree(int n_) : n(n_), g(n) {
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void hld(int rt) {
        par.resize(n, -1);
        dep.resize(n);
        siz.resize(n, 1);
        lnk.resize(n, -1);
        dfn.resize(n);
        ord.clear();
        ord.reserve(n);
        top.resize(n);
        auto dfs1 = [&](auto &&self, int u) -> void {
            for (int v : g[u]) {
                if (v == par[u]) {
                    continue;
                }
                par[v] = u;
                dep[v] = dep[u] + 1;
                self(self, v);
                siz[u] += siz[v];
                if (lnk[u] == -1 || siz[lnk[u]] < siz[v]) {
                    lnk[u] = v;
                }
            }
        };
        auto dfs2 = [&](auto &&self, int u, int t) -> void {
            dfn[u] = int(ord.size());
            ord.push_back(u);
            top[u] = t;
            if (lnk[u] != -1) {
                self(self, lnk[u], t);
            }
            for (int v : g[u]) {
                if (v != par[u] && v != lnk[u]) {
                    self(self, v, v);
                }
            }
        };
        dfs1(dfs1, rt);
        dfs2(dfs2, rt, rt);
    }

    template<typename T>
    void dfn_sort(vector<T> &v) const {
        vector<T> t(n);
        for (int i = 0; i < n; ++i) {
            t[dfn[i]] = v[i];
        }
        v.swap(t);
    }

    int lca(int u, int v) const {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                swap(u, v);
            }
            u = par[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    template<typename F>
    int apply(int u, int v, const F &f, bool includes_lca = true) const {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                swap(u, v);
            }
            f(dfn[top[u]], dfn[u]);
            u = par[top[u]];
        }
        if (dep[u] > dep[v]) {
            swap(u, v);
        }
        if (includes_lca) {
            f(dfn[u], dfn[v]);
        } else if (u != v) {
            f(dfn[u] + 1, dfn[v]);
        }
        return u;
    }
};
