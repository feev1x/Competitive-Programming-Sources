/**
 *    author:  feev1x
 *    created: 04.08.2025 17:23:50
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

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

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
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

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n + 1), fac(n + 1, 1), c(n + 1);
        std::vector<std::vector<int>> pos(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], pos[a[i]].emplace_back(i), fac[i] = mul(fac[i - 1], i);

        auto C = [&](int N, int K) {
            return divide(fac[N], mul(fac[K], fac[N - K]));
        };

        for (int i = k - 1; i <= n; ++i)
            c[i] = C(i, k - 1);

        int mx = 0, res = 0;
        std::vector<std::pair<int, int>> dp(n + 2);

        dp[1] = {0, 1};
        for (int i = 1; i <= n + 1; ++i) {
            if (dp[i].first > mx) {
                mx = dp[i].first;
                res = dp[i].second;
            } else if (dp[i].first == mx)
                add_self(res, dp[i].second);

            for (int j = 1; j <= n; ++j) {
                int x = -1;

                for (int ps = 0; ps < pos[j].size(); ++ps)
                    if (pos[j][ps] >= i) {
                        x = ps;
                        break;
                    }

                int y = x + k - 1, cnt = k - 1;
                for (int y = x + k - 1; x != -1 && y < pos[j].size(); ++y, ++cnt) {
                    int ii = pos[j][y] + 1;

                    if (dp[ii].first < dp[i].first + k) {
                        dp[ii] = {dp[i].first + k, mul(c[cnt], dp[i].second)};
                    } else if (dp[ii].first == dp[i].first + k)
                        add_self(dp[ii].second, mul(c[cnt], dp[i].second));
                }
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
