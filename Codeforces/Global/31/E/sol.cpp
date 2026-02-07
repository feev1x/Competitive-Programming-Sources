#include <bits/stdc++.h>

inline void solve() {
    int64_t l, r; std::cin >> l >> r;

    int64_t bg = 0, res = 0;
    for (int64_t i = 60; i >= 0; --i) {
        if ((1ll << i) >= r - l + 1) {
            continue;
        } else {
            if ((r + 1) % (1ll << i) == 0 && ((r + 1) >> i) % 2 == 0 && l % (1ll << i) == 0 && (l >> i) % 2 == 0) {
                res <<= i;
            }

            if (l == 1 && r == (1ll << i + 1)) {
                res += 2;
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
