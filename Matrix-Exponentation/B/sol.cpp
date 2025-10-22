/**
 *    author:  feev1x
 *    created: 15.10.2025 16:04:35
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
        int h = b.a.size(), w = b.a[0].size();

        assert(m == h);
        Matrix c(n, w);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < w; ++j)
                for (int k = 0; k < m; ++k)
                    add_self(c.a[i][j], mul(a[i][k], b.a[k][j]));

        return c;
    }
};

inline Matrix binpow(Matrix a, int64_t n) {
    Matrix res(a.a.size(), a.a.size());

    for (int i = 0; i < a.a.size(); ++i)
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

//    std::vector<std::pair<int, int>> dp(n + 1);
//
//    dp[0].first = 1;
//    for (int i = 1; i <= n; ++i) {
//        dp[i].first = dp[i - 1].first * 19 + dp[i - 1].second * 6;
//        dp[i].second = dp[i - 1].first * 7 + dp[i - 1].second * 20;
//    }


    Matrix a({{19, 0, 6, 0},
              {1, 0, 0, 0},
              {7, 0, 20, 0},
              {0, 0, 1, 0}});

    Matrix b({{19},
              {1},
              {7},
              {0}});

    a = binpow(a, n);

    std::cout << (a * b).a[1][0] << '\n';
    return 0;
}
