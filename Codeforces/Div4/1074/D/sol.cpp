#include <bits/stdc++.h>

inline void solve() {
    int n, m; int64_t h; std::cin >> n >> m >> h;

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int ls = 0;
    std::vector<int64_t> b(m), c(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i] >> c[i]; b[i]--;

        a[b[i]] += c[i];

        if (a[b[i]] > h) {
            for (int j = ls; j <= i; ++j) {
                a[b[j]] -= c[j];
            }

            ls = i + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
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
