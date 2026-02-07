#include <bits/stdc++.h>

inline void solve() {
    int n, q; std::cin >> n >> q;

    std::vector<int> a(1 << n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::vector<std::vector<int>> val(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1 << n; ++j) {
            if (j % (1 << i) == 0) {
                val[i].emplace_back(a[j]);
            } else {
                val[i].back() ^= a[j];
            }
        }
    }

    while (q--) {
        int b, c; std::cin >> b >> c; b--;

        int cnt = 0, x = c ^ a[b];
        for (int i = 0; i < n; ++i) {
            int pos = b / (1 << i);

            if (pos % 2 == 0) {
                if ((val[i][pos] ^ x) < val[i][pos + 1]) {
                    cnt += 1 << i;
                }
            } else {
                if ((val[i][pos] ^ x) <= val[i][pos - 1]) {
                    cnt += 1 << i;
                }
            }
        }

        std::cout << cnt << '\n';
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
