/**
 *    author:  feev1x
 *    created: 28.07.2025 20:44:16
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
    
    std::string s; std::cin >> s;

    if (s[2] == ':') {
        int64_t n = (s[0] - '0') * 10 + (s[1] - '0');

        n *= 60;

        n += (s[3] - '0') * 10 + (s[4] - '0');

        n *= 60;

        n += (s[6] - '0') * 10 + (s[7] - '0');

        std::cout << n << '\n';
    } else {
        int64_t n = 0;
        for (int i = 0; i < s.size(); ++i)
            n = n * 10 + s[i] - '0';

        int64_t s = n % 60;
        n -= s;

        n /= 60;

        int64_t m = n % 60;

        n -= m;

        n /= 60;

        int64_t h = n % 24;

        std::cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << ':' << s / 10 << s % 10 << '\n';
    }
    return 0;
}
