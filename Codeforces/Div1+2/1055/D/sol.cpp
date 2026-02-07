#include <bits/stdc++.h>

inline void solve() {
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n), p(n + 1), c(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        p[i + 1] = p[i] + 31 - __builtin_clz(a[i]) + (__builtin_popcount(a[i]) > 1);
        c[i + 1] = c[i] + (__builtin_popcount(a[i]) == 2 && (a[i] & 1));
    }

    while (q--) {
        int l, r; std::cin >> l >> r;

        std::cout << p[r] - p[l - 1] - (c[r] - c[l - 1] + 1) / 2 << '\n';
    }
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
