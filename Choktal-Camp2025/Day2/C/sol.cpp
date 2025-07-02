/**
 *    author:  feev1x
 *    created: 02.07.2025 10:58:40
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<int, int> mp;
    auto Ask = [&](int p) {
        if (mp.count(p)) {
            return mp[p];
        }

        std::cout << "? " << p << std::endl;

        int64_t got; std::cin >> got;
        if (got == -1) {
            assert(false);
        }

        mp[p] = got;
        return got;
    };
    
    int tt; std::cin >> tt;
    while (tt--) {
        mp.clear();
        int64_t n, k; std::cin >> n >> k;

        n = std::min(n, n * (n + 1) / 2 - Ask(n));
        std::vector<int> res(1);

        int64_t sum = 0;
        for (int _ = 0; _ < k; ++_) {
            int l = res.back() + 1, r = n, ans = -1;

            while (l <= r) {
                int m = l + r >> 1;

                int got = Ask(m);

                if (got < m * (m + 1) / 2 - sum) {
                    r = m - 1, ans = m;

                    if (m * (m + 1) / 2 - sum - got < l * 2 + 1) {
                        ans = m * (m + 1) / 2 - sum - got;

                        break;
                    }
                } else {
                    l = m + 1;
                }
            }

            sum += ans;
            res.emplace_back(ans);
        }

        std::cout << "! ";
        for (int i = 1; i <= k; ++i) {
            std::cout << res[i] << ' ';
        }

        std::cout << std::endl;

        int got; std::cin >> got;
        if (got == -1) {
            assert(false);
        }
    }
    return 0;
}
