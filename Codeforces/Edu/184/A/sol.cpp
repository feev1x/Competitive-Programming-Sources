/**
 *    author:  feev1x
 *    created: 14.11.2025 20:37:08
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, a; std::cin >> n >> a;

        int sm = 0, bg = 0;
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;

            if (u > a)
                bg++;
            else if (u < a)
                sm++;
        }

        if (bg > sm)
            std::cout << a + 1 << '\n';
        else
            std::cout << a - 1 << '\n';
    }
    return 0;
}
