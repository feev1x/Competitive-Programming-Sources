/**
 *    author:  feev1x
 *    created: 07.09.2025 21:02:10
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

        std::vector<int> a(n), cnt(n + 1);
        for (auto &u: a)
            std::cin >> u, cnt[u]++;

        int st = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] != 1)
                break;

            st = i + 1;
        }

        if (st == n) {
            std::cout << (int64_t)n * (n - 1) / 2 << '\n';
            continue;
        }

        if (k == 1) {
            int64_t sum = 0, val = -1, cn = 0;

            for (int i = 0; i <= n; ++i) {
                if (st > i) {
                    sum += i;
                } else {
                    if (cnt[i] == 0 && val == -1)
                        val = i;
                    else if (cnt[i] == 1 && val == -1)
                        cn++, sum += i;
                }
            }

            assert(val != -1);

            sum += val * (n - st - cn);

            std::cout << sum << '\n';
            continue;
        }

        int64_t sum = (int64_t)st * (st - 1) / 2 + st * (n - st);

        if ((k & 1) == (cnt[st] > 0) && (n - st) > 1)
            sum += (n - st);

        std::cout << sum << '\n';
    }
    return 0;
}
