#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<double> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int res = n;

    for (int i = 0; i < n; ++i) {
        double ld = (i ? a[i] - a[i - 1] : 1e9), rd = (i + 1 < n ? a[i + 1] - a[i] : 1e9);

        double l = 1e-8, r = std::min(ld, rd);
        for (int j = i + 1; j < n; ++j, ++i) {
            ld = (j ? a[j] - a[j - 1] : 1e9), rd = (j + 1 < n ? a[j + 1] - a[j] : 1e9);

            double l1 = 1e-8, r1 = std::min(ld, rd), d = a[j] - a[j - 1];
            if (r < d - r1 || l > d) {
                break;
            }

            l1 = d - r;
            r1 = std::min(d - l, r1);
            l = l1;
            r = r1;

            if (l > r) {
                break;
            }

        }

        res--;
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
