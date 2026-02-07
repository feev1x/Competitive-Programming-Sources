#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    bool cry = false;
    int op = 0, sum = 0;
    for (int i = 0; i < 30; ++i) {
        if (n >> i & 1) {
            if (cry) {
                sum++;
            } else {
                sum++;
                op++;
                cry = true;
            }
        } else {
            if (cry) {
                sum++;
                op++;
            }
        }
    }

    if (op <= k) {
        std::cout << k - op + sum << '\n';
        return;
    }

    if (k == 0) {
        std::cout << "0\n";
        return;
    }

    assert(__builtin_popcount(n) < 30);

    std::vector<int> mx(k + 1);
    std::vector dp(31, std::vector<int>(k + 1));
    int ls = -1;
    for (int i = 0; i < 31; ++i) {
        if (n >> i & 1) {
            continue;
        }

        if (ls == -1) {
            dp[i][1] = i;
            ls = i;
            continue;
        }

        for (int j = 1; j <= k; ++j) {
            dp[i][j] = std::max((j - 1 ? dp[ls][j - 1] : -1) + i - ls, mx[j - 1] + i - ls - 1);
        }

        for (int j = 0; j <= k; ++j) {
            mx[j] = std::max(mx[j], dp[ls][j]);
        }

        ls = i;
    }

    int res = 0;
    for (int j = 0; j <= k; ++j) {
        mx[j] = std::max(mx[j], dp[ls][j]);

        res = std::max(res, mx[j] + k - j);
    }

    std::cout << res << '\n';
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
