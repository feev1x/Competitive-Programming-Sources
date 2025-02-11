/**
 *    author:  feev1x
 *    created: 11.02.2025 13:36:25
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

int main() {
    std::freopen("mountains.in", "r", stdin);
    std::freopen("mountains.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> x(n), y(n), pos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];

        pos[i] = i;
    }

    std::sort(pos.begin(), pos.end(), [&](int i, int j) {
        return y[i] > y[j];
    });

    int cnt = 0;
    tree<int, null_type, std::less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> sl, sr;
    for (auto i: pos) {
        int cnt_p = (int)sl.order_of_key(x[i] + y[i]) + (int)sr.size() - sr.order_of_key(x[i] - y[i] + 1);

        if (cnt_p == sl.size()) {
            cnt++;

            sl.insert(x[i] + y[i]);
            sr.insert(x[i] - y[i]);
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
