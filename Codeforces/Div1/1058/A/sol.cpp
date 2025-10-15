/**
 *    author:  feev1x
 *    created: 12.10.2025 20:45:35
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

    auto Ask = [&](std::vector<int> a) {
        if (a.size() == 1)
            return 0;

        std::cout << "? " << a.size();

        for (auto u: a)
            std::cout << ' '  << u;

        std::cout << std::endl;

        int got; std::cin >> got;

        return got;
    };

    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> ask, res(2 * n + 1);
        for (int i = 1; i <= 2 * n; ++i) {
            ask.emplace_back(i);

            int got = Ask(ask);

            if (got != 0) {
                res[i] = got;

                ask.pop_back();
            }
        }

        ask.clear();

        for (int i = 2 * n; i >= 1; --i) {
            ask.emplace_back(i);

            if (res[i])
                continue;

            int got = Ask(ask);

            if (got != 0) {
                res[i] = got;

                ask.pop_back();
            }
        }

        std::cout << "!";
        for (int i = 1; i <= 2 * n; ++i)
            std::cout << ' ' << res[i];

        std::cout << std::endl;
    }
    return 0;
}
