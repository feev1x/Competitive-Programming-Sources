#include <bits/stdc++.h>

constexpr int MOD = 1e8 + 543;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

using mat = std::vector<std::vector<int>>;

mat pm;

struct Matrix {
    mat a;
    int n, m;
    Matrix(mat a) : a(a), n(a.size()), m(a[0].size()) {}
    Matrix(int n, int m) : n(n), m(m) { a.resize(n, std::vector<int>(m)); }
    inline Matrix operator*(const Matrix &b) const {
        Matrix c(n, b.m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < m; ++k)
                    add_self(c.a[i][j], mul(a[i][k], b.a[k][j]));
        return c;
    }
    inline Matrix operator+(const Matrix &b) const {
        Matrix c = b;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                add_self(c.a[i][j], a[i][j]);
        return c;
    }
    inline void binpow(int x) {
        if (x <= 0) return a = Matrix(n, m).a, void();
        Matrix res = Matrix(a);
        Matrix b = Matrix(a);
        x--;
        while (x) { if (x & 1) res = res * b; b = b * b, x >>= 1; }
        a = res.a;
    }
};

//struct Segtree {
//    std::vector<Matrix> t, psh;
//    int n;
//    Segtree(int n) : n(n) { t.resize(4 * n), psh.resize(4 * n, pm); }
//    inline void push(int v) {
//        if (psh[v] != pm) {
//            t[v << 1] = psh[v] * t[v << 1];
//            t[v << 1 | 1] = psh[v] * t[v << 1 | 1];
//            psh[v << 1] = psh[v] * psh[v << 1];
//            psh[v << 1 | 1] = psh[v] * psh[v << 1 | 1];
//            psh[v] = pm;
//        }
//    }
//    inline void update(int v, int tl, int tr, int l, int r, const Matrix &b) {
//        if (tl > r || l > tr) return;
//        if (l <= tl && tr <= r) {
//            t[v] = b * t[v];
//            psh[v] = b * psh[v];
//            return;
//        }
//        push(v);
//        int tm = tl + tr >> 1;
//        update(v << 1, tl, tm, b);
//        update(v << 1 | 1, tm + 1, tr, b);
//        t[v] = t[v << 1] + t[v << 1 | 1];
//    }
//    inline Matrix get(
//};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    pm.resize(5, std::vector<int>(5));
    for (int i = 0; i < 5; ++i) pm[i][i] = 1;
    return 0;
}
