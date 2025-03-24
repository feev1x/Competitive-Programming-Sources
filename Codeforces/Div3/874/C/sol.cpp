/**
 *    author:  feev1x
 *    created: 06.03.2025 14:14:04
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        std::sort(a.begin(), a.end());

        bool flag = true;
        if (a[0] & 1) {
            // skip
        } else {
            for (auto u: a) {
                if (u & 1) {
                    flag = false;

                    break;
                }
            }
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
