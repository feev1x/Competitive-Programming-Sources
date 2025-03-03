/**
 *    author:  feev1x
 *    created: 28.02.2025 22:00:36
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n, l, r; std::cin >> n >> l >> r;

        std::vector<int> a(n + 1), p(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            p[i] = p[i - 1] ^ a[i];
        }


        auto Ans = [&](auto &&self, int64_t i) -> bool {
            if (n >= i) {
                return a[i];
            }

//            if (tt == 6) {
//                std::cout << "T " << ' ' << i << '\n';
//            }
            if (i / 2 <= n) {
                return p[i / 2];
            }

            if (n & 1) {
                if ((i / 2) & 1) {
                    return p[n];
                } else {
                    return p[n] ^ self(self, i / 2);
                }
            } else {
                if ((i / 2) & 1) {
                    return p[n] ^ self(self, n + 1);
                } else {
                    return p[n] ^ self(self, n + 1) ^ self(self, i / 2);
                }
            }
        };

        std::cout << Ans(Ans, l) << '\n';
    }
    return 0;
}
