/**
 *    author:  feev1x
 *    created: 19.10.2025 14:51:42
**/
#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")

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
    
    int n; int64_t k; std::cin >> n >> k;    

    std::vector<int> q(n + 1), fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> q[i], fac[i] = mul(fac[i - 1], i);

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i >= 1; --i)
        inv[i] = mul(inv[i + 1], i + 1);


    auto C = [&](int N, int K) {
        return mul(fac[N], mul(inv[N - K], inv[K]));
    };

    std::vector<bool> used(n + 1);

    std::map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        if (used[i])
            continue;

        int sz = 1;

        int u = q[i];
        
        used[i] = true;
        while (u != i) {
            used[u] = true;
            sz++;

            u = q[u];
        }

        mp[sz]++;
    }

    int res = 1;
    for (auto [sz, cnt]: mp) {
        std::vector<bool> val(cnt + 1);

        std::vector<int> vals;
        for (int64_t c = 1; c <= cnt; ++c) {
            int64_t K = k % (c * sz);

            if (K == 0) {
                if (sz == 1) {
                    val[c] = true;
                    vals.emplace_back(c);
                }
            } else {
                if (std::lcm(K, c * sz) / K == sz) {
                    val[c] = true;
                    vals.emplace_back(c);
                }
            }
        }

        std::vector<int> dp(cnt + 1);

        dp[0] = 1;
        for (auto c: vals) {
            for (int i = cnt; i >= 0; --i) {
                if (!dp[i])
                    continue;

                int ml = inv[c], lm = mul(fac[c - 1], binpow(sz, c - 1)), lmc = lm;

                for (int j = 1; i + j * c <= cnt; ++j) {
//                    if (c == 2 && j == 1 && i == 0)
//                        std::cout << mul(mul(mul(mul(mul(fac[cnt - i], ml), inv[(cnt - i) - j * c]), lmc), 1), 1) << '\n';

                    add_self(dp[i + j * c], mul(mul(mul(mul(mul(fac[cnt - i], ml), inv[(cnt - i) - j * c]), lmc), inv[j]), dp[i]));

                    ml = mul(ml, inv[c]);
                    lmc = mul(lmc, lm);
                }
            }
//            if (c == 2)
//                std::cout << dp[1] << ' ' << dp[2] << ' ' << dp[3] << ' ' << dp[4] << ' ' << dp[5] << '\n';
        }

        res = mul(res, dp[cnt]);
    }

    std::cout << res << '\n';
    return 0;
}
