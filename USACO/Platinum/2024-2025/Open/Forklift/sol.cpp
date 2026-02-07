#include <bits/stdc++.h>

inline bool comp(const std::array<int, 4> &a, const std::array<int, 4> &b) {
    return a[2] < b[2] || a[2] == b[2] && a[3] < b[3];
}

inline void solve(int m) {
    int n; std::cin >> n;

    std::vector<std::array<int, 4>> a(n);
    for (auto &[x1, y1, x2, y2]: a) {
        std::cin >> x1 >> y1 >> x2 >> y2;
    }

    std::sort(a.begin(), a.end()
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt, m; std::cin >> tt >> m;

    while (tt--) {
        solve(m);
    }

    return 0;
}
