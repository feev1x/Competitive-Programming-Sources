/**
 *    author:  feev1x
 *    created: 10.02.2025 15:15:44
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, c; std::cin >> a >> b >> c;

    if (a * b == c || b * c == a || a * c == b) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}
