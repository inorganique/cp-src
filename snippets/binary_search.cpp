template<typename Check>
constexpr ll find_first(ll lo, ll hi, Check f) {
    while (lo < hi) {
        ll mid = (lo + hi) >> 1;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

template<typename Check>
constexpr ll find_last(ll lo, ll hi, Check f) {
    while (lo < hi) {
        ll mid = (lo + hi + 1) >> 1;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }
    return hi;
}
