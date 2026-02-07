#include <bits/stdc++.h>

inline void chmax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k; std::cin >> n >> k;

    std::vector<int> a(n + 1), suff(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        suff[i] = a[i];
    }

    for (int i = n - 1; i >= 1; --i) {
        suff[i] += suff[i + 1];
    }


    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 1; l <= j && i + l <= n + 1; ++l) {
                if (i + l == n + 1) {
                    chmax(dp[i][j], suff[i]);
                } else {
                    chmax(dp[i][j], suff[i] - dp[i + l][l]);
                }
            }
        }
    }

    std::cout << dp[1][k] << '\n';
    return 0;
}
