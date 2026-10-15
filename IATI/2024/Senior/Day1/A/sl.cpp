#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::srand(time(nullptr));
    int ls = 0;
    int n; std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int val = rnd(ls + 1, (i < n / 2 ? 50000 : 100000) - (n - i));
        std::cout << val << ' ';
        ls = val;
    }
    return 0;
}
