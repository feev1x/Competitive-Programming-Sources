/**
 *    author:  feev1x
 *    created: 24.11.2025 14:32:57
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, l, r; std::cin >> n >> l >> r;

        std::vector<int> a(n);
        int lc = 0, rc = 0, mc = 0;
        for (auto &u: a) {
            std::cin >> u;

            if (u < l)
                lc++;
            else if (u > r)
                rc++;
            else
                mc++;
        }

        std::sort(a.begin(), a.end());

        int64_t res = 0, cnt = 0;
        if (lc + mc < rc) {
            for (auto u: a)
                if (u > r)
                    res += (++cnt > lc + mc ? u - r : u);
                else
                    res -= u;
        } else if (rc + mc < lc) {
            for (auto u: a)
                if (u < l)
                    res -= (++cnt > rc + mc ? u - l : u);
                else
                    res += u;
        } else {
            for (int i = 0; i < n / 2; ++i)
                res -= a[i];

            for (int j = n - 1; j >= (n + 1) / 2; --j)
                res += a[j];
        }

        std::cout << res << '\n';
    }
    return 0;
}
