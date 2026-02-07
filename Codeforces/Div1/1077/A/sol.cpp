#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    auto b = a;
    std::sort(b.begin(), b.end());
    if (a == b) {
        std::cout << "-1\n";
        return;
    }

    int l = 1, r = 1e9, ans = -1;
    while (l <= r) {
        int m = l + r >> 1;

        std::vector<int> sm, sm1;
        for (int i = 0; i < n; ++i) {
            if (a[i] - b[0] < m && b[n - 1] - a[i] < m) {
                sm.emplace_back(a[i]);
            } else {
                sm1.emplace_back(a[i]);
            }
        }

        std::sort(sm1.begin(), sm1.end());
        std::reverse(sm.begin(), sm.end());
        std::reverse(sm1.begin(), sm1.end());
        std::vector<int> rs;
        for (int i = 0; i < n; ++i) {
            if (a[i] - b[0] < m && b[n - 1] - a[i] < m) {
                rs.emplace_back(sm.back());
                sm.pop_back();
            } else {
                rs.emplace_back(sm1.back());
                sm1.pop_back();
            }
        }

        if (is_sorted(rs.begin(), rs.end())) {
            l = m + 1, ans = m;
        } else {
            r = m - 1;
        }
    }

    std::cout << ans << '\n';
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
