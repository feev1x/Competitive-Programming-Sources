/**
 *    author:  feev1x
 *    created: 14.11.2025 12:14:19
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;


    std::map<int, int> cnt;
    std::vector<int> a(n);
    for (auto &u: a)
        std::cin >> u, cnt[u]++;

    std::set<std::pair<int, int>> st;


    st.emplace(log2(n + 1), 0);

    std::vector<int> ans((n + 1) / 2);
    for (auto [key, val]: cnt) {
        auto Choose = [&](int v, int pos) {
            val -= v;

            st.erase({v, pos});
            
            ans[pos] = key;

            pos++;
            for (int i = 1; i < v; ++i)
                st.emplace(i, pos), pos += (1 << i - 1);
        };

        if (val) {
            auto it = st.upper_bound({val, 5 * n + 1000});

            if (it == st.begin())
                break;

            auto [v, pos] = *--it;

            Choose(v, pos);
        }

        if (val) {
            std::cout << "-1\n";
            exit(0);
        }
    }

    if (st.size()) {
        std::cout << "-1\n";
        exit(0);
    }

    for (int i = 0; i < (n + 1) / 2; ++i)
        std::cout << ans[i] << " \n"[i == (n + 1) / 2 - 1];
    return 0;
}
