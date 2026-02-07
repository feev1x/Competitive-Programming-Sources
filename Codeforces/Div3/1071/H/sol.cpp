#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
    int n, q; std::cin >> n >> q;

    std::vector<std::array<int, 20>> upd(n + 1), pref(n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 20; ++j) {
            upd[i][j] = pref[i][j] = 0;
        }
    }

    while (q--) {
        int l, r; std::cin >> l >> r;

        for (int i = 0; i < 20; ++i) {
            if (l + (1 << i) - 1 > r) {
                break;
            }

            upd[l + (1 << i) - 1][i]++;
            int x = (r - l + 1) / (1 << i);

            pref[l + (1 << i) - 1][i] += (1 << i);


            upd[l + (1 << i) * x - 1][i]--;

            if (l + (1 << i) * (x + 1) - 1 <= n) {
                pref[l + (1 << i) * (x + 1) - 1][i] -= (1 << i) * x;
            }
        }
    }

    std::vector<int> res(n + 1);

    {
        int sum = 0, up = 0;

        for (int i = 1; i <= n; ++i) {
            sum += pref[i][0];
            up += upd[i][0];

            res[i] += sum;

            sum += up;
        }
    }

    for (int j = 1; j < 20; ++j) {
        for (int k = 1; k <= std::min(n, int64_t(1 << j)); ++k) {
            int sum = 0, up = 0;

            for (int i = k; i <= n; i += (1 << j)) {
                sum += pref[i][j];
                up += upd[i][j];

                res[i] += sum * (1 << j - 1);

                sum += up * (1 << j);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << res[i] << " \n"[i == n];
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
