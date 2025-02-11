/**
 *    author:  feev1x
 *    created: 10.02.2025 09:38:47
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

int main() {
    std::freopen("sort.in", "r", stdin);
    std::freopen("sort.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    
    int res = 0;
    tree<int, null_type, std::greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> st;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        res = std::max(res, (int)st.order_of_key(u));

        st.insert(u);
    }

    std::cout << res + 1 << '\n';
    return 0;
}
