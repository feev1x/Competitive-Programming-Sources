/**
 *    author:  feev1x
 *    created: 30.06.2025 22:59:08
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int64_t sum = 0, cnt = 0;
        std::vector<int64_t> a(n + 1);

        bool nap = false;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            sum += std::abs(a[i]);

            if (a[i] > 0 && nap) {
                nap = false;
            } else if (a[i] < 0 && !nap) {
                nap = true;
                cnt++;
            }
        }

        std::cout << sum << ' ' << cnt << '\n';
    }
    return 0;
}
