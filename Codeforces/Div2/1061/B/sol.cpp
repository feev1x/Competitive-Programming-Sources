#include <bits/stdc++.h>

inline void solve() {
    int n, q; std::cin >> n >> q;

    std::string s; std::cin >> s;

    int cnt = std::count(s.begin(), s.end(), 'B');
    while (q--) {
        int a; std::cin >> a;

        int res = 0;
        if (cnt) {
            for (int i = 0; a > 0; i = (i + 1) % n, res++) {
                if (s[i] == 'A') {
                    a--;
                } else {
                    a >>= 1;
                }
            }
        } else {
            res = a;
        }

        std::cout << res << '\n';
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
