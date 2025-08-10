/**
 *    author:  feev1x
 *    created: 09.08.2025 19:40:06
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

    std::string s; std::cin >> s;

    int l = 0;

    int64_t res = count(s.begin(), s.end(), '1');
    for (int r = 0; r + 1 < n; ++r) {
        if (s[r] == s[r + 1]) {
            ++r;
        } else {
            if (l != r) {
                int sz = (r - l) * ((r - l + 1) / 2) / 2;
                res += sz;
            }

            l = r + 1;
        }
    }

    if (l != n - 1) {
        int sz = (n - l - 1) * ((n - l) / 2) / 2;
        res += sz;
    }

    std::cout << res << '\n';
    return 0;
}
