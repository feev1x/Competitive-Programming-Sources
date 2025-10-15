/**
 *    author:  feev1x
 *    created: 20.08.2025 20:06:31
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

constexpr int MOD = 1e9 + 7, N = 26;

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

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int n = s.size();
    std::vector<int> cnt(N), fac(n + 1, 1), inv(n + 1, 1);
    for (auto u: s)
        cnt[u - 'a']++;

    for (int i = 1; i <= n; ++i)
        fac[i] = mul(fac[i - 1], i);

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i >= 1; --i)
        inv[i] = mul(inv[i + 1], i + 1);

    auto C = [&](int r, int c) {
        return mul(fac[r], mul(inv[c], inv[r - c]));
    };

    int res = 1, space = n;
    for (int i = 0; i < N; ++i)
        res = mul(res, C(space, cnt[i])), space -= cnt[i];

    std::cout << res << '\n';
    return 0;
}
