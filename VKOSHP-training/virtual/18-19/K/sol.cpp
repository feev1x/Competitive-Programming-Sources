/**
 *    author:  feev1x
 *    created: 09.08.2025 16:09:31
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
    
    int n; std::cin >> n;

    std::map<int, std::map<std::string, std::vector<int>>> mp;
    for (int i = 1; i <= n; ++i) {
        std::string s, t; std::cin >> s >> t;

        int mask = 0;
        for (auto u: t)
            mask |= (1 << u - 'a');

        while (s.size() && (mask >> (s.back() - 'a') & 1))
            s.pop_back();

        mp[mask][s].emplace_back(i);
    }

    std::vector<std::vector<int>> res;
    for (auto [key, val]: mp)
        for (auto [key1, val1]: val)
            res.emplace_back(val1);

    std::cout << res.size() << '\n';
    for (auto u: res) {
        std::cout << u.size() << ' ';

        for (auto v: u)
            std::cout << v << ' ';

        std::cout << '\n';
    }

    return 0;
}
