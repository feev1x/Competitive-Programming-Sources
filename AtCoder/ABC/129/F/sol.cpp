/**
 *    author:  feev1x
 *    created: 15.10.2025 22:04:49
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

int MOD;

inline void add_self(__int128 &a, __int128 b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int64_t mul(int64_t a, int64_t b) {
    return a * b % MOD;
}

inline int64_t mul(__int128 a, __int128 b) {
    return b * a % MOD;
}

struct Matrix {
    std::vector<std::vector<__int128>> a;
    int n, m;

    Matrix() {}
    Matrix(int _n, int _m, int val) : n(_n), m(_m) {
        a.resize(n, std::vector<__int128>(m));

        for (int i = 0; i < std::min(n, m); ++i)
            a[i][i] = val;
    }

    Matrix(std::vector<std::vector<__int128>> _a) : a(_a), n(a.size()), m(a[0].size()) {}

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

    Matrix res(a.n, a.n, 1);
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

    auto Size = [](__int128 x) {
        int64_t res = 0;

        while (x)
            res++, x /= 10;

        return res;
    };
    
    int64_t n, A, B; std::cin >> n >> A >> B >> MOD;

    int64_t l = 0, r = -1;

    __int128 pw = 10;

    Matrix b(3, 1, 1);
    for (int sz = 1; sz <= 38; ++sz) {
        l = r + 1;

        if (l > n - 1)
            break;

        {
            int64_t bl = l, br = n - 1, ans = -1;
            while (bl <= br) {
                int64_t m = bl + br >> 1;

                int bsz = Size(A + (__int128)B * m);
                assert(bsz >= sz);

                if (bsz == sz)
                    bl = m + 1, ans = m;
                else
                    br = m - 1;
            }

            if (ans == -1) {
                pw *= 10;
                continue;
            }

            r = ans;
        }

        Matrix a({{1, 0, 0},
                  {1, 1, 0},
                  {A, B, pw}});

        a = binpow(a, r - l + 1);

        pw *= 10;
        b = a * b;
    }

    std::cout << (int64_t)b.a[2][0] << '\n';
    return 0;
}
