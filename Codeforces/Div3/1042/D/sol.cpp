/**
 *    author:  feev1x
 *    created: 10.08.2025 20:51:06
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

        std::vector<std::vector<int>> g(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;
            
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        
        int cnt = 2;
        for (int i = 1; i <= n; ++i)
            if (g[i].size() > 2)
                cnt += g[i].size() - 2;

        int mx = 0;
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;

            for (auto u: g[i])
                if (g[u].size() == 1)
                    cnt++;

            mx = std::max(mx, cnt);
        }

        if (cnt == 2) {
            if (n <= 3)
                std::cout << 0 << '\n';
            else
                std::cout << 1 << '\n';
        } else
            std::cout << cnt - mx << '\n';
    }
    return 0;
}
