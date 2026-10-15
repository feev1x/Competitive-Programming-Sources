#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    if (n == 1) return std::cout << a[0] << '\n', 0;
    std::sort(a.begin(), a.end());
    if (n & 1) {
        if ((a[n / 2] + a[n / 2 - 1]) % 2 == 0) {
            std::cout << a[n / 2] << ' ' << a[n / 2 - 1] << ' ';
            for (int i = 0; i < n / 2 - 1; ++i) std::cout << a[i] << ' ' << a[n - i - 1] << ' ';
            std::cout << a[n / 2 + 1] << '\n';
        } else if ((a[n / 2] + a[n / 2 + 1]) % 2 == 0) {
            std::cout << a[n / 2] << ' ' << a[n / 2 + 1] << ' ';
            for (int i = 0; i < n / 2 - 1; ++i) std::cout << a[i] << ' ' << a[n - i - 1] << ' ';
            std::cout << a[n / 2 - 1] << '\n';
        } else {
            std::cout << a[n / 2 + 1] << ' ' << a[n / 2 - 1] << ' ';
            for (int i = 0; i < n / 2 - 1; ++i) std::cout << a[i] << ' ' << a[n - i - 1] << ' ';
            std::cout << a[n / 2] << '\n';
        }
    } else {
        if ((a[n / 2] + a[n / 2 - 1]) & 1) return std::cout << "-1\n", 0;
        std::cout << a[n / 2] << ' ' << a[n / 2 - 1] << ' ';
        for (int i = 0; i < n / 2 - 1; ++i) std::cout << a[i] << ' ' << a[n - i - 1] << ' ';
        std::cout << '\n';
    }
    return 0;
}
