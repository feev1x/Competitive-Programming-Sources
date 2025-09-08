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

        std::vector<std::vector<int>> g(n + 1), idx(n + 1);
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

        std::vector<int> p(k);
        for (int i = 0; i < k; ++i)
            std::cin >> p[i], sm[h[p[i]]]--, idx[h[p[i]]].emplace_back(i);

        std::queue<std::pair<int, int>> q;

        std::vector dp(n + 1, std::vector<int>(1 << k));
        std::vector<int> d(n + 1);

        q.emplace(1, 0);
        while (q.size()) {
            auto [v, mask] = q.front();

            q.pop();
            for (auto to: g[v]) {
                if (d[to] > d[v] + 1) {
                    d[to] = d[v] + 1;

                    q.emplace(to, mask);
                }
            }
        }

        dp[1][0] = true;

        q.emplace(1, 0);
        while (q.size()) {
            auto [v, mask] = q.front();

            q.pop();
            for (auto to: g[v]) {
                int nx = mask;

                for (auto u: idx[to])
                    nx |= 1 << u;

                if (d[to] == d[v] + 1 && !dp[to][nx]) {
                    dp[to][nx] = true;

                    q.emplace(to, nx);
                }
            }
        }


        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < 1 << k; ++j) {
                if (!dp[i][j])
                    continue;

                for (int l = 1; l < 1 << k; ++l) {
                    if (!dp[i][l])
                        continue;

                    int nw = j | l;
                    if (dp[i][nw] > dp[i][j] + dp[i][l] || !dp[i][nw])
                        dp[i][nw] = dp[i][j] + dp[i][l];
                }
            }
        }

        std::vector<bool> ans(1 << k);

        ans[0] = true;
        for (int i = 1; i <= n; ++i) {
            auto new_ans = ans;

            for (int j = 1; j < 1 << k; ++j) {
                if (!dp[i][j] || dp[i][j] > sm[i])
                    continue;

                for (int m = 0; m < 1 << k; ++m) {
                    if (!ans[m])
                        continue;

                    new_ans[m | j] = true;
                }
            }

            ans = new_ans;
        }

        int res = 0;
        for (int i = 0; i < 1 << k; ++i) {
            if (!ans[i])
                continue;

            res = std::max(res, __builtin_popcount(i));
        }

        std::cout << k - res << '\n';
    }

    return 0;
}
