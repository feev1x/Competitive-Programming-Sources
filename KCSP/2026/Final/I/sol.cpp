#include:wq
<bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (auto &u: a) for (auto &v: u) std::cin >> v;
    std::map<std::pair<int, int>, int> mp;
    int nw = 0;
    for (int i = 0; i <= 6; ++i) for (int j = i; j <= 6; ++j) mp[{i, j}] = mp[{j, i}] = nw++;
    auto Rec = [&](auto &&self, std::vector<std::vector<int>> b, std::vector<int> cnt) -> int {
        
    };
    return 0;
}
