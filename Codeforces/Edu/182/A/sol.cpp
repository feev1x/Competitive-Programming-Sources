/**
 *    author:  feev1x
 *    created: 15.09.2025 20:36:34
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
        for (auto &u: a)
            std::cin >> u;

        int L = 0, R = 0;
        for (int l = 0; l + 2 < n; ++l) {
            for (int r = l + 1; r + 1 < n; ++r) {
                int s1 = 0, s2 = 0, s3 = 0;

                for (int i = 0; i <= l; ++i)
                    s1 += a[i];

                for (int i = l + 1; i <= r; ++i)
                    s2 += a[i];

                for (int i = r + 1; i < n; ++i)
                    s3 += a[i];

                s1 %= 3;
                s2 %= 3;
                s3 %= 3;
                if (s1 == s2 && s2 == s3 || s1 != s2 && s2 != s3 && s1 != s3)
                    L = l + 1, R = r + 1;
            }
        }

        std::cout << L << ' ' << R << '\n';
    }
    return 0;
}
