#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<int> c(n + 1), cnt(61), fac(n + m + 1, 1), inv(n + m + 1, 1), vnv(n + m + 1), p2(n + m + 1, 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];

        cnt[c[i]]++;
    }

    for (int i = 0; i <= n + m; ++i) {
        vnv[i] = binpow(i, MOD - 2);
    }

    for (int i = 1; i <= n + m; ++i) {
        p2[i] = mul(p2[i - 1], 2);
    }

    for (int i = 2; i <= n + m; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    inv[n + m] = binpow(fac[n + m], MOD - 2);

    for (int i = n + m - 1; i >= 2; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }

    auto C = [&](int n, int k) {
        return mul(fac[n], mul(inv[k], inv[n - k]));
    };

    while (m--) {
        int type; int64_t x; std::cin >> type >> x;

        if (type == 1) {
            cnt[x]++;
        } else if (type == 2) {
            cnt[x]--;
        } else {
            int dec = 0, res = 0, ans = 1;

            auto tcnt = cnt;

            auto p = cnt;
            for (int i = 1; i < 61; ++i) {
                p[i] += p[i - 1];
            }

            for (int i = 60; i >= 0; --i) {
                if (x >> i & 1) {
                    if (tcnt[i + dec]) {
                        ans = mul(ans, binpow(C(cnt[i + dec], tcnt[i + dec]), MOD - 2));
                        tcnt[i + dec]--;
                        ans = mul(ans, C(cnt[i + dec], tcnt[i + dec]));
                    } else {
                        ans = 0;
                        break;
                    }

                    dec++;
                } else {
                    if (tcnt[i + dec]) {
                        int nans = mul(ans, binpow(C(cnt[i + dec], tcnt[i + dec]), MOD - 2));

                        int sm = 0;
                        for (int j = cnt[i + dec] - tcnt[i + dec] + 1; j <= cnt[i + dec]; ++j) {
                            add_self(sm, C(cnt[i + dec], j));
                        }

                        add_self(res, mul(p2[p[i + dec] - cnt[i + dec]], mul(sm, nans)));
                    }
                }
            }

            int cn = 1;
            for (int i = dec - 1; i >= 0; --i) {
                if (cnt[i] > tcnt[i]) {
                    int cn1 = 0;

                    for (int j = cnt[i] - tcnt[i]; j <= cnt[i]; ++j) {
                        add_self(cn1, C(cnt[i], j));
                    }

                    ans = mul(ans, binpow(C(cnt[i], tcnt[i]), MOD - 2));
                    cn = mul(cn, cn1);
                } else {
                    cn = mul(cn, p2[cnt[i]]);
                }
            }

            add_self(res, mul(ans, cn));
            std::cout << res << '\n';
        }
    }
    return 0;
}
