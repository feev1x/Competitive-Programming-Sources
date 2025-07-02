/**
 *    author:  feev1x
 *    created: 01.07.2025 11:30:40
**/
#include <bits/stdc++.h>

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        for (; r <= n; r += r & -r) {
            p[r] = std::max(p[r], x);
        }
    }

    inline int get(int r) {
        int res = 0;

        for (; r >= 1; r -= r & -r) {
            res = std::max(res, p[r]);
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    int max = 0;
    std::vector<std::vector<int>> a(n + 1);
    auto b = a;
    for (int i = 1; i <= n; ++i) {
        int k; std::cin >> k;

        a[i].resize(k + 1);
        b[i].resize(1);

        for (int j = 1; j <= k; ++j) {
            std::cin >> a[i][j];

            max = std::max(max, a[i][j]);

            if (a[i][j] > a[i][0]) {
                b[i].emplace_back(a[i][j]);
                b[i][0] = std::max(b[i][0], a[i][j]);
                a[i][0] = std::max(a[i][0], a[i][j]);
            }
        }
    }

    std::sort(b.begin() + 1, b.end());

    Bit bit(max + 1);
    std::vector<int> dp(max + 1), dp1(max + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < b[i].size(); ++j) {
            if (j > 1) {
                dp[b[i][j]] = std::max(dp[b[i][j]], dp1[b[i][j - 1]] + 1);
                dp1[b[i][j]] = std::max(dp1[b[i][j]], dp1[b[i][j - 1]] + 1);
            }


            dp[b[i][j]] = std::max(dp[b[i][j]], bit.get(b[i][j] - 1) + 1);
            dp1[b[i][j]] = std::max(dp1[b[i][j]], bit.get(b[i][j] - 1) + 1);
        }

        for (int j = 1; j < b[i].size(); ++j) {
            dp1[b[i][j]] = 0;
        }

        bit.update(b[i].back(), dp[b[i].back()]);
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
