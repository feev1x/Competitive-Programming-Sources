/**
 *    author:  feev1x
 *    created: 29.01.2025 19:31:46
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t x; std::cin >> x;

    int64_t fac = 1;
    for (int64_t i = 2; ; ++i) {
        fac *= i;

        if (fac == x) {
            std::cout << i << '\n';

            exit(0);
        }
    }
    return 0;
}
