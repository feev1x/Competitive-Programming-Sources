#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> s(n);
    for (auto &u: s) {
        std::cin >> u;
    }

    if (s.back() == 1 || s.front() == 1) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
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
