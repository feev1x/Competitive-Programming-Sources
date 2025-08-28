/**
 *    author:  feev1x
 *    created: 20.08.2025 19:21:21
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

constexpr int ITER = 1000;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define rnd(l, r) std::uniform_int_distribution<int64_t>(l, r)(rng)

inline int64_t binpow(int64_t a, int64_t n, int64_t mod) {
    int64_t res = 1;

    while (n) {
        if (n & 1)
            res = (__int128)res * a % mod;

        a = (__int128)a * a % mod;
        n >>= 1;
    }

    return res;
}

inline bool prime(int64_t n) {
    if (n == 1)
        return false;

    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 0; i < ITER; ++i) {
        int64_t a = rnd(2, n - 2);

        if (binpow(a, n - 1, n) != 1)
            return false;
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n; std::cin >> n;

        while (!prime(++n));

        std::cout << n << '\n';
    }
    return 0;
}
