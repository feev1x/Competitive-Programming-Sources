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

    int n, m; std::cin >> n >> m;

    std::vector<std::string> str(n);
    for (auto &u: str) {
        std::cin >> u;
    }

    std::vector<std::vector<std::pair<int, int>>> ps(10);
    std::vector<std::vector<int>> pss(10);
    std::vector<std::vector<int>> cnt(10, std::vector<int>(n));
    for (int j = 0; j < m; ++j) {
        std::array<bool, 10> inc;

        for (int i = 0; i < n; ++i) {
            if (cnt[str[i][j] - '0'][i] < n) {
                ps[str[i][j] - '0'].emplace_back(i, pss[str[i][j] - '0'].size() + n);
                inc[str[i][j] - '0'] = true;
                cnt[str[i][j] - '0'][i]++;
            }
        }

        for (int i = 0; i < 10; ++i) {
            if (inc[i]) {
                pss[i].emplace_back(j);
            }
        }
    }

    int res = n * m + 5;
    for (char c = 0; c <= 9; ++c) {
        int nw = pss[c].size() + n;

        idxgraph g(nw + 2);
        edges e;
        std::vector<int> cp;
        auto Add = [&](int u, int v, int cap) {
            g[u].emplace_back(v, e.size());
            e.emplace_back(u, v);
            cp.emplace_back(cap);
        };

        int s = nw, t = nw + 1;

        for (int i = 0; i < pss[c].size(); ++i) {
            int j = pss[c][i];

            Add(i + n, t, 1);
        }

        for (auto [i, j]: ps[c]) {
            Add(i, j, 1);
        }


        for (int i = 0; i < n; ++i) {
            Add(s, i, 1);
        }

        int l = 0, r = n * m + 5, ans = n * m + 5;
        while (l <= r) {
            int mid = l + r >> 1;

            for (int i = 0; i < pss[c].size(); ++i) {
                int j = pss[c][i];

                cp[i] = mid / m + (mid % m >= j);
            }

            Flow fl(g, e, cp);

            if (fl.get(s, t) == n) {
                r = mid - 1, ans = mid;
            } else {
                l = mid + 1;
            }
        }

        res = std::min(res, ans);
    }
    
    std::cout << (res == n * m + 5 ? -1 : res) << '\n';
    return 0;
}

