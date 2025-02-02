/**
 *    author:  feev1x
 *    created: 26.01.2025 20:36:10
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        std::string s; std::cin >> s;

        std::cout << std::count(s.begin(), s.end(), '1') << '\n';
    }
    return 0;
}
