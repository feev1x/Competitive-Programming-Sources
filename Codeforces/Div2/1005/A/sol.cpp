/**
 *    author:  feev1x
 *    created: 16.02.2025 20:36:58
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::string s, s1; std::cin >> s;

        for (int i = 0; i < n; ++i) {
            if (s1.empty() || s1.back() != s[i]) {
                s1 += s[i];
            }
        }

        if (s1.front() == '0') {
            std::cout << s1.size() - 1 << '\n';
        } else {
            std::cout << s1.size() << '\n';
        }
    }
    return 0;
}
