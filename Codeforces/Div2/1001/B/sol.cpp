/**
 *    author:  feev1x
 *    created: 26.01.2025 20:38:09
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        bool flag = true;
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;
            
            if (u <= 2 * i || u <= 2 * (n - i - 1)) {
                flag = false;
            }
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
