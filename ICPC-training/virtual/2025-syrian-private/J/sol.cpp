/**
 *    author:  feev1x
 *    created: 13.08.2025 16:32:13
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
        int n, m, q; std::cin >> n >> m >> q;

        std::vector<int> a(n + 1), cnt(m);
        for (int i = 1; i <= n; ++i) 
            std::cin >> a[i], cnt[--a[i]]++;

        std::vector<int> pos;
        std::vector<bool> good(m);
        for (int i = 0; i < m; ++i)
            if (cnt[i] & 1)
                pos.emplace_back(i);
            else
                good[i] = true;

        int num = 0;
        while (q--) {
            int type; std::cin >> type;

            if (type == 2) {
                int i; std::cin >> i;

                if (!good[a[i]]) {
                    std::cout << a[i] + 1 << '\n';
                    continue;
                }

                if (pos.empty()) {
                    std::cout << (a[i] + num) % m + 1 << '\n';
                    continue;
                }

                int j = std::upper_bound(pos.begin(), pos.end(), a[i]) - pos.begin(), val;

                if (pos.size() == j)
                    val = pos.front() + m;
                else
                    val = pos[j];

                std::cout << (a[i] + num <= val ? (a[i] + num) % m : val % m) + 1 << '\n';
            } else num++;
        }
    }
    return 0;
}
