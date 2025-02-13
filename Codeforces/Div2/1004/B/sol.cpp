/**
 *    author:  feev1x
 *    created: 11.02.2025 20:43:01
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::map<int, int> mp;
        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;

            mp[u]++;
        }

        int ls = 0, cnt = 0;
        for (auto [key, val]: mp) {
            if (val == 1) {
                goto NO;
            }

            if (val > 2) {
                mp[key + 1] += (val - 2);
                val = 2;
            }

            ls = key, cnt = val;
        }

        if (cnt & 1) {
            goto NO;
        }


        std::cout << "YES\n";
        continue;
NO:
        std::cout << "NO\n";
    }
    return 0;
}
