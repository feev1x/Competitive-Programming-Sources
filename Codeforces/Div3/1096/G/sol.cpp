#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using ordered_mset = tree<int64_t, null_type, std::less_equal<int64_t>, rb_tree_tag, tree_order_statistics_node_update>;

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    ordered_mset st0, st1;
    int64_t sum = 0, res = 0;
    for (auto &u: a) std::cin >> u;
    for (int i = 0; i < n; ++i) {
        if (i & 1) sum -= a[i], st1.insert(sum);
        else sum += a[i], st0.insert(sum);
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            res += st1.order_of_key(sum);
            sum -= a[i], st1.erase(st1.upper_bound(sum));
        } else {
            res += st0.size() - st0.order_of_key(sum + 1);
            sum += a[i], st0.erase(st0.upper_bound(sum));
        }
    }
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
