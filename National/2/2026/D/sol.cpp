#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using ordered_mset = tree<int, null_type, std::less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::reverse(a.begin(), a.end());

    int64_t res = 0;

    ordered_mset st;
    for (auto u: a) {
        if (st.size()) {
            res += st.order_of_key(u);
        }

        st.insert(u);
    }

    std::cout << res << '\n';
    return 0;
}
