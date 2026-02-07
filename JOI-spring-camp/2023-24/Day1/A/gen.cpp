#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = rnd(1, 10), d = rnd(1, 10); std::cout << n << ' ' << d << '\n';

    for (int i = 0; i < n; ++i) {
        std::cout << rnd(1, 10) << " \n"[i == n - 1];
    }

    int q = rnd(1, 10); std::cout << q << '\n';
    while (q--) {
        int l = rnd(1, n), r = rnd(l, n); std::cout << l << ' ' << r << '\n';
    }

    return 0;
}
