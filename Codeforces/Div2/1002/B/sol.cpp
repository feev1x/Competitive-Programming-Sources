/**
 *    author:  feev1x
 *    created: 02.02.2025 20:42:29
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        int res = k / 2 + 1;
        for (int i = 2; i <= n; ++i) {
            int u = a[i];

            if (n == k) {
                if (i & 1) {
                    continue;
                }

                if (u == i / 2) {
                    continue;
                }

                res = i / 2;

                break;
            } else {
                int mx = std::min(k / 2, (i + 1) / 2), mn = std::max(1, (k - (n - i) + 1) / 2);

                if (mx == mn && mx == u) {
                    continue;
                }

                if (mn == u) {
                    res = std::min(res, mn + 1);
                } else {
                    res = std::min(res, mn);
                }
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
