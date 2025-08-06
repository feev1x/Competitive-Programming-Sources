/**
 *    author:  feev1x
 *    created: 02.08.2025 18:19:31
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
    
    int n, m; std::cin >> n >> m;

    std::multiset<int> st;
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;

        st.emplace(u);
    }

    for (int i = 0; i < m; ++i) {
        int u; std::cin >> u;

        if (st.size() && st.count(u))
            st.erase(st.find(u));
    }

    for (auto u: st)
        std::cout << u << ' ';

    std::cout << '\n';
    return 0;
}
