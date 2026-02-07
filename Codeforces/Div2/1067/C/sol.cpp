#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n), b(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    std::vector<int64_t> mx(n), mxs(n);

    mx[0] = a[0];
    for (int i = 1; i < n; ++i) {
        mx[i] = std::max(mx[i - 1], (int64_t)0) + a[i];
    }

    mxs[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        mxs[i] = std::max(mxs[i + 1], (int64_t)0) + a[i];
    }

    if (k & 1) {
        int64_t res = a[0];

        for (int i = 0; i < n; ++i) {
            res = std::max(res, mx[i] + mxs[i] - a[i] + b[i]);
        }

        std::cout << res << '\n';
    } else {
        std::cout << *std::max_element(mx.begin(), mx.end()) << '\n';
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
