/**
 *    author:  feev1x
 *    created: 16.05.2025 13:31:53
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int r, x; std::cin >> r >> x;

    if (x == 2) {
        std::cout << (1200 <= r && r < 2400 ? "Yes\n" : "No\n");
    } else {
        std::cout << (1600 <= r && r < 3000 ? "Yes\n" : "No\n");
    }

    return 0;
}
