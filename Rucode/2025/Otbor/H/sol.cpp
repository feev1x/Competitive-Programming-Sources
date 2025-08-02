/**
 *    author:  feev1x
 *    created: 28.07.2025 22:59:06
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    auto Ask = [&](int x) {
        std::cout << "? " << x << std::endl;

        int got; std::cin >> got;

        return got;
    };

    int res = 0;
    for (int i = 0; i < 30; ++i) {
        int got = Ask(1 << i);

        if (got == 1)
            continue;

        for (int j = i; j <= i - got && j < 30; ++j)
            res |= 1 << j;

        i += 1 - got;
    }

    std::cout << "! " << res << std::endl;
    return 0;
}
