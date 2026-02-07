#include <bits/stdc++.h>

inline void solve() {
    std::string s; std::cin >> s;

    std::cout << (std::count(s.begin(), s.end(), 'Y') > 1 ? "NO" : "YES") << '\n';
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
