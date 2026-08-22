mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

struct RollingHash {
    static constexpr ull M = (1ULL << 61) - 1;
    static const ull B;

    ull base;
    vector<ull> pf;
    vector<ull> pw;

    static ull add_mod(ull a, ull b) {
        a += b;
        if (a >= M) a -= M;
        return a;
    }
    static ull sub_mod(ull a, ull b) {
        a += M - b;
        if (a >= M) a -= M;
        return a;
    }
    static ull mul_mod(ull a, ull b) {
        u128 c = u128(a) * u128(b);
        c = (c & M) + (c >> 61);
        if (c >= M) c -= M;
        return ull(c);
    }

    RollingHash() : base(B), pf{0}, pw{1} {
    }
    void extend(ull x) {
        assert(x != M - 1);
        x = (x & M) + (x >> 61);
        if (x >= M) x -= M;
        pf.push_back(add_mod(mul_mod(pf.back(), base), x + 1));
        pw.push_back(mul_mod(pw.back(), base));
    }
    ull query(int l, int r) const {
        return sub_mod(pf[r + 1], mul_mod(pf[l], pw[r - l + 1]));
    }
};
const ull RollingHash::B = rng64() % M;
