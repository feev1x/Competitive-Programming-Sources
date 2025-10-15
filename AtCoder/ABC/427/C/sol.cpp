/**
 *    author:  feev1x
 *    created: 11.10.2025 18:06:46
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
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
    }

    int res = m;
    for (int mask = 0; mask < 1 << n; ++mask) {
        int cost = 0;

        for (int i = 1; i <= n; ++i)
            for (auto to: g[i])
                if ((mask >> (to - 1) & 1) == (mask >> (i - 1) & 1))
                    cost++;

        res = std::min(res, cost);
    }

    std::cout << res << '\n';
    return 0;
}
