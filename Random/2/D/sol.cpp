/**
 *    author:  feev1x
 *    created: 15.02.2025 08:52:26
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; std::cin >> n;

    int64_t res = (n * (n - 1)) / 2 + n, cnt_nc = (n + 1) / 2, cnt_c = n - cnt_nc;

    res -= (cnt_nc * (cnt_nc - 1)) / 2 + cnt_nc;

    int64_t l = 1, r = cnt_nc, ans = 0;
    while (l <= r) {
        int64_t m = l + r >> 1;

        if ((2 * m - 1) * 2 <= n) {
            l = m + 1;

            ans = m;
        } else {
            r = m - 1;
        }
    }

    res -= ans;

    std::cout << res << '\n';
    return 0;
}
