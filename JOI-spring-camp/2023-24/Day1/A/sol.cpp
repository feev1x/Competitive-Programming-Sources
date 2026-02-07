#include <bits/stdc++.h>

struct Segtree {
    std::vector<int64_t> t, psh;
    int n;

    Segtree(int n) : n(n) {
        t.resize(4 * n);
        psh.assign(4 * n, -1);
    }

    inline void push(int v, int tl, int tr) {
        if (psh[v] != -1) {
            int tm = tl + tr >> 1;

            psh[v << 1] = psh[v << 1 | 1] = psh[v];

            t[v << 1] = psh[v] * (tm - tl + 1);
            t[v << 1 | 1] = psh[v] * (tr - tm);

            psh[v] = -1;
        }
    }

    inline void update(int v, int tl, int tr, int l, int r, int64_t x) {
        if (tl > r || l > tr) {
            return;
        }

        if (l <= tl && tr <= r) {
            t[v] = x * (tr - tl + 1);
            psh[v] = x;
            return;
        }

        push(v, tl, tr);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr) {
            return 0ll;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        push(v, tl, tr);

        int tm = tl + tr >> 1;
        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline void update(int l, int r, int64_t x) {
        update(1, 1, n, l, r, x);
    }

    inline int64_t get(int l, int r) {
        if (l <= r) {
            return get(1, 1, n, l, r);
        }

        return (int64_t)0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; int64_t d; std::cin >> n >> d;

    std::vector<int64_t> c(n + 1), suff(n + 1), val(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> c[i];
    }

    {
        int64_t ls = 0, res = 0;
        for (int i = n - 1; i > 0; --i) {
            int64_t df = c[i + 1] - c[i];

            if (df < ls) {
                int64_t cnt = (ls - df + d - 1) / d;
                res += cnt;

                ls = df + cnt * d;
            } else {
                ls = df;
            }

            ls -= df;

            suff[i] = res;

            val[i] = ls;
        }
    }

    int q; std::cin >> q;
    std::vector<int64_t> ans(q);
    std::vector<std::vector<std::pair<int, int>>> qq(n + 1);
    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r;

        if (l == r) {
            continue;
        }

        qq[r - 1].emplace_back(i, l);
    }

    Segtree t(n);
    std::set<std::pair<int64_t, int>> st;
    for (int i = 1; i < n; ++i) {
        int l = i;

        int64_t df = c[i + 1] - c[i];
        while (st.size() && st.rbegin()->first > (val[i + 1] - df + d - 1) / d) {
            l = st.rbegin()->second;
            st.erase(--st.end());
        }

        t.update(l, i, std::max((val[i + 1] - df + d - 1) / d, (int64_t)0));

        st.emplace(std::max((val[i + 1] - df + d - 1) / d, (int64_t)0), l);

        for (auto [idx, l]: qq[i]) {
            int64_t ls = 0;
            int64_t df = c[i + 1] - c[i];

            if (df < ls) {
                int64_t cnt = (ls - df + d - 1) / d;

                ls = df + cnt * d;
            } else {
                ls = df;
            }

            ls -= df;

            int64_t ch = (val[i] - ls) / d;

            auto it = st.upper_bound({ch, 0});

            int r = i;
            int64_t add = 0;
            if (st.size() && it != st.end()) {
                add += ch * (i - std::max(it->second, l) + 1);
                r = std::max(it->second, l) - 1;
            }

            int64_t vl = val[l] - std::min(ch, t.get(l, l)) * d;
            ans[idx] = (vl > c[l] ? (int64_t)-1 : suff[l] - suff[i + 1] - t.get(l, r) - add);
        }
    }

    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}
