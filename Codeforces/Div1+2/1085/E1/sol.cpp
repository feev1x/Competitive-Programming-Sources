#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using ordered_set =
    tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update>;

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n), cnt(3 * n);
    for (auto &u: a) {
        std::cin >> u;

        if (u < 3 * n) {
            cnt[u] = 1;
        }
    }

    std::set<int> st;
    ordered_set mex;
    for (int i = 0; i < 3 * n; ++i) {
        if (!cnt[i]) {
            st.insert(i);
        }

        mex.insert(i);
    }

    std::vector<int> b;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        int mex_nw = *mex.find_by_order(n - i - 1);

        if (mex_nw > a[i]) {
            flag = false;
            break;
        }

        if (mex_nw == a[i]) {
            b.emplace_back(5 * n);
        } else {
            auto it = st.upper_bound(a[i]);
            
            if (st.empty() || it == st.begin()) {
                flag = false;
                break;
            }

            --it;

            b.emplace_back(*it);
            mex.erase(*it);

            st.erase(it);

            mex_nw = *mex.find_by_order(n - i - 1);
            if (mex_nw != a[i]) {
                flag = false;
                break;
            }
        }
    }

    if (!flag) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
