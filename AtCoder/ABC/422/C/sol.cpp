/**
 *    author:  feev1x
 *    created: 07.09.2025 10:18:42
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

int main() {
#define int long long
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int a, b, c; std::cin >> a >> b >> c;

        if (b >= a || b >= c) {
            std::cout << std::min(a, c) << '\n';
            continue;
        }

        if (a > c)
            std::swap(a, c);

        a -= b;
        c -= b;

        if (c - a >= a)
            std::cout << a + b << '\n';
        else {
            int64_t sum = 2 * a - c + c - (c - a) * 2;

            std::cout << c - a + b + sum / 3 << '\n';
        }
    }

    return 0;
}
