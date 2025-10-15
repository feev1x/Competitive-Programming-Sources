/**
 *    author:  feev1x
 *    created: 09.10.2025 15:01:30
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int type; std::cin >> type;

        if (type == 1) {
            int64_t n, k; std::cin >> n >> k; k--;

            std::vector<int> res(n + 1);
            ordered_set st;
            std::vector<int64_t> fac(n + 1, 1);
            for (int64_t i = 1; i <= n; ++i)
                fac[i] = fac[i - 1] * i, st.insert(i);

            for (int i = 1; i <= n; ++i) {
                int l = 1, r = n - i + 1, ans = -1;

                while (l <= r) {
                    int m = l + r >> 1;

                    if (fac[n - i] * (m - 1) > k)
                        r = m - 1;
                    else
                        l = m + 1, ans = m;
                }

                k -= fac[n - i] * (ans - 1);

                std::cout << *st.find_by_order(ans - 1) << " \n"[i == n];

                st.erase(st.find_by_order(ans - 1));
            }

        } else {
            int n; std::cin >> n;

            int64_t k = 1;
            ordered_set st;
            std::vector<int64_t> fac(n + 1, 1);
            for (int64_t i = 1; i <= n; ++i)
                fac[i] = fac[i - 1] * i, st.insert(i);

            for (int i = 1; i <= n; ++i) {
                int u; std::cin >> u;
                
                int64_t pos = st.order_of_key(u) + 1;
                k += fac[n - i] * (pos - 1);

                st.erase(u);
            }

            std::cout << k << '\n';
        }
    }
    return 0;
}
