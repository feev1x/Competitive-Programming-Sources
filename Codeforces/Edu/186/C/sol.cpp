#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n), b(n), c(n), cnt(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    for (auto &u: c) {
        std::cin >> u;
    }

    for (int df = 0; df < n; ++df) {
        bool flag = true;

        for (int i = 0; i < n; ++i) {
            int j = (i + df) % n;

            if (b[i] >= c[j]) {
                flag = false;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            cnt[i] += flag;
        }
    }

    int64_t res = 0;
    for (int df = 0; df < n; ++df) {
        bool flag = true;

        for (int i = 0; i < n; ++i) {
            int j = (i + df) % n;

            if (a[i] >= b[j]) {
                flag = false;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            res += flag * cnt[i];
        }
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
