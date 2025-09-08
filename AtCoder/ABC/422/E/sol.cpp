/**
 *    author:  feev1x
 *    created: 07.09.2025 11:05:31
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

#define int int64_t 
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

inline std::array<int, 3> get(int x, int y, int x1, int y1) {
    int A = y1 - y, B = x - x1, C = -(A * x + B * y);
    return {A, B, C};
}

constexpr int N = 8;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> y[i];

    int _ = 100;
    while (_--) {
        int i = 0, j = 0;

        while (i == j) {
            i = rnd(0, n - 1);
            j = rnd(0, n - 1);
        }

        auto [a, b, c] = get(x[i], y[i], x[j], y[j]);

        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (a * x[i] + b * y[i] + c == 0)
                cnt++;

        if (cnt > n / 2) {
            std::cout << "Yes\n" << a << ' ' << b << ' ' << c << '\n';
            exit(0);
        }
    }

    std::cout << "No\n";
    return 0;
}
