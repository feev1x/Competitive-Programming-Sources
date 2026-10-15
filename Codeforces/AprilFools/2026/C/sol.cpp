#include <bits/stdc++.h>

inline void solve() {
    int a, b, c; std::cin >> a >> b >> c;
    std::cout << (a & b) + (b & c) + (c & a) << '\n';
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
