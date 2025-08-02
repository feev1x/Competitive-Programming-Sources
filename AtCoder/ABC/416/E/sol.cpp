/**
 *    author:  feev1x
 *    created: 26.07.2025 18:41:10
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    int64_t sum = 0;
    std::vector<std::vector<int64_t>> d(n + 1, std::vector<int64_t>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
        d[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int a, b; int64_t c; std::cin >> a >> b >> c;

        d[a][b] = d[b][a] = std::min(d[a][b], c);
    }

    int k; int64_t t; std::cin >> k >> t;
    std::vector<int> D(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> D[i];

        for (int j = 0; j < i; ++j)
            d[D[i]][D[j]] = d[D[j]][D[i]] = std::min(d[D[i]][D[j]], t);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (d[i][j] != INF)
                sum += d[i][j];

    int q; std::cin >> q;
    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int x, y, T; std::cin >> x >> y >> T;

            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j) {
                    if (d[i][j] != INF)
                        sum -= d[i][j];

                    d[i][j] = std::min(d[i][j], d[i][x] + T + d[y][j]);
                    d[i][j] = std::min(d[i][j], d[i][y] + T + d[x][j]);
                    if (d[i][j] != INF)
                        sum += d[i][j];
                }
        } else if (type == 2) {
            int x; std::cin >> x;

            D.emplace_back(x);
            for (int i = 0; i < D.size(); ++i) {
                if (d[D[i]][x] != INF)
                    sum -= d[D[i]][x];

                if (d[x][D[i]] != INF)
                    sum -= d[x][D[i]];

                d[D[i]][x] = d[x][D[i]] = std::min(d[x][D[i]], t);
                if (d[D[i]][x] != INF)
                    sum += d[D[i]][x];

                if (d[x][D[i]] != INF)
                    sum += d[x][D[i]];
            }

            std::vector<int> vl(n + 1);
            for (int j = 1; j <= n; ++j) {
                int val = -1;

                for (int i = 0; i < D.size(); ++i)
                    if (val == -1 || d[j][val] > d[j][D[i]])
                        val = D[i];

                vl[j] = val;
            }

            for (int j = 1; j <= n; ++j) {
                int val = -1;

                for (int i = 0; i < D.size(); ++i)
                    if (val == -1 || d[val][j] > d[D[i]][j])
                        val = D[i];

                for (int i = 1; i <= n; ++i) {
                    if (d[i][j] != INF)
                        sum -= d[i][j];

                    d[i][j] = std::min(d[i][j], d[i][vl[i]] + t + d[val][j]);
                    if (d[i][j] != INF)
                        sum += d[i][j];
                }
            }
        } else
            std::cout << sum << '\n';
    }
    return 0;
}
