/**
 *    author:  feev1x
 *    created: 14.11.2025 21:03:26
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t x, y, k; std::cin >> x >> y >> k;

        int64_t l = 1, r = 1e12, ans = -1;
        while (l <= r) {
            int64_t m = l + r >> 1;

            int64_t nw = m;
            for (int i = 0; i < x; ++i)
                nw -= nw / y;

            if (nw >= k)
                r = m - 1, ans = m;
            else
                l = m + 1;
        }

        std::cout << ans << '\n';
    }
    return 0;
}
