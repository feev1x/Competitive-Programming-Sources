/**
 *    author:  feev1x
 *    created: 15.03.2025 18:01:14
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long double x; std::cin >> x;

    if (x >= 38.0) {
        std::cout << "1\n";
    } else if (x >= 37.5) {
        std::cout << "2\n";
    } else {
        std::cout << "3\n";
    }
    return 0;
}
