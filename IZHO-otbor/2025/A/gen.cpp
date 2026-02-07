/**
 *    author:  feev1x
 *    created: 03.11.2025 13:58:13
**/
#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n = rnd(1, 4), m = rnd(0, 4); std::cout << n << ' ' << m << '\n';

    for (int i = 0; i < n + m; ++i)
        std::cout << rnd(1, 10) << ' ' << rnd(1, 10) << ' ' << rnd(1, 10) << '\n';

    return 0;
}
