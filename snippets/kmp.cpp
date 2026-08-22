template<typename Str>
vector<int> kmp(const Str &s) {
    int n = int(size(s));
    vector<int> pi(n + 1);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j != 0 && s[i] != s[j]) {
            j = pi[j];
        }
        j += (s[i] == s[j]);
        pi[i + 1] = j;
    }
    return pi;
}
