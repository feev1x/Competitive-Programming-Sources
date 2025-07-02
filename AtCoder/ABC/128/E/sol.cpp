/**
 *    author:  feev1x
 *    created: 16.04.2025 12:05:02
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<std::tuple<int, int, int>> sp;
    for (int i = 0; i < n; ++i) {
        int s, t, x; std::cin >> s >> t >> x;

        sp.emplace_back(s - x, 0, x);
        sp.emplace_back(t - x, 1, x);
    }

    std::vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        int d; std::cin >> d;

        sp.emplace_back(d, 3, i);
    }
    
    std::multiset<int> st;
    std::sort(sp.begin(), sp.end());
    for (auto [pos, type, nw]: sp) {
        if (type == 0) {
            st.emplace(nw);
        } else if (type == 1) {
            st.erase(st.find(nw));
        } else {
            ans[nw] = st.size() ? *st.begin() : -1;
        }
    }

    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << '\n'; 
    }
    return 0;
}
