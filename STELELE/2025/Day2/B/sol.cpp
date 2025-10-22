/**
 *    author:  feev1x
 *    created: 19.10.2025 13:11:06
**/
#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")

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

inline int min(int a, int b) {
    if (a > b)
        return b;

    return a;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n + 1);
    std::vector<int> l(n + 1), r(n + 1);
    std::map<int64_t, int> mp;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    int64_t sum = 0;

    for (int i = 1; i <= n; ++i) {
        int j = i;

        while (j - 1 > 0 && (a[j - 1] & a[i]) == a[i])
            j -= std::max(l[j - 1] + 1, l[j]);
    

        l[i] = i - j;
    }


    for (int i = n; i >= 1; --i) {
        int j = i;

        while (j + 1 <= n && (a[j + 1] & a[i]) == a[i])
            j += std::max(r[j + 1] + 1, r[j]);

        r[i] = j - i;
    }

    for (int i = 1; i <= n; ++i) {
        if (i - l[i] <= mp[a[i]])
            l[i] = i - mp[a[i]] - 1;
        
        sum += (int64_t)(l[i] + 1) * (r[i] + 1);
//        std::cout << i - l[i] << ' ' << i << ' ' << i + r[i] << '\n';

        mp[a[i]] = i;
    }

    std::cout << sum << '\n';
    return 0;
}

