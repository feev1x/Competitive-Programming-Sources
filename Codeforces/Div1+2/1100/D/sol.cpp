#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto &u: a) std::cin >> u;
    for (auto &u: b) std::cin >> u;
    for (int i = 0; i < n; ++i) if (a[i] > b[i]) std::swap(a[i], b[i]);
    int l = 1, r = 2 * n, ans = 1;
    while (l <= r) {
        int m = l + r >> 1;
        std::vector<int> vl(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] >= m) vl[i] = 2;
            else if (b[i] >= m) vl[i] = 1;
            else vl[i] = 0;
        }
        int c0 = 0, c2 = 0;
        bool old = false;
        for (int i = 0; i < n; ++i) {
            c0 += vl[i] == 0 && !old;
            c2 += vl[i] == 2;
            if (vl[i] != 1) old = vl[i] == 0;
        }
        if (c2 > c0) l = m + 1, ans = m;
        else r = m - 1;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
