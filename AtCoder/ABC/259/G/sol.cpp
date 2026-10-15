#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;
constexpr int SINF = 1e9;

using edges = std::vector<std::pair<int, int>>;
using idxgraph = std::vector<edges>;

struct Flow {
    idxgraph g;
    edges e;
    std::vector<int64_t> c, f;
    std::vector<int> d, nw;
    int n, sz, et;

    inline void addB(int u, int v, int64_t cap) {
        g[u].emplace_back(v, e.size());
        e.emplace_back(u, v);
        c.emplace_back(cap);
        f.emplace_back(cap);
    }

    Flow(idxgraph _g, edges _e, std::vector<int64_t> _c) : g(_g), e(_e), c(_c), n(g.size()), sz(e.size()) {
        d.resize(n);
        nw.resize(n);
        f.resize(sz);

        for (int i = 0; i < sz; ++i) {
            auto [u, v] = e[i];

            addB(v, u, c[i]);
        }
    }

    inline void bfs(int s) {
        std::queue<int> q;

        std::fill(d.begin(), d.end(), SINF);
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

    inline int64_t dfs(int v, int64_t mn) {
        if (v == et) {
            return mn;
        }

        for (; nw[v] < g[v].size(); ++nw[v]) {
            auto [to, i] = g[v][nw[v]];

            if (d[to] == d[v] + 1 && c[i] > f[i]) {
                int64_t got = dfs(to, std::min(mn, c[i] - f[i]));

                if (got != -1) {
                    f[i] += got;
                    f[(i + sz) % e.size()] -= got;

                    return got;
                }
            }
        }

        return -1;
    }

    inline int64_t get(int s, int t) {
        et = t;

        while (true) {
            int cnt = 0;

            bfs(s);
            while (dfs(s, INF) != -1) {
                cnt++;
            }

            if (!cnt) {
                break;
            }
        }

        int64_t res = 0;
        for (auto [to, i]: g[s]) {
            res += f[i];
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w; std::cin >> h >> w;

    std::vector<std::vector<int>> a(h, std::vector<int>(w));
    idxgraph g(h + w + 2);
    edges e;
    std::vector<int64_t> c;
    auto Add = [&](int u, int v, int64_t cap) {
        g[u].emplace_back(v, e.size());
        e.emplace_back(u, v);
        c.emplace_back(cap);
    };

    int64_t res = 0;
    int s = h + w, t = s + 1;
    for (int i = 0; i < h; ++i) {
        int64_t sum = 0;

        for (auto &u: a[i]) {
            std::cin >> u;
            sum += u;
        }

        if (sum > 0) {
            res += sum;
            Add(s, i, sum);
        }
    }

    for (int j = 0; j < w; ++j) {
        int64_t sum = 0;

        for (int i = 0; i < h; ++i) {
            sum += a[i][j];

            Add(i, j + h, (a[i][j] >= 0 ? (int64_t)a[i][j] : INF));
        }

        if (sum > 0) {
            res += sum;
            Add(j + h, t, sum);
        }
    }

    Flow fl(g, e, c);

    std::cout << res - fl.get(s, t) << '\n';
    return 0;
}
