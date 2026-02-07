#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline void chmin(int &a, int b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    
    std::string v1, v2; std::cin >> v1 >> v2;

    std::reverse(v1.begin(), v1.end());
    std::reverse(v2.begin(), v2.end());

    while (v1.size() && v2.size() && v1.back() == v2.back()) {
        v1.pop_back();
        v2.pop_back();
    }

    if (v1.size() && v2.size()) {
        std::cout << "-1\n";
        return 0;
    }

    if (v2.size()) {
        std::swap(v1, v2);
    }

    std::reverse(v1.begin(), v1.end());

    std::array<int, 26> empt;

    for (auto &u: empt) {
        u = 0;
    }

    std::vector<std::array<int, 26>> tr;
    std::vector<std::string> s;
    std::vector<int> idx;
    tr.emplace_back(empt);
    idx.emplace_back(-1);

    int n; std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string t; std::cin >> t;
        s.emplace_back(t);

        int nw = 0;
        for (auto u: t) {
            if (!tr[nw][u - 'a']) {
                tr[nw][u - 'a'] = tr.size();
                tr.emplace_back(empt);
                idx.emplace_back(-1);
            }

            nw = tr[nw][u - 'a'];
        }

        idx[nw] = i;
    }

    std::vector<std::vector<int>> dp2(n, std::vector<int>(105, INF));
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dp(v1.size() + 105, std::vector<int>(n, INF));
    std::vector<std::vector<std::pair<int, int>>> add;

    dp[0][0] = 0;
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == INF) {
                continue;
            }

            for (int k = 0; k < n; ++k) {
                bool flag = true;

                for (int l = 0; i + l < v1.size() && l < s[k].size(); ++l) {
                    if (v1[i + l] != s[k][l]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    chmin(dp[i + s[k].size()][k], dp[i][j] + 1);
                }
            }
        }
    }

    for (int i = v1.size(); i < dp.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] != INF) {
                q.emplace(j, (int)s[j].size() - i + (int)v1.size());

                if (add.size() <= dp[i][j]) {
                    add.resize(dp[i][j] + 1);
                }

                add[dp[i][j]].emplace_back(j, (int)s[j].size() - i + (int)v1.size());
            }
        }
    }

    for (int i = 0; i < add.size(); ++i) {
        if (add[i].size()) {
            for (auto [u, v]: add[i]) {
                dp2[u][v] = i;
                q.emplace(u, v);
            }

            break;
        }
    }

    int res = INF;
    while (q.size()) {
        auto [i, j] = q.front();

        if (s[i].size() == j) {
            chmin(res, dp2[i][j]);
        }

        q.pop();

        if (dp2[i][j] + 1 < add.size()) {
            for (auto [u, v]: add[dp2[i][j] + 1]) {
                if (dp2[u][v] != INF) {
                    continue;
                }

                dp2[u][v] = dp2[i][j] + 1;
                q.emplace(u, v);
            }
        }

        for (int k = 0; k < n; ++k) {
            int ni, nj;

            if (j + s[k].size() > s[i].size()) {
                ni = k, nj = (int)s[i].size() - j;
            } else {
                ni = i, nj = j + s[k].size();
            }

            bool flag = true;

            for (int l = 0; j + l < s[i].size() && l < s[k].size(); ++l) {
                if (s[i][j + l] != s[k][l]) {
                    flag = false;
                    break;
                }
            }

            if (flag && dp2[ni][nj] == INF) {
                chmin(dp2[ni][nj], dp2[i][j] + 1);

                if (nj == s[ni].size()) {
                    chmin(res, dp2[ni][nj]);
                } else {
                    q.emplace(ni, nj);
                }
            }
        }
    }

    if (res == INF) {
        res = -1;
    }

    std::cout << res << '\n';
    return 0;
}
