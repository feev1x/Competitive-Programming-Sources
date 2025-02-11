/**
 *    author:  feev1x
 *    created: 03.02.2025 11:26:03
**/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr int MOD = 1e9 + 7, MX = 1 << 18;

int dp[MX][18], dpp[MX], fr[MX], pw[18];
bool used[MX][18];

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, p; std::cin >> n >> p;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < 18; ++i) {
        pw[i] = 1 << i;
    }

    auto Calc = [&](auto &&self, int mask, int i) {
        if (i == -1) {
            if (dpp[mask] != 0 || mask == 0) {
                return dpp[mask];
            } else {
                return dpp[mask] = binpow(mask, p);
            }
        }

        if (used[mask][i]) {
            return dp[mask][i];
        }

        used[mask][i] = true;

        add_self(dp[mask][i], self(self, mask, i - 1));
        add_self(dp[mask][i], self(self, mask ^ pw[i], i - 1));

        return dp[mask][i];
    };
  
    for (int mask = 0; mask < MX; ++mask) {
        fr[mask] = 31 - __builtin_clz(mask);
    }

    fr[0] = -1;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int ans = 0, mask = i + 1, j = fr[mask];

        while (j != -1) {
            add_self(ans, Calc(Calc, a[i], j - 1));

            a[i] ^= pw[j];
            mask ^= pw[j];

            j = fr[mask];
        }

        add_self(res, mul(ans, n - i));
    }

    std::cout << res << '\n';
    return 0;
}
