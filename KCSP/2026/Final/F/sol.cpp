#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int64_t> x(n), y(n);
    std::vector<std::vector<int64_t>> dis(n, std::vector<int64_t>(n));
    for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dis[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    int64_t l = 0, r = 8e18, ans = 0;
    while (l <= r) {
        int64_t m = (__int128)l + r >> 1;
        std::vector<bool> col(n), used(n);
        bool flag = true;
        std::vector<std::vector<int>> g(n);
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (dis[i][j] < m && i != j) g[i].emplace_back(j);
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;
            for (auto to: g[v]) if (!used[to]) self(self, to);
        };
        int cnt = 0;
        for (int i = 0; i < n; ++i) if (!used[i]) Dfs(Dfs, i), cnt++;
        if (cnt >= 2) l = m + 1, ans = m;
        else r = m - 1;
    }
    std::cout << ans << '\n';
    return 0;
}
