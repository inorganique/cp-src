template<typename Cap>
struct FlowGraph {
    struct sedge {
        int to;
        Cap cap;
        sedge() : sedge(-1, 0) {}
        sedge(int v, Cap c) : to(v), cap(c) {}
    };
    struct edge {
        int from;
        int to;
        Cap cap;
        Cap flow;
        edge() : edge(-1, -1, 0, 0) {}
        edge(int u, int v, Cap c, Cap f) : from(u), to(v), cap(c), flow(f) {}
    };

    int n;
    int m;
    vector<sedge> e;
    vector<vector<int>> g;

    FlowGraph() : FlowGraph(0) {}
    explicit FlowGraph(int n) : n(n), m(0), e{}, g(n) {}

    void add_edge(int u, int v, Cap c) {
        e.emplace_back(v, c);
        e.emplace_back(u, 0);
        g[u].push_back(2 * m);
        g[v].push_back(2 * m + 1);
        ++m;
    }

    void set_edge(int i, Cap c, Cap f) {
        e[2 * i].cap = c - f;
        e[2 * i + 1].cap = f;
    }

    edge get_edge(int i) const {
        return edge(e[2 * i + 1].to, e[2 * i].to,
                    e[2 * i].cap + e[2 * i + 1].cap, e[2 * i + 1].cap);
    }

    vector<edge> edges() const {
        vector<edge> t;
        t.reserve(m);
        for (int i = 0; i < m; ++i) {
            t.push_back(get_edge(i));
        }
        return t;
    }

    Cap flow(int s, int t, Cap lim = numeric_limits<Cap>::max()) {
        vector<int> dep(n, -1);
        auto bfs = [&]() -> bool {
            fill(dep.begin(), dep.end(), -1);
            dep[s] = 0;
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int i : g[u]) {
                    int v = e[i].to;
                    if (dep[v] == -1 && e[i].cap > 0) {
                        dep[v] = dep[u] + 1;
                        q.push(v);
                    }
                }
            }
            return dep[t] != -1;
        };
        vector<int> p(n);
        auto dfs = [&](auto &&self, int u, Cap up) -> Cap {
            if (u == t) {
                return up;
            }
            Cap r = up;
            for (int &j = p[u]; j < ssize(g[u]); ++j) {
                int i = g[u][j];
                int v = e[i].to;
                if (dep[v] == dep[u] + 1 && e[i].cap > 0) {
                    Cap d = self(self, v, min(e[i].cap, r));
                    e[i].cap -= d;
                    e[i ^ 1].cap += d;
                    r -= d;
                    if (r == 0) {
                        break;
                    }
                }
            }
            return up - r;
        };
        Cap flow = 0;
        while (flow < lim && bfs()) {
            fill(p.begin(), p.end(), 0);
            flow += dfs(dfs, s, lim - flow);
        }
        return flow;
    }

    vector<bool> min_cut(int s) const {
        vector<bool> vis(n);
        queue<int> q;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : g[u]) {
                int v = e[i].to;
                if (!vis[v] && e[i].cap > 0) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return vis;
    }
};
