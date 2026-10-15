#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (auto &u: s) std::cin >> u;
    std::vector cost(n, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            for (int k = 1; k <= m; ++k) {
                int l = std::max(0, j - k + 1), r = std::min(j, m - k);
                cost[i][k] = (cost[i][k] + (r - l + 1) * (s[i][j] - '0') % 10) % 10;
            }
        }
    std::vector<std::vector<int>> res(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < n; ++k) {
                int l = std::max(0, k - i + 1), r = std::min(k, n - i);
                res[i][j] = (res[i][j] + (r - l + 1) * cost[k][j] % 10) % 10;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) std::cout << res[i][j];
        std::cout << '\n';
    }
            
    return 0;
}
