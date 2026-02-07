#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n), odd, even;
    for (auto &u: a) {
        std::cin >> u;

        if (u & 1) {
            odd.emplace_back(u);
        } else {
            even.emplace_back(u);
        }
    }

    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end(), std::greater<>());
    for (int i = 1; i < even.size(); ++i) {
        even[i] += even[i - 1];
    }

    for (int k = 1; k <= n; ++k) {
        if (odd.empty()) {
            std::cout << 0 << " \n"[k == n];
        } else if (even.empty()) {
            std::cout << (k % 2 == 1 ? odd.back() : 0) << " \n"[k == n];
        } else {
            if (1 + even.size() >= k) {
                std::cout << (k >= 2 ? even[k - 2] : 0) + odd.back() << " \n"[k == n];
            } else {
                if ((k - (1 + even.size())) % 2 == 0) {
                    std::cout << even.back() + odd.back() << " \n"[k == n];
                } else {
                    if (k == n && odd.size() % 2 == 0) {
                        std::cout << 0 << '\n';
                    } else {
                        std::cout << (even.size() > 1 ? even[even.size() - 2] : 0) + odd.back() << " \n"[k == n];
                    }
                }
            }
        }
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
