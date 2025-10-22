/**
 *    author:  feev1x
 *    created: 15.10.2025 20:48:16
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

constexpr int64_t INF = 3e18;

inline void chmin(int64_t &a, int64_t b) {
    if (a > b)
        a = b;
}

struct Matrix {
    std::vector<std::vector<int64_t>> a;
    int n, m;

    Matrix() {}
    Matrix(int _n, int _m) : n(_n), m(_m) {
        a.assign(n, std::vector<int64_t>(m, INF));
    }

    Matrix(std::vector<std::vector<int64_t>> _a) : a(_a), n(a.size()), m(a[0].size()) {}

    inline Matrix operator*(const Matrix &b) const {
        assert(m == b.n);

        Matrix c(n, b.m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < m; ++k)
                    chmin(c.a[i][j], a[i][k] + b.a[k][j]);

        return c;
    }
};

inline Matrix binpow(Matrix a, int n) {
    assert(a.n == a.m);

    Matrix res(a.n, a.n);

    bool flag = false;
    while (n) {
        if (n & 1)
            res = (flag ? res * a : a), flag = true;

        a = a * a;
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k; std::cin >> n >> m >> k;    

    Matrix a(n, n), b(n, 1);
    for (int i = 0; i < m; ++i) {
        int u, v; int64_t w; std::cin >> u >> v >> w; u--, v--;

        chmin(a.a[u][v], w);
    }

    for (int i = 0; i < n; ++i)
        b.a[i][0] = 0;

    a = binpow(a, k) * b;

    int64_t res = INF;
    for (int i = 0; i < n; ++i)
        chmin(res, a.a[i][0]);

    if (res > 1e18)
        std::cout << "IMPOSSIBLE\n";
    else
        std::cout << res << '\n';
    return 0;
}
