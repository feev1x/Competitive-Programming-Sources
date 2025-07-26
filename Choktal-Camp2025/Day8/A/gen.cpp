/**
 *    author:  feev1x
 *    created: 08.07.2025 11:56:31
**/
#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n = rnd(1, 15); std::cout << n << '\n';

    while (n--)
        std::cout << rnd(1, 100) << " 2 1\n";

    int q = rnd(6, 10);
    std::cout << q << '\n';
    while (q--)
        std::cout << rnd(1, 100) << '\n';

    return 0;
}
