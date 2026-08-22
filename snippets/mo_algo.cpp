vector<int> mo_algo(int n, const vector<int> &lp, const vector<int> &rp) {
    assert(lp.size() == rp.size());
    int q = int(lp.size());
    if (q == 0) {
        return {};
    }
    const int B = max(1, int(n / sqrt(q)));
    vector<int> ids(q);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) -> bool {
        const int b1 = lp[i] / B;
        const int b2 = lp[j] / B;
        if (b1 != b2) {
            return lp[i] < lp[j];
        }
        return ((b1 & 1) ? rp[i] > rp[j] : rp[i] < rp[j]);
    });
    return ids;
}

vector<int> mo_algo(int n, const vector<pair<int, int>> &qs) {
    int q = int(qs.size());
    vector<int> lp(q);
    vector<int> rp(q);
    for (int i = 0; i < q; ++i) {
        tie(lp[i], rp[i]) = qs[i];
    }
    return mo_algo(n, lp, rp);
}
