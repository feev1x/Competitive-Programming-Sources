/**
 *    author:  feev1x
 *    created: 15.06.2025 10:34:37
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int p; std::cin >> p;

    for (int i = 1; i <= p; ++i) {
        if (2 * i + 2 * i - 1 >= p) {
            std::cout << i << '\n';

            exit(0);
        }
    }
    return 0;
}
