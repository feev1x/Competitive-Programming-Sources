/**
 *    author:  feev1x
 *    created: 20.08.2025 19:51:32
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

constexpr int MOD = 1e9 + 7, N = 1e6 + 5;

inline int mul(int &a, int b) {
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

    std::vector<int> fac(N, 1), invfac(N, 1);
    for (int i = 2; i < N; ++i)
        fac[i] = mul(fac[i - 1], i);

    invfac[N - 1] = binpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i > 0; --i)
        invfac[i] = mul(invfac[i + 1], i + 1);

    auto C = [&](int n, int k) {
        return mul(fac[n], mul(invfac[k], invfac[n - k]));
    };
    
    int n; std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b; std::cin >> a >> b;

        std::cout << C(a, b) << '\n';
    }
    return 0;
}
