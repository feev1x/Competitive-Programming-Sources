/**
 *    author:  feev1x
 *    created: 31.07.2025 19:58:07
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> l(n), r(n), real(n), idx(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> l[i] >> r[i] >> real[i];

            idx[i] = i;
        }

        std::sort(idx.begin(), idx.end(), [&](int i, int j) {
            return l[i] < l[j];
        });

        for (auto i: idx) {
            if (k < l[i])
                break;

            if (k <= r[i])
                k = std::max(k, real[i]);
        }

        std::cout << k << '\n';
    }
    return 0;
}
