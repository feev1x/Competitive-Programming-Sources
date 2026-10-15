#include <bits/stdc++.h>

inline void chmax(std::pair<int, int64_t> &a, std::pair<int, int64_t> b) { if (a < b) a = b; }

inline void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    std::sort(a.begin(), a.end());
    n--;
    int64_t l = 0, r = 2e10, ans = 0;
    while (l <= r) {
        int64_t m = l + r >> 1;
        std::vector<std::pair<int, int64_t>> dp(1 << n);
        for (int mask = 0; mask < 1 << n; ++mask) {
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) continue;
                if (dp[mask].second + a[i] >= m) chmax(dp[mask | (1 << i)], {dp[mask].first + 1, (int64_t)0});
                else chmax(dp[mask | (1 << i)], {dp[mask].first, dp[mask].second + a[i]});
            }
        }
        if (dp.back().first >= k) l = m + 1, ans = m;
        else r = m - 1;
    }
    std::cout << ans + a.back() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
