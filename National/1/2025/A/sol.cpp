/**
 *    author:  feev1x
 *    created: 26.01.2025 11:32:57
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::string res;
    for (int i = 0; i < s.size(); i += 2) {
        for (int j = 0; j < s[i] - '0'; ++j) {
            res += s[i + 1];
        }
    }

    std::cout << res << '\n';
    return 0;
}
