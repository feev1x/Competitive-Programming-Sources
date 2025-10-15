/**
 *    author:  feev1x
 *    created: 13.09.2025 20:54:15
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

        std::vector<std::vector<int>> a(n);
        for (auto &u: a) {
            int k; std::cin >> k;

            u.resize(k);
            for (auto &v: u)
                std::cin >> v;
        }

        std::vector<int> ans;

        while (a.size()) {
            std::sort(a.begin(), a.end());
            std::reverse(a.begin(), a.end());

            int sz = a.back().size();

            std::reverse(a.back().begin(), a.back().end());
            while (a.back().size()) {
                ans.emplace_back(a.back().back());
                a.back().pop_back();
            }

            a.pop_back();

            std::vector<std::vector<int>> new_a;
            for (auto &u: a) {
                if (u.size() <= sz)
                    continue;

                std::reverse(u.begin(), u.end());
                int w = sz;
                while (w--)
                    u.pop_back();

                std::reverse(u.begin(), u.end());
                new_a.emplace_back(u);
            }

            a = new_a;
        }

        for (auto u: ans)
            std::cout << u << ' ';

        std::cout << '\n';
    }
    return 0;
}
