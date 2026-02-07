#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = rnd(1, 10); std::cout << n << '\n';

    for (int i = 2; i <= n; ++i) {
        std::cout << i << ' ' << rnd(1, i - 1) << '\n';
    }

    for (int i = 2; i <= n; ++i) {
        std::cout << i << ' ' << rnd(1, i - 1) << '\n';
    }

    return 0;
}
