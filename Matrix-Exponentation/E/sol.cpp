/**
 *    author:  feev1x
 *    created: 15.10.2025 17:27:14
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

constexpr int64_t MOD = 4294967296;

inline void add_self(int64_t &a, int64_t b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int64_t mul(int64_t a, int64_t b) {
    return (__int128)a * b % MOD;
}

struct Matrix {
    std::vector<std::vector<int64_t>> a;
    int n, m;

    Matrix() {}
    Matrix(int _n, int _m) : n(_n), m(_m) {
        a.resize(n, std::vector<int64_t>(m));
    }

    Matrix(std::vector<std::vector<int64_t>> _a) : a(_a), n(a.size()), m(a[0].size()) {}

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

inline Matrix binpow(Matrix a, int n) {
    assert(a.n == a.m);

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
    
    auto Idx = [](int i, int j) {
        return i * 8 + j;
    };

    int dx[]{2, -2, 2, -2, 1, 1, -1, -1};
    int dy[]{1, 1, -1, -1, 2, -2, 2, -2};

    int n = 8 * 8;

    Matrix a(2 * n, 2 * n), b(2 * n, 1);
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            int from = Idx(i, j);

            b.a[from][0] = 1;
            b.a[from + n][0] = 1;
            a.a[from + n][from + n]++;
            for (int k = 0; k < 8; ++k) {
                int x = dx[k] + i, y = dy[k] + j;

                if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                    int to = Idx(x, y);

                    a.a[from][to]++;
                    a.a[from + n][to]++;
                }
            }
        }

    int k; std::cin >> k;

    a = binpow(a, k);

    a = a * b;

    std::cout << a.a[n][0] << '\n';
    return 0;
}
