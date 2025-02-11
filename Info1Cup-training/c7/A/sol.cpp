/**
 *    author:  feev1x
 *    created: 05.02.2025 08:42:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int r, c, n; std::cin >> r >> c >> n;

    std::map<int, std::set<std::pair<int, int>>> mp;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];

        mp[x[i]].emplace(y[i], i);
    }

    std::vector<std::array<int, 32>> anc(n);

    for (int i = 0; i < n; ++i) {
        auto it = mp[x[i] + 1].lower_bound({y[i], -1});

        if (mp[x[i] + 1].empty() || it == mp[x[i] + 1].end()) {
            anc[i][0] = -1;
        } else {
            anc[i][0] = it->second;
        }
    }

    for (int j = 1; j < 32; ++j) {
        for (int i = 0; i < n; ++i) {
            if (anc[i][j - 1] == -1) {
                anc[i][j] = -1;

                continue;
            }

            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    int t; std::cin >> t;
    while (t--) {
        int xs, ys, xe, ye; std::cin >> xs >> ys >> xe >> ye;

        if (xs > xe || ys > ye) {
            std::cout << "No\n";

            continue;
        }

        int dis = xe - xs;

        if (!dis) {
            std::cout << "Yes\n";

            continue;
        }

        auto it = mp[xs].lower_bound({ys, -1});

        int in = -1;
        if (mp[xs].size() && it != mp[xs].end()) {
            in = it->second;
        }

        for (int i = 31; i >= 0 && in > -1; --i) {
            if (x[in] + (1 << i) < xe && anc[in][i] != -1) {
                in = anc[in][i];
            }
        }

        if (in != -1 && x[in] == xe - 1 && y[in] <= ye) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
