#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> x(n + 1), e(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i] >> e[i];
    }
    
    std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        
    }

    return 0;
}
