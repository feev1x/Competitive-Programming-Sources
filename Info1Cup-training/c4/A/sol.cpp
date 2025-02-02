/**
 *    author:  feev1x
 *    created: 31.01.2025 09:07:23
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::set<std::pair<int64_t, int>> st;
    std::vector<int64_t> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> v[i];

        st.emplace(v[i], i);
    }

    std::deque<int> ans;
    std::deque<int> end;

    int ls = n;
    int64_t res = 0;
    for (int i = n; i >= 1; --i) {
        if (st.rbegin()->second == i) {
            for (int j = ls; j > i; --j) {
                ans.emplace_front(j);

                res += v[i];
            }

            if (ls != n) {
                res += v[i];
            }

            end.emplace_back(i);

            ls = i - 1;
        }

        st.erase({v[i], i});
    }

    while (end.size()) {
        ans.emplace_back(end.front());

        end.pop_front();
    }

    std::cout << res << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}
