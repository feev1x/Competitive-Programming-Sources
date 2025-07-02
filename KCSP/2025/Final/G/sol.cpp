/**
 *    author:  feev1x
 *    created: 15.06.2025 11:13:52
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<int> t(n + 1), e(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i];
        e[i] = e[i - 1] + t[i - 1];
    }

    int r1, l1;
    {
        int l = 1, r = 1e13, ans = -1;
        while (l <= r) {
            int m = l + r >> 1;

            bool flag = true;
            int sum = 0;
            for (int i = 1; i <= n; ++i) {
                if ((i - 1) * m > sum) {
                    flag = false;
                    break;
                }

                sum += t[i];
            }

            if (flag) {
                l = m + 1, ans = m;
            } else {
                r = m - 1;
            }
        }

        r1 = ans;
    }

    {
        int l = 1, r = 1e13, ans = -1;
        while (l <= r) {
            int m = l + r >> 1;

            bool flag = true;
            std::queue<int> q;
            for (int i = 1; i <= n; ++i) {
                q.emplace(e[i]);

                while (q.size() && (i - 1) * m >= q.front()) {
                    q.pop();
                }

                if (q.size() > k) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                r = m - 1, ans = m;
            } else {
                l = m + 1;
            }
        }

        l1 = ans;
    }
    
    if (l1 == -1 || r1 == -1 || l1 > r1) {
        std::cout << "-1\n";

        exit(0);
    }

    std::cout << r1 << '\n';
    return 0;
}
