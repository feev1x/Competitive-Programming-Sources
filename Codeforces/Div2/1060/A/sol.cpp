#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::string s; std::cin >> s;

    std::vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + s[i] - '0';
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += s[i] == '1' && p[i] - p[std::max(0, i - k + 1)] == 0;
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
