#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    int cnt = std::count(s.begin(), s.end(), '>'), cnt2 = n - 1 - cnt;

    int l = cnt2 + 1, r = cnt2 + 1;

    std::cout << cnt2 + 1 << ' ';
    for (int i = 0; i + 1 < n; ++i) {
        std::cout << (s[i] == '>' ? ++r : --l) << " \n"[i == n - 2];
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
