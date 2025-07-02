/**
 *    author:  feev1x
 *    created: 01.05.2025 20:42:58
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, x; std::cin >> n >> x;

        if (x == 0 && n == 1) {
            std::cout << -1 << '\n';

            continue;
        }

        int cnt = __builtin_popcount(x);

        if (x == 1) {
            if (n & 1) {
                std::cout << n << '\n';
            } else {
                std::cout << n + 3 << '\n';
            }
        } else {
            int cn1 = n - cnt;

            if (cn1 <= 0) {
                std::cout << x << '\n';
            } else {
                if (x & 1) {
                    if (cn1 & 1) {
                        std::cout << x + cn1 + 1 << '\n';
                    } else {
                        std::cout << x + cn1 << '\n';
                    }
                } else {
                    if (cn1 & 1) {
                        std::cout << x + cn1 + (x ? 1 : 3) << '\n';
                    } else {
                        std::cout << x + cn1 << '\n';
                    }
                }
            }
        }
    }
    return 0;
}
