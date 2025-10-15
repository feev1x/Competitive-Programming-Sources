/**
 *    author:  feev1x
 *    created: 14.09.2025 18:19:08
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
    
    int n, R; std::cin >> n >> R;

    int l = R + 1, r = R;
    std::vector<int> L(n + 1);
    for (int i = 1; i <= n; ++i) {
        int u; std::cin >> u;

        L[i] = u;

        if (u == 0)
            l = l == -1 || l > i ? i : l,
            r = std::max(r, i);
    }

    if (l > r) {
        std::cout << "0\n";
        exit(0);
    }

    int cnt = 0;
    for (int i = l; i <= r; ++i)
        cnt += L[i] == 1;

    std::cout << cnt + r - l + 1 << '\n';
    return 0;
}
