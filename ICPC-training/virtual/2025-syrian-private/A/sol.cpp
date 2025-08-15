/**
 *    author:  feev1x
 *    created: 13.08.2025 14:07:22
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
    
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n), pos(1, -1), idx(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        a[i] %= k;

        if (!a[i]) {
            idx[i] = pos.size();
            pos.emplace_back(i);
        }
    }

    if (k == 1) {
        int64_t x = n;

        std::cout << x * (x + 1) / 2 << '\n';
        exit(0);
    }

    int64_t res = 0;

    if (k <= n) {
        for (int bl = 0; bl < k; ++bl) {
            int64_t sum = 0;

            int m = pos.size();

            int ls = bl;
            for (int i = bl; i < m; i += k)
                ls = i;

            for (int i = ls; i >= 0; i -= k) {
                int64_t l = (i + 1 == m ? n : pos[i + 1]) - pos[i];

                res += l * sum;

                sum += l;
            }
        }
    }

    pos.emplace_back(n);
    for (int i = 1; i < pos.size(); ++i) {
        int64_t x = pos[i] - pos[i - 1] - 1;

        res += x * (x + 1) / 2;
    }

    std::cout << res << '\n';
    return 0;
}
