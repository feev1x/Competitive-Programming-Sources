/**
 *    author:  feev1x
 *    created: 16.09.2025 11:30:08
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

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> pos(n + 1), ans(n + 1);
    
    std::vector<std::array<int, 3>> pt(n);
    std::set<std::array<int, 3>> st;
    for (int i = 0; i < n; ++i) {
        std::cin >> pt[i][0] >> pt[i][1];

        pt[i][2] = i + 1;

        st.emplace(pt[i]);
    }

    std::sort(pt.begin(), pt.end());

    while (st.size()) {
        auto [x, y, i] = *st.begin();

        st.erase(st.begin());

        if (ans[i] == 0)
            ans[i] = 1, pos[1] = i;

        
    }
    return 0;
}
