#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::map<int, std::vector<std::pair<int, int>>> dg;
    std::map<int, std::vector<int>> row, col;
    std::map<int, std::unordered_map<int, bool>> mp;
    std::vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i] >> y[i];

        mp[x[i]][y[i]] = true;
        dg[x[i] - y[i]].emplace_back(x[i], y[i]);
        row[x[i]].emplace_back(y[i]);
        col[y[i]].emplace_back(x[i]);
    }

    for (auto &[key, val]: dg) {
        std::sort(val.begin(), val.end());
    }

    for (auto &[key, val]: row) {
        std::sort(val.begin(), val.end());
    }

    for (auto &[key, val]: col) {
        std::sort(val.begin(), val.end());
    }

    int64_t res = 0;
    for (int i = 1; i <= n; ++i) {
        auto &rw = row[x[i]];
        auto &cl = col[y[i]];
        auto &d = dg[x[i] - y[i]];

        int cr = rw.end() - std::upper_bound(rw.begin(), rw.end(), y[i]);
        int cc = cl.end() - std::upper_bound(cl.begin(), cl.end(), x[i]);
        int cd = d.end() - std::upper_bound(d.begin(), d.end(), std::pair{x[i], y[i]});

        int mn = std::min({cr, cc, cd});

        if (mn == cr) {
            int j = (int)rw.size() - cr;

            for (; j < rw.size(); ++j) {
                int df = std::abs(y[i] - rw[j]);

                if (mp[x[i] + df][y[i]] && mp[x[i] + df][rw[j]]) {
                    res++;
                }
            }
        } else if (mn == cc) {
            int j = (int)cl.size() - cc;

            for (; j < cl.size(); ++j) {
                int df = std::abs(x[i] - cl[j]);

                if (mp[x[i]][y[i] + df] && mp[cl[j]][y[i] + df]) {
                    res++;
                }
            }
        } else {
            int j = (int)d.size() - cd;

            for (; j < d.size(); ++j) {
                if (mp[x[i]][d[j].second] && mp[d[j].first][y[i]]) {
                    res++;
                }
            }
        }
    }

    std::cout << res << '\n';
    return 0;
}
