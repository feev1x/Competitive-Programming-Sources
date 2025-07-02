/**
 *    author:  feev1x
 *    created: 29.03.2025 20:51:11
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int64_t sum = 0, cnt_o = 0, mx = 0;
        std::vector<int64_t> a(n);
        for (auto &u: a) {
            std::cin >> u;

            sum += u;
            mx = std::max(mx, u);
            cnt_o += (u & 1);
        }

        if (cnt_o % n == 0) {
            std::cout << mx << '\n';

            continue;
        }

        std::cout << sum - cnt_o + 1 << '\n';
    }
    return 0;
}
