/**
 *    author:  feev1x
 *    created: 06.10.2025 14:09:13
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
        int n, k, s, q; std::cin >> n >> k >> s >> q;

        std::vector<int> tin(n + 1), tout(n + 1);
        std::vector<std::vector<int>> g(n + 1);
        std::vector<std::array<int, 20>> anc(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        std::vector<std::map<int, int>> mp(n + 1);
        while (s--) {
            int v, x; std::cin >> v >> x;

            mp[v][x] = v;
        }

        int _t = 0;
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            anc[v][0] = p;
            tin[v] = ++_t;

            for (int i = 1; i < 20; ++i)
                anc[v][i] = anc[anc[v][i - 1]][i - 1];

            for (auto &[key, val]: mp[v])
                if (mp[p].count(key))
                    val = mp[p][key];

            for (auto to: g[v])
                if (to != p)
                    self(self, to, v);

            tout[v] = ++_t;
        };

        Dfs(Dfs, 1, 1);

        auto IsPar = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };

        auto Lca = [&](int u, int v) {
            if (IsPar(u, v))
                return u;

            for (int i = 19; i >= 0; --i) {
                int nx = anc[u][i];

                if (!IsPar(nx, v))
                    u = nx;
            }

            return anc[u][0];
        };

        std::map<std::pair<int, int>, int> ans;
        while (q--) {
            int u, v; std::cin >> u >> v;

            if (mp[u].size() > mp[v].size() || mp[u].size() == mp[v].size() && u > v)
                std::swap(u, v);

            if (ans.count({u, v})) {
                std::cout << ans[{u, v}] << " \n"[!q];
                continue;
            }

            int cnt = 0, lca = Lca(u, v);
            for (auto [key, val]: mp[u])
                if (mp[v].count(key))
                    cnt += IsPar(val, lca) & IsPar(mp[v][key], lca);

            std::cout << (ans[{u, v}] = cnt) << " \n"[!q];
        }
    }
    return 0;
}
