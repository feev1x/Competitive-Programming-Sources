/**
 *    author:  feev1x
 *    created: 19.01.2025 20:36:34
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        std::vector<int> a(6, -500);

        for (int i = 1; i <= 2; ++i) {
            std::cin >> a[i];
        }

        for (int i = 4; i <= 5; ++i) {
            std::cin >> a[i];
        }

        int res = 0;
        for (; a[3] <= 500; ++a[3]) {
            int cnt = 0;

            for (int i = 1; i <= 3; ++i) {
                cnt += a[i + 2] == a[i] + a[i + 1];
            }

            res = std::max(res, cnt);
        }

        std::cout << res << '\n';
    }
    return 0;
}
