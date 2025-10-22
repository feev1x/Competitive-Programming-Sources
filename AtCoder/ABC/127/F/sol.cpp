/**
 *    author:  feev1x
 *    created: 15.10.2025 22:36:27
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, std::less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

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
    
    int q; std::cin >> q;

    ordered_set st;

    int64_t sum = 0, mid = 0;
    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int a, b; std::cin >> a >> b;

            if (st.empty())
                mid = a;

            sum += b + std::abs(mid - a);

            st.insert(a);
            int nmid = *st.find_by_order((st.size() + 1) / 2 - 1);

            if ((int)st.size() & 1)
                sum -= std::abs(mid - nmid);

            mid = nmid;
        } else if (type == 2) {
            assert(st.size());

            std::cout << mid << ' ' << sum << '\n';
        }
    }
    return 0;
}
