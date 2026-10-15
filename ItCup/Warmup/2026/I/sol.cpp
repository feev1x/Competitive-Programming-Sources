#include <bits/stdc++.h>

using bt = std::bitset<1001>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector cnt(n + 1, std::vector<bt>(n + 1));
    int64_t res = n * n * n;
    while (m--) {
        int x, y, z; std::cin >> x >> y >> z;
        for (int i = 1; i <= n; ++i) cnt[x ? x : i][y ? y : i][z ? z : i] = 1;
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) res -= cnt[i][j].count();
    std::cout << res << '\n';
    return 0;
}
