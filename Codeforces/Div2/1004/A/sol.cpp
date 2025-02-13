/**
 *    author:  feev1x
 *    created: 11.02.2025 20:35:57
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int x, y; std::cin >> x >> y;

        if (x > y) {
            if ((x - y) % 9 == 8) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            if (y - x == 1) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}
