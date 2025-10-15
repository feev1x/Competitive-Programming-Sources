/**
 *    author:  feev1x
 *    created: 13.10.2025 12:13:10
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>

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
    
    int n, k; std::cin >> n >> k;

    std::vector<int> a(k);
    for (auto &u: a)
        std::cin >> u;

    ordered_set st;
    for (int i = 1; i <= n; ++i)
        st.insert(i);

    int nw = 0;
    std::vector<int> num(n + 1), ord;

    int del = 1;
    for (int x = 0; st.size(); ++x) {
        int i = x % k;

        int u = a[i];
        while (u--) {
            if (nw >= st.size())
                nw = 0;

            if (st.empty())
                break;

            auto it = st.find_by_order(nw);

            num[*it] = del++;
            ord.emplace_back(*it);
            st.erase(st.find_by_order(nw));
        }

        if (st.empty())
            break;

        nw += a[i];
        nw %= (int)st.size();
    }

    int q; std::cin >> q;
    while (q--) {
        int t, p; std::cin >> t >> p;

        if (t == 1)
            std::cout << num[p];
        else
            std::cout << ord[p - 1];

        std::cout << '\n';
    }
    return 0;
}
