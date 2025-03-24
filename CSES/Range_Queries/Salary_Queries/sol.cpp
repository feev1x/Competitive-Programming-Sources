/**
 *    author:  feev1x
 *    created: 04.03.2025 17:01:20
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using ordered_set = 
    __gnu_pbds::tree<std::pair<int, int>, __gnu_pbds::null_type, std::less<std::pair<int, int>>,
    __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    ordered_set st;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        st.insert({p[i], i});
    }

    while (q--) {
        char ch; std::cin >> ch;

        if (ch == '!') {
            int i, x; std::cin >> i >> x;

            st.erase({p[i], i});

            p[i] = x;

            st.insert({p[i], i});
        } else {
            int l, r; std::cin >> l >> r;

            std::cout << st.order_of_key({r + 1, -1}) - st.order_of_key({l, -1}) << '\n';
        }
    }
    return 0;
}
