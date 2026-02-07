#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int> (l, r) (rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q = rnd(1, 10);
    int n = rnd(1, 10); std::cout << n << ' ' << q << '\n';

    for (int i = 0; i < n; ++i) {
        std::cout << rnd(-10, 10) << " \n"[i == n - 1];
    }

    while (q--) {
        int type = rnd(1, 2); std::cout << type << ' ';

        if (type == 1) {
            int l = rnd(1, n), r = rnd(l, n);
            std::cout << l << ' ' << r << '\n';
        } else {
            int x = rnd(1, n), v = rnd(-10, 10); std::cout << x << ' ' << v << '\n';
        }
    }

    return 0;
}
