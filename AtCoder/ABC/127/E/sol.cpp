/**
 *    author:  feev1x
 *    created: 16.04.2025 10:19:42
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        n >>= 1;
        a = mul(a, a);
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k; std::cin >> n >> m >> k;

    std::vector<int> fac(n * m + 1);

    fac[0] = 1;
    for (int i = 1; i <= n * m; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    int ml = divide(fac[n * m - 2], mul(fac[k - 2], fac[n * m - k])), sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            add_self(sum, i + j);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            add_self(res, mul(sum, ml));
            
            if (j != m) {
                add_self(sum, mul(j, n));
                add_self(sum, -mul(m - j, n));
            } else {
                add_self(sum, mul(i, m));
                add_self(sum, -mul(n - i, m));
            }
        }

    }


    std::cout << divide(res, 2) << '\n';
    return 0;
}
