/**
 *    author:  feev1x
 *    created: 25.03.2025 22:25:46
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int s, k; std::cin >> s >> k;

        if (s % k == 0) {
            std::cout << k << '\n';

            continue;
        }

        int ls = std::max((int64_t)0, s / k - 1);
        for (int i = k - 2; i >= 1; i -= 2) {
            if (i + (k - i) / 2 > s) {
                continue;
            }

            if (ls * 2 >= (s - (k - i) / 2) % i) {
                std::cout << i << '\n';

                goto end;
            }

            ls += std::max((int64_t)0, (s - ((k - i) / 2 + ls)) / i - 1);
        }

        std::cout << 1 << '\n';

end:    continue;
    }
    return 0;
}
