/**
 *    author:  feev1x
 *    created: 16.10.2025 11:52:01
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

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

struct Matrix {
    std::vector<std::vector<int>> a;
    int n, m;

    Matrix() {}
    Matrix(int _n, int _m, int val) : n(_n), m(_m) {
        a.resize(n, std::vector<int>(m));

        if (val)
            for (int i = 0; i < std::min(n, m); ++i)
                a[i][i] = val;
    }

    Matrix(std::vector<std::vector<int>> _a) : a(_a), n(a.size()), m(a[0].size()) {}

    inline Matrix operator*(const Matrix &b) const {
        assert(m == b.n);

        Matrix c(n, b.m, 0);
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < m; ++k)
                for (int j = 0; j < b.m; ++j)
                    add_self(c.a[i][j], mul(a[i][k], b.a[k][j]));

        return c;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, q; std::cin >> n >> m >> q;    

    std::array<Matrix, 30> a;

    a[0] = Matrix(n, n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v; --u, --v;

        a[0].a[v][u]++;
    }

    for (int i = 1; i < 30; ++i)
        a[i] = a[i - 1] * a[i - 1];

    while (q--) {
        int s, t, k; std::cin >> s >> t >> k; s--, t--;

        Matrix b(n, 1, 0);

        b.a[s][0] = 1;
        for (int i = 0; i < 30; ++i, k >>= 1)
            if (k & 1)
                b = a[i] * b;

        std::cout << b.a[t][0] << '\n';
    }

    return 0;
}
