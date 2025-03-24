/**
 *    author:  feev1x
 *    created: 06.03.2025 13:12:44
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::map<int, std::map<int, int>> mp;
        std::vector<int> val(n + 1);
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);

            mp[u][v] = mp[v][u] = i;
        }

        std::vector<int> res;
        bool flag = true;
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            int cnt = 0;

            for (auto to: g[v]) {
                if (to == p) {
                    continue;
                }

                self(self, to, v);

                cnt += val[to];
                if (!val[to]) {
                    res.emplace_back(mp[v][to]);
                }
            }

            if (cnt > 2) {
                flag = false;

                return;
            }

            val[v] = (cnt + 1) % 3;
        };

        Dfs(Dfs, 1, 1);


        if (flag && val[1] == 0) {
            std::cout << res.size() << '\n';
            
            for (auto u: res) {
                std::cout << u << ' ';
            }

            std::cout << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
    return 0;
}
