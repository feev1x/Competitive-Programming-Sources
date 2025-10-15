/**
 *    author:  feev1x
 *    created: 09.09.2025 11:22:51
**/
#include <bits/stdc++.h>

#define int int64_t

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

constexpr int MOD = 998244353;

inline int mul(int a, int b) {
    return a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a += MOD;

    if (a < 0)
        a -= MOD;
}

struct Node {
    int pow = 0, val = 0;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
    }

    inline Node comb(Node a, Node b) {
        if (a.pow > b.pow)
            std::swap(a, b);

        if (b.pow - a.pow > 31)
            return b;

        int val = 1ll << (b.pow - a.pow);

        if (val * b.val >= a.val)
            return b;

        return a;
    }

    inline void update(int v, int tl, int tr, const int &i, const int &pw, const int &x) {
        if (tl == tr) {
            t[v] = {pw, x};
            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, pw, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, pw, x);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }

    inline Node get(int v, int tl, int tr, const int &l, const int &r) {
        if (l > tr || tl > r)
            return {0, 0};

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;
        return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int i, int pw, int x) {
        update(1, 1, n, i, pw, x);
    }

    inline Node get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<std::vector<std::pair<char, int>>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::string c; int idx; std::cin >> c >> idx;

        g[i].emplace_back(c[0], idx);
        std::cin >> c >> idx;

        g[i].emplace_back(c[0], idx);
    }

    std::vector<int> w(n + 2), tin(n + 1), tout(n + 1), tw(n + 2), pos(n + 2), idx(n + 2), dep(n + 1), d(n + 2);
    for (int i = 1; i <= n + 1; ++i)
        std::cin >> w[i];

    int _t = 0;
    auto Dfs = [&](auto &&self, int v) -> void {
        tin[v] = tout[v] = ++_t;

        for (auto [ch, to]: g[v]) {
            if (ch == 'W')
                tw[to] = ++_t, d[to] = dep[v] + 1;
            else 
                dep[to] = dep[v] + 1, self(self, to);
        }

        tout[v] = ++_t;
    };

    Dfs(Dfs, 1);

    Segtree t(_t);
    for (int i = 1; i <= n + 1; ++i) {
        t.update(tw[i], d[i], w[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int k, we; std::cin >> k >> we;

            w[k] = we;
            t.update(tw[k], d[k], we);
        } else {
            int s; std::cin >> s;

            auto got = t.get(tin[s], tout[s]);
            std::cout << mul(binpow(2, got.pow - dep[s]), got.val) << '\n';
        }
    }
    return 0;
}
