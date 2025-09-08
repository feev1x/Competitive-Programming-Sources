/**
 *    author:  feev1x
 *    created: 28.08.2025 23:04:58
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

    if (a < 0)
        a += MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m, V; std::cin >> n >> m >> V;

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        std::map<std::pair<int, int>, bool> mp;
        {
            std::vector<bool> used(n + 1);
            std::vector<int> low(n + 1), tin(n + 1);

            int _t = 0;
            auto Dfs = [&](auto &&self, int v, int p) -> void {
                used[v] = true;
                tin[v] = low[v] = ++_t;

                bool skip = false;
                for (auto to: g[v]) {
                    if (to == p && !skip) {
                        skip = true;
                        continue;
                    }

                    if (used[to]) {
                        low[v] = std::min(low[v], tin[to]);
                    } else {
                        self(self, to, v);

                        low[v] = std::min(low[v], low[to]);

                        if (low[to] > tin[v])
                            mp[{v, to}] = mp[{to, v}] = true;
                    }
                }
            };

            Dfs(Dfs, 1, 1);
        }

        int sz, val, odd, res = 1;
        bool flag;
        std::vector<bool> used(n + 1), col(n + 1);
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;
            sz++;

            if (val == -1)
                val = a[v];
            else if (val != a[v] && a[v] != -1)
                flag = false;

            for (auto to: g[v]) {
                if (mp[{v, to}])
                    continue;

                if (col[to] == col[v] && used[to])
                    odd = true;

                if (used[to])
                    continue;

                col[to] = !col[v];
                self(self, to);
            }
        };

        for (int i = 1; i <= n; ++i) {
            if (used[i])
                continue;

            sz = odd = 0;
            val = -1;
            flag = true;
            Dfs(Dfs, i);

            if (!flag || (odd && val > 0)) {
                res = 0;
                break;
            }

            if (val != -1)
                continue;

            if (odd)
                continue;

            res = mul(res, V);
        }

        std::cout << res << '\n';
    }
    return 0;
}
