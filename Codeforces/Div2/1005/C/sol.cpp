/**
 *    author:  feev1x
 *    created: 16.02.2025 21:05:19
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int64_t> a(n), neg(n), pos(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        int l = 0, r = n - 1;
        for (int i = l; i <= r; ++i) {
            if (i) {
                pos[i] = pos[i - 1];
            }

            if (a[i] > 0) {
                pos[i] += a[i];
            }
        }


        for (int i = r; i >= l; --i) {
            if (i + 1 < n) {
                neg[i] = neg[i + 1];
            }

            if (a[i] < 0) {
                neg[i] += -a[i];
            }
        }

        int64_t ans = 0;
        for (int i = l; i <= r; ++i) {
            ans = std::max(ans, pos[i] + neg[i]);
        }

        std::cout << ans << '\n';
    }
    return 0;
}
