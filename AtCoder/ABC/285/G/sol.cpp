#include <bits/stdc++.h>

constexpr int INF = 1e9;

struct Flow {
    std::vector<std::vector<std::pair<int, int>>> g;
    std::vector<std::pair<int, int>> e;
    std::vector<int> d, f, c, nw;
    int n, sz, et;

    inline void add(int u, int v, int cap, int flow) {
        g[u].emplace_back(v, e.size());
        e.emplace_back(u, v);
        f.emplace_back(flow);
        c.emplace_back(cap);
    }

    Flow(std::vector<int> c, std::vector<std::vector<std::pair<int, int>>> g, std::vector<std::pair<int, int>> e) : e(e), g(g), n(g.size()), c(c) {
        f.resize(c.size());
        d.resize(n);
        nw.resize(n);

        sz = e.size();
        for (int i = 0; i < sz; ++i) {
            auto [v, u] = e[i];

            add(u, v, c[i], c[i]);
        }
    }

    inline void bfs(int s) {
        std::queue<int> q;

        q.emplace(s);
        std::fill(d.begin(), d.end(), INF);

        d[s] = 0;
        while (q.size()) {
            int v = q.front();

            q.pop();
            for (auto [to, i]: g[v]) {
                if (d[to] > d[v] + 1 && f[i] < c[i]) {
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

            if (d[to] == d[v] + 1 && f[i] < c[i]) {
                int got = dfs(to, std::min(mn, c[i] - f[i]));
                if (got != -1) {
                    int op = (i + sz) % (int)e.size();

                    f[i] += got;
                    f[op] -= got;
                    return got;
                }
            }
        }

        return -1;
    }

    inline std::vector<int> get(int s, int t) {
        et = t;

        while (true) {
            int pcnt = 0;

            std::fill(nw.begin(), nw.end(), 0);
            bfs(s);
            while (true) {
                if (dfs(s, INF) != -1) {
                    pcnt++;
                } else {
                    break;
                }
            }

            if (!pcnt) {
                break;
            }
        }

        return f;
    }
};

inline bool solve(std::vector<std::vector<std::pair<int, int>>> g, std::vector<std::array<int, 4>> edges) {
    int n = g.size(), m = edges.size();

    int idx = 0;
    std::vector<int> c(m), bal(n);
    std::vector<std::pair<int, int>> e;
    for (auto &[u, v, dem, cap]: edges) {
        bal[u] -= dem;
        bal[v] += dem;

        c[idx++] = cap - dem;
        e.emplace_back(u, v);
    }

    auto Add = [&](int u, int v, int cap) {
        g[u].emplace_back(v, e.size());
        e.emplace_back(u, v);
        c.emplace_back(cap);
    };

    int s = n, t = n + 1;

    n += 2;

    g.resize(n);
    bal.resize(n);

    std::vector<int> ps;
    for (int i = 0; i < n; ++i) {
        if (!bal[i]) {
            continue;
        }

        if (bal[i] > 0) {
            Add(s, i, bal[i]);
        } else {
            ps.emplace_back(e.size());
            Add(i, t, -bal[i]);
        }
    }

    int i = 0;
    Flow fl(c, g, e);

    auto f = fl.get(s, t);

    for (auto [to, i]: g[s]) {
        if (c[i] > f[i]) {
            return false;
        }
    }

    for (auto i: ps) {
        if (c[i] > f[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w; std::cin >> h >> w;

    std::vector<std::vector<int>> idx(h, std::vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            idx[i][j] = i * w + j;
        }
    }

    std::vector<std::string> s(h);
    for (auto &u: s) {
        std::cin >> u;
    }

    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};

    std::vector<std::vector<std::pair<int, int>>> g(h * w + 2);
    std::vector<std::array<int, 4>> edges;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if ((i + j) & 1) {
                g[idx[i][j]].emplace_back(h * w + 1, edges.size());
                edges.push_back({idx[i][j], h * w + 1, s[i][j] == '2' ? 1 : 0, s[i][j] != '1' ? 1 : 0});
            } else {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];

                    if (x >= 0 && x < h && y >= 0 && y < w) {
                        g[idx[i][j]].emplace_back(idx[x][y], edges.size());
                        edges.push_back({idx[i][j], idx[x][y], 0, s[i][j] != '1' && s[x][y] != '1' ? 1 : 0});
                    }
                }

                g[h * w].emplace_back(idx[i][j], edges.size());
                edges.push_back({h * w, idx[i][j], s[i][j] == '2' ? 1 : 0, s[i][j] != '1' ? 1 : 0});
            }
        }
    }


    g[h * w + 1].emplace_back(h * w, edges.size());
    edges.push_back({h * w + 1, h * w, 0, INF});


    if (solve(g, edges)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}
