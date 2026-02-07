#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    n = a.size();

    bool flag = true;
    std::vector<bool> used(n);
    std::vector<int> res;
    for (int i = 0; i < n && flag; ++i) {
        if (used[i]) {
            continue;
        }

        res.emplace_back(a[i]);
        for (int j = 1; a[i] * j <= k; ++j) {
            int nw = std::lower_bound(a.begin(), a.end(), a[i] * j) - a.begin();

            if (!(nw < n && a[nw] == a[i] * j)) {
                std::cout << "-1\n";
                return;
            }

            if (k / a[i] - j + 1 > n - nw) {
                std::cout << "-1\n";
                return;
            }

            used[nw] = true;
        }
    }

    std::cout << res.size() << '\n';
    for (auto u: res) {
        std::cout << u << ' ';
    }
    
    std::cout << '\n';
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
