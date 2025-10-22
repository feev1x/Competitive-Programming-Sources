/**
 *    author:  feev1x
 *    created: 16.10.2025 17:39:28
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

constexpr int MOD = 998244353;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fac[i] = mul(fac[i - 1], i);

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i > 0; --i)
        inv[i] = mul(inv[i + 1], i + 1);

    auto C = [&](int N, int CK, int Z, int K) {
        return mul(fac[N], mul(mul(CK, Z), inv[K]));
    };

    std::vector<std::map<int, int>> dp(n + 1);

    dp[0][1] = 1;
    for (int j = 1; j <= n; ++j)
        for (int i = n; i >= j; --i) {
            int ck = inv[j], fc = fac[j - 1];

            for (int k = 1; i - j * k >= 0; ++k) {
                for (auto [key, val]: dp[i - j * k])
                    add_self(dp[i][std::lcm(key, j)], mul(mul(val, C(n - i + j * k, ck, inv[n - i], k)), fc));

                ck = mul(ck, inv[j]);
                fc = mul(fc, fac[j - 1]);
            }
        }

    int res = 0;
    for (auto [key, val]: dp[n])
        add_self(res, mul(binpow(key, k), val));

    std::cout << res << '\n';
    return 0;
}
