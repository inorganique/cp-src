template<typename Str>
vector<int> z_algo(const Str &s) {
    int n = int(size(s));
    vector<int> z(n, n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = i < r ? min(r - i, z[i - l]) : 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (r < i + z[i]) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
