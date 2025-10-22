/**
 *    author:  feev1x
 *    created: 29.03.2025 18:00:36
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::string s, t; std::cin >> s >> t;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
