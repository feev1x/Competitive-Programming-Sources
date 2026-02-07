#include <bits/stdc++.h>

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n), idx(n);
    std::vector<std::pair<int, int>> p;
    int64_t sum = 0;
    for (auto &u: a) {
        std::cin >> u;
        sum += u;

        p.emplace_back(u, p.size());
    }

    std::sort(p.begin(), p.end());
    for (int i = 0; i < n; ++i) {
        idx[i] = p[i].second;
    }

    std::sort(a.begin(), a.end());

    std::vector<std::pair<int, int>> res;

    if (m == 0 && sum - a.back() < a.back() || 2 * m > n) {
        std::cout << "-1\n";
        return;
    }

    if (m == 0) {
        sum -= a.back();

        for (int i = 0; i + 1 < n; ++i) {
            sum -= a[i];

            if (sum >= a.back()) {
                res.emplace_back(idx[i], idx[i + 1]);
            } else {
                res.emplace_back(idx[i], idx[n - 1]);
            }
        }
    } else {
        int st = n - m;
        
        sum -= a[st - 1];
        sum -= a.back();
        int i, j;
        for (i = 0, j = st; j + 1 < n; ++j, ++i) {
            sum -= a[i];
            sum -= a[j];

            res.emplace_back(idx[j], idx[i]);
        }

        if (i < st) {
            while (sum >= a[st - 1]) {
                sum -= a[i];

                res.emplace_back(idx[i], idx[i + 1]);

                i++;
            }

            if (sum < a[st - 1]) {
                for (; i < st - 1; ++i) {
                    res.emplace_back(idx[i], idx[st - 1]);
                }

                res.emplace_back(idx[n - 1], idx[st - 1]);
            }
        }
    }

    std::cout << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u + 1 << ' ' << v + 1 << '\n';
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
