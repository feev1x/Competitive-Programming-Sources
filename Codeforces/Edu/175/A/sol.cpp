/**
 *    author:  feev1x
 *    created: 27.02.2025 20:36:18
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        
        int num = n / 15 * 15, cnt = n / 15;

        std::cout << std::min(n - num + 1, 3) + cnt * 3 << '\n';
    }
    return 0;
}
