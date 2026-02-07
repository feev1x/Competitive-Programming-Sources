#include <bits/stdc++.h>

#define int int64_t

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, n, l; std::cin >> k >> n >> l;

    std::string s; std::cin >> s;

    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i > 1; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }

    auto C = [&](int n, int k) {
        return mul(fac[n], mul(inv[k], inv[n - k]));
    };

    int res = 1;

    std::vector<int> m;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'O') {
            continue;
        }

        m.emplace_back(i);
    }

    m.emplace_back(n);

    int ls = 0;
    for (int i = 0; i + 1 < m.size(); ++i) {
        int sz = m[i + 1] - m[i] - 1;

        res = mul(res, C(ls + k, k));

        ls = (k + ls) - sz;
    }

    std::cout << binpow(res, l) << '\n';
    return 0;
}
