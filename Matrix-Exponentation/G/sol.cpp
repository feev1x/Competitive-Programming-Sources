/**
 *    author:  feev1x
 *    created: 16.10.2025 08:30:14
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

        for (int i = 0; i < std::min(n, m); ++i)
            a[i][i] = val;
    }

    Matrix(std::vector<std::vector<int>> _a) : a(_a), n(a.size()), m(a[0].size()) {}

    inline Matrix operator*(const Matrix &b) const {
        assert(m == b.n);

        Matrix c(n, b.m, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < m; ++k)
                    add_self(c.a[i][j], mul(a[i][k], b.a[k][j]));

        return c;
    }
};

inline Matrix binpow(Matrix a, int64_t n) {
    assert(a.n == a.m);

    Matrix res(a.n, a.m, 1);
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
    
    int n; int64_t k; std::cin >> n >> k;

    Matrix b(n + 3, 1, 0);
    Matrix a(n + 3, n + 3, 0);
    std::vector<int> A(n), c(n);
    for (int i = 0; i < n; ++i)
        std::cin >> A[i];

    int j = 0;
    for (int i = n - 1; i >= 0; --i, ++j)
        b.a[j][0] = A[i];

    assert(j == n);

    b.a[n][0] = 1;
    b.a[n + 1][0] = n;
    b.a[n + 2][0] = n * n;

    for (int i = 0; i < n; ++i)
        std::cin >> c[i], a.a[0][i] = c[i];

    int p, q, r; std::cin >> p >> q >> r;

    a.a[0][n] = p;
    a.a[0][n + 1] = q;
    a.a[0][n + 2] = r;
    
    for (int i = 1; i < n; ++i)
        a.a[i][i - 1] = 1;

    a.a[n][n] = 1;
    a.a[n + 1][n] = a.a[n + 1][n + 1] = 1;
    a.a[n + 2][n] = a.a[n + 2][n + 2] = 1;
    a.a[n + 2][n + 1] = 2;

    a = binpow(a, k) * b;

    std::cout << a.a[n - 1][0] << '\n';
    return 0;
}
