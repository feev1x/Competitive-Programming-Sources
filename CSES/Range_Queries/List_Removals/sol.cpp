/**
 *    author:  feev1x
 *    created: 04.03.2025 16:53:22
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
    
    int n; std::cin >> n;

    ordered_set st;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        st.insert({i, a[i]});
    }

    for (int i = 1; i <= n; ++i) {
        int pos; std::cin >> pos;

        auto it = st.find_by_order(pos - 1);

        std::cout << it->second << " \n"[i == n];

        st.erase(it);
    }
    return 0;
}
