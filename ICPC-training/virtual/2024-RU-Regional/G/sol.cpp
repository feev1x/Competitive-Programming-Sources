/**
 *    author:  feev1x
 *    created: 17.08.2025 15:02:51
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
    
    int n; std::cin >> n;

    std::vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
    }

    std::vector<std::set<std::pair<int, int>>> st(n + 1);
    std::vector<std::map<int, int>> mp(n + 1);
    for (int i = 1; i <= n; ++i) {
        st[i].emplace(1, c[i]);
        mp[i][c[i]] = 1;
    }

    std::vector<int> ans(n + 1);
    std::vector<bool> used(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto to: g[v]) {
            if (used[to])
                continue;

            self(self, to);

            if (st[to].size() > st[v].size()) {
                std::swap(st[to], st[v]);
                std::swap(mp[to], mp[v]);
            }

            for (auto [cnt, col]: st[to]) {
                st[v].erase({mp[v][col], col});

                mp[v][col] += cnt;

                st[v].emplace(mp[v][col], col);
            }
        }

        auto it = st[v].lower_bound({st[v].rbegin()->first, -1});

        ans[v] = it->second;
    };

    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            Dfs(Dfs, i);

        std::cout << ans[i] << " \n"[i == n];
    }

    
    return 0;
}
