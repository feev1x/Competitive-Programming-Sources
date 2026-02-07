#include <bits/stdc++.h>
#include "grader.h"

inline void solve(int n) {
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.emplace(i);
    }

    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        auto q = p;

        q.erase(q.begin());
        for (int j = 0; j < n; ++j) {
            
        }
    }
}
