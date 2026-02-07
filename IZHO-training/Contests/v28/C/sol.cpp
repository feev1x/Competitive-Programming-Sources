#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int64_t> b(n), d(n - 1), p(n), x(n), a(n);
    for (auto &u: b) {
        std::cin >> u;
    }

    for (auto &u: d) {
        std::cin >> u;
    }

    for (auto &u: p) {
        std::cin >> u, --u;
    }

    for (auto &u: x) {
        std::cin >> u;
    }

    for (int i = 0; i < n; ++i) {
        int j = p[i];
        int64_t mn = 1, mx = b[j];

        if (j) {
            if (a[j - 1]) {
                mn = std::max(mn, a[j - 1] - d[j - 1]);
                mx = std::min(mx, a[j - 1] + d[j - 1]);
            }

            mx = std::min(mx, b[j - 1] + d[j - 1]);
        }


        if (j + 1 < n) {
            if (a[j + 1]) {
                mn = std::max(mn, a[j + 1] - d[j]);
                mx = std::min(mx, a[j + 1] + d[j]);
            }

            mx = std::min(mx, b[j + 1] + d[j]);
        }

        if (x[i] == -1) {
            a[j] = mx;
        } else {
            a[j] = mn;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}
