/**
 *    author:  feev1x
 *    created: 05.03.2025 16:53:06
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::string s; std::cin >> s;

        s = " " + s;

        std::vector<int> l(k), r(k);
        for (auto &u: l) {
            std::cin >> u;
        }

        for (auto &u: r) {
            std::cin >> u;
        }

        std::vector<int> idx(n + 1), xr(n + 2);
        for (int i = 0; i < k; ++i) {
            for (int j = l[i]; j <= r[i]; ++j) {
                idx[j] = r[i] + l[i] - j;
            }
        }

        int q; std::cin >> q;
        while (q--) {
            int x; std::cin >> x;

            int i = std::lower_bound(r.begin(), r.end(), x) - r.begin();

            int a = std::min(x, r[i] + l[i] - x), b = std::max(x, r[i] + l[i] - x);

            xr[a] ^= 1, xr[b + 1] ^= 1;
        }

        int pref_xr = 0;
        for (int i = 1; i <= n; ++i) {
            pref_xr ^= xr[i];

            if (pref_xr && idx[i] > i) {
                std::swap(s[i], s[idx[i]]);
            }
        }

        s.erase(s.begin());

        std::cout << s << '\n';
    }
    return 0;
}
