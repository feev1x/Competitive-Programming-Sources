/**
 *    author:  feev1x
 *    created: 28.10.2025 15:52:08
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

    std::vector<int> a(n + 1), div;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        for (int j = 1; j * j <= a[i]; ++j)
            if (a[i] % j == 0)
                div.emplace_back(j), div.emplace_back(a[i] / j);
    }

    std::sort(div.begin(), div.end());
    div.erase(unique(div.begin(), div.end()), div.end());

    std::vector<int> t(div.size());

    int cnt = 0;
    for (int i = 0; i < div.size(); ++i) {
        for (int j = 1; j <= n; ++j)
            if (a[j] % div[i] == 0)
                t[i] = std::gcd(t[i], a[j]);

        if (div[i] == t[i])
            cnt++;
    }

    std::cout << cnt << '\n';
    return 0;
}
