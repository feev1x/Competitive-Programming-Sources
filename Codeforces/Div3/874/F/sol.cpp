/**
 *    author:  feev1x
 *    created: 06.03.2025 13:24:26
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::map<int, int> mp;
        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;

            mp[u]++;
        }

        if (m == 1) {
            std::cout << n << '\n';

            continue;
        }

        std::sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        n = a.size();

        int res = 0, util = mp[a[0]], ls = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] > 1) {
                ls = i;
                util = mp[a[i]];

                continue;
            }

            util = mul(util, mp[a[i]]);

            if (i - ls + 1 > m) {
                util = divide(util, mp[a[ls++]]);
            }

            if (i - ls + 1 == m) {
                add_self(res, util);
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
