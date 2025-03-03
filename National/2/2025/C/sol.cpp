/**
 *    author:  feev1x
 *    created: 22.02.2025 14:43:56
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::string s1, s2; std::cin >> s1 >> s2;

    std::map<char, char> mp;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) {
            continue;
        }

        if (!mp.count(s1[i])) {
            mp[s1[i]] = s2[i];
        }

        s1[i] = mp[s1[i]];
    }

    if (s1 != s2) {
        std::cout << "NO\n";

        exit(0);
    }

    std::vector<std::pair<char, char>> res;
    for (auto [key, val]: mp) {
        if (key != val) {
            res.emplace_back(key, val);
        }
    }

    std::cout << "YES\n" << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u << ' ' << v << '\n';
    }
    return 0;
}
