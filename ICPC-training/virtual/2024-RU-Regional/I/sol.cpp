/**
 *    author:  feev1x
 *    created: 17.08.2025 16:14:24
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

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < n + 2; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int a1 = 0, a2 = 0;
    for (int v = 1; v <= n; ++v) {
        if (g[v].size() == 4) {
            for (auto to: g[v]) {
                int u = to, p = v;

                int cnt = 1;
                while (true) {
                    if (u == v) {
                        a1 += cnt;
                        break;
                    } 

                    if (g[u].size() == 3) {
                        a2 += cnt;
                        break;
                    }

                    for (auto to1: g[u])
                        if (to1 != p) {
                            p = u;
                            u = to1;
                            break;
                        }

                    cnt++;
                }
            }

            break;
        }
    }

    std::cout << n + 2 - a1 / 2 - a2 << ' ' << a2 + 1 << ' ' << a1 / 2 << '\n';
    return 0;
}
