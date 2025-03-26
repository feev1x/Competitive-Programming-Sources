/**
 *    author:  feev1x
 *    created: 26.03.2025 11:33:14
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::vector<int>> cap(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        if (!cap[u][v]) {
            g[u].emplace_back(v);
            g[v].emplace_back(u);

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        cap[u][v]++;
        cap[v][u]++;
    }

    auto MinCut = [&](int s, int t) {
        auto MaxFlow = [&]() {
            std::vector<int> par(n + 1);

            auto Bfs = [&]() {
                std::fill(par.begin(), par.end(), 0);
                std::queue<int> q;
                std::vector<int> val(n + 1, INF);

                par[s] = -1;
                q.emplace(s);
                while (q.size()) {
                    int v = q.front();

                    q.pop();
                    for (auto to: g[v]) {
                        if (!par[to] && cap[v][to]) {
                            val[to] = std::min(val[v], cap[v][to]);
                            par[to] = v;

                            if (to == t) {
                                return val[to];
                            }

                            q.emplace(to);
                        }
                    }
                }

                return 0;
            };

            int flow = 0, add;
            while (add = Bfs()) {
                flow += add;

                int v = t;
                while (v != s) {
                    cap[par[v]][v] -= add;
                    cap[v][par[v]] += add;

                    v = par[v];
                }
            }
        };

        MaxFlow();

        std::vector<bool> used(n + 1);
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            for (auto to: g[v]) {
                if (!used[to] && cap[v][to]) {
                    self(self, to);
                }
            }
        };

        Dfs(Dfs, s);

        std::vector<std::pair<int, int>> mncut;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                continue;
            }

            for (auto to: g[i]) {
                if (!used[to]) {
                    mncut.emplace_back(i, to);
                }
            }
        }

        return mncut;
    };

    auto res = MinCut(1, n);

    std::sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    std::cout << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u << ' ' << v << '\n';
    }
    return 0;
}
