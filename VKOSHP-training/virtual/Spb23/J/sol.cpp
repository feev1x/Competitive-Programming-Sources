/**
 *    author:  feev1x
 *    created: 14.11.2025 13:06:53
**/
#include <bits/stdc++.h>

#define int int64_t

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int64_t>(l, r)(rng)

constexpr int INF = 1e18;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (auto &u: s)
        std::cin >> u;
    
    int dx[]{0, 0, 1, -1};
    int dy[]{1, -1, 0, 0};

    int cx[]{0, 0, 1, -1, 1, 1, -1, -1};
    int cy[]{1, -1, 0, 0, 1, -1, -1, 1};
    std::vector<std::pair<std::array<int, 4>, std::array<int, 4>>> pts;

    std::vector<int> ps(1 << 16, -1), msk;
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

    for (int mask = 0; mask < 1 << 16; ++mask) {
        if (__builtin_popcount(mask) != 4)
            continue;

        std::array<std::array<int, 4>, 4> a;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                a[i][j] = mask >> (i * 4 + j) & 1;

        bool flag = false;
        for (int i = 0; i < 4; ++i)
            if (a[i][3])
                flag = true;


        if (!flag)
            continue;

        flag = false;
        for (int j = 0; j < 4; ++j)
            if (a[3][j])
                flag = true;

        if (!flag)
            continue;
        
        std::array<int, 4> x, y;

        int nw = 0;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (a[i][j])
                    x[nw] = i, y[nw] = j, nw++;

        if (!IsCon(x, y))
            continue;

        ps[mask] = pts.size();
        pts.emplace_back(x, y);
        msk.emplace_back(mask);
    }

    std::vector<std::vector<std::tuple<int, int, int>>> g(pts.size());
    int nw = 0;
    for (auto [x, y]: pts) {
        bool x0 = false, y0 = false;

        for (int i = 0; i < 4; ++i)
            if (x[i] == 0)
                x0 = true;

        for (int i = 0; i < 4; ++i)
            if (y[i] == 0)
                y0 = true;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                int I = cx[j] + x[i], J = cy[j] + y[i];

                if (I < 0 || I > 3 || J < 0 || J > 3) {
                    if (I < 0) {
                        continue;
                    } else if (I > 3) {
                        if (x0)
                            continue;

                        auto Ox = x; auto Oy = y;
                        int nx = 0, ny = 0;
                        int mask = 0;

                        for (int l = 0; l < 4; ++l)
                            x[l]--;

                        I--;

                        x[i] = I, y[i] = J;

                        for (int l = 0; l < 4; ++l)
                            mask ^= 1 << (x[l] * 4 + y[l]), nx = std::max(nx, x[l]), ny = std::max(ny, y[l]);

                        if (!IsCon(x, y)) {
                            x = Ox, y = Oy;
                            continue;
                        }

                        g[nw].emplace_back(nx + 1, ny, ps[mask]);

                        x = Ox, y = Oy;
                    } else if (J < 0) {
                        continue;
                    } else if (J > 3) {
                        if (y0)
                            continue;

                        auto Ox = x; auto Oy = y;
                        int nx = 0, ny = 0;
                        int mask = 0;

                        for (int l = 0; l < 4; ++l)
                            y[l]--;

                        J--;

                        x[i] = I, y[i] = J;

                        for (int l = 0; l < 4; ++l)
                            mask ^= 1 << (x[l] * 4 + y[l]), nx = std::max(nx, x[l]), ny = std::max(ny, y[l]);

                        if (!IsCon(x, y)) {
                            x = Ox, y = Oy;
                            continue;
                        }

                        g[nw].emplace_back(nx, ny + 1, ps[mask]);

                        x = Ox, y = Oy;
                    }

                    continue;
                }

                if (msk[nw] >> (I * 4 + J) & 1)
                    continue;

                auto Ox = x; auto Oy = y;

                int nx = 0, ny = 0;
                int mask = 0;

                x[i] = I, y[i] = J;

                for (int i = 0; i < 4; ++i)
                    nx = std::max(nx, x[i]);

                for (int i = 0; i < 4; ++i)
                    ny = std::max(ny, y[i]);

                if (nx == 2) {
                    for (int i = 0; i < 4; ++i)
                        x[i]++;
                } else if (ny == 2)
                    for (int i = 0; i < 4; ++i)
                        y[i]++;

                for (int i = 0; i < 4; ++i)
                    mask ^= 1 << (x[i] * 4 + y[i]);


                if (!IsCon(x, y)) {
                    x = Ox, y = Oy;
                    continue;
                }

                g[nw].emplace_back(nx, ny, ps[mask]);
                
                x = Ox, y = Oy;
            }
        }

        nw++;
    }

    std::queue<std::tuple<int, int, int>> q;
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(pts.size(), INF)));

    q.emplace(1, 1, 14);
    dp[1][1][14] = 0;

    while (q.size()) {
        auto [x, y, idx] = q.front();

        q.pop();
        for (auto [Dx, Dy, ni]: g[idx]) {
            int nx = Dx + x - 3, ny = Dy + y - 3;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dp[nx][ny][ni] <= dp[x][y][idx] + 1)
                continue;

            bool flag = true;
            auto [xx, yy] = pts[ni];
            for (int i = 0; i < 4; ++i) {
                int X = xx[i], Y = yy[i];
                if (X + nx - 3 < 0 || X + nx - 3 >= n || Y + ny - 3 < 0 || Y + ny - 3 >= m || s[X + nx - 3][Y + ny - 3] == '#') {
                    flag = false;
                    break;
                }
            }

            if (!flag)
                continue;

            dp[nx][ny][ni] = dp[x][y][idx] + 1;

            q.emplace(nx, ny, ni);
        }
    }

    if (dp[n - 1][m - 1][14] == INF) {
        std::cout << "-1\n";
        exit(0);
    }

    std::cout << dp[n - 1][m - 1][14] << '\n';
    return 0;
}
