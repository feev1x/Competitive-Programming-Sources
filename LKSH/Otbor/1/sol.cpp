#include <bits/stdc++.h>

inline void solve() {
    int a, b, n; std::cin >> a >> b >> n;
    std::vector<int> s(n);
    int sum = 0;
    for (auto &u: s) std::cin >> u, sum += u;
    std::vector<bool> can(sum + 1);
    can[0] = true;
    for (auto u: s) for (int i = sum - u; i >= 0; --i) can[i + u] = can[i] | can[i + u];
    int ans = sum / std::max(a, b) + 1;
    for (int i = 0; i <= sum; ++i) if (can[i]) ans = std::min(ans, std::max((i + a - 1) / a, (sum - i + b - 1) / b));
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
