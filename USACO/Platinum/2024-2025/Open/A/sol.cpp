#include <bits/stdc++.h>

constexpr int N = 5e5 + 5;

inline void chmax(int &a, int b) { a = (a < b ? b : a); }

struct Bit {
    std::vector<int> p;
    int n;
    Bit(int n) : n(n) { p.resize(n + 1); };
    inline void update(int r, int x) { for (; r <= n; r += r & -r) chmax(p[r], x); }
    inline int get(int r) {
        int res = 0;
        for (; r > 0; r -= r & -r) chmax(res, p[r]);
        return res;
    }
};

struct Node {
    int y = N, i = N;
};

struct Segtree {
    std::vector<std::set<std::pair<int, int>>> a;
    std::vector<Node> t;
    int n;
    Segtree(int n) : n(n) { t.resize(4 * n), a.resize(n + 1); }
    inline Node comb(Node a, Node b) { return a.y > b.y ? b : a; }
    inline void add(int v, int tl, int tr, int x, int y, int i) {
        if (tl == tr) {
            a[tl].emplace(y, i);
            std::tie(t[v].y, t[v].i) = *a[tl].begin();
            return;
        }
        int tm = tl + tr >> 1;
        if (x <= tm) add(v << 1, tl, tm, x, y, i);
        else add(v << 1 | 1, tm + 1, tr, x, y, i);
        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
    inline void remove(int v, int tl, int tr, int x, int y, int i) {
        if (tl == tr) {
            a[tl].erase({y, i});
            if (a[tl].size()) std::tie(t[v].y, t[v].i) = *a[tl].begin();
            else t[v] = {N, N};
            return;
        }
        int tm = tl + tr >> 1;
        if (x <= tm) remove(v << 1, tl, tm, x, y, i);
        else remove(v << 1 | 1, tm + 1, tr, x, y, i);
        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
    inline Node get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr) return {N, N};
        if (l <= tl && tr <= r) return t[v];
        int tm = tl + tr >> 1;
        return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }
    inline void add(int x, int y, int i) { add(1, 1, n, x, y, i); }
    inline void remove(int x, int y, int i) { remove(1, 1, n, x, y, i); }
    inline Node get(int l, int r) { return get(1, 1, n, l, r); }
};

inline void solve(int m) {
    int n; std::cin >> n;
    std::vector<int> x1(n), y1(n), x2(n), y2(n), idx(n);
    for (int i = 0; i < n; ++i) std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i], idx[i] = i;
    auto idx2 = idx;
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return x1[i] < x1[j] || x1[i] == x1[j] && y1[i] < y1[j];
    });
    std::sort(idx2.begin(), idx2.end(), [&](int i, int j) {
        return x2[i] < x2[j] || x2[i] == x2[j] && y2[i] < y2[j];
    });
    if (m == 2) {
        std::string s(n, '0');
        Bit bit(2 * n);
        int j = 0;
        for (auto i: idx2) {
            while (j < n && x1[idx[j]] < x2[i]) bit.update(y1[idx[j]], idx[j]), j++;
            s[i] = char((bit.get(y2[i] - 1) <= i) + '0');
        }
        std::cout << s << '\n';
    } else {
        Segtree t(2 * n);
        std::vector<bool> used(n);
        for (int i = 0; i < n; ++i) t.add(x1[i], y1[i], i);
        auto Dfs = [&](auto &&self, int v) -> void {
            if (used[v]) return;
            used[v] = true;
            t.remove(x1[v], y1[v], v);
            for (Node sm = t.get(1, x2[v] - 1); sm.y < y2[v]; sm = t.get(1, x2[v] - 1)) self(self, sm.i);
            std::cout << v + 1 << ' ';
        };
        for (int i = 0; i < n; ++i) Dfs(Dfs, i);
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt, m; std::cin >> tt >> m;
    while (tt--) solve(m);
    return 0;
}
