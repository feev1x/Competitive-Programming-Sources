/**
 *    author:  feev1x
 *    created: 19.08.2025 15:32:11
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

    std::vector a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        std::vector<int> ar;

        for (int j = 0; j < n; ++j) {
            auto ch = ar;

            for (int k = 0; k < i; ++k)
                ch.emplace_back(a[k][j]);

            std::sort(ch.begin(), ch.end());
            ch.erase(unique(ch.begin(), ch.end()), ch.end());

            int mex = ch.size();
            for (int k = 0; k < ch.size(); ++k)
                if (ch[k] != k) {
                    mex = k;
                    break;
                }

            std::cout << (a[i][j] = mex) << " \n"[j == n - 1];
            ar.emplace_back(mex);
        }
    }

    return 0;
}
