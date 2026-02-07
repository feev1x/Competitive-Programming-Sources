/**
 *    author:  feev1x
 *    created: 25.10.2025 18:09:00
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
    
    int n, c; int64_t m; std::cin >> n >> m >> c;

    std::vector<int64_t> a(n), next(n);
    for (auto &u: a)
        std::cin >> u;

    std::sort(a.begin(), a.end());
    next[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
        if (a[i] != a[i + 1])
            next[i] = i;
        else
            next[i] = next[i + 1];


    if (a.front() == a.back()) {
        std::cout << m * n << '\n';
        exit(0);
    }

    auto Dis = [&](int64_t l, int64_t r) {
        if (r < l)
            return m - l + r + 1;

        return r - l + 1;
    };

    int64_t res = 0;
    
    int64_t r = 0, cnt = 0;
    for (int l = 0; l < n; ++l) {
        if (l + 1 < n && a[l] == a[l + 1])
            continue;

        cnt = c + next[(l + c) % n] - ((l + c) % n);
        
        res += Dis(a[l], (a[(l + 1) % n] - 1 + m) % m) * cnt;
    }

    std::cout << res << '\n';
    return 0;
}
