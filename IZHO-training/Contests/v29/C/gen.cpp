#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int> (l, r) (rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q = rnd(1, 5), m = rnd(1, 5);
    int n = rnd(1, 5); std::cout << n << ' ' << m << ' ' << q << '\n';

    for (int i = 0; i < n; ++i) {
        std::cout << rnd(1, 10) << " \n"[i == n - 1];
    }

    for (int i = 0; i < m; ++i) {
        int l = rnd(1, n), r = rnd(l, n);

        std::cout << l << ' ' << r << ' ' << rnd(1, 10) << ' ' << rnd(1, 10) << '\n';
    }

    while (q--) {
        int c = rnd(1, n), d = rnd(1, n);

        if (c == d) {
            d = rnd(1, n);
        }

        std::cout << c << ' ' << d << '\n';
    }

    return 0;
}
