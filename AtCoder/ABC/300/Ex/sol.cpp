/**
 *    author:  feev1x
 *    created: 23.10.2025 09:52:19
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

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;

    if (a < 0)
        a += MOD;
}

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int k; int64_t n; std::cin >> k >> n;

    int res = k, resl = 1, cnt = 0;
    for (int64_t i = 0; i < 60; ++i) {
        if (n >> i & 1) {
            cnt++;

            add_self(res, mul(res, binpow(2, binpow(2, i))));
            add_self(resl, mul(resl, binpow(2, binpow(2, i))));
        }
    }

    cnt = binpow(2, cnt);

    int bn = (-binpow(2, k) + MOD) % MOD;

    res = mul(res, bn);
    resl = mul(resl, binpow(2, k));

    add_self(res, cnt);
    add_self(res, resl);

    for (int64_t i = 0; i < k; ++i)
        if ((n & i) == i) {
            int val = mul(mul(binpow(2, i), k), bn);

            add_self(val, -binpow(2, i));

            add_self(val, 1);

            add_self(res, -val);
        }

    std::cout << res << '\n';
    return 0;
}
