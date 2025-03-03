/**
 *    author:  feev1x
 *    created: 20.02.2025 14:04:12
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s1, s2; std::cin >> s1 >> s2;

    if (s1 == "sick" && s2 == "sick") {
        std::cout << "1\n";
    } else if (s1 == "sick" && s2 == "fine") {
        std::cout << "2\n";
    } else if (s1 == "fine" && s2 == "sick") {
        std::cout << "3\n";
    } else {
        std::cout << "4\n";
    }
    return 0;
}
