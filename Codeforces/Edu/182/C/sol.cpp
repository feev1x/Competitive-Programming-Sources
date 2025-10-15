/**
 *    author:  feev1x
 *    created: 15.09.2025 20:46:52
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

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n), b(n);
        for (auto &u: a)
            std::cin >> u;

        for (auto &u: b)
            std::cin >> u;

        int cnt0 = 1, cnt1 = 1;
        for (int i = 1; i < n; ++i) {
            int new_0 = ((a[i] >= a[i - 1] && b[i] >= b[i - 1]) * cnt0 + (a[i] >= b[i - 1] && b[i] >= a[i - 1]) * cnt1) % MOD;
            int new_1 = ((b[i] >= a[i - 1] && a[i] >= b[i - 1]) * cnt0 + (b[i] >= b[i - 1] && a[i] >= a[i - 1]) * cnt1) % MOD;

            cnt0 = new_0;
            cnt1 = new_1;
        }

        std::cout << (cnt0 + cnt1) % MOD << '\n';
    }
    return 0;
}
