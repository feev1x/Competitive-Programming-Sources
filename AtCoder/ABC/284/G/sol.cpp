/**
 *    author:  feev1x
 *    created: 22.10.2025 08:42:02
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
    
    int64_t n, m; std::cin >> n >> m; 

    std::vector<int64_t> pw(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        pw[i] = (pw[i - 1] * n) % m;

    int64_t res = 0, pnk = 1;
    for (int64_t i = n, k = 1; i >= 1; --i, ++k) {
        res = (res + (((((pnk * 1 % m) * pw[n - k]) % m) * ((k * (k - 1) / 2) % m)) % m)) % m;

//        std::cout << res << '\n';

        if (i > 1)
            pnk = (pnk * (i - 1)) % m;
    }

    std::cout << (res * n) % m << '\n';
    return 0;
}
