/**
 *    author:  feev1x
 *    created: 20.09.2025 18:20:59
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
    
    int n, m, k; std::cin >> n >> m >> k;

    std::vector<int> cnt(n + 1), ls(n + 1);
    for (int i = 1; i <= k; ++i) {
        int a, b; std::cin >> a >> b;

        cnt[a]++;
        ls[a] = i;
    }

    std::vector<int> a;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] == m)
            a.emplace_back(i);

    std::sort(a.begin(), a.end(), [&](int i, int j) {
        return ls[i] < ls[j];
    });

    for (int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " \n"[i + 1 == a.size()];

    return 0;
}
