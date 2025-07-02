/**
 *    author:  feev1x
 *    created: 05.04.2025 18:05:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a; std::cin >> a;

    if (400 % a == 0) {
        std::cout << 400 / a << '\n';
    } else {
        std::cout << "-1\n";
    }
    return 0;
}
