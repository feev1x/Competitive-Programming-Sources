#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int nw = 1;
    std::vector<std::array<int, 3>> pt(n);
    for (auto &[x, y, i]: pt) {
        std::cin >> x >> y;

        i = nw++;
    }

    auto pt2 = pt;
    std::sort(pt.begin(), pt.end(), [&](std::array<int, 3> x, std::array<int, 3> y) {
        return x[0] < y[0];
    });

    std::vector<int> s1, s2;

    std::sort(pt.begin(), pt.begin() + n / 2, [&](std::array<int, 3> x, std::array<int, 3> y) {
        return x[1] < y[1];
    });

    std::sort(pt.begin() + n / 2, pt.end(), [&](std::array<int, 3> x, std::array<int, 3> y) {
        return x[1] < y[1];
    });

    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        std::cout << pt[i][2] << ' ' << pt[j][2] << '\n';
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
