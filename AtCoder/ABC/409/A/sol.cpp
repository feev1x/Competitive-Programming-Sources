/**
 *    author:  feev1x
 *    created: 13.06.2025 15:11:42
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::string s, t; std::cin >> s >> t;

    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i] && s[i] == 'o') {
            std::cout << "Yes\n";
            exit(0);
        }
    }

    std::cout << "No\n";
    return 0;
}
