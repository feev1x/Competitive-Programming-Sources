/**
 *    author:  feev1x
 *    created: 02.02.2025 11:04:49
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::pair<int64_t, char>> a(n);
    int64_t w = 1;
    for (auto &[u, v]: a) {
        std::cin >> u >> v;

        if (v == 'G') {
            w = std::max(w, u);
        }
    }

    for (auto [u, v]: a) {
        if (v == 'Y') {
            if (u <= w) {
                std::cout << "-1\n";

                exit(0);
            }

            if (u > 2 * w) {
                w += (u - 2 * w + 1) / 2;
            }
        }
    }

    for (auto [u, v]: a) {
        if (v == 'R') {
            if (u <= 2 * w) {
                std::cout << "-1\n";

                exit(0);
            }

            if (u > 3 * w) {
                w += (u - 3 * w + 2) / 3;
            }
        }
    }

    for (auto [u, v]: a) {
        if (v == 'Y') {
            if (u <= w) {
                std::cout << "-1\n";

                exit(0);
            }
        }

        if (v == 'R') {
            if (u <= 2 * w) {
                std::cout << "-1\n";
                
                exit(0);
            }
        }

        if (v == 'B') {
            if (u <= 3 * w) {
                std::cout << "-1\n";

                exit(0);
            }
        }
    }

    std::cout << w << ' ';

    int64_t w1 = 2e9, w2 = 2e9, w3 = 2e9;
    for (auto [u, v]: a) {
        if (v == 'Y') {
            w1 = std::min(w1, u - 1);
        }
    }

    for (auto [u, v]: a) {
        if (v == 'R') {
            w2 = std::min(w2, (u + 1) / 2 - 1);
        }
    }

    for (auto [u, v]: a) {
        if (v == 'B') {
            w3 = std::min(w3, (u + 2) / 3 - 1);
        }
    }

    std::cout << std::min({w1, w2, w3}) << '\n';
    return 0;
}
