/**
 *    author:  feev1x
 *    created: 19.08.2025 15:51:30
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
    
    std::string s; std::cin >> s;

    int mx = 0;
    std::map<char, int> mp;
    for (auto u: s)
        mp[u]++, mx = std::max(mx, mp[u]);

    if (mx * 2 > s.size() + 1) {
        std::cout << "-1\n";
        exit(0);
    }

    char ls = '$';
    int sz = s.size();
    while (mp.size()) {
        int cnt = 0;
        char ch = '$';

        for (auto [key1, val1]: mp) {
            if (key1 == ls)
                continue;

            int mx = 0;
            for (auto [key, val]: mp)
                if (mx < val - (key1 == key))
                    mx = val - (key1 == key);

            if (mx * 2 <= sz) {
                ch = key1, cnt = val1;
                break;
            }
        }

        std::cout << ch;

        mp[ch]--;
        if (cnt == 1)
            mp.erase(ch);

        ls = ch;
        sz--;
    }

    std::cout << '\n';
    return 0;
}
