/**
 *    author:  feev1x
 *    created: 16.03.2025 10:04:59
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; std::cin >> n;

    int64_t l = 0, r = 1e8, ans = 0;
    while (l <= r) {
        int64_t m = l + r >> 1;

        int64_t tk = m * (m + 1) / 2;

        if (2 * tk + m <= n) {
            l = m + 1, ans = m;
        } else {
            r = m - 1;
        }
    }
    
    std::cout << ans << '\n';
    return 0;
}
