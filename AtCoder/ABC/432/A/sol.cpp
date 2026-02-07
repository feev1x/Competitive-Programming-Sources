/**
 *    author:  feev1x
 *    created: 15.11.2025 18:00:36
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> a(3);
    for (auto &u: a)
        std::cin >> u;

    std::sort(a.begin(), a.end(), std::greater<>());

    for (auto u: a)
        std::cout << u;
    
    std::cout << '\n';
    return 0;
}
