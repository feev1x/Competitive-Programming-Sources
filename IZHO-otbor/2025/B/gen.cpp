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
    
    int n = rnd(1, 10), m = rnd(0, n * (n - 1) / 2); std::cout << n << ' ' << m << '\n';

    for (int i = 0; i < n; ++i)
        std::cout << rnd(1, 100) << " \n"[i == n - 1];

    std::map<std::pair<int, int>, bool> mp;
    for (int i = 0; i < m; ++i) {
        int u = rnd(1, n), v = rnd(1, n);

        while (mp[{u, v}] || u == v)
            u = rnd(1, n), v = rnd(1, n);

        std::cout << u << ' ' << v << '\n';

        mp[{u, v}] = mp[{v, u}] = true;
    }

    return 0;
}
