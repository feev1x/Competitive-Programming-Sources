/**
 *    author:  feev1x
 *    created: 20.11.2025 02:25:59
**/
#include <bits/stdc++.h>

inline void chmax(int &a, int b) {
    if (a < b)
        a = b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;
    while (tt--) {
        std::map<std::pair<int, int>, int> mp;

        auto Ask = [&](int l, int r) {
            if (!mp.count({l, r})) {
                std::cout << "? " << l << ' ' << r << std::endl;

                int got; std::cin >> got;

                mp[{l, r}] = got;
            }

            return mp[{l, r}];
        };

        int n, q; std::cin >> n >> q;

        std::vector<std::pair<int, int>> qq(q);
        for (auto &[l, r]: qq)
            std::cin >> l >> r;

        std::sort(qq.begin(), qq.end());

        std::vector<std::pair<int, int>> new_qq;

        int max = -1;
        for (auto [l, r]: qq) {
            if (max >= r)
                continue;

            new_qq.emplace_back(l, r);

            max = r;
        }

        std::swap(qq, new_qq);

        int l = 0, r = qq.size() - 1, ans = -1;
        while (l <= r) {
            if (l == r) {
                chmax(ans, Ask(qq[l].first, qq[r].second));
                break;
            }

            int m = l + r >> 1;

            int a = Ask(1, qq[m].second), b = Ask(qq[m].first, n);

            chmax(ans, std::min(a, b));
            if (a < b)
                l = m + 1;
            else
                r = m - 1;
        }

        std::cout << "! " << ans << std::endl;
    }
    return 0;
}
