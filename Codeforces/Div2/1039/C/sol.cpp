/**
 *    author:  feev1x
 *    created: 27.07.2025 20:48:57
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        
        int mn = 1e9;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;

            if (u >= mn * 2)
                flag = false;

            mn = std::min(mn, u);
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
