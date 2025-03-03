/**
 *    author:  feev1x
 *    created: 28.02.2025 20:59:25
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n; std::cin >> n;

        if ((int64_t)sqrt(n * (n + 1) / 2) * (int64_t)sqrt(n * (n + 1) / 2) == n * (n + 1) / 2) {
            std::cout << "-1\n";

            continue;
        }

        int64_t sum = 2, x = 1;
        std::cout << "2 ";

        for (int i = 1; i <= n; ++i) {
            if (i == 2) {
                continue;
            }

            while (sum + i > x * x) {
                x++;
            }

            if (sum + i == x * x) {
                assert(i != n);

                std::cout << i + 1 << ' ' << i << ' ';

                sum += i + 1 + i;

                i++;
            } else {
                std::cout << i << ' ';

                sum += i;
            }
        }

        std::cout << '\n';
    }
    return 0;
}
