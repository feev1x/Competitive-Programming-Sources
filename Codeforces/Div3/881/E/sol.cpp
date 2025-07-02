/**
 *    author:  feev1x
 *    created: 30.06.2025 22:46:07
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<int> L(m + 1), R(m + 1);
        for (int i = 1; i <= m; ++i) {
            std::cin >> L[i] >> R[i];
        }

        int qq; std::cin >> qq;
        std::vector<int> q(qq + 1);
        for (int i = 1; i <= qq; ++i) {
            std::cin >> q[i];
        }

        int l = 1, r = qq, ans = -1;
        while (l <= r) {
            int _m = l + r >> 1;

            std::vector<int> a(n + 1);
            for (int i = 1; i <= _m; ++i) {
                a[q[i]] = 1;
            }

            for (int i = 1; i <= n; ++i) {
                a[i] += a[i - 1];
            }

            bool flag = false;
            for (int i = 1; i <= m; ++i) {
                int cnt1 = a[R[i]] - a[L[i] - 1], cnt0 = (R[i] - L[i] + 1) - cnt1;

                if (cnt1 > cnt0) {
                    flag = true;

                    break;
                }
            }

            if (flag) {
                r = _m - 1, ans = _m;
            } else {
                l = _m + 1;
            }
        }

        std::cout << ans << '\n';
    }
    return 0;
}
