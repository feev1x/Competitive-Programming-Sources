/**
 *    author:  feev1x
 *    created: 14.11.2025 20:54:51
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int64_t res = 0, mx = 0, nw = 0;
        for (int i = 1; i <= n; ++i) {
            int u; std::cin >> u;

            res += u;

            mx = std::max(mx + 2 * i - u, int64_t(0));

            nw = std::max(nw, mx);
        }

        std::cout << res + nw << '\n';
    }
    return 0;
}
