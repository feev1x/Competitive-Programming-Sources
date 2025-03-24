/**
 *    author:  feev1x
 *    created: 06.03.2025 15:58:11
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;    

    int cnt = count(s.begin(), s.end(), '2') + 1;

    while (cnt--) {
        std::cout << "2\n"[!cnt];
    }
    return 0;
}
