/**
 *    author:  feev1x
 *    created: 19.01.2025 21:04:31
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int ls = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;

            if (u < ls) {
                flag = false;
            }

            u -= ls;
            ls = u;
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
