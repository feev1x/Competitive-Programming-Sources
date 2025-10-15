/**
 *    author:  feev1x
 *    created: 10.09.6025 11:35:05
**/
#include <bits/stdc++.h>

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

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;

    if (a < 0)
        a += MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<std::vector<int>> g(n);
    std::vector<int64_t> f(n), p(n), tin(n), tout(n);
    for (int i = 1; i < n; ++i) {
        std::cin >> p[i];

        g[p[i]].emplace_back(i);
    }


    std::cin >> f[0];

    int sum = f[0] % MOD, sum1 = mul(int(f[0] % MOD), int(f[0] % MOD));
    for (int i = 1; i < n; ++i) {
        std::cin >> f[i];

        f[i] = f[p[i]] & f[i], add_self(sum, int(f[i] % MOD)), add_self(sum1, mul(int(f[i] % MOD), int(f[i] % MOD)) % MOD);
    }

    int _t = 0;
    std::vector<int> idx;
    auto Dfs = [&](auto &&self, int v) -> void {
        tin[v] = ++_t;

        if (idx.size() <= _t)
            idx.resize(_t + 1);

        idx[tin[v]] = v + 1;

        for (auto to: g[v])
            self(self, to);

        tout[v] = ++_t;
    };

    Dfs(Dfs, 0);

    idx.resize(_t + 1);

    std::cout << mul(sum, sum) << ' ' << mul(((mul(sum, sum) - sum1) % MOD + MOD) % MOD, (MOD + 1) / 2) << '\n';

    p.clear();
    g.clear();

    std::vector<int64_t> qx(q + 1), qv(q + 1);
    std::array<std::vector<bool>, 60> valid;
    for (auto &u: valid)
        u.resize(_t + 1);

    for (int i = 1; i <= q; ++i) {
        int64_t v, x; std::cin >> v >> x;

        qx[i] = x;
        qv[i] = v;

        for (int j = 0; j < 60; ++j) {
            if (x & 1) {
                x >>= 1;
                continue;
            }

            valid[j][tin[v]] = true;

            x >>= 1;
        }
    }

    std::array<std::vector<int>, 60> next;
    for (auto &u: next)
        u.resize(_t + 1);

    for (int64_t j = 0; j < 60; ++j)
        for (int i = 1; i <= _t; ++i)
            if (idx[i] && (f[idx[i] - 1] >> j & 1))
                valid[j][i] = true;

    for (int j = 0; j < 60; ++j) {
        next[j][_t] = -1;

        for (int i = _t - 1; i >= 1; --i) {
            if (valid[j][i + 1])
                next[j][i] = i + 1;
            else
                next[j][i] = next[j][i + 1];
        }
    }

    for (int l = 1; l <= q; ++l) {
        for (int64_t j = 0; j < 60; ++j) {
            if (qx[l] >> j & 1)
                continue;

            int nw = 0;
            for (nw = tin[qv[l]]; nw <= tout[qv[l]] && nw != -1; nw = next[j][nw]) {
                int i = idx[nw] - 1;

                if (f[i] >> j & 1) {
                    add_self(sum, (int)(-f[i] % MOD));
                    add_self(sum1, -mul(int(f[i] % MOD), int(f[i] % MOD)));
                    f[i] = f[i] ^ (1ll << j);
                    add_self(sum, int(f[i] % MOD));
                    add_self(sum1, mul(int(f[i] % MOD), int(f[i] % MOD)));
                }

                if (nw != tin[qv[l]])
                    valid[j][nw] = false;
            }

            next[j][tin[qv[l]]] = nw;
        }

        std::cout << mul(sum, sum) << ' ' << mul(((mul(sum, sum) - sum1) % MOD + MOD) % MOD, (MOD + 1) / 2) << '\n';
    }

    return 0;
}
