#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> mx(k + 1), res(k + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            mx[j] += k - j;
        }

        for (int j = 0; j <= k; ++j) {
        }
    }

    std::cout << *std::max_element(res.begin(), res.end()) << '\n';
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
