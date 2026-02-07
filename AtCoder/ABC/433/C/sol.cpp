/**
 *    author:  feev1x
 *    created: 24.11.2025 16:03:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;
    
    int res = 0, n = s.size();
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] + 1 == s[i + 1]) {
            int l = i, r = i + 1;

            while (l >= 0 && r < n && s[l] + 1 == s[r] && s[l] == s[i])
                res++, l--, r++;
        }
    }

    std::cout << res << '\n';
    return 0;
}
