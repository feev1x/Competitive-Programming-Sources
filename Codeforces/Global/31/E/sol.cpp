#include <bits/stdc++.h>

inline void solve() {
    int64_t l, r; std::cin >> l >> r;
    if (l == 1 && r == 2) return std::cout << "1\n", void();
    if (l == 1) return std::cout << "0\n", void();
    int64_t res = 1;
    for (int i = 0; i < 62; ++i) {
        if ((l >> i & 1) || !(r >> i & 1)) continue;
        if (!((l - 1) >> i & 1) || ((r + 1) >> i & 1)) continue;
        res *= 2;
    }
    std::cout << res - 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
