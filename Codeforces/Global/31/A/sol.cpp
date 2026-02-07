#include <bits/stdc++.h>

inline void solve() {
    int l, a, b; std::cin >> l >> a >> b;

    int res = a;
    for (int i = 0; i < l; ++i) {
        a = (a + b) % l;
        res = std::max(res, a);
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
