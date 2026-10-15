#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::map<char, int> mp;
    while (std::getline(std::cin, s)) {
        for (auto u: s) {
            if (u == ' ') {
                continue;
            }
            mp[u]++;
        }
    }
    int mx = 0;
    std::vector<std::pair<int, int>> pr;
    for (auto [key, val]: mp) {
        mx = std::max(mx, val);
        pr.emplace_back(key, val);
    }
    std::vector<std::vector<char>> res(mx + 1, std::vector<char>(pr.size()));
    for (int i = 0; i <= mx; ++i) {
        for (int j = 0; j < pr.size(); ++j) {
            std::cout << char((i == mx ? pr[j].first : ((int)mx - pr[j].second > i ? ' ' : '#')));
        }
        std::cout << '\n';
    }
    return 0;
}
