#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int> (l, r) (rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = rnd(1, 10); std::cout << n << '\n';

    for (int i = 0; i < n; ++i) {
        std::cout << rnd(1, 2 * n) << " \n"[i == n - 1];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << rnd(1, 2 * n) << " \n"[i == n - 1];
    }

    int q = rnd(1, n + 1); std::cout << q << '\n';
    while (q--) {
        int l = rnd(0, n), r = rnd(l, n);
        std::cout << l << ' ' << r << '\n';
    }

    return 0;
}
