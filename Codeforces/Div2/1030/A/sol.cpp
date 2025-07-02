/**
 *    author:  feev1x
 *    created: 13.06.2025 13:05:51
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            std::cout << (i < k ? "1" : "0");
        }

        std::cout << '\n';
    }

    return 0;
}
