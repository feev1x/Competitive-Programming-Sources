#include <bits/stdc++.h>

#define int int64_t

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    a %= MOD;

    if (a < 0)
        a += MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
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

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;
    while (tt--) {
        int n, m, l; std::cin >> n >> m >> l;

        std::vector<std::vector<std::pair<int, int64_t>>> g(n + 1);
        
        std::vector<std::tuple<int, int, int64_t>> e(m);
        for (auto &[u, v, w]: e)
            std::cin >> u >> v >> w;

        std::vector<int64_t> d(n + 1);

        int res = 1;
        for (int i = 1; i <= n; ++i)
            std::cin >> d[i];

        for (auto [u, v, w]: e) {
            if (d[u] > d[v]) {
                g[u].emplace_back(v, w);
            } else if (d[v] > d[u]) {
                g[v].emplace_back(u, w);
            } else {
                if (w == -1)
                    res = mul(res, l);
            }
        }

        for (int v = 2; v <= n; ++v) {
            bool flag = true;

            for (auto [to, w]: g[v])
                if ((w != -1 && d[to] + w < d[v]) || (w == -1 && d[to] + l < d[v]))
                    flag = false;

            if (!flag) {
                res = 0;
                break;
            }

            int Mul = 1;
            for (auto [to, w]: g[v])
                if (w != -1 && d[to] + w == d[v])
                    flag = false;
                else if (w == -1)
                    Mul = mul(Mul, l - (d[v] - d[to]) + 1);

            if (!flag) {
                res = mul(res, Mul);
                continue;
            }

            std::vector<int> ar;

            int ml = 1;
            for (auto [to, w]: g[v])
                if (w == -1)
                    ar.emplace_back(l - (d[v] - d[to])), ml = mul(ml, l - (d[v] - d[to]) + 1);

            int bc = 1, ans = 0;
            for (auto u: ar) {
                ml = mul(ml, binpow(u + 1, MOD - 2));

                add_self(ans, mul(ml, bc));
                
                bc = mul(bc, u);
            }

            res = mul(res, ans);
        }

        if (d[1] != 0)
            res = 0;

        std::cout << res << '\n';
    }
}
