/**
 *    author:  feev1x
 *    created: 14.11.2025 13:06:53
**/
#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int64_t>(l, r)(rng)

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (auto &u: s)
        std::cin >> u;

    std::vector<std::vector<int64_t>> val(n, std::vector<int64_t>(m));
    for (auto &u: val)
        for (auto &v: u)
            v = rnd(1e16, 1e18);

    std::map<int64_t, bool> used;

    int64_t hsh = val[n - 1][m - 1] + val[n - 1][m - 2] + val[n - 2][m - 1] + val[n - 2][m - 2];
    std::queue<std::tuple<std::array<int, 4>, std::array<int, 4>, int>> q;

    int dx[]{0, 0, 1, -1};
    int dy[]{1, -1, 0, 0};
    auto IsCon = [&](std::array<int, 4> x, std::array<int, 4> y) {
        std::vector<bool> used(4);

        std::queue<int> q;

        q.emplace(0);
        used[0] = true;
        while (q.size()) {
            int v = q.front();

            q.pop();

            for (int k = 0; k < 4; ++k) {
                int i = dx[k] + x[v], j = dy[k] + y[v];

                int pos = -1;
                for (int l = 0; l < 4; ++l)
                    if (x[l] == i && y[l] == j) {
                        pos = l;
                        break;
                    }

                if (pos == -1 || used[pos])
                    continue;

                used[pos] = true;
                q.emplace(pos);
            }
        }

        return used[0] && used[1] && used[2] && used[3];
    };

    int cx[]{0, 0, 1, -1, 1, 1, -1, -1};
    int cy[]{1, -1, 0, 0, 1, -1, -1, 1};

    q.push({{0, 0, 1, 1}, {1, 0, 1, 0}, 0});
    while (q.size()) {
        auto [x, y, ans] = q.front();

        int64_t nwh = 0;
        q.pop();

        for (int i = 0; i < 4; ++i)
            nwh += val[x[i]][y[i]];

        if (nwh == hsh) {
            std::cout << ans << '\n';
            exit(0);
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                int I = cx[j] + x[i], J = cy[j] + y[i];

                if (I < 0 || I >= n || J < 0 || J >= m || s[I][J] == '#')
                    continue;

                bool flag = true;
                for (int l = 0; l < 4; ++l)
                    if (x[l] == I && y[l] == J) {
                        flag = false;
                        break;
                    }

                if (!flag)
                    continue;

                int64_t hh = nwh - val[x[i]][y[i]] + val[I][J];

                if (used[hh])
                    continue;

                int Ox = x[i], Oy = y[i];

                x[i] = I, y[i] = J;

                if (!IsCon(x, y)) {
                    x[i] = Ox, y[i] = Oy;
                    continue;
                }

                used[hh] = true;
                q.emplace(x, y, ans + 1);

                x[i] = Ox, y[i] = Oy;
            }
        }
    }

    std::cout << "-1\n";
    return 0;
}

