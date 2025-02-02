/**
 *    author:  feev1x
 *    created: 22.01.2025 18:06:11
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int l, r; std::cin >> l >> r;
        
        std::cout << r - l + (l == r && l == 1) << '\n';
    }
    return 0;
}
