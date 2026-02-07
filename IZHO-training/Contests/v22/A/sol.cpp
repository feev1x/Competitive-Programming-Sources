#include <bits/stdc++.h>

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, M, q; std::cin >> n >> M >> q;

    std::map<int, int> mp;
    for (int i = 0; i < M; ++i) {
        int l, r; std::cin >> l >> r;

        mp[l] ^= 1;
        mp[r + 1] ^= 1;
    }

    std::vector<int> l, r, p, p2;
    
    int xr = 0, old = 1;
    for (auto [key, val]: mp) {
        if (val == 0) {
            continue;
        }

        if (xr) {
            int sm = (p2.size() ? mul(p2.back(), binpow(2, key - 1 - r.back())) : 0);

            l.emplace_back(old);
            r.emplace_back(key - 1);

            int pf = (p.size() ? p.back() : 0);
            p.emplace_back(key - old + pf);

            add_self(sm, binpow(2, key - old));
            add_self(sm, -1);
            p2.emplace_back(sm);
        }

        xr ^= val;

        old = key;
    }
    
    assert(!xr);

    while (q--) {
        int ql, qr, k; std::cin >> ql >> qr >> k;

        if (r.empty()) {
            std::cout << "0\n";
            continue;
        }

        int i = std::lower_bound(r.begin(), r.end(), ql) - r.begin(), si = (l[i] >= ql ? i : i + 1);
        int ei = std::upper_bound(l.begin(), l.end(), qr) - l.begin(), cn = 0;

        if (i >= r.size() || l[i] > qr) {
            std::cout << "0\n";
            continue;
        }

        if (l[i] < ql) {
            cn = r[i] - ql + 1;
        }

        int bl = si, br = ei - 1, ans = -1;
        while (bl <= br) {
            int m = bl + br >> 1;

            int c1 = p[m] - (si ? p[si - 1] : 0) + cn, c0 = (r[m] - ql + 1) - c1;

            if (c0 > (qr - ql + 1) - k) {
                br = m - 1;
            } else {
                bl = m + 1, ans = m;
            }
        }
        

        int cc0 = 0;
        if (ans != -1) {
            int c1 = p[ans] - (si ? p[si - 1] : 0), c0 = (r[ans] - ql + 1) - c1;
            cn += c1;
            cc0 = (qr - ql + 1) - k - c0;

            ans++;
        } else {
            if (si && r[si - 1] >= ql) {
                cc0 = l[si] - r[si - 1] - 1;
            } else {
                cc0 = l[si] - ql;
            }

            ans = si;
        }

        int res = 0;
        if (ans < ei) {
            if (ei) {
                if (r[ei - 1] > qr) {
                    int val = (ei - 1 ? mul(p2[ei - 2], binpow(2, qr - r[ei - 2])) : 0);

                    add_self(val, binpow(2, qr - l[ei - 1] + 1));
                    add_self(val, -1);

                    add_self(res, val);
                } else {
                    add_self(res, mul(p2[ei - 1], binpow(2, qr - r[ei - 1])));
                }

                if (ans) {
                    int sz = qr - r[ans - 1];
                    add_self(res, -mul(p2[ans - 1], binpow(2, sz)));
                }
            }
        }

        int pw = k - cn, num = binpow(2, cn);

        add_self(num, -1);

        if (pw < 0) {
            int sm = binpow(2, k);

            add_self(sm, -1);
            std::cout << sm << '\n';
            continue;
        }

        add_self(res, mul(num, binpow(2, pw)));

        std::cout << res << '\n';
    }

    return 0;
}
