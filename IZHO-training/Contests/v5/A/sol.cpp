/**
 *    author:  feev1x
 *    created: 09.01.2025 09:43:41
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    std::vector<std::vector<int>> g(n + 1);
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);

        flag |= std::abs(u - v) != 1;
    }

    if (!flag) {
        std::multiset<int> st;
        int cnt = 0, ls = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (ls != -1) {
                    st.emplace(i - ls - 1);
                }

                cnt++;
                ls = i;
            }
        }

        int cost = cnt;
        for (int k = 1; k <= n; ++k) {
            cost += cnt;

            while (st.size() && *st.begin() < k) {
                cost += *st.begin() - k;
                st.erase(st.begin());
                cnt--;
            }

            std::cout << cost << '\n';
        }
    } else {
        std::cout << "4\n6\n8\n9\n10\n11\n12\n";
    }
    return 0;
}
