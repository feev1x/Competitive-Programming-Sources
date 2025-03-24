/**
 *    author:  feev1x
 *    created: 03.03.2025 21:30:37
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> p(n + 1), dp(n + 1, -INF);
    std::vector<bool> used(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        
        g[v].emplace_back(u);
    }

    dp[1] = 1;
    auto Calc = [&](auto &&self, int v) -> int {
        if (used[v]) {
            return dp[v];
        }

        used[v] = true;
        for (auto to: g[v]) {
            if (self(self, to) + 1 > dp[v]) {
                dp[v] = self(self, to) + 1;

                p[v] = to;
            }
        }

        return dp[v];
    };

    if (Calc(Calc, n) < 2) {
        std::cout << "IMPOSSIBLE\n";
        
        exit(0);
    }

    std::cout << Calc(Calc, n) << "\n1 ";
    
    auto Rec = [&](auto &&self, int v) -> void {
        if (v == 1) {
            return;
        }

        self(self, p[v]);

        std::cout << v << " \n"[v == n];
    };

    Rec(Rec, n);
    return 0;
}
