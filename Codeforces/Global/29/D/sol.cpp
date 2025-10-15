/**
 *    author:  feev1x
 *    created: 20.09.2025 21:25:11
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

int main() {
#define int int64_t
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> A(n + 1);
        std::map<int, int> mp;
        for (int i = 1; i <= n; ++i)
            std::cin >> A[i], mp[A[i]]++;

        int cnt = 0;

        int64_t sum = 0, add = 0;
        std::vector<int> ar;
        for (auto [key, val]: mp) {
            if (key & 1) {
                ar.emplace_back(key);
            } else {
                sum += val;

                add += (key / 2) * val;
            }
        }

        std::sort(ar.begin(), ar.end(), [&](int i, int j) {
            return mp[i] > mp[j];
        });

        int64_t a = 0, b = 0;
        for (int i = 0; i < ar.size(); ++i) {
            if (i & 1)
                b += mp[ar[i]];
            else
                a += mp[ar[i]];

            add += (ar[i] / 2) * mp[ar[i]];
        }

        std::cout << a + add << ' ' << b + add << '\n';
    }
    return 0;
}
