template<typename Str>
vector<int> manacher(const Str &s) {
    int n = int(size(s));
    if (n == 0) {
        return {};
    }
    vector<int> pal(2 * n - 1);
    int l = -1;
    int r = -1;
    for (int c = 0; c < 2 * n - 1; ++c) {
        int i = (c + 1) >> 1;
        int j = c >> 1;
        int k = r < i ? 0 : min(r - j, pal[2 * (l + r) - c] >> 1);
        while (0 <= i - k - 1 && j + k + 1 < n &&
               s[i - k - 1] == s[j + k + 1]) {
            ++k;
        }
        pal[c] = 2 * k + 1 - (c & 1);
        if (r < j + k) {
            l = i - k;
            r = j + k;
        }
    }
    return pal;
}
