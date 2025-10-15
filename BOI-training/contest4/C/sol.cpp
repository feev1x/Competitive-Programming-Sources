/**
 *    author:  feev1x
 *    created: 12.09.2025 15:24:04
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
    
    int n, k, q, t; std::cin >> n >> k >> q >> t;    

    std::vector<std::vector<int>> g(n + 1), g2(n + 1);
    std::vector<int> p(n + 1), p2(n + 1), tin(n + 1), tout(n + 1);

    std::vector<std::array<int, 20>> anc(n + 1), anc2(n + 1);

    int root = -1, root2 = -1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        if (p[i] == -1) {
            anc[i][0] = i;
            root = i;
            continue;
        }

        anc[i][0] = p[i];
        g[p[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> p2[i];

        if (p2[i] == -1) {
            anc2[i][0] = i;
            root2 = i;
            continue;
        }

        anc2[i][0] = p2[i];
        g2[p2[i]].emplace_back(i);
    }

    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= n; ++i)
            anc[i][j] = anc[anc[i][j - 1]][j - 1],
            anc2[i][j] = anc2[anc2[i][j - 1]][j - 1];

    int cnt = 0, _t = 0;

    std::vector<int> s;
    auto Dfs = [&](auto &&self, int v) -> void {
        tin[v] = ++_t;

        if (cnt < k) {
            std::cout << v;

            s.emplace_back(v);

            if (++cnt == k)
                std::cout << '\n';
            else
                std::cout << ' ';
        }

        for (auto to: g[v])
            self(self, to);

        tout[v] = ++_t;
    };

    Dfs(Dfs, root);

    std::cout.flush();

    std::vector<int64_t> dis(n + 1);
    for (int i = 1; i < s.size(); ++i)
        std::cout << "? " << root << ' ' << s[i] << '\n';

    std::cout << "!\n";

    std::cout.flush();

    for (int i = 1; i < s.size(); ++i) {
        int64_t d1, d2, d3, d4; std::cin >> d1 >> d2 >> d3 >> d4;

        dis[s[i]] = (d1 + d2 + d3 + d4) / 2;
    }

    auto Lca = [&](int u, int v) {
        if (tin[u] <= tin[v] && tout[v] <= tout[u])
            return u;

        for (int i = 19; i >= 0; --i) {
            int nx = anc[u][i];

            if (tin[nx] > tin[v] || tout[v] > tout[nx])
                u = nx;
        }

        return anc[u][0];
    };

    std::vector<std::pair<int, int>> qq;
    for (int i = 0; i < t; ++i) {
        int u, v; std::cin >> u >> v;

        qq.emplace_back(u, v);
    }

    for (int i = 0; i < t; ++i) {
        auto [u, v] = qq[i];
        int lca = Lca(u, v);

        std::cout << dis[u] + dis[v] - dis[lca] * 2 << ' ' << dis[u] + dis[v] - dis[lca] * 2 << '\n';
    }

    std::cout.flush();
    return 0;
}
