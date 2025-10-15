/**
 *    author:  feev1x
 *    created: 15.09.2025 20:40:24
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
        int n; std::cin >> n;

        int cnt0 = 0, l0 = n + 1, r0 = -1, l = n + 1, r = -1;

        std::vector<bool> used(n + 1);
        for (int i = 1; i <= n; ++i) {
            int u; std::cin >> u;

            used[u] = true;

            if (u == 0) {
                l0 = std::min(l0, i);
                r0 = i;
                cnt0++;
            } else if (u != i) {
                l = std::min(l, i);
                r = i;
            }
        }

        if (cnt0 > 1 || cnt0 == 1 && used[l0]) {
            r = std::max(r, r0);
            l = std::min(l, l0);
        }

        if (l > r) {
            std::cout << "0\n";
            continue;
        }

        std::cout << r - l + 1 << '\n';
    }
    return 0;
}
