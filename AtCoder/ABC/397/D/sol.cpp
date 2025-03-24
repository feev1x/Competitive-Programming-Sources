/**
 *    author:  feev1x
 *    created: 15.03.2025 18:13:55
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; std::cin >> n;

    auto Cube = [&](int i) {
        return (int64_t)i * i * i;
    };

    int j = 1;
    for (int i = 1; i <= 7e8; ++i) {
        while (Cube(i) - Cube(j) > n) {
            j++;
        }

        if (Cube(i) - Cube(j) == n) {
            std::cout << i << ' ' << j << '\n';

            exit(0);
        }
    }

    std::cout << "-1\n";
    return 0;
}
