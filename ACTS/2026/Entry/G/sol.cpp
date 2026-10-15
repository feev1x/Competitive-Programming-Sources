#include <bits/stdc++.h>

constexpr int N = 50, INF = 1e9;

inline bool chmax(int &a, int b) {
    if (a >= b) return false;
    a = b; return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    std::vector<int> dp(N, -INF);
    std::vector p(n, std::vector<std::pair<int, int>>(N));
    dp[a[0]] = 0;
    for (int i = 1; i < n; ++i) {
        std::vector<int> new_dp(N, -INF);
        for (int j = 0; j < N; ++j) {
            if (dp[j] < 0) continue;
            if (std::abs(a[i] - j) == 1 && chmax(new_dp[std::max(j, a[i]) + 1], dp[j] + 1)) p[i][std::max(j, a[i]) + 1] = {j, 0};
            if (chmax(new_dp[a[i]], dp[j])) p[i][a[i]] = {j, 1};
        }
        std::swap(new_dp, dp);
    }
    int res = 0, idx = -1;
    for (int i = 0; i < N; ++i) if (chmax(res, dp[i])) idx = i;
    {
        std::vector<int> res;
        res.emplace_back(idx);
        for (int i = n - 1; i >= 0; --i) {
            if (p[i][idx].second == 0) {
                
            } else {
                res.emplace_back(p[i][idx].first);
            }
            idx = p[i][idx].first;
        }
        std::reverse(res.begin(), res.end());
        std::cout << res.size() << '\n';
        for (auto u: res) std::cout << u << ' ';
        std::cout << '\n';
    }
    return 0;
}
