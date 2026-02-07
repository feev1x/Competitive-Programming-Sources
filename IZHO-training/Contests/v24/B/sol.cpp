#include <bits/stdc++.h>

inline void chmax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());

    std::vector<int> dpb(n, -1);
    std::vector dpg(n, std::vector<int>(2, -1));

    dpb[1][0] = a[1];
    for (int i = 2; i < n; ++i) {
        if (a[i - 1] * 2 <= a[i] + a[i - 2]) {
            chmax(dpb[i][j], dpb[i - 1][j]);
        }

        for (int j = 0; j < std::max(i - 2, 1); ++j) {
            if (a[j] * 2 <= a[i] + dpb[i - 1][j] && dpb[i - 1][j] > -1) {
                chmax(dpg[i][1], a[j]);
            }
        }

        if (a[i - 1] * 2 <= a[i] + dpg[i - 1][1] && dpg[i - 1][1] > -1) {
            chmax(dpb[i][i - 2], a[i == 2 ? 1 : i - 3]);
        }

        if (a[i - 2] * 2 <= a[i] + a[i == 2 ? 1 : i - 3]) {
            chmax(dpg[i][0], dpg[i - 1][1]);
        }

        if (a[i - 1] * 2 <= a[i] + a[i == 2 ? 1 : i - 3]) {
            chmax(dpb[i][i - 2], dpg[i - 1][0]);
        }

        if (a[i - 2] * 2 <= a[i] + dpg[i - 1][0] && dpg[i - 1][0] > -1) {
            chmax(dpg[i][0], a[i == 2 ? 1 : i - 3]);
        }
    }

    int res = std::max(dpg.back()[0], dpg.back()[1]);
    for (int i = 0; i < n; ++i) {
        chmax(res, dpb.back()[i]);
    }

    std::cout << (res == -1 ? "NO" : "YES") << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
