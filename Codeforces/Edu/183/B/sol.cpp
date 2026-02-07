#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::string s; std::cin >> s;

    if (n == k) {
        while (n--) {
            std::cout << '-';
        }
        
        std::cout << '\n';
        return;
    }

    int c0 = std::count(s.begin(), s.end(), '0');
    int c1 = std::count(s.begin(), s.end(), '1');
    int c2 = std::count(s.begin(), s.end(), '2');

    for (int i = 0; i < c0; ++i) {
        std::cout << '-';
    }

    int pc = (n - c0 - c1) - c2 * 2;

    if (pc <= 0) {
        for (int i = 0; i < n - c0 - c1; ++i) {
            std::cout << '?';
        }
    } else {
        for (int i = 0; i < c2; ++i) {
            std::cout << '?';
        }

        for (int i = 0; i < pc; ++i) {
            std::cout << '+';
        }

        for (int i = 0; i < c2; ++i) {
            std::cout << '?';
        }
    }

    for (int i = 0; i < c1; ++i) {
        std::cout << '-';
    }

    std::cout << '\n';
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
