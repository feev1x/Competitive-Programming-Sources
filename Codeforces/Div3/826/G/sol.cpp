/**
 *    author:  feev1x
 *    created: 10.08.2025 14:49:20
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        int f; std::cin >> f;

        std::vector<int> h(f + 1), sm(n + 1);
        for (int i = 1; i <= f; ++i)
            std::cin >> h[i], sm[h[i]]++;

        int k; std::cin >> k;

        std::vector<int> p(k + 1);
        for (int i = 1; i <= k; ++i)
            std::cin >> p[i], sm[h[p[i]]]--;

        auto Bfs = [&](int v) {
            std::queue<int> q;

            std::vector<bool> used(n + 1);
            std::vector<int> d(n + 1);
            used[v] = true;

            q.emplace(v);
            while (q.size()) {
                int v = q.front();

                q.pop();
                for (auto to: g[v]) {
                    if (!used[to]) {
                        d[to] = d[v] + 1;
                        used[to] = true;

                        q.emplace(to);
                    }
                }
            }

            return d;
        };

        auto d = Bfs(1);

        int res = k;

        for (int mask = 0; mask < 1 << k; ++mask) {
            auto sum = sm;

            bool flag = true;

            int sz = __builtin_popcount(mask), nw = 0;
            std::vector<std::vector<bool>> can(sz, std::vector<bool>(n + 1));

            std::vector<int> imask;
            for (int i = 0; i < k; ++i)
                if (mask >> i & 1) {
                    imask.emplace_back(nw);
                    auto dis = Bfs(h[p[i + 1]]);

                    for (int j = 1; j <= n; ++j)
                        if (d[j] == d[h[p[i + 1]]] + dis[j]) {
                            can[nw][j] = true;
                        }

                    nw++;
                }

            std::vector<bool> dp(1 << sz);

            dp[0] = true;
            for (int i = 1; i <= n; ++i) {
                auto new_dp = dp;

                for (int msk = 0; msk < 1 << sz; ++msk) {
                    if (dp[msk])
                        continue;

                    std::vector<int> imsk;
                    for (int j = 0; j < sz; ++j)
                        if (msk >> j & 1)
                            imsk.emplace_back(j);

                    int zz = __builtin_popcount(msk);
                    for (int ms = 0; ms < 1 << zz; ++ms) {
                        bool flag = true;

                        int mm = 0, szz = __builtin_popcount(ms);
                        for (int j = 0; j < zz; ++j) {
                            if (ms >> j & 1) {
                                int idx = imask[imsk[j]];

                                if (!can[idx][i]) {
                                    flag = false;
                                    break;
                                }
                            } else
                                mm |= 1 << imsk[j];
                        }

                        if (flag && dp[mm] && sum[i] >= szz) {
                            new_dp[msk] = true;
                            break;
                        }
                    }
                }

                dp = new_dp;
            }

            if (dp[(1 << sz) - 1])
                res = std::min(res, k - sz);
        }

        std::cout << res << '\n';
    }

    return 0;
}
