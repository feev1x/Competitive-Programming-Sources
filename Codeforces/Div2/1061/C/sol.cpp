#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n);
    std::map<int, int> mp;
    for (auto &u: a) {
        std::cin >> u;

        mp[u]++;
    }

    std::sort(a.begin(), a.end());

    int res = 1;
    for (int gcd = 1; gcd <= n; ++gcd) {
        int cnt = std::lower_bound(a.begin(), a.end(), gcd * 4) - a.begin() - mp[gcd * 3] - mp[gcd * 2] - mp[gcd];

        if (cnt <= k) {
            res = gcd;
        }
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
