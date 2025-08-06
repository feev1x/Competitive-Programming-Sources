/**
 *    author:  feev1x
 *    created: 02.08.2025 13:09:57
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

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

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;

    if (a < 0)
        a += MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> fac(2 * n + 1, 1);
    for (int i = 2; i <= 2 * n; ++i)
        fac[i] = mul(fac[i - 1], i);

    auto C = [&](int N, int K) {
        return divide(fac[N], mul(fac[K], fac[N - K]));
    };

    auto Cat = [&](int N) {
        return divide(C(2 * N, N), N + 1);
    };

    int res = binpow(2, n - 1);

    add_self(res, -binpow(2, n / 2));
    add_self(res, -binpow(2, n / 2 - 1));
    add_self(res, -binpow(2, n / 2 - 1));
    add_self(res, 2);

    std::cout << res << '\n';
    return 0;
}
