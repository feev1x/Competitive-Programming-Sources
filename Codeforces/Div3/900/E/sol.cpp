/**
 *    author:  feev1x
 *    created: 05.03.2025 17:10:11
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        std::vector<std::array<int, 30>> rr(n + 2);
        for (int j = 0; j < 30; ++j) {
            rr[n + 1][j] = n;
        }

        for (int i = n; i >= 1; --i) {
            for (int j = 0; j < 30; ++j) {
                if (a[i] >> j & 1) {
                    rr[i][j] = rr[i + 1][j];
                } else {
                    rr[i][j] = i - 1;
                }
            }
        }

        int q; std::cin >> q;
        while (q--) {
            int l, k; std::cin >> l >> k;

            int r = n, opt = -1;
            for (int j = 29; j >= 0; --j) {
                if (k >> j & 1) {
                    r = std::min(r, rr[l][j]);
                } else {
                    opt = std::max(opt, std::min(rr[l][j], r));
                }
            }

            opt = std::max(opt, r);

            if (opt < l) {
                opt = -1;
            }

            std::cout << opt << " \n"[!q];
        }
    }
    return 0;
}
