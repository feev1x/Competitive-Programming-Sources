/**
 *    author:  feev1x
 *    created: 15.10.2025 16:49:11
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
    Matrix(int _n, int _m) : n(_n), m(_m) {
        a.resize(n, std::vector<int>(m));
    }

    Matrix(std::vector<std::vector<int>> _a) : a(_a), n(a.size()), m(a[0].size()) {}

    inline Matrix operator*(const Matrix &b) const {
        assert(m == b.n);
        Matrix c(n, b.m);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < m; ++k)
                    add_self(c.a[i][j], mul(a[i][k], b.a[k][j]));

        return c;
    }
};

inline Matrix binpow(Matrix a, int64_t n) {
    Matrix res(a.n, a.n);

    for (int i = 0; i < a.n; ++i)
        res.a[i][i] = 1;

    while (n) {
        if (n & 1)
            res = res * a;

        a = a * a;
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; std::cin >> n;

    Matrix a({{1, 1},
              {1, 0}});

    Matrix b(2, 1);

    b.a[0][0] = 1;

    a = binpow(a, n);

    std::cout << (a * b).a[1][0] << '\n';
    return 0;
}
