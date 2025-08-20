/**
 *    author:  feev1x
 *    created: 17.08.2025 13:33:24
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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    bool cnt = false;
    for (int i = 3; i <= n; ++i)
        if ((a[1] < a[2]) != (a[i - 1] < a[i]))
            cnt = true;
        else if (cnt) {
            std::cout << "NO\n";
            exit(0);
        }

    std::cout << (cnt ? "YES\n" : "NO\n");
    return 0;
}
