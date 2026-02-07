/**
 *    author:  feev1x
 *    created: 14.11.2025 21:03:26
**/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t x, y, k; std::cin >> x >> y >> k;

        if (y > k) {
            std::cout << k << '\n';
            continue;
        }

        {
            int64_t nw = 1e12;

            for (int64_t i = 0; i < x && nw >= k;) {
                if (nw - (x - i) < k) {
                    nw = k - 1;
                    break;
                }
                
                if (nw - (x - i) * (nw / y) >= k)
                    break;

                int64_t ans = ((nw % y) + (nw / y) - 1) / (nw / y);

                if (ans == 0)
                    ans = 1;

                if (ans > x - i)
                    ans = x - i;

                nw -= (nw / y) * ans;

                i += ans;
            }

            if (nw < k) {
                std::cout << "-1\n";
                continue;
            }
        }

        int64_t l = k + x * (k / y), r = std::min((int64_t)1e12, (int64_t)1e12 - ((int64_t)1e12 - ((int64_t)1e12 / y) * x - k) + 1), ans = -1;
        while (l <= r) {
            int64_t m = l + r >> 1;

            int64_t nw = m;
            for (int64_t i = 0; i < x && nw >= k;) {
                if (nw - (x - i) < k) {
                    nw -= (x - i);
                    break;
                }
                
                if (nw - (x - i) * (nw / y) >= k) {
                    nw -= (x - i) * (nw / y);
                    break;
                }

                int64_t ans = ((nw % y) + (nw / y) - 1) / (nw / y);

                if (ans == 0)
                    ans = 1;

                if (ans > x - i)
                    ans = x - i;

                nw -= (nw / y) * ans;

                i += ans;
            }

            if (nw >= k)
                r = m - std::max((int64_t)1, (nw - k)), ans = (m - std::max((int64_t)1, (nw - k)) + 1);
            else
                l = m + k - nw;
        }

        std::cout << ans << '\n';
    }
    return 0;
}
