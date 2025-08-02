/**
 *    author:  feev1x
 *    created: 28.07.2025 20:51:52
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
    
    int n; std::cin >> n;

    std::array<int, 4> dp{10, 20, 1, 0};

    // 0 = vowel, 1 = consonant, 2 = freakass j, 3 = special

    for (int i = 1; i < n; ++i) {
        std::array<int, 4> new_dp{0, 0, 0, 0};

        add_self(new_dp[0], mul(dp[1], 10));
        add_self(new_dp[0], mul(dp[2], 10));
        add_self(new_dp[0], mul(dp[3], 10));

        add_self(new_dp[1], mul(dp[0], 20));
        add_self(new_dp[2], dp[0]);

        add_self(new_dp[3], mul(dp[1], 2));

        dp = new_dp;
    }

    add_self(dp[0], dp[1]);
    add_self(dp[0], dp[2]);
    add_self(dp[0], dp[3]);

    std::cout << dp[0] << '\n';
    return 0;
}
