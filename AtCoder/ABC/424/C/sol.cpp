/**
 *    author:  feev1x
 *    created: 20.09.2025 18:24:52
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

    std::vector<int> a(n + 1), b(n + 1);
    std::vector<std::vector<int>> g(n + 1);

    std::queue<int> q;
    std::vector<bool> used(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> b[i];

        if (!a[i] || !b[i])
            q.emplace(i), used[i] = true;

        g[a[i]].emplace_back(i);
        g[b[i]].emplace_back(i);
    }

    while (q.size()) {
        int v = q.front();

        q.pop();
        for (auto to: g[v])
            if (!used[to])
                q.emplace(to), used[to] = true;
    }

    std::cout << std::count(used.begin(), used.end(), true) << '\n';
    return 0;
}
