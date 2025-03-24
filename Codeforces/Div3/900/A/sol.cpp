/**
 *    author:  feev1x
 *    created: 05.03.2025 16:28:45
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        bool flag = false;
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;

            if (k == u) {
                flag = true;
            }
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
