/**
 *    author:  feev1x
 *    created: 11.02.2025 21:35:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> x(n + 1), cnt(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> x[i];

            cnt[x[i]] = 1;
            pos[x[i]] = i;
        }

        auto Ask = [&](int i, int j) {
            std::cout << "? " << i << ' ' << j << std::endl;

            int got; std::cin >> got;

            return got;
        };

        int ind = -1;
        for (int i = 1; i <= n; ++i) {
            if (!cnt[i]) {
                ind = i;

                break;
            }
        }

        if (ind == -1) {
            int g1 = Ask(pos[1], pos[n]), g2 = Ask(pos[n], pos[1]);
         
            if (g1 == g2 && g1 && g1 >= n - 1) {
                std::cout << "! B" << std::endl;
            } else {
                std::cout << "! A" << std::endl;
            }
        } else {
            if (!Ask(ind, ind == n ? ind - 1 : ind + 1)) {
                std::cout << "! A" << std::endl;
            } else {
                std::cout << "! B" << std::endl;
            }
        }
    }
    return 0;
}
