/**
 *    author:  feev1x
 *    created: 19.08.2025 16:13:09
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;

        mp[u]++;
    }

    int res = 1;
    for (auto [key, val]: mp)
        res = mul(res, val + 1);

    std::cout << (res - 1 + MOD) % MOD << '\n';
    return 0;
}
