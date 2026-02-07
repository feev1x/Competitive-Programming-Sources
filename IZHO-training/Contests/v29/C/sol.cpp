#include <bits/stdc++.h>

constexpr int N = 1e5 + 5, INF = 1e9;

struct Node {
    int val = INF, pos = 0;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    Segtree(int n) : n(n) {
        t.resize(4 * n);
    }

    inline Node comb(Node a, Node b) {
        Node res;

        if (a.val > b.val) {
            res = b;
        } else {
            res = a;
        }

        return res;
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = {x, tl};
            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm) {
            update(v << 1, tl, tm, i, x);
        } else {
            update(v << 1 | 1, tm + 1, tr, i, x);
        }

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }

    inline Node get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return {INF, 0};
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        int tm = tl + tr >> 1;
        return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r).pos;
    }
};

struct Dsu {
    std::vector<int> p, sz;
    int n;

    Dsu(int n) : n(n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        std::iota(p.begin(), p.end(), 0);
    }
    
    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline bool unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            sz[v] += sz[u];
            p[u] = v;
            return true;
        }

        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q; std::cin >> n >> m >> q;

    std::set<int> st;
    Segtree t(n);
    std::vector<int> h(n + 1), next(n + 1, n + 1), prev(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> h[i];

        t.update(i, h[i]);
        if (i < n) {
            st.emplace(i);
        }
    }

    {
        std::stack<int> stk;
        
        for (int i = 1; i <= n; ++i) {
            while (stk.size() && h[stk.top()] >= h[i]) {
                stk.pop();
            }

            if (stk.size()) {
                prev[i] = stk.top();
            }

            stk.emplace(i);
        }
    }

    {
        std::stack<int> stk;
        
        for (int i = n; i >= 1; --i) {
            while (stk.size() && h[stk.top()] >= h[i]) {
                stk.pop();
            }

            if (stk.size()) {
                next[i] = stk.top();
            }

            stk.emplace(i);
        }
    }

    Dsu d(n);
    int sq = sqrt(n);
    std::vector<std::vector<int>> qb(n / sq + 1), le(n + 1), re(n + 1);

    for (int i = 1; i <= n; ++i) {
        if (next[i] < n + 1) {
            le[next[i]].emplace_back(i);
            re[i].emplace_back(next[i]);
        }

        if (prev[i] > -1) {
            re[prev[i]].emplace_back(i);
            le[i].emplace_back(prev[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::sort(le[i].begin(), le[i].end(), std::greater<>());
        std::sort(re[i].begin(), re[i].end());
    }
    
    std::vector<std::array<int, 4>> e(m);
    std::vector<std::tuple<int, int, int>> edges;
    std::unordered_map<int, std::unordered_map<int, int>> mp;
    int nw = 0;
    for (auto &[l, r, w, t]: e) {
        std::cin >> l >> r >> w >> t;

        if (r - l + 1 > sq) {
            qb[l / sq].emplace_back(nw++);
        } else {
            for (auto [l, r, w, t]: e) {
                std::vector<int> val;
     
                for (int i = l; i <= r; ++i) {
                    if (h[i] <= t) {
                        val.emplace_back(i);
                    }
                }
     
                for (int i = 0; i + 1 < val.size(); ++i) {
                    int u = val[i], v = val[i + 1];
     
                    int U = std::min(u, v), V = std::max(u, v);
                    if (!mp[U].count(V)) {
                        mp[U][V] = INF;
                    }

                    mp[U][V] = std::min(mp[U][V], w);
                }
            }
        }
    }

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    auto Add = [&](int u, int v, int w) {
        if (d.unite(u, v)) {
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
    };

    for (int i = 0; i <= n / sq; ++i) {
        std::sort(qb[i].begin(), qb[i].end());

        int s = (i + 1) * sq, r = s;
        for (auto idx: qb[i]) {
//            assert(e[idx][0] < s);
//            assert(r <= e[idx][1] || r - e[idx][1] == 1);
            while (r <= e[idx][1]) {
                for (auto u: le[r]) {
                    if (u < e[idx][0]) {
                        break;
                    }

                    int U = std::min(u, r), V = std::max(u, r);
                    if (!mp[U].count(V)) {
                        mp[U][V] = INF;
                    }

                    mp[U][V] = std::min(mp[U][V], e[idx][2]);
                }

                r++;
            }

            int l = s - 1;
            while (l >= e[idx][0]) {
                for (auto u: re[l]) {
                    if (u >= r) {
                        break;
                    }

                    int U = std::min(u, l), V = std::max(u, l);
                    if (!mp[U].count(V)) {
                        mp[U][V] = INF;
                    }

                    mp[U][V] = std::min(mp[U][V], e[idx][2]);
                }

                l--;
            }

        }
    }

    std::vector<std::tuple<int, int, int>> eg;
    for (auto [key, val]: mp) {
        for (auto [key1, val1]: val) {
            eg.emplace_back(val1, key, key1);
        }
    }

    std::sort(eg.begin(), eg.end());
    for (auto [w, u, v]: eg) {
        Add(u, v, w);
    }

    std::vector<int> tin(n + 1), tout(n + 1);
    std::vector<std::array<int, 20>> anc(n + 1), mx(n + 1);
    for (auto &u: anc) {
        for (auto &v: u) {
            v = 0;
        }
    }

    for (auto &u: mx) {
        for (auto &v: u) {
            v = 0;
        }
    }

    int _t = 0;
    auto Dfs = [&](auto &&self, int v) -> void {
        tin[v] = ++_t;

        for (int i = 1; i < 20; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            mx[v][i] = std::max(mx[v][i - 1], mx[anc[v][i - 1]][i - 1]);
        }

        for (auto [to, w]: g[v]) {
            if (to == anc[v][0]) {
                continue;
            }

            anc[to][0] = v;
            mx[to][0] = w;
            self(self, to);
        }

        tout[v] = ++_t;
    };

    for (int i = 1; i <= n; ++i) {
        if (tin[i] == 0) {
            Dfs(Dfs, i);
        }
    }

    tout[0] = ++_t;

    auto Lca = [&](int u, int v) {
        if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
            return u;
        }

        for (int i = 19; i >= 0; --i) {
            int nx = anc[u][i];
            
            if (tin[nx] > tin[v] || tout[v] > tout[nx]) {
                u = nx;
            }
        }

        return anc[u][0];
    };

    while (q--) {
        int a, b; std::cin >> a >> b;

        if (d.get(a) != d.get(b)) {
            std::cout << "-1\n";
            continue;
        }

        int lca = Lca(a, b);

        int max = 0;
        for (int i = 19; i >= 0; --i) {
            int nx = anc[a][i];

            if (tin[nx] <= tin[lca] && tout[lca] <= tout[nx]) {
                continue;
            }

            max = std::max(max, mx[a][i]);
            a = nx;
        }

        if (a != lca) {
            max = std::max(max, mx[a][0]);
        }

        for (int i = 19; i >= 0; --i) {
            int nx = anc[b][i];

            if (tin[nx] <= tin[lca] && tout[lca] <= tout[nx]) {
                continue;
            }

            max = std::max(max, mx[b][i]);
            b = nx;
        }

        if (b != lca) {
            max = std::max(max, mx[b][0]);
        }

        std::cout << max << '\n';
    }

    return 0;
}
