/**
 *    author:  feev1x
 *    created: 18.07.2025 23:48:55
**/
#include <bits/stdc++.h>

inline int INF = 1e9;

struct Centroid {
    std::vector<int> sz, d, mxd;
    std::vector<bool> del;
    std::vector<std::vector<std::pair<int, int>>> g;
    std::array<std::vector<int>, 2> c, f;
    int n, nw_sz, k, m;

    Centroid(std::vector<std::vector<std::pair<int, int>>> _g, int _k, int _m) : g(_g), n(g.size() - 1), k(_k), m(_m) {
        del.resize(n + 1);
        d.resize(n + 1);
        mxd.resize(n + 1);
        sz.resize(n + 1);
    }

    inline void dfs(int v, int p) {
        sz[v] = 1;

        for (auto [to, w]: g[v]) {
            if (to == p || del[to])
                continue;

            dfs(to, v);
            sz[v] += sz[to];
        }
    }

    inline int get(int v, int p) {
        for (auto [to, w]: g[v]) {
            if (to == p || del[to])
                continue;

            if (sz[to] > nw_sz / 2)
                return get(to, v);
        }

        return v;
    }

    inline void calc(int v, int p) {
        d[v] = d[p] + 1;
        mxd[v] = d[v];

        for (auto [to, w]: g[v]) {
            if (to == p || del[to])
                continue;

            calc(to, v);
            mxd[v] = std::max(mxd[v], mxd[to]);
        }
    }

    inline int get_ans(int v, int p, int cost, int cnt, int fs, int val, int val1, bool flag) {
        int ans = 0, cst = cost + cnt / (k + 1), fst = flag ? cnt % (k + 1) : fs;

        int l = 1, r = c[0].size() - 1, res = -1;
        while (l <= r) {
            int md = l + r >> 1;

            if (c[val1 ^ 1][md] + cst <= m)
                l = md + 1, res = md;
            else
                r = md - 1;
        }

        if (res != -1)
            ans = std::max(ans, d[v] + res);

        l = 1, r = c[0].size() - 1, res = -1;
        while (l <= r) {
            int md = l + r >> 1;

            if (c[val1][md] + cst < m)
                l = md + 1, res = md;
            else
                r = md - 1;
        }

        if (res != -1)
            ans = std::max(ans, d[v] + res);

        l = 1, r = c[0].size() - 1, res = -1;
        while (l <= r) {
            int md = l + r >> 1;

            if (c[val1][md] + cst < m)
                l = md + 1;
            else if (c[val1][md] + cst > m)
                r = md - 1;
            else {
                if (f[val1][md] + fst <= k)
                    l = md + 1, res = md;
                else
                    r = md - 1;
            }
        }

        if (res != -1)
            ans = std::max(ans, d[v] + res);

        for (auto [to, w]: g[v]) {
            if (to == p || del[to])
                continue;

            if (w == val)
                ans = std::max(ans, get_ans(to, v, cost, cnt + 1, fs + flag, val, val1, flag));
            else
                ans = std::max(ans, get_ans(to, v, cost + cnt / (k + 1), 1, flag ? cnt % (k + 1) : fs, w, val1, false));
        }

        return ans;
    }

    inline void update(int v, int p, int cost, int cnt, int fs, int val, int val1, bool flag) {
        int fst = flag ? cnt % (k + 1) : fs, cst = cost + cnt / (k + 1);
        if (c[val1][d[v]] > cst || c[val1][d[v]] == cst && f[val1][d[v]] > fst) {
            c[val1][d[v]] = cst;
            f[val1][d[v]] = fst;
        }

        for (auto [to, w]: g[v]) {
            if (to == p || del[to])
                continue;

            if (w == val)
                update(to, v, cost, cnt + 1, fs + flag, val, val1, flag);
            else
                update(to, v, cost + cnt / (k + 1), 1, flag ? cnt % (k + 1) : fs, w, val1, false);
        }
    }

    inline int dec(int v) {
        dfs(v, v);

        nw_sz = sz[v], v = get(v, v);

        d[v] = 0;

        c[0].clear();
        c[1].clear();
        f[0].clear();
        f[1].clear();

        for (auto [to, w]: g[v]) {
            if (del[to])
                continue;

            calc(to, v);
        }

        std::sort(g[v].begin(), g[v].end(), [&](std::pair<int, int> x, std::pair<int, int> y) {
            return mxd[x.first] < mxd[y.first];
        });

        int res = 0;
        for (auto [to, w]: g[v]) {
            if (del[to])
                continue;

            while (c[0].size() <= mxd[to])
                c[0].emplace_back(INF),
                c[1].emplace_back(INF),
                f[0].emplace_back(INF),
                f[1].emplace_back(INF);

            res = std::max(res, get_ans(to, v, 0, 1, 1, w, w, true));

            update(to, v, 0, 1, 1, w, w, true);
        }

        del[v] = true;
        for (auto [to, w]: g[v]) {
            if (del[to])
                continue;

            res = std::max(res, dec(to));
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, m; std::cin >> n >> k >> m;

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    Centroid cen(g, k, m);

    std::cout << cen.dec(1) << '\n';
    return 0;
}
