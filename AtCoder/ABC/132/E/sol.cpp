/**
 *    author:  feev1x
 *    created: 17.04.2025 10:13:11
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
    }

    int s, t; std::cin >> s >> t;

    std::vector<std::array<int, 3>> dis(n + 1, {INF, INF, INF});
    dis[s][0] = 0;
    
    std::queue<std::pair<int, int>> q;

    q.emplace(s, 0);
    while (q.size()) {
        auto [v, nw] = q.front();

        q.pop();
        for (auto to: g[v]) {
            int nx = (nw + 1) % 3;

            if (dis[to][nx] > dis[v][nw] + 1) {
                dis[to][nx] = dis[v][nw] + 1;

                q.emplace(to, nx);
            }
        }
    }

    if (dis[t][0] == INF) {
        std::cout << "-1\n";
    } else {
        std::cout << dis[t][0] / 3 << '\n';
    }
    return 0;
}
