/**
 *    author:  feev1x
 *    created: 03.11.2025 14:24:18
**/
#include <bits/stdc++.h>

#define int int64_t

constexpr int64_t INF = 1e18;

struct Segtree {
    std::vector<int> t, psh;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
        psh.resize(4 * n + 1);
    }

    inline void push(int v) {
        if (psh[v]) {
            psh[v << 1] += psh[v];
            psh[v << 1 | 1] += psh[v];

            t[v << 1] += psh[v];
            t[v << 1 | 1] += psh[v];
            psh[v] = 0;
        }
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = std::max(t[v], x);
            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl > r || l > tr)
            return;

        if (l <= tl && tr <= r) {
            psh[v] += x;
            t[v] += x;
            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return -INF;

        if (l <= tl && tr <= r)
            return t[v];

        push(v);
        
        int tm = tl + tr >> 1;
        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

struct Segtree1 {
    std::vector<int> p;
    int n;

    Segtree1(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        for (; r <= n; r += r & -r)
            p[r] += x;
    }

    inline int get(int r) {
        int res = 0;

        for (; r > 0; r -= r & -r)
            res += p[r];

        return res;
    }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::array<int, 3>> sw(n), dem(m);
    std::vector<int64_t> p(m + 1), B;
    for (auto &[a, b, cost]: sw)
        std::cin >> a >> b >> cost, B.emplace_back(b);

    for (auto &[c, d, profit]: dem)
        std::cin >> c >> d >> profit, B.emplace_back(d);

    std::sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    for (auto &[a, b, cost]: sw)
        b = std::lower_bound(B.begin(), B.end(), b) - B.begin() + 1;

    for (auto &[c, d, profit]: dem)
        d = std::lower_bound(B.begin(), B.end(), d) - B.begin() + 1;

    Segtree t(n + m + 5);
    Segtree1 t1(n + m + 5);

    std::sort(sw.begin(), sw.end());
    std::sort(dem.begin(), dem.end());

    int t1sum = 0;
    for (auto [c, d, profit]: dem) {
        t1.update(d, profit);

        t1sum += profit;

        if (d > 1)
            t.update(1, d - 1, profit);
    }

    int j = m - 1;
    for (int i = n - 1; i >= 0 && j >= 0; --i) {
        while (j >= 0 && dem[j][0] > sw[i][0]) {
            if (dem[j][1] > 1)
                t.update(1, dem[j][1] - 1, -dem[j][2]);

            t1.update(dem[j][1], -dem[j][2]);

            t1sum -= dem[j][2];

            j--;
        }
        
        if (j < 0)
            break;

        int sum = t1sum - t1.get(sw[i][1]);

        int got = 0;

        if (sw[i][1] > 1)
            got = std::max(got, t.get(1, sw[i][1] - 1) - sum - sw[i][2]);

        got = std::max(got, t1sum - sum - sw[i][2]);

        got += sum;

        t.update(sw[i][1], got);
    }

    while (j >= 0) {
        if (dem[j][1] > 1)
            t.update(1, dem[j][1] - 1, -dem[j][2]);

        t1.update(dem[j][1], -dem[j][2]);

        j--;
    }

    std::cout << t.t[1] << '\n';
    return 0;
}
