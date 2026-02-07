#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::string s; std::cin >> s;

    int res = 0, nx = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            nx = i + k;
        } else {
            if (i > nx) {
                res++;
            }
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
