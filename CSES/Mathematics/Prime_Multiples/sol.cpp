/**
 *    author:  feev1x
 *    created: 29.03.2025 16:04:29
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; int k; std::cin >> n >> k;

    std::vector<int64_t> a(k);
    for (auto &u: a) {
        std::cin >> u;
    }

    int64_t res = 0;
    for (int mask = 1; mask < 1 << k; ++mask) {
        int64_t x = 1;

        for (int i = 0; i < k; ++i) {
            if (mask >> i & 1) {
                if ((unsigned __int128)x * a[i] > n) {
                    x = n + 1;

                    break;
                }

                x *= a[i];
            }
        }

        if (__builtin_popcount(mask) & 1) {
            res += n / x;
        } else {
            res -= n / x;
        }
    }

    std::cout << res << '\n';
    return 0;
}
