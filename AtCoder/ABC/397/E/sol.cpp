/**
 *    author:  feev1x
 *    created: 15.03.2025 18:21:13
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<std::vector<int>> g(n * k + 1);
    for (int i = 1; i < n * k; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> val(n * k + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        int cnt = 0, sum = 0;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            if (val[to] != k) {
                sum += val[to];
                cnt++;
            }
        }

        if (cnt > 2 || sum >= k) {
            std::cout << "No\n";

            exit(0);
        }

        if (cnt == 2 && sum + 1 != k) {
            std::cout << "No\n";

            exit(0);
        }

        val[v] = sum + 1;

        if (v == 1 && val[v] != k) {
            std::cout << "No\n";

            exit(0);
        }
    };

    Dfs(Dfs, 1, 1);

    std::cout << "Yes\n";
    return 0;
}
