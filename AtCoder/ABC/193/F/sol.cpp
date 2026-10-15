#include <bits/stdc++.h>

constexpr int INF = 1e9;

using idxgraph = std::vector<std::vector<std::pair<int, int>>>;
using edges = std::vector<std::pair<int, int>>;

struct Flow {
    idxgraph g;
    edges e;
    std::vector<int> nw, f, c, d;
    int n, sz, et;

    inline void addB(int u, int v, int cap) {
        g[u].emplace_back(v, e.size());
        e.emplace_back(u, v);
        f.emplace_back(cap);
        c.emplace_back(cap);
    }

    Flow(idxgraph g, edges e, std::vector<int> c) : g(g), e(e), c(c), n(g.size()), sz(e.size()) {
        nw.resize(n);
        d.resize(n);
        f.resize(sz);

        for (int i = 0; i < sz; ++i) {
            auto [u, v] = e[i];

            addB(v, u, c[i]);
        }
    }

    inline void bfs(int s) {
        std::queue<int> q;

        std::fill(d.begin(), d.end(), INF);
        std::fill(nw.begin(), nw.end(), 0);

        d[s] = 0;
        q.emplace(s);
        while (q.size()) {
            int v = q.front();

            q.pop();
            for (auto [to, i]: g[v]) {
                if (d[to] > d[v] + 1 && c[i] > f[i]) {
                    d[to] = d[v] + 1;

                    q.emplace(to);
                }
            }
        }
    }

    inline int dfs(int v, int mn) {
        if (v == et) {
            return mn;
        }

        for (; nw[v] < g[v].size(); ++nw[v]) {
            auto [to, i] = g[v][nw[v]];

            if (d[to] == d[v] + 1 && c[i] > f[i]) {
                int got = dfs(to, std::min(mn, c[i] - f[i]));

                if (got != -1) {
                    f[i] += got;
                    f[(i + sz) % (int)e.size()] -= got;

                    return got;
                }
            }
        }

        return -1;
    }

    inline int get(int s, int t) {
        et = t;

        while (true) {
            int pcnt = 0;

            bfs(s);
            while (dfs(s, INF) != -1) {
                pcnt++;
            }

            if (!pcnt) {
                break;
            }
        }

        int res = 0;
        for (auto [to, i]: g[s]) {
            res += f[i];
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<std::vector<int>> idx(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            idx[i][j] = n * i + j;
        }
    }

    edges e;
    std::vector<int> c;
    idxgraph g(n * n + 2);
    auto Add = [&](int u, int v, int cap) {
        g[u].emplace_back(v, e.size());
        e.emplace_back(u, v);
        c.emplace_back(cap);
    };

    std::vector<std::string> str(n);
    for (auto &u: str) {
        std::cin >> u;
    }
    
    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};
    int s = n * n, t = s + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) & 1) {
                if (str[i][j] == 'W') {
                    Add(s, idx[i][j], INF);
                } else if (str[i][j] == 'B') {
                    Add(idx[i][j], t, INF);
                }
            } else {
                if (str[i][j] == 'B') {
                    Add(s, idx[i][j], INF);
                } else if (str[i][j] == 'W') {
                    Add(idx[i][j], t, INF);
                }
            }

            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;

                if (std::min(x, y) >= 0 && std::max(x, y) < n) {
                    Add(idx[i][j], idx[x][y], 1);
                }
            }
        }
    }

    Flow fl(g, e, c);

    std::cout << 2 * (n - 1) * n - fl.get(s, t) << '\n';
    return 0;
}
