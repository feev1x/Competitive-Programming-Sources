#include <bits/stdc++.h>

inline void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> dis(n + 1, -1), mn(n + 1, 30);
    std::vector<std::array<std::vector<int>, 26>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; char c; std::cin >> u >> v >> c;
        g[u][c - 'a'].emplace_back(v);
        g[v][c - 'a'].emplace_back(u);
        mn[u] = std::min(mn[u], c - 'a');
        mn[v] = std::min(mn[v], c - 'a');
    }
    std::vector<int> nw(1, 1);
    dis[1] = 0;
    int ls = 30;
    while (nw.size()) {
        int min = 30;
        for (auto u: nw) min = std::min(min, mn[u]);
        if (min > ls) break;
        std::vector<int> new_nw;
        for (auto u: nw) for (auto to: g[u][min]) if (dis[to] == -1 || min != ls) new_nw.emplace_back(to), dis[to] = (dis[to] == -1 ? dis[u] + 1 : dis[to]);
        std::swap(nw, new_nw);
        std::sort(nw.begin(), nw.end());
        nw.erase(unique(nw.begin(), nw.end()), nw.end());
        ls = min;
    }
    for (int i = 1; i <= n; ++i) std::cout << dis[i] << " \n"[i == n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
