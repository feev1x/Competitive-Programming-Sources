/**
 *    author:  feev1x
 *    created: 10.10.2025 20:41:45
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

        std::vector<int> a(n);

        std::map<int64_t, int> mp;
        for (auto &u: a)
            std::cin >> u, mp[u]++;

        int64_t res = 0, used = 0;

        std::vector<int64_t> ar;
        for (auto [key, val]: mp) {
            res += (int64_t)key * (val - (val & 1));


            used += (val - (val & 1));

            if (val & 1)
                ar.emplace_back(key);
        }

        std::sort(ar.begin(), ar.end(), std::greater<>());

        for (int i = 0; i < ar.size(); ++i) {
            int j = i + 1;

            if (j < ar.size()) {
                if (res + ar[j] > ar[i]) {
                    used += 2, res += ar[j] + ar[i];
                    break;
                }
            } else {
                if (res > ar[i]) {
                    used++, res += ar[i];
                    break;
                }
            }
        }
        

        if (used > 2)
            std::cout << res << '\n';
        else
            std::cout << 0 << '\n';
    }
    return 0;
}
