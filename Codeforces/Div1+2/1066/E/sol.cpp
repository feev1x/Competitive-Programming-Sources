/**
 *    author:  feev1x
 *    created: 24.11.2025 13:48:08
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::map<int, int> mp, next, one;
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;

            mp[u]++;
        }
        
        int res = 0, ls = -1;

        mp[10 * n] = 1;

        std::vector<int> vec;
        for (auto [key, val]: mp) {
            if (ls != -1)
                next[ls] = key;

            vec.emplace_back(key);
            ls = key;
        }

        std::reverse(vec.begin(), vec.end());
        for (auto u: vec) {
            int nw = u, cnt = mp[u];

            while (cnt > 1) {
                int nx = next[nw], pos = (u == nw ? u : one[nw]);

                if (cnt > k && cnt - (nx - pos - 1) <= k)
                    res = std::max(res, cnt - k + pos - u);

                if (cnt - (nx - pos - 1) <= 1) {
                    one[u] = cnt - 1 + pos;
                    next[u] = nx;
                    break;
                }

                nw = nx;
                cnt -= (nx - pos - 1);
            }

            if (!one.count(u))
                one[u] = u;
        }

        std::cout << res << '\n';
    }
    return 0;
}
