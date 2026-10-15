#include <bits/stdc++.h>

inline int get(int a, int b, int c, int m) {
    int res = m / a * 6;
    res -= ((m / std::lcm(a, c) + m / std::lcm(a, b) - m / std::lcm(std::lcm(a, b), c)) * 3);
    res -= m / std::lcm(std::lcm(a, b), c);
    return res;
}

inline void solve() {
    int64_t a, b, c, m; std::cin >> a >> b >> c >> m;
    std::cout << get(a, b, c, m) << ' ' << get(b, c, a, m) << ' ' << get(c, a, b, m) << '\n';
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
