#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    if (n == 2) {
        std::cout << "-1\n";
        exit(0);
    }

    if (n & 1) {
        std::cout << (n + 1) / 2 << '\n';

        for (int i = 1; i <= n / 2; ++i) {
            std::cout << "2 " << i << ' ' << n - i << '\n';
        }

        std::cout << "1 " << n << '\n';
    } else {
        std::cout << n / 2 << '\n';

        for (int i = 1; i <= n / 2; ++i) {
            std::cout << "2 " << i << ' ' << n - i + 1 << '\n';
        }
    }

    return 0;
}
