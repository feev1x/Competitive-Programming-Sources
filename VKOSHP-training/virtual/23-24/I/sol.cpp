#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::map<std::pair<int, int>, bool> mp;
    
    std::array<std::array<int, 2>, 2> cnt;
    for (auto &u: cnt) {
        for (auto &v: u) {
            v = 0;
        }
    }


    for (int i = 0; i < n; ++i) {
        int x, y; std::cin >> x >> y;

        cnt[x % 2][y % 2] -= mp[{x, y}];

        mp[{x, y}] = !mp[{x, y}];

        cnt[x % 2][y % 2] += mp[{x, y}];

        std::cout << std::max({cnt[0][0], cnt[0][1], cnt[1][0], cnt[1][1]}) << '\n';
    }

    return 0;
}
