/**
 *    author:  feev1x
 *    created: 26.07.2025 18:07:16
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<std::string> s(n);
    for (auto &u: s)
        std::cin >> u;

    std::sort(s.begin(), s.end(), [&](std::string s1, std::string s2) {
        return s1 + s2 < s2 + s1 || s1 + s2 == s2 + s1 && s1.size() < s2.size();
    });

    std::string res;

    for (int i = 0; i < k; ++i)
        res += s[0];

    std::cout << res << '\n';
    return 0;
}

