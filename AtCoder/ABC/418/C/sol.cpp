/**
 *    author:  feev1x
 *    created: 09.08.2025 19:30:13
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
    
    int n, q; std::cin >> n >> q;

    std::vector<int64_t> a(n + 1);

    int64_t sum = 0, mx = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        sum += a[i];
        mx = std::max(mx, a[i]);
    }

    std::sort(a.begin(), a.end());

    sum = std::min(sum, (int64_t)1000000);
    std::vector<int64_t> ans(mx + 1, -1);

    ans[1] = 1;
    for (int i = 2; i <= mx; ++i)
        ans[i] = ans[i - 1] + a.end() - std::lower_bound(a.begin(), a.end(), i - 1);

    while (q--) {
        int b; std::cin >> b;

        if (b > mx)
            std::cout << "-1\n";
        else
            std::cout << ans[b] << '\n';
    }
    return 0;
}
