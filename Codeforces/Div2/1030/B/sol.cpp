/**
 *    author:  feev1x
 *    created: 13.06.2025 13:14:11
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::cout << 2 * n - 1 << '\n';
        for (int i = 1; i <= n; ++i) {
            std::cout << i << " 1 " << i << '\n';
            
            if (i != n)
                std::cout << i << ' ' << i + 1 << ' ' << n << '\n';
        }
    }
    return 0;
}
