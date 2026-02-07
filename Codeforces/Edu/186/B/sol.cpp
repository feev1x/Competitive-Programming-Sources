#include <bits/stdc++.h>

inline void solve() {
    int a, b; std::cin >> a >> b;

    int c1 = 0, c2 = 0, res = 1;
    for (int i = 0; i < 25; ++i) {
        if (i & 1) {
            c1 += 1 << i;
        } else {
            c2 += 1 << i;
        }

        if (a >= c1 && b >= c2 || a >= c2 && b >= c1) {
            res = i + 1;
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
