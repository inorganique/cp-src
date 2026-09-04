constexpr ll absll(ll x) {
    return x < 0 ? -x : x;
}

constexpr ll floor(ll x, ll y) {
    ll q = x / y;
    return q - ((x ^ y) < 0 && x != q * y);
}
constexpr ll ceil(ll x, ll y) {
    ll q = x / y;
    return q + ((x ^ y) > 0 && x != q * y);
}
constexpr ll bmod(ll x, ll y) {
    ll r = x % y;
    if ((x ^ y) < 0 && r != 0) {
        r += y;
    }
    return r;
}
constexpr pair<ll, ll> divmod(ll x, ll y) {
    ll q = x / y;
    ll r = x - q * y;
    if ((x ^ y) < 0 && r != 0) {
        --q;
        r += y;
    }
    return {q, r};
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

constexpr ll powmodll(ll x, ll n, ll m) {
    if (m == 1) {
        return 0;
    }
    i128 r = 1;
    i128 y = bmod(x, m);
    while (n) {
        if (n & 1) {
            r = r * y % m;
        }
        y = y * y % m;
        n >>= 1;
    }
    return ll(r);
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

pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    ll r0 = 0;
    ll m0 = 1;
    for (int i = 0; i < n; ++i) {
        assert(m[i] >= 1);
        ll r1 = bmod(r[i], m[i]);
        ll m1 = m[i];
        if (m0 < m1) {
            swap(m0, m1);
            swap(r0, r1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) {
                return {0LL, 0LL};
            }
            continue;
        }
        auto [im, g] = exgcd(m0, m1);
        if ((r1 - r0) % g != 0) {
            return {0LL, 0LL};
        }
        ll u1 = m1 / g;
        r0 += (r1 - r0) / g % u1 * im % u1 * m0;
        m0 *= u1;
        if (r0 < 0) {
            r0 += m0;
        }
    }
    return {r0, m0};
}
