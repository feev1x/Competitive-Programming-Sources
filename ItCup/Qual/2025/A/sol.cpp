/**
 *    author:  feev1x
 *    created: 06.04.2025 11:06:35
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    if (n == 1) {
        std::cout << a.front() << '\n';

        exit(0);
    }

    std::sort(a.begin(), a.end());

    if (n & 1) {
        if ((a[n / 2] + a[n / 2 + 1]) % 2 == 0) {
            std::cout << a[n / 2 + 1] << ' ' << a[n / 2] << ' ';

            for (int i = 0, j = n - 1; i < n / 2 - 1 && j > n / 2 + 1; ++i, --j) {
                std::cout << a[i] << ' ' << a[j] << ' ';
            }

            std::cout << a[n / 2 - 1] << '\n';
        } else if ((a[n / 2] + a[n / 2 - 1]) % 2 == 0) {
            std::cout << a[n / 2 - 1] << ' ' << a[n / 2] << ' ';

            for (int i = 0, j = n - 1; i < n / 2 - 1 && j > n / 2 + 1; ++i, --j) {
                std::cout << a[i] << ' ' << a[j] << ' ';
            }

            std::cout << a[n / 2 + 1] << '\n';
        } else {
            std::cout << a[n / 2 - 1] << ' ' << a[n / 2 + 1] << ' ';

            for (int i = 0, j = n - 1; i < n / 2 - 1 && j > n / 2 + 1; ++i, --j) {
                std::cout << a[i] << ' ' << a[j] << ' ';
            }

            std::cout << a[n / 2] << '\n';
        }
    } else {
        if ((a[n / 2] + a[n / 2 - 1]) & 1) {
            std::cout << "-1\n";

            exit(0);
        }

        std::cout << a[n / 2] << ' ' << a[n / 2 - 1];

        for (int i = 0, j = n - 1; i < n / 2 - 1 && j > n / 2; ++i, --j) {
            std::cout << ' ' << a[i] << ' ' << a[j];
        }

        std::cout << '\n';
    }
    return 0;
}
