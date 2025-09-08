/**
 *    author:  feev1x
 *    created: 07.09.2025 20:53:27
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

        std::vector<int> b(n), cnt(n + 1);
        for (auto &u: b)
            std::cin >> u, cnt[u]++;

        bool flag = true;
        for (int i = 1; i <= n; ++i)
            if (cnt[i] % i != 0)
                flag = false;

        if (!flag) {
            std::cout << "-1\n";
            continue;
        }

        std::fill(cnt.begin(), cnt.end(), 0);

        int mx = 0;
        std::vector<int> val(n + 1);
        for (int i = 0; i < n; ++i) {
            if (cnt[b[i]] % b[i] == 0)
                val[b[i]] = ++mx;

            std::cout << val[b[i]] << " \n"[i == n - 1];
            cnt[b[i]]++;
        }
    }
    return 0;
}
