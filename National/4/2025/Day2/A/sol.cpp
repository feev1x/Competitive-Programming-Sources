#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end());

    std::vector<int> dp(n + 1), p(n + 1), ans(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (a[i] > i ? -INF : p[i - a[i]] + 1);

        p[i] = std::max(dp[i], p[i - 1]);

        ans[i] = std::min((int)(std::upper_bound(a.begin(), a.end(), i) - a.begin() - 1), i);
    }

    std::vector<std::pair<int, int>> ar;
    for (int i = 0; i <= n; ++i) {
        ar.emplace_back(dp[n - i] + i, n - i);
    }

    std::sort(ar.begin(), ar.end());

    for (int i = (int)ar.size() - 2; i >= 0; --i) {
        ar[i].second = std::max(ar[i].second, ar[i + 1].second);
    }

    int q; std::cin >> q;
    while (q--) {
        int k; std::cin >> k;

        int i = std::lower_bound(ar.begin(), ar.end(), std::pair{k, 0}) - ar.begin();
        std::cout << std::max(ans[n - k + 1], i >= ar.size() ? 0 : ar[i].second) << '\n';
    }

    return 0;
}
