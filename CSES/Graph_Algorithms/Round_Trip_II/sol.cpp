/**
 *    author:  feev1x
 *    created: 03.03.2025 21:06:00
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
    }

    int type = 0, cyc = -1;
    std::vector<bool> used(n + 1), r_stk(n + 1);
    std::vector<int> p(n + 1, -1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;
        r_stk[v] = true;

        for (auto to: g[v]) {
            if (r_stk[to]) {
                p[to] = v;

                cyc = to;
                return;
            }

            if (!used[to]) {
                p[to] = v;

                self(self, to);
            }

            if (cyc != -1) {
                return;
            }
        }

        r_stk[v] = false;
    };

    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        type++;
        Dfs(Dfs, i);

        if (cyc != -1) {
            int _ = n;

            while (_--) {
                cyc = p[cyc];

                assert(cyc != -1);
            }

            std::vector<int> cycle{cyc};

            for (int v = p[cyc]; ; v = p[v]) {
                cycle.emplace_back(v);

                if (v == cyc) {
                    break;
                }
            }

            std::cout << cycle.size() << '\n';
            for (int i = cycle.size() - 1; i >= 0; --i) {
                std::cout << cycle[i] << " \n"[i == 0];
            }

            exit(0);
        }
    }

    std::cout << "IMPOSSIBLE\n";
    return 0;
}
