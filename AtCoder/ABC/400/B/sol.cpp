/**
 *    author:  feev1x
 *    created: 05.04.2025 18:07:09
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n, m; std::cin >> n >> m;

    int64_t x = 0;

    for (int i = 0; i <= m && x <= 1e9; ++i) {
        x += pow(n, i);
    }

    if (x > 1e9) {
        std::cout << "inf\n";
    } else {
        std::cout << x << '\n';
    }
    return 0;
}
