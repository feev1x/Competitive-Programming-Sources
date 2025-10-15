/**
 *    author:  feev1x
 *    created: 19.09.2025 13:14:54
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

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mod(int a) {
    return (a % MOD + MOD) % MOD;
}

inline int binpow(int a, int64_t n) {
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
    
    int n; int64_t D; std::cin >> n >> D;
    
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    if (n == 2)
        std::cout << binpow(4, D) << '\n';
    else {
        std::vector<bool> dp(n + 1);

        {
            auto Dfs = [&](auto &&self, int v, int p) -> void {
                for (auto to: g[v]) {
                    if (to == p)
                        continue;

                    self(self, to, v);
                    if (!dp[to])
                        dp[v] = true;
                }
            };

            Dfs(Dfs, 1, 1);
        }

        int res = 0;
        int cnt2 = 0;
        std::vector<bool> dp2(n + 1);
        std::vector<int> cnt(n + 1), sub(n + 1);
        {
            auto Dfs = [&](auto &&self, int v, int p) -> void {
                if (!dp[v])
                    sub[v]++;

                int cn = 0;
                for (auto to: g[v]) {
                    if (to == p || dp[v] == dp[to])
                        continue;

                    cn++;
                }

                if (!dp[v])
                    cn = 1;

                for (auto to: g[v]) {
                    if (to == p)
                        continue;

                    self(self, to, v);
                    if ((cn == 1) && dp[v] != dp[to])
                        sub[v] += sub[to];
                }
            };

            Dfs(Dfs, 1, 1);
        }

        {
            auto Dfs = [&](auto &&self, int v, int p, bool par, int cp) -> void {
                if (dp[v] || !par)
                    dp2[v] = true, cnt2 += dp[1];
                else
                    cnt2 += !dp[1];

                int cn = 0;
                for (auto to: g[v]) {
                    if (to == p || dp[to])
                        continue;

                    cn++;
                }

                if (dp2[v]) {
                    if (cn + (!par) > 1) {
                        cnt[v] = 0;
                    } else {
                        cnt[v] = sub[v] + cp;
                    }
                } else {
                    cnt[v] = sub[v] + cp;
                }

                if (cn == 1 && par) {
                    int val = -1;

                    for (auto to: g[v]) {
                        if (to == p || dp[to])
                            continue;

                        val = to;
                        self(self, to, v, false, cnt[v] - sub[to]);
                    }

                    for (auto to: g[v]) {
                        if (to == p || !dp[to])
                            continue;

                        self(self, to, v, true, sub[val]);
                    }
                } else if (cn > 1 || !par) {

                    if (cn + (!par) == 2) {
                        for (auto to: g[v]) {
                            if (to == p)
                                continue;

                            self(self, to, v, true, (!dp[to] ? cp + sub[v] - sub[to] : 0));
                        }
                    } else {
                        for (auto to: g[v]) {
                            if (to == p)
                                continue;

                            self(self, to, v, true, 0);
                        }
                    }
                } else {
                    assert(par && cn == 0);

                    for (auto to: g[v]) {
                        if (to == p)
                            continue;

                        self(self, to, v, false, cnt[v] - sub[to]);
                    }
                }
            };

            Dfs(Dfs, 1, 1, true, 0);
        }

        add_self(res, mul(cnt[1], cnt2));
        std::cout << res << '\n';
    }
    return 0;
}
