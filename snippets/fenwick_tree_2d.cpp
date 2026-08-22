template<typename T>
struct FenwickTree2D {
    int h;
    int w;
    vector<vector<T>> t;
    FenwickTree2D() : FenwickTree2D(0, 0) {
    }
    FenwickTree2D(int h_, int w_) : h(h_), w(w_), t(h, vector<T>(w)) {
    }
    void add(int x, int y, T v) {
        for (int i = x; i < h; i |= i + 1) {
            for (int j = y; j < w; j |= j + 1) {
                t[i][j] = t[i][j] + v;
            }
        }
    }
    T get(int x, int y) const {
        T s = {};
        for (int i = x; i != -1; i = (i & (i + 1)) - 1) {
            for (int j = y; j != -1; j = (j & (j + 1)) - 1) {
                s = s + t[i][j];
            }
        }
        return s;
    }
    T sum(int x1, int y1, int x2, int y2) const {
        --x1, --y1;
        return get(x2, y2) - get(x2, y1) - get(x1, y2) + get(x1, y1);
    }
};
