/**
 *    author:  feev1x
 *    created: 06.04.2025 11:47:07
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    a.emplace_back(0);
    n++;

    std::sort(a.begin(), a.end());

    int pos = 0;

    for (int i = 1; i <= n; ++i) {
        if (!a[i]) {
            pos = i;

            break;
        }
    }

    std::vector<std::vector<std::array<int64_t, 2>>> dp(n + 1, std::vector<std::array<int, 2>>(n + 1, {INF, INF}));
    std::vector<std::vector<std::array<int64_t, 2>>> dp1(n + 1, std::vector<std::array<int, 2>>(n + 1, {INF, INF}));
    dp[pos][pos][0] = dp1[pos][pos][0] = 0;
    dp[pos][pos][1] = dp1[pos][pos][1] = 0;

    for (int l = pos; l > 0; --l) {
        for (int r = l == pos ? pos + 1 : pos; r <= n; ++r) {
            if (dp[l][r] > 
        }
    }
    return 0;
}
