/**
 *    author:  feev1x
 *    created: 19.01.2025 21:24:23
**/
#include <bits/stdc++.h>

constexpr int MOD = 998244353, N = 1e5, FAC = 875880304;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;
    
    if (a >= MOD) {
        a -= MOD;
    }
}


inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

inline int fac(int n) {
    return divide(FAC, divide(FAC, n));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> p(N + 1);
    for (int k = 2; k <= N; ++k) {
        int u = k;

        for (int i = 2; i * i <= u;) {
            if (u % i == 0) {
                p[k].emplace_back(i);
                
                u /= i;
            } else {
                i++;
            }
        }
    }

    int tt; std::cin >> tt;
    while (tt--) {
        int k, n; std::cin >> k >> n;

        for (int i = 1; i <= k; ++i) {
            int res = 0, ans = 1, sz = p[i].size();

            for (int j = 1; j <= std::min(n, sz); ++j) {
                ans = mul(ans, j);

                add_self(ans, mul(fac(j), binpow(j, sz - j)));
                add_self(res, ans);
            }

            if (n > sz) {
                add_self(res, mul(ans, divide(fac(n), fac(sz))));
            }

            std::cout << res << '\n';
        }
    }
    return 0;
}
