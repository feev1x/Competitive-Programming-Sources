/**
 *    author:  feev1x
 *    created: 17.10.2025 10:26:58
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
    
    int n; int64_t a, b, c, x; std::cin >> n >> a >> b >> c >> x;    

    std::vector<std::pair<int64_t, int>> sl;
    for (int i = 1; i <= n; ++i) {
        sl.emplace_back(a * i + b * n, 1);
        sl.emplace_back(a * i, -1);
    }

    std::sort(sl.begin(), sl.end());

    std::map<int64_t, int64_t> mp;

    int64_t res = 0;
    for (int i = 1; i <= n && c * i <= x; ++i) {
        while (sl.size() && sl.back().first >= x - c * i) {
            mp[sl.back().first % b] += sl.back().second;
            sl.pop_back();
        }

        res += mp[(x - c * i) % b];
    }

    std::cout << res << '\n';
    return 0;
}
