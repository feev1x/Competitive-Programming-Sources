/**
 *    author:  feev1x
 *    created: 13.06.2025 13:32:22
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        int64_t k; std::cin >> k;

        std::vector<int64_t> a(n);

        for (auto &u: a) {
            std::cin >> u;
        }

        for (int64_t bp = 0; bp < 64; ++bp) {
            bool flag = true;

            for (auto &u: a) {
                if (u >> bp & 1) {
                    continue;
                }

                int64_t nd = 1ll << bp;

                if (k >= nd) {
                    u += nd;
                    k -= nd;
                } else {
                    flag = false;
                    break;
                }
            }


            if (!flag) {
                break;
            }
        }

        int res = 0;
        for (auto u: a) {
            res += __builtin_popcountll(u);
        }

        std::cout << res << '\n';
    }

    return 0;
}
