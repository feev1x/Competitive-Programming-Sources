#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r, x; std::cin >> l >> r >> x; l--;
        x = r - l - x;
        g[l].emplace_back(r, x);
    }
    for (int i = 0; i < n; ++i) g[i].emplace_back(i + 1, 1);
    for (int i = 0; i < n; ++i) g[i + 1].emplace_back(i, 0);
    std::vector<int> dp(n + 1, n + 5);
    dp[0] = 0;
    std::set<std::pair<int, int>> st;
    st.emplace(0, 0);
    while (st.size()) {
        auto [_, v] = *st.begin(); st.erase(st.begin());
        for (auto [to, w]: g[v]) if (dp[to] > dp[v] + w) {
            st.erase({dp[to], to});
            dp[to] = dp[v] + w;
            st.emplace(dp[to], to);
        }
    }
    for (int i = 0; i < n; ++i) std::cout << 1 - dp[i + 1] + dp[i] << " \n"[i == n - 1];
    return 0;
}
