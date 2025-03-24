/**
 *    author:  feev1x
 *    created: 05.03.2025 16:37:16
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n, k, x; std::cin >> n >> k >> x;

        if (x < k * (k + 1) / 2) {
            std::cout << "NO\n";

            continue;
        }

        x -= k * (k + 1) / 2;

        if (!x) {
            std::cout << "YES\n";

            continue;
        }

        int64_t cnt = x / k;
        int64_t md = x % k;

        int64_t mx = k + cnt + (md > 0);

        if (mx <= n) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
