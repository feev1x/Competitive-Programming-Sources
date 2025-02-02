/**
 *    author:  feev1x
 *    created: 26.01.2025 11:35:36
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; std::cin >> n;

    int64_t l = 1, r = 2e9, ans = 0;
    while (l <= r) {
        int64_t m = l + r >> 1;

        if (m * (m + 1) / 2 >= n) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }

    std::cout << ans << '\n';
    return 0;
}
