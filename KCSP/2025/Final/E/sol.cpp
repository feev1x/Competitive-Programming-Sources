/**
 *    author:  feev1x
 *    created: 15.06.2025 14:48:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::map<std::string, int> mp;
    std::vector<int> nx(n + 1, -1), pv(n + 1, -1);
    int nw = 1;
    for (int i = 0; i < m; ++i) {
        std::string s1, s2; std::cin >> s1 >> s2;
        
        if (!mp.count(s1)) {
            mp[s1] = nw++;
        }

        if (!mp.count(s2)){
            mp[s2] = nw++;
        }

        nx[mp[s1]] = mp[s2];
        pv[mp[s2]] = mp[s1];
    }

    std::vector<long double> ans(n + 1), cans(n + 1);

    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    while (q.size()) {
        auto [mask, v] = q.front();

        q.pop();
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                continue;
            }

            if (nx[v] != -1 && nx[v] != i + 1 || nx[i + 1] != -1 && (mask >> (nx[i + 1] - 1) & 1)) {
                ans[__builtin_popcount(mask) + 1]++;
                cans[__builtin_popcount(mask) + 1]++;
            } else {

                cans[__builtin_popcount(mask) + 1]++;
                int nmask = mask | (1 << i);

                q.emplace(nmask, i + 1);
            }
        }
    }

    std::cout << std::fixed << std::setprecision(10);
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] / cans[i] << '\n';
    }
    return 0;
}
