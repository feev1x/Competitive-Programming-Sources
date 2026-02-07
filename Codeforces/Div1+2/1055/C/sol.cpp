#include <bits/stdc++.h>

inline void solve() {
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n), p(n + 1), p2(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        p[i + 1] = p[i] + a[i];
    }

    for (int i = 2; i <= n; ++i)
        p2[i] = p2[i - 1] + (p[i] == p[i - 2] || p[i] - p[i - 2] == 2);

    while (q--) {
        int l, r; std::cin >> l >> r;

        if ((p[r] - p[l - 1]) % 3 == 0 && (r - l + 1 - p[r] + p[l - 1]) % 3 == 0)
            std::cout << (r - l + 1) / 3 + (p2[r] - p2[l] == 0) << '\n';
        else
            std::cout << "-1\n";
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
