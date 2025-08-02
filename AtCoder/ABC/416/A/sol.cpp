/**
 *    author:  feev1x
 *    created: 26.07.2025 18:00:35
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l, r; std::cin >> n >> l >> r; --l, --r;

    std::string s; std::cin >> s;

    for (int i = l; i <= r; ++i)
        if (s[i] != 'o') {
            std::cout << "No\n";

            exit(0);
        }

    std::cout << "Yes\n";
    return 0;
}
