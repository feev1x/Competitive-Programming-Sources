/**
 *    author:  feev1x
 *    created: 10.02.2025 11:46:55
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("convention2.in", "r", stdin);
    std::freopen("convention2.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::set<std::array<int, 3>> st, nw;
    for (int i = 1; i <= n; ++i) {
        int a, t; std::cin >> a >> t;

        st.insert({a, t, i});
    }
    
    int tm = -1, res = 0;
    for (auto it = st.begin(); it != st.end(); ++it) {
        auto it1 = it;
        ++it1;

        nw.insert({(*it)[2], (*it)[0], (*it)[1]});

        tm = std::max(tm, (*nw.begin())[1]);
        
        if (it1 == st.end() || (*it1)[0] > tm) {
            it1 = nw.begin();
            res = std::max(res, tm - (*it1)[1]);

            tm += (*it1)[2];

            nw.erase(it1);
        }
    }

    std::cout << res << '\n';
    return 0;
}
