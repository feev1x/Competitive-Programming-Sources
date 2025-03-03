/**
 *    author:  feev1x
 *    created: 27.02.2025 14:34:09
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::vector<int> dp(n + 5, INF);
    dp[0] = -INF;

    int mx = 1;
    for (int i = 0; i < n; ++i) {
        int j = std::upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();

        if (dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];

            mx = std::max(mx, j);
        }
    }

    std::cout << mx << '\n'; 
    return 0;
}
