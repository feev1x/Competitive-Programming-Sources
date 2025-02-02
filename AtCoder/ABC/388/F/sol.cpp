/**
 *    author:  feev1x
 *    created: 11.01.2025 19:10:05
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; int m, a, b; std::cin >> n >> m >> a >> b;    
    std::vector<int> l(m), r(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> l[i] >> r[i];
    }

    auto Check = [&](int i) {
        int j = std::upper_bound(l.begin(), l.end(), i) - l.begin() - 1;

        if (j < m && j >= 0 && r[j] >= i && l[j] <= i) {
            return false;
        }

        return true;
    };

    int mask = 1, st = 1;
    for (int i = 0; i < m; ++i) {
        int new_mask = 0;

        for (int j = 0; j < b; ++j) {
            if (!Check(r[i] + j + 1)) {
                continue;
            }

            for (int k = 0; k < b; ++k) {
                if (!(mask >> k & 1)) {
                    continue;
                }

                if (st + k == r[i] + j + 1) {
                    new_mask |= 1 << j;
                    break;
                }

                if (st + k >= l[i]) {
                    continue;
                }

                int cnt = (l[i] - 1 - st - k) / a;
                int left = st + k + a * cnt, right = std::min(l[i] - 1, left + cnt * (b - a));

                if (left + a <= r[i] + j + 1 && right + b >= r[i] + j + 1) {
                    new_mask |= 1 << j;
                    break;
                }
            }
        }

        mask = new_mask;
        if (!mask) {
            std::cout << "No\n";
            exit(0);
        }

        st = r[i] + 1;
    }


    for (int i = 0; i < b; ++i) {
        if (!(mask >> i & 1)) {
            continue;
        }

        int cnt = (n - st - i) / a;
        int left = st + i + a * cnt;

        if (left + cnt * (b - a) >= n && n >= left) {
            std::cout << "Yes\n";
            exit(0);
        }
    }

    std::cout << "No\n";
    return 0;
}
