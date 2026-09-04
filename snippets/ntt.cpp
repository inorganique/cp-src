constexpr int P = 998244353;

constexpr ll absll(ll x) {
    return x < 0 ? -x : x;
}

constexpr ll bmod(ll x, ll y) {
    ll r = x % y;
    if ((x ^ y) < 0 && r != 0) {
        r += y;
    }
    return r;
}

constexpr int mulm(int x, int y) {
    return (int)bmod(1LL * x * y, P);
}
constexpr int addm(int x, int y) {
    return (int)bmod(0LL + x + y, P);
}

constexpr int powmod(ll x, ll n, int m) {
    if (m == 1) {
        return 0;
    }
    ll r = 1;
    ll y = bmod(x, m);
    while (n) {
        if (n & 1) {
            r = r * y % m;
        }
        y = y * y % m;
        n >>= 1;
    }
    return int(r);
}

constexpr pair<ll, ll> exgcd(ll x, ll y) {
    ll u = 1;
    ll v = 0;
    ll z = y;
    while (z) {
        ll t = x / z;
        x -= t * z;
        u -= t * v;
        swap(x, z);
        swap(u, v);
    }
    if (x < 0) {
        x = -x;
        u = -u;
    }
    if (u < 0) {
        u += absll(y) / x;
    }
    return {u, x};
}

constexpr ll invmod(ll x, ll m) {
    auto [a, g] = exgcd(x, m);
    assert(g == 1);
    return a;
}

constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; 1LL * i * i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (powmod(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return g;
        }
    }
    assert(false);
    return -114514;
}
template<int m>
constexpr int primitive_root = primitive_root_constexpr(m);

template<bool INV>
void ntt(vector<int> &a) {
    static int m = 0;
    static vector<int> rev = {};
    int n = int(a.size());
    assert((n & (n - 1)) == 0);
    constexpr int R = primitive_root<P>;
    constexpr int C = (INV ? invmod(R, P) : R);
    if (m < n) {
        m = n;
        rev.resize(m);
        for (int i = 0; i < m; ++i) {
            rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (m >> 1);
        }
    }
    int shift = 0;
    while ((n << shift) < m) {
        ++shift;
    }
    for (int i = 0; i < n; ++i) {
        if (i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        int wn = powmod(C, (P - 1) >> bit_width(unsigned(k)), P);
        for (int i = 0; i < n; i += k << 1) {
            int w = 1;
            for (int j = i; j < i + k; ++j) {
                int g = a[j];
                int h = mulm(w, a[j + k]);
                a[j] = addm(g, h);
                a[j + k] = addm(g, P - h);
                w = mulm(w, wn);
            }
        }
    }
    if constexpr (INV) {
        int inv_n = (int)invmod(n, P);
        for (int &x : a) {
            x = mulm(x, inv_n);
        }
    }
}

vector<int> convolve(vector<int> a, vector<int> b) {
    assert(!a.empty());
    assert(!b.empty());
    int n = int(a.size() + b.size()) - 1;
    int m = bit_ceil(unsigned(n));
    a.resize(m);
    b.resize(m);
    ntt<false>(a);
    ntt<false>(b);
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        c[i] = mulm(a[i], b[i]);
    }
    ntt<true>(c);
    c.resize(n);
    return c;
}
