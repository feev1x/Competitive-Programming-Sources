/**
 *    author:  feev1x
 *    created: 10.03.2025 13:34:32
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int q; std::cin >> q;
    while (q--) {
        int n, k; std::cin >> n >> k;

        int l = 0, r = n - 1, d = 1, nw = 1, cnt = 0;
        while (cnt < k) {
            if ((int64_t)d * 2 * (k - cnt) + nw < n) {
                std::cout << d * 2 * (k - cnt) + nw + 1 << '\n';

                exit(0);
            }

            int sz = (r - l + 1) / d;

            nw = ((int64_t)d * 2 * (sz + 1) / 2 + nw) % r;


        }

        std::cout << "-1\n";
    }
    return 0;
}
