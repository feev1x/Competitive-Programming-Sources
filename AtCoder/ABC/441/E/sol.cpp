#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using ordered_mset = tree<int64_t, null_type, std::less_equal<int64_t>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::string s; std::cin >> s;

    ordered_mset st;

    int64_t df = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            df++;
        } else if (s[i] == 'B') {
            df--;
        }

        st.insert(df);
    }

    df = 0;
    int64_t res = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
//        std::cout << (int)st.size() - st.order_of_key(-sum + 1) << '\n';

        res += (int)st.size() - st.order_of_key(-sum + 1);

        if (s[i] == 'A') {
            df++;
            sum--;
        } else if (s[i] == 'B') {
            df--;
            sum++;
        }

        st.erase(st.upper_bound(df));
    }

    std::cout << res << '\n';
    return 0;
}
