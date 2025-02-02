/**
 *    author:  feev1x
 *    created: 29.01.2025 19:30:41
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::cout << (s[0] - '0') * (s[2] - '0') << '\n';
    return 0;
}
