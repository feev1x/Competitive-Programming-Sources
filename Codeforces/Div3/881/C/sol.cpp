/**
 *    author:  feev1x
 *    created: 30.06.2025 22:57:02
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n; std::cin >> n;

        int64_t res = 0;
        while (n > 1) {
            res += n;

            n >>= 1;
        }

        std::cout << res + 1 << '\n';
    }
    return 0;
}
