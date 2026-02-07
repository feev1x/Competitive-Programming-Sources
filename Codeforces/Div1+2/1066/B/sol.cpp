/**
 *    author:  feev1x
 *    created: 24.11.2025 15:06:05
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, x, y; std::cin >> n >> x >> y;

        std::string s; std::cin >> s;

        x = std::abs(x);
        y = std::abs(y);
        for (auto u: s) {
            if (x > y)
                std::swap(x, y);


            if (u == '4')
                y--;
            else
                x--, y--;
        }

        std::cout << (x <= 0 && y <= 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}
