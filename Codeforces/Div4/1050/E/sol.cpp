/**
 *    author:  feev1x
 *    created: 13.09.2025 21:03:21
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
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n + 1);
        std::vector<std::vector<int>> pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            pos[a[i]].emplace_back(i);
        }

        bool flag = true;
        std::vector<int> cnt(n + 1);
        for (int i = 1; i <= n; ++i)
            if (pos[i].size() % k != 0)
                flag = false;

        if (!flag) {
            std::cout << "0\n";
            continue;
        }

        int r = 0;
        int64_t res = 0;
        for (int l = 1; l <= n; ++l) {
            while (r + 1 <= n && cnt[a[r + 1]] + 1 <= (int)(pos[a[r + 1]].size()) / k) {
                r++;
                cnt[a[r]]++;
            }

            res += r - l + 1;

            if (r >= l)
                cnt[a[l]]--;
            else 
                r = l;
        }

        std::cout << res << '\n';
    }

    return 0;
}
