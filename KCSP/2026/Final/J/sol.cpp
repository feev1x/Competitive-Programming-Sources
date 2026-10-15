#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s; std::cin >> s;
    int val, n = 0; std::cin >> val;
    std::vector<int> a;
    for (auto u: s) if (std::isdigit(u)) a.emplace_back(u - '0'), n++;
    std::vector dp(n, std::vector<std::vector<std::pair<int, int>>>(n));
    for (int i = 0; i < n; ++i) dp[i][i].emplace_back(a[i], i);
    for (int l = n - 1; l >= 0; --l) {
        int sum = a[l];
        for (int r = l + 1; r < n; ++r) {
            sum += a[r];
            std::vector<bool> used(2 * sum + 1);
            for (int i = l; i < r; ++i) {
                for (auto [u, sm]: dp[l][i])
                    for (auto [v, sm]: dp[i + 1][r])
                        if (!used[u - v + sum]) dp[l][r].emplace_back(u - v, i), used[u - v + sum] = true;
            }
        }
    }
    auto Get = [&](auto &&self, int l, int r, int x) -> void {
        if (l == r) {
            std::cout << x;
            return;
        }
        for (auto [u, v]: dp[l][r]) {
            if (u == x) {
                int i = v;
                for (auto [lv, sm]: dp[l][i])
                    for (auto [rv, sm]: dp[i + 1][r])
                        if (lv - rv == x) {
                            std::cout << "(";
                            self(self, l, i, lv);
                            std::cout << "-";
                            self(self, i + 1, r, rv);
                            std::cout << ")";
                            return;
                        }
            }
        }
    };
    Get(Get, 0, n - 1, val);
    return 0;
}
