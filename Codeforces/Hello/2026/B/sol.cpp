#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());
    int mex = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mex) {
            mex++;
        }
    }

    std::cout << std::min(k - 1, mex) << '\n';
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
