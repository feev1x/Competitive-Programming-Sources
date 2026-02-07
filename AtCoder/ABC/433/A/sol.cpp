/**
 *    author:  feev1x
 *    created: 24.11.2025 15:55:59
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x, y, z; std::cin >> x >> y >> z;

    int n = (x - z * y) / (z - 1);

    std::cout << (n < 0 || (x + n) != z * (y + n) ? "No" : "Yes") << '\n';
    return 0;
}
