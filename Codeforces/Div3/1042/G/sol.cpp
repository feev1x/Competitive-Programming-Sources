/**
 *    author:  feev1x
 *    created: 10.08.2025 22:05:37
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> s(n);
        for (auto &u: s)
            std::cin >> u;

        std::sort(s.begin(), s.end());

        int val = -1;

        int res = 1;
        
        for (auto u: s) {
            if (u > 30 || (1 << (u - 1)) >= k) {
                val = u;
                break;
            }

            res = mul(res, u);
            for (int i = 2; i <= u - 1; ++i)
                res = mul(res, binpow(i, (1ll << (u - i - 1)) % MOD) % MOD);

            k -= (1 << (u - 1));
        }

        if (val != -1) {
            res = mul(res, val % MOD);

            if (val > 31)
                val = 31;

            k--;
            val--;

            for (; val >= 0; --val) {
                if ((1 << val) <= k) {
                    res = mul(res, (val + 1) % MOD);

                    for (int i = 2; i <= val; ++i)
                        res = mul(res, binpow(i, (1ll << (val - i)) % MOD));

                    k -= (1 << val);
                }
            }
        }

        std::cout << res << '\n';
    }

    return 0;
}
