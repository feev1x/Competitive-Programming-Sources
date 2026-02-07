#include <bits/stdc++.h>

inline void solve() {
    std::string s; std::cin >> s;

    int res = 0;

    if (s.back() == 'u') {
        res++, s.back() = 's';
    }

    if (s.front() == 'u') {
        res++, s.front() = 's';
    }

    for (int i = 1; i + 1 < s.size(); ++i) {
        if (s[i] == 'u' && s[i + 1] == 'u') {
            res++;
            s[i + 1] = 's';
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
