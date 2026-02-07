/**
 *    author:  feev1x
 *    created: 24.11.2025 15:08:55
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> cnt(n + 1);
        for (int i = 1; i <= n; ++i) {
            int u; std::cin >> u;

            cnt[u]++;
        }

        int res = 0;
        for (int i = 0; i <= n; ++i)
            if (cnt[i] >= i)
                res += cnt[i] - i;
            else
                res += cnt[i];

        std::cout << res << '\n';
    }
    return 0;
}
