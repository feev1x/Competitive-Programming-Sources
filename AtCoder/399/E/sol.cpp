/**
 *    author:  feev1x
 *    created: 29.03.2025 18:15:21
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::string s, t; std::cin >> s >> t;

    std::vector<std::vector<int>> g(26);
    std::vector<std::vector<int>> r_g(26);
    std::vector<bool> good(26);
    int cnt = 0;
    std::map<char, char> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.count(s[i])) {
            s[i] = mp[s[i]];
        } else {
            if (s[i] != t[i]) {
                cnt++;
            }

            g[s[i] - 'a'].emplace_back(t[i] - 'a');
            r_g[t[i] - 'a'].emplace_back(s[i] - 'a');

            if (r_g[t[i] - 'a'].size() > 1 || s[i] == t[i]) {
                good[t[i] - 'a'] = true;
            }

            s[i] = mp[s[i]] = t[i];
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (g[i].empty()) {
            for (int j = 0; j < 26; ++j) {
                g[i].emplace_back(j);
                r_g[j].emplace_back(i);
            }
        }
    }

    std::vector<bool> used(26), nw(26);

    int cyc = -1;
    auto Dfs = [&](auto &&self, int v) -> void {
        nw[v] = true;
        used[v] = true;
        
        for (auto to: g[v]) {
            if (g[to].size() == 26) {
                continue;
            }

            if (nw[to]) {
                cyc = to;
            }

            if (used[to]) {
                continue;
            }

            self(self, to);
        }

        nw[v] = false;
    };

    for (int i = 0; i < 26; ++i) {
        if (used[i] || g[i].size() == 26) {
            continue;
        }

        cyc = -1;
        Dfs(Dfs, i);

        if (cyc != -1) {
            int cnt_g = r_g[cyc].size() > 1, cnt_g1 = good[cyc];

            for (int u = g[cyc][0]; u != cyc; u = g[u][0]) {
                cnt_g += r_g[u].size() > 1;
                cnt_g1 += good[u];
            }

            if (!cnt_g && !cnt_g1) {
                std::cout << -1 << '\n';

                exit(0);
            }

            if (!cnt_g1) {
                cnt++;
            }
        }
    }

    std::cout << (s == t ? cnt : -1) << '\n';
    return 0;
}
