#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> l(n), r(n);

    std::set<std::pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        std::string s, t; std::cin >> s >> t;

        l[i] = std::stoi(s.substr(0, 2)) * 60 + std::stoi(s.substr(3, 2));
        r[i] = std::stoi(t.substr(0, 2)) * 60 + std::stoi(t.substr(3, 2)) + 1;

        st.emplace(l[i], i);
        st.emplace(r[i], i);
    }

    int res = 0;
    std::set<int> nw;
    for (auto [tm, i]: st) {
        if (nw.size() && nw.find(i) != nw.end()) {
            nw.erase(i);
        } else {
            nw.emplace(i);
        }

        res = std::max(res, (int)nw.size());
    }

    std::cout << res << '\n';
    return 0;
}
