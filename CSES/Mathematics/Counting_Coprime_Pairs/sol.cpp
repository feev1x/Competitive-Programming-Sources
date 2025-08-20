/**
 *    author:  feev1x
 *    created: 20.08.2025 18:41:49
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

constexpr int N = 1e6 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<bool> odd(N), prime(N, true), skip(N);

    prime[1] = false;
    for (int i = 2; i < N; ++i)
        if (prime[i] && (odd[i] = true))
            for (int j = i * 2; j < N; j += i)
                prime[j] = false, odd[j] = !odd[j], skip[j] = j % (int64_t)(i * i) == 0 ? true : skip[j];
    
    int n; std::cin >> n;

    std::vector<int> cnt(N);
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;

        cnt[u]++;
    }

    int64_t res = 0;
    for (int i = 2; i < N; ++i) {
        if (skip[i])
            continue;

        int64_t cn = 0;

        for (int j = i; j < N; j += i)
            cn += cnt[j];

        res += cn * (cn - 1) / 2 * (odd[i] ? 1 : -1);
    }

    std::cout << (int64_t)n * (n - 1) / 2 - res << '\n';
    return 0;
}
