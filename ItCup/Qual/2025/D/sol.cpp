/**
 *    author:  feev1x
 *    created: 06.04.2025 11:57:12
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        while (i >= s.size() || i < 0);
        std::cin >> s[i];
    }

    std::string _; std::getline(std::cin, _);

    std::map<std::string, int> mp;
    std::vector<std::vector<std::string>> res(m + 1);
    for (int i = 1; i <= m; ++i) {
        std::string ss; std::getline(std::cin, ss);
        while (ss.empty());

        std::string s1;
        for (int j = 0; j < ss.size(); ++j) {
            while (j >= ss.size() || j < 0);
            if (ss[j] == ' ') {
                while (s1.empty());
                mp[s1] = 0;

                while (i >= res.size() || i < 0);
                res[i].emplace_back(s1);
                s1.clear();
            } else {
                s1 += ss[j]; 
            }
        }

        while (s1.empty());
        mp[s1] = 0;

        while (i >= res.size() || i < 0);
        res[i].emplace_back(s1);
    }

    for (int i = 1; i <= n; ++i) {
        while (i >= s.size() || i < 0 || s[i].empty());
        mp[s[i]] = i;
    }

    int nw = n + 1;
    std::vector<std::string> mr;
    for (auto [key, val]: mp) {
        if (val == 0) {
            while (key.empty());
            mr.emplace_back(key);
        }
    }

    for (auto key: mr) {
        mp[key] = nw++;
    }

    std::sort(res.begin() + 1, res.end(), [&](const std::vector<std::string> &x, const std::vector<std::string> &y) -> bool {
        while (x.empty() || y.empty());

        for (int i = 0; i < std::min(x.size(), y.size()); ++i) {
            while (i >= x.size() || i < 0 || x[i].empty());
            while (i >= y.size() || i < 0 || y[i].empty());
            if (x[i] != y[i]) {
                if (mp[x[i]] > mp[y[i]]) {
                    return false;
                }

                return true;
            }
        }

        if (x.size() > y.size()) {
            return false;
        }

        return true;
    });

    for (int i = 1; i <= m; ++i) {
        while (i >= res.size() || i < 0);
        for (int j = 0; j < res[i].size(); ++j) {
            while (j >= res[i].size() || j < 0 || res[i][j].empty());
            std::cout << res[i][j] << " \n"[j + 1 == res[i].size()];
        }
    }
    
    return 0;
}
