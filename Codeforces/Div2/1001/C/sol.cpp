/**
 *    author:  feev1x
 *    created: 26.01.2025 20:45:37
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        auto Sum = [](std::vector<int64_t> a) {
            int64_t n = a.size(), sum = 0;

            for (int i = 1; i < n; ++i) {
                sum += a[i] - a[i - 1];
            }

            return std::abs(sum);
        };

        std::vector<int64_t> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        int64_t res = accumulate(a.begin(), a.end(), 0ll);
        while (n > 1) {
            res = std::max(res, Sum(a));

            std::vector<int64_t> b;
            for (int i = 1; i < n; ++i) {
                b.emplace_back(a[i] - a[i - 1]);
            }

            n--;
            a = b;
        }

        std::cout << res << '\n';
    }
    return 0;
}
