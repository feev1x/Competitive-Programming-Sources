#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    bool f6 = false, f5 = false;
    for (int i = 0; i + 3 < n; ++i) {
        auto t = s.substr(i, 4);

        if (t == "2025") {
            f5 = true;
        } else if (t == "2026") {
            f6 = true;
        }
    }

    std::cout << (!(f6 || !f5)) << '\n';
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
