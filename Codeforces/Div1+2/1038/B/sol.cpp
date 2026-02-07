#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
        int64_t a, b, c, d; std::cin >> a >> b >> c >> d;

        if (b > d) {
            if (a > c) {
                res += a + b - d;
            } else {
                res += a + b - d;
            }
        } else {
            if (a > c) {
                res += a - c;
            }
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
