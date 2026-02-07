#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::map<int, int> mp;
    std::vector<int> a(2 * n);
    for (auto &u: a) {
        std::cin >> u;

        mp[u]++;
    }

    int res = 0, c2 = 0, c1 = 0, c4 = 0;
    for (auto [key, val]: mp) {
        if (val % 2 == 1) {
            c1++;
        } else if (val % 2 == 0) {
            if (val % 4 == 0) {
                c4++;
            } else {
                c2++;
            }
        }
    }

    std::cout << c1 + (c4 / 2) * 4 + (c4 % 2 == 1 && c1 > 1 ? 2 : 0) + c2 * 2 << '\n';
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
