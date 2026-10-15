#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

inline int binpow(int a, int n) {
    int res = 1;
    while (n) { if (n & 1) res = mul(res, a); a = mul(a, a), n >>= 1; }
    return res;
}

struct Dsu {
    std::vector<int> sz, p;
    std::stack<std::tuple<int, int, int>> st;
    int n;
    Dsu(int n) : n(n) {
        sz.assign(n, 1);
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
    }
    inline int get(int v) { return v == p[v] ? v : get(p[v]); }
    inline bool check(int u, int v) { return get(u) != get(v); }
    inline void unite(int u, int v) {
        u = get(u), v = get(v);
        if (u != v) {
            if (sz[u] > sz[v]) std::swap(u, v);
            sz[v] += sz[u];
            st.emplace(u, v, p[u]);
            p[u] = v;
        }
    }
    inline void rollback() {
        auto [u, v, x] = st.top(); st.pop();
        sz[v] -= sz[u];
        p[u] = x;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n);
    std::vector<std::tuple<int, int, int>> e;
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, l; std::cin >> a >> b >> l; --a, --b;
        e.emplace_back(l, a, b);
    }
    Dsu d(n);
    std::sort(e.begin(), e.end());
    for (auto [l, u, v]: e) edges.emplace_back(u, v);
    int res = 1, cost = 0;
    for (int i = 0; i < m; ++i) {
        int j = i; while (j < m && std::get<0>(e[j]) == std::get<0>(e[i])) j++;
        j--;
        int sz = j - i + 1;
        std::vector<int> p(sz);
        std::iota(p.begin(), p.end(), 0);
        std::set<int> st;
        do {
            int cn = 0, val = 0;
            for (auto u: p) {
                if (d.check(edges[i + u].first, edges[i + u].second)) {
                    d.unite(edges[i + u].first, edges[i + u].second);
                    cn++;
                    val += 1 << u;
                }
            }
            st.emplace(val);
            while (cn--) d.rollback();
        } while (next_permutation(p.begin(), p.end()));
        for (int x = i; x <= j; ++x) d.unite(edges[x].first, edges[x].second);
        res = mul(res, st.size());
        i = j;
    }
    d = Dsu(n);
    for (auto [l, u, v]: e) {
        if (d.check(u, v)) {
            d.unite(u, v);
            add_self(cost, l);
        }
    }
    std::cout << cost << ' ' << res << '\n';
    return 0;
}
