struct CartesianTree {
    int rt;
    vector<int> par;
    vector<int> ls;
    vector<int> rs;
};

template<typename T, typename Cmp = less<T>>
CartesianTree build_cartesian_tree(const vector<T> &v, Cmp cmp = {}) {
    int n = int(v.size());
    int rt = -1;
    vector<int> par(n, -1);
    vector<int> ls(n, -1);
    vector<int> rs(n, -1);
    stack<int> stk;
    for (int u = 0; u < n; ++u) {
        int last = -1;
        while (!stk.empty() && !cmp(v[u], v[stk.top()])) {
            last = stk.top();
            stk.pop();
        }
        if (!stk.empty()) {
            par[u] = stk.top();
            rs[stk.top()] = u;
        } else {
            rt = u;
        }
        if (last != -1) {
            par[last] = u;
            ls[u] = last;
        }
        stk.push(u);
    }
    return {rt, par, ls, rs};
}
