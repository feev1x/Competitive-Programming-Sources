/**
 *    author:  feev1x
 *    created: 20.02.2025 14:08:53
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int n = s.size(), res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'A') {
            continue;
        }

        for (int j = i + 1; j < n; ++j) {
            if (s[j] != 'B') {
                continue;
            }
            
            res += s[2 * j - i] == 'C';
        }
    }

    std::cout << res << '\n';
    return 0;
}
