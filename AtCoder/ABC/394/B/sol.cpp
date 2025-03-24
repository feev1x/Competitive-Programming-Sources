/**
 *    author:  feev1x
 *    created: 06.03.2025 16:01:04
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::string> s(n);
    for (auto &u: s) {
        std::cin >> u;
    }

    std::sort(s.begin(), s.end(), [](std::string &s1, std::string &s2) {
            return s1.size() < s2.size();
            });

    std::string res;
    for (auto u: s) {
        res += u;
    }

    std::cout << res << '\n';
    return 0;
}
