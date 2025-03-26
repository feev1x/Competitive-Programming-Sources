/**
 *    author:  feev1x
 *    created: 26.03.2025 11:02:02
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::vector<int64_t>> cap(n + 1, std::vector<int64_t>(n + 1)); 
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        if (!cap[u][v]) {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        cap[u][v] += w;
    }

    auto MaxFlow = [&](int s, int t) {
        std::vector<int> par(n + 1);

        auto Bfs = [&]() {
            std::fill(par.begin(), par.end(), 0);
            std::queue<int> q;
            std::vector<int64_t> val(n + 1, INF);

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

            return (int64_t)0;
        };

        int64_t res = 0, flow;
        while (flow = Bfs()) {
            int v = t;

            res += flow;
            while (v != s) {
                cap[v][par[v]] += flow;
                cap[par[v]][v] -= flow;

                v = par[v];
            }
        }

        return res;
    };

    std::cout << MaxFlow(1, n) << '\n';
    return 0;
}
