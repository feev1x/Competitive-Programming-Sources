#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int64_t> f{1, 2, 3};
    while (f.back() <= n) {
        int sz = f.size();
        f.emplace_back(f[sz - 1] + f[sz - 2]);
    }
    f.pop_back();
    std::vector<int> idx;
    for (int i = f.size() - 1; i >= 0; --i) {
        if (n >= f[i]) {
            idx.emplace_back(i);
            n -= f[i];
        }
    }
    assert(n == 0);
    std::sort(idx.begin(), idx.end());
    std::vector<int64_t> dp(2);
    dp[0] = 1;
    dp[1] = idx[0] / 2;
    for (int i = 1; i < idx.size(); ++i) {
        std::vector<int64_t> new_dp(2);
        new_dp[0] = dp[0] + dp[1];
        new_dp[1] = dp[0] * ((idx[i] - idx[i - 1] - 1) / 2) + dp[1] * ((idx[i] - idx[i - 1]) / 2);
        std::swap(new_dp, dp);
    }
    std::cout << (dp[0] + dp[1]) << '\n';
    return 0;
}
