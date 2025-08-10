/**
 *    author:  feev1x
 *    created: 09.08.2025 19:24:56
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
    
    int n = s.size();

    double rate = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 2; j < n; ++j)
            if (s[i] == 't' && s[j] == 't') {
                std::string t = s.substr(i, j - i + 1);

                rate = std::max(rate, ((int)count(t.begin(), t.end(), 't') - 2.0) / (j - i - 1.0));
            }

    std::cout << std::fixed << std::setprecision(10) << rate << '\n';
    return 0;
}
