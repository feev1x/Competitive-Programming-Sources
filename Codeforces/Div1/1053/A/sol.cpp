/**
 *    author:  feev1x
 *    created: 02.10.2025 16:56:34
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

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
        int n, m; std::cin >> n >> m;

        std::string s; std::cin >> s;

        std::vector<int> a(m);
        ordered_set st;
        for (auto &u: a)
            std::cin >> u, st.emplace(u);
        
        int i = 0, nw = 1;
        for (auto u: s) {
            if (u == 'A')
                st.emplace(
        }

        std::cout << st.size() << '\n';
        for (auto u: st)
            std::cout << u << ' ';

        std::cout << '\n';
    }
    return 0;
}
