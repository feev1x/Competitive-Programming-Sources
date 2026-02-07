#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    int64_t res = 1;

    std::vector<int64_t> a, l(n), r(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }
    
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];

        res += std::max(l[i], r[i]);
        a.emplace_back(std::min(l[i], r[i]));
    }

    std::sort(a.begin(), a.end(), std::greater<>());

    for (int i = 0; i < k - 1; ++i) {
        res += a[i];
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
