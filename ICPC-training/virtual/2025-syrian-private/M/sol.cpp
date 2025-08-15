/**
 *    author:  feev1x
 *    created: 13.08.2025 14:10:22
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
        int q; std::cin >> q;

        std::array<__int128, 3> sz{};
        std::vector<std::array<__int128, 3>> cnt(26);
        while (q--) {
            int64_t type; std::cin >> type;
            std::string s; std::cin >> s;
            int64_t k; std::cin >> k;

            for (auto u: s)
                cnt[u - 'a'][type] += k;

            sz[type] += (__int128)s.size() * k;

            __int128 i1 = 0, i2 = 0;

            bool flag = false, tie = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i][1] == cnt[i][2]) {
                    i1 += cnt[i][1];
                    i2 += cnt[i][2];

                    continue;
                }

                if (cnt[i][1] > cnt[i][2] && i2 + cnt[i][2] < sz[2]) {
                    flag = true;
                    tie = false;
                    break;
                } 

                if (cnt[i][1] > cnt[i][2] && i2 + cnt[i][2] == sz[2]) {
                    flag = false;
                    tie = false;
                    break;
                }

                if (cnt[i][2] > cnt[i][1] && i1 + cnt[i][1] < sz[1]) {
                    flag = false;
                    tie = false;
                    break;
                }

                flag = true;
                tie = false;
                break;
            }

            if (tie)
                std::cout << "Tie\n";
            else if (flag)
                std::cout << "Alice\n";
            else
                std::cout << "Bob\n";
        }
    }
    return 0;
}
