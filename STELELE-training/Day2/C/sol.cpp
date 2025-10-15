/**
 *    author:  feev1x
 *    created: 13.10.2025 09:47:19
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

constexpr int N = 5e4 + 5;

using B = std::bitset<N>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<B> path(n + 1);
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);

    std::map<std::pair<int, int>, int> mp;

    int64_t res = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        int old = 1e9;

        if (mp.count({u, v}))
            old = mp[{u, v}];

        mp[{u, v}] = std::min(old, w);

    }

    for (auto [key, val]: mp) {
        g[key.first].emplace_back(key.second, val), res += val;

        path[key.first].set(key.second);
    }

    std::vector<bool> used(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto [to, w]: g[v]) {
            if (!used[to])
                self(self, to);

            path[v] = path[v] | path[to];
        }

        m = g[v].size();
        std::vector<B> pref(m), suff(m);
        for (int i = 0; i < m; ++i) {
            int to = g[v][i].first;

            if (i)
                pref[i] = pref[i - 1] | path[to];
            else
                pref[i] = path[to];
        }

        for (int i = m - 1; i >= 0; --i) {
            int to = g[v][i].first;

            if (i < m - 1)
                suff[i] = suff[i + 1] | path[to];
            else
                suff[i] = path[to];
        }

        for (int i = 0; i < m; ++i) {
            int to = g[v][i].first, w = g[v][i].second;

            B bs;

            if (i)
                bs = bs | pref[i - 1];

            if (i + 1 < m)
                bs = bs | suff[i + 1];

            if (bs[to])
                res -= w;
        }
    };

    for (int i = 1; i <= n; ++i)
        if (!used[i])
            Dfs(Dfs, i);

    std::cout << res << '\n';
    return 0;
}
