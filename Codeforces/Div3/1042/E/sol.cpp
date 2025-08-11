/**
 *    author:  feev1x
 *    created: 10.08.2025 21:14:18
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

        std::vector<int> a(n), b(n);
        for (auto &u: a)
            std::cin >> u;

        for (auto &u: b)
            std::cin >> u;

        bool flag = true;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == b[i] || i != n - 1 && ((b[i + 1] ^ a[i]) == b[i] || (a[i + 1] ^ a[i]) == b[i])) {
            } else {
                flag = false;
                break;
            }
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
