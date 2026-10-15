#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q; std::cin >> q;
    std::multiset<int> st, ans;
    auto get = [&](std::multiset<int>::iterator it) {
        if (st.empty() || it == st.end() || next(it) == st.end()) return -1;
        return (*next(it)) ^ (*it);
    };
    while (q--) {
        int type; std::cin >> type;
        if (type == 1) {
            int x; std::cin >> x;
            if (st.size()) {
                auto it = st.lower_bound(x);
                if (st.size() && it != st.begin() && it != st.end()) ans.erase(ans.find(get(prev(it))));
            }
            st.emplace(x);
            auto it = st.lower_bound(x);
            if (it != st.begin() && it != st.end()) ans.emplace(get(prev(it)));
            if (get(it) != -1) ans.emplace(get(it));
        } else if (type == 2) {
            int x; std::cin >> x;
            auto it = st.lower_bound(x);
            if (it != st.begin() && it != st.end()) ans.erase(ans.find(get(prev(it))));
            if (get(it) != -1) ans.erase(ans.find(get(it)));
            st.erase(st.find(x));
            if (st.size()) {
                it = st.lower_bound(x);
                if (st.size() && it != st.begin() && it != st.end()) ans.emplace(get(prev(it)));
            }
        } else std::cout << *ans.begin() << '\n';
    }
    return 0;
}
