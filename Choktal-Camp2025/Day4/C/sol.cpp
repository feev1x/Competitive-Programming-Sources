/**
 *    author:  feev1x
 *    created: 04.07.2025 12:43:39
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ord = tree<int, null_type, std::less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2));

    if (n == 1) {
        for (int j = 1; j <= m; ++j)
            std::cin >> a[1][j];

        ord st;

        int64_t res = 0;
        for (int j = m; j >= 1; --j) {
            st.insert(a[1][j]);

            res += st.order_of_key(a[1][j]);
        }

        std::cout << res << '\n';
        exit(0);
    }

    std::vector<std::vector<bool>> inq(n + 2, std::vector<bool>(m + 2));
    std::vector<std::vector<int64_t>> dp(n + 2, std::vector<int64_t>(m + 2, INF));
    std::vector<std::vector<ord>> st(n + 2, std::vector<ord>(m + 2));
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];

            for (int k = 1; k <= i; ++k)
                for (int l = 1; l <= j; ++l)
                    st[k][l].insert(a[i][j]);
        }

    std::queue<std::pair<int, int>> q;
    
    q.emplace(1, 1);

    inq[1][1] = true;
    dp[1][1] = 0;

    while (q.size()) {
        auto [i, j] = q.front();

        inq[i][j] = false;

        q.pop();
        
        ord st1;

        if (i <= n) {
            int64_t cnt = 0;

            for (int k = j; k <= m; ++k) {
                st1.insert(a[i][k]);

                cnt += st[i][j].order_of_key(a[i][k]);
                cnt -= st1.order_of_key(a[i][k]);
            }

            if (dp[i + 1][j] > dp[i][j] + cnt) {
                dp[i + 1][j] = dp[i][j] + cnt;

                if (!inq[i + 1][j]) {
                    q.emplace(i + 1, j);
                    inq[i + 1][j] = true;
                }
            }

            st1.clear();
        }

        if (j <= m) {
            int64_t cnt = 0;

            for (int k = i; k <= n; ++k) {
                st1.insert(a[k][j]);

                cnt += st[i][j].order_of_key(a[k][j]);
                cnt -= st1.order_of_key(a[k][j]);
            }

            if (dp[i][j + 1] > dp[i][j] + cnt) {
                dp[i][j + 1] = dp[i][j] + cnt;

                if (!inq[i][j + 1]) {
                    q.emplace(i, j + 1);
                    inq[i][j + 1] = true;
                }
            }
        }
    }

    std::cout << dp[n + 1][m + 1] << '\n';
    return 0;
}
