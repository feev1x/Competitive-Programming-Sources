/**
 *    author:  feev1x
 *    created: 27.07.2025 20:52:47
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n; std::cin >> n;

        std::vector<int64_t> a(n);
        for (auto &u: a)
            std::cin >> u;

        int64_t res = 1;
        for (int64_t i = 0; i + 1 < n; ++i) {
            res++;

            res += (n - i - 1) * (n - i) / 2;

            res += (n - i - 1);
        }

        for (int64_t i = 0; i + 1 < n; ++i) {
            if (a[i] < a[i + 1]) {
                res -= (i + 1) * (n - i - 1);
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
