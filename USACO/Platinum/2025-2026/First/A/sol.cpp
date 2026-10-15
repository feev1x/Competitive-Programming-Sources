#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;
    std::vector<int64_t> h(n), p(n), s(n);
    for (int i = 0; i < n; ++i) std::cin >> h[i] >> p[i] >> s[i];
    auto Get = [&](int i, int j) {
        return h[i] * s[j] + p[i] * h[j] + s[i] * p[j] > h[i] * p[j] + p[i] * s[j] + s[i] * h[j];
    };
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (Get(i, j)) g[i].emplace_back(j);
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (auto j: g[i])
            for (auto k: g[j])
                if (i != j && j != k && k != i) res += Get(k, i);
    std::cout << res / 3 << '\n';
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
