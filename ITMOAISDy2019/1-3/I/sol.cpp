/**
 *    author:  feev1x
 *    created: 16.10.2025 14:42:53
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
    
    int n, m; std::cin >> n >> m;    

    bool swap = false;
    if (m > n)
        std::swap(n, m), swap = true;

    std::vector<std::vector<char>> a(n, std::vector<char>(m));
    if (swap)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                std::cin >> a[j][i];
    else
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                std::cin >> a[i][j];

    return 0;
}
