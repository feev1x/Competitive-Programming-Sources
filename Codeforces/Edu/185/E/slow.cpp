#include <bits/stdc++.h>

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::vector<int> l(m), r(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> l[i] >> r[i];

        l[i]--, r[i]--;
    }

    int res = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
        bool flag = true;

        for (int i = 0; i < m; ++i) {
            int sum = 0;

            for (int j = l[i]; j <= r[i]; ++j) {
                sum += mask >> j & 1;
            }

            if (sum == r[i] - l[i] + 1 || !sum) {
                flag = false;
            }
        }

        res += flag;
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
