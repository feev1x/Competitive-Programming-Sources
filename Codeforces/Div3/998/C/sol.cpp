/**
 *    author:  feev1x
 *    created: 19.01.2025 20:51:40
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> cnt(n + 1);
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;

            cnt[u]++;
        }

        int res = 0;
        for (int i = 1; i <= std::min(n, k / 2); ++i) {
            if (k % 2 == 0 && i == k / 2) {
                res += cnt[i] / 2;
            } else if (k - i <= n) {
                res += std::min(cnt[i], cnt[k - i]);
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
