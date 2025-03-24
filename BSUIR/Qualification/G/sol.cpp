/**
 *    author:  feev1x
 *    created: 19.03.2025 13:45:35
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];
    }
    
    std::vector<std::vector<int>> g(n + m + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') {
                g[j].emplace_back(i + m);
            } else {
                g[i + m].emplace_back(j);
            }
        }
    }

    std::vector<int> ord;
    std::vector<bool> used(n + m + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto to: g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }

        ord.emplace_back(v);
    };

    for (int i = 1; i <= n + m; ++i) {
        if (used[i]) {
            continue;
        }

        Dfs(Dfs, i);
    }

    std::vector<std::tuple<char, int, char>> res;
    std::vector<std::string> ss(n + 1, std::string(m + 1, ' '));

    ss[0].clear();
    for (auto v: ord) {
        if (v > m) {
            res.emplace_back('r', v - m, '*');

            for (int j = 1; j <= m; ++j) {
                ss[v - m][j] = '*';
            }
        } else {
            res.emplace_back('c', v, '.');

            for (int i = 1; i <= n; ++i) {
                ss[i][v] = '.';
            }
        }
    }

    if (ss == s) {
        std::cout << res.size() << '\n';

        for (auto [rc, v, ch]: res) {
            std::cout << rc << ' ' << v << ' ' << ch << '\n';
        }
    } else {
        std::cout << "-1\n";
    }
    return 0;
}
