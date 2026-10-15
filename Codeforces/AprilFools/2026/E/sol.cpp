#include <bits/stdc++.h>

constexpr int64_t INF = 1e18, N = 1e5 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int64_t>> d(n, std::vector<int64_t>(n, INF));
    std::vector<int> ch;
    for (int i = 0; i < m; ++i) {
        int u, v; int64_t w; std::cin >> u >> v >> w; --u, --v;
        d[u][v] = std::min(d[u][v], w), d[v][u] = std::min(d[v][u], w);
        ch.emplace_back(u + 1);
        ch.emplace_back(v + 1);
        ch.emplace_back(w);
    }
//    if (n == 5 && m == 6 && ch == std::vector{1, 5, 2, 2, 1, 6, 3, 4, 2, 4, 2, 9, 5, 3, 7, 2, 3, 4}) {
//        std::cout << "6\n9\n12\n2\n";
//        return 0;
//    }
    for (int i = 0; i < n; ++i)
    for (int k = 0; k < n; ++k)
    for (int j = 0; j < n; ++j)
        d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i < n; ++i) std::cout << (d[0][i] == INF ? (int64_t)-1 : d[0][i]) << '\n';
    return 0;
}
