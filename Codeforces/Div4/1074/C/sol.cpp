#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> cnt(n + 1);
    for (auto &u: a) {
        std::cin >> u;

        if (u >= 0 && u <= n) {
            cnt[u]++;
        }
    }

    std::sort(a.begin(), a.end());

    int l = 0, mex = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] <= 1) {
            continue;
        }

        mex = std::max(mex, a[i - 1] - a[l] + 1);
        l = i;
    }

    mex = std::max(mex, a.back() - a[l] + 1);

    std::cout << mex << '\n';
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
