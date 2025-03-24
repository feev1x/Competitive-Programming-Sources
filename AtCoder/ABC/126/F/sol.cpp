/**
 *    author:  feev1x
 *    created: 20.03.2025 11:33:49
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int m, k; std::cin >> m >> k;

    if ((1 << m) - 1 < k || m == 1 && k != 0) {
        std::cout << "-1\n";

        exit(0);
    }

    if (k == 0) {
        for (int i = 0; i < (1 << m); ++i) {
            std::cout << i << ' ' << i << " \n"[i == (1 << m) - 1];
        }

        exit(0);
    }

    for (int i = 0; i < (1 << m); ++i) {
        if (i == k) {
            continue;
        }

        std::cout << i << ' ';
    }

    std::cout << k << ' ';

    for (int i = (1 << m) - 1; i >= 0; --i) {
        if (i == k) {
            continue;
        }

        std::cout << i << ' ';
    }

    std::cout << k << '\n';
    return 0;
}
