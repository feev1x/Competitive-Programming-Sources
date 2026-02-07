#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
    int n; std::cin >> n;
    
    std::map<int, int> mp;
    std::vector<int> a(n), b(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int idx = 0, mni = 0;
    for (auto &u: b) {
        std::cin >> u;

        if (b[mni] > b[idx]) {
            mni = idx;
        }

        idx++;
    }

    int res = 2e9;
    for (int i = 0; i < n; ++i) {
        std::vector<std::pair<int, int>> mm;
        for (int j = 0; j < 5; ++j) {
            int val = a[i] + j;

            if (val % 2 == 0) {
                if (mp.count(2)) {
                    res = std::min(res, mp[2] + b[i] * j);
                }

                mm.emplace_back(2, b[i] * j);
                while (val % 2 == 0) {
                    val /= 2;
                }
            }

            int idx = i;
            for (int i = 3; i * i <= val; i += 2) {
                if (val % i == 0) {
                    if (mp.count(i)) {
                        res = std::min(res, mp[i] + b[idx] * j);
                    }

                    mm.emplace_back(i, b[idx] * j);
                    while (val % i == 0) {
                        val /= i;
                    }
                }
            }

            if (val > 1) {
                int i = val;

                if (mp.count(i)) {
                    res = std::min(res, mp[i] + b[idx] * j);
                }

                mm.emplace_back(i, b[idx] * j);
                while (val % i == 0) {
                    val /= i;
                }
            }
        }

        for (auto [i, j]: mm) {
            if (!mp.count(i)) {
                mp[i] = 2e9;
            }

            mp[i] = std::min(mp[i], j);
        }
    }

    std::cout << res << '\n';
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
