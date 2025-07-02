/**
 *    author:  feev1x
 *    created: 26.03.2025 15:49:57
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int q; std::cin >> q;
    while (q--) {
        int n, k; std::cin >> n >> k;

        auto Calc = [](auto &&self, int n, int k) {
            if (n == 1) {
                return k;
            }

            if (k <= (n + 1) / 2) {
                if (2 * k > n) {
                    return (2 * k) % n;
                }

                return 2 * k;
            }

            int temp = self(self, n / 2, k - (n + 1) / 2);
            if (n & 1) {
                return 2 * temp + 1;
            }

            return 2 * temp - 1;
        };

        std::cout << Calc(Calc, n, k) << '\n';
    }
    return 0;
}
