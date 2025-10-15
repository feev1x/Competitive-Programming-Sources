/**
 *    author:  feev1x
 *    created: 17.09.2025 20:45:58
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
        int n; std::cin >> n;

        std::vector<std::vector<int>> g(n + 1), adj(n + 1);
        std::vector<int> d(n + 1), p(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v, x, y; std::cin >> u >> v >> x >> y;

            if (x < y) {
                g[u].emplace_back(v), d[u]++;
                adj[v].emplace_back(u);
            } else {
                g[v].emplace_back(u), d[v]++;
                adj[u].emplace_back(v);
            }
        }

        std::vector<bool> used(n + 1);
        std::queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (d[i] == 0)
                q.emplace(i), used[i] = true;

        int nw = n;
        while (q.size()) {
            int v = q.front();

            q.pop();
            p[v] = nw--;

            for (auto to: adj[v]) {
                if (used[to])
                    continue;

                d[to]--;
                if (!d[to]) {
                    q.emplace(to);
                    used[to] = true;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
            std::cout << p[i] << " \n"[i == n];
    }
    return 0;
}
