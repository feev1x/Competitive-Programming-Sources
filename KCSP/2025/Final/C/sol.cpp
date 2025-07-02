/**
 *    author:  feev1x
 *    created: 15.06.2025 10:44:13
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t x[4], y[4]; 
    for (int i = 0; i < 4; ++i) {
        std::cin >> x[i] >> y[i];
    }

    int64_t df = std::abs(x[0] - x[1]) * std::abs(x[0] - x[1]) + std::abs(y[0] - y[1]) * std::abs(y[0] - y[1]);
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;

        if (std::abs(x[i] - x[j]) * std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) * std::abs(y[i] - y[j]) != df) {
            std::cout << "NO\n";

            exit(0);
        }

        j = (i - 1 + 4) % 4;
        if (std::abs(x[i] - x[j]) * std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) * std::abs(y[i] - y[j]) != df) {
            std::cout << "NO\n";

            exit(0);
        }
    }

    if (df <= 0) {
        std::cout << "NO\n";

        exit(0);
    }

    df = std::abs(x[0] - x[2]) * std::abs(x[0] - x[2]) + std::abs(y[0] - y[2]) * std::abs(y[0] - y[2]);
    for (int i = 0; i < 4; ++i) {
        int j = (i + 2) % 4;

        if (std::abs(x[i] - x[j]) * std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) * std::abs(y[i] - y[j]) != df) {
            std::cout << "NO\n";
            exit(0);
        }
    }

    if (df <= 0) {
        std::cout << "NO\n";

        exit(0);
    }

    std::cout << "YES\n";
    return 0;
}
