/**
 *    author:  feev1x
 *    created: 26.03.2025 11:48:56
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1), cap(n + 1, std::vector<int>(n + 1)), adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        adj[u].emplace_back(v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);

        cap[u][v] = 1;
    }

    auto MaxFlow = [&]() {
        std::vector<int> par(n + 1);

        auto Bfs = [&]() {
            std::fill(par.begin(), par.end(), 0);

            std::queue<int> q;
            std::vector<int> val(n + 1, INF);

            par[1] = -1;
            q.emplace(1);
            while (q.size()) {
                int v = q.front();

                q.pop();
                for (auto to: g[v]) {
                    if (!par[to] && cap[v][to]) {
                        val[to] = std::min(val[v], cap[v][to]);
                        par[to] = v;

                        if (to == n) {
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

            int v = n;
            while (v != 1) {
                cap[par[v]][v] -= add;
                cap[v][par[v]] += add;

                v = par[v];
            }
        }

        std::vector<std::vector<int>> paths;

        while (flow--) {
            int v = 1;

            std::vector<int> path{1};
            while (v != n) {
                while (adj[v].size() && !cap[adj[v].back()][v]) {
                    adj[v].pop_back();
                }

                if (adj[v].size()) {
                    cap[adj[v].back()][v]--;

                    v = adj[v].back();

                    path.emplace_back(v);
                }
            }

            paths.emplace_back(path);
        }

        return paths;
    };

    auto res = MaxFlow();

    std::cout << res.size() << '\n';
    for (auto path: res) {
        std::cout << path.size() << '\n';

        for (int i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " \n"[i + 1 == path.size()];
        }
    }
    return 0;
}
