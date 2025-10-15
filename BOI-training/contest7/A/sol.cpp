#include <bits/stdc++.h>

std::vector<int> solve(int n, std::vector<int>& v, int q, std::vector<std::pair<int,int>>& queries) {
    std::vector<int> res, p(n + 1);

    for (int i = 1; i <= n; ++i) {
        p
    }
    

    for (auto [l, r]: queries) {
        std::set<int> st;

        for (int i = 1; i <= n + 1; ++i)
            st.emplace(i);

        for (int i = l; i <= r; ++i)
            st.erase(v[i]);

        int k = 0, mex = *st.begin();
        
        st.clear();
        for (int i = 1; i < mex; ++i)
            st.emplace(i);

        if (st.empty()) {
            res.emplace_back(r - l + 1);
            continue;
        }

        for (int i = l; i <= r; ++i) {
            if (st.empty()) {
                k++;

                for (int j = 1; j < mex; ++j)
                    st.emplace(j);
            }

            st.erase(v[i]);
        }

        if (st.empty())
            k++;

        res.emplace_back(k);
    }

    return res;
}
