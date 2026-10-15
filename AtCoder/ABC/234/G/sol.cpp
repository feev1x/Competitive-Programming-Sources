#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }
inline int mod(int a) { return (a % MOD + MOD) % MOD; }

struct Segtree {
    std::vector<int> t, psh;
    int n;
    Segtree(int n) : n(n) {
        t.resize(4 * n), psh.resize(4 * n);
    }
    inline int comb(int a, int b) {
        add_self(a, b);
        return a;
    }
    inline void apply(int v, int x) {
        add_self(t[v], x), add_self(psh[v], x);
    }
    inline void push(int v) {
        if (psh[v]) {
            apply(v << 1, psh[v]), apply(v << 1 | 1, psh[v]);
            psh[v] = 0;
        }
    }
    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl > r || l > tr) return;
        if (l <= tl && tr <= r) return apply(v, x);
        push(v);
        int tm = tl + tr >> 1;
        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);
        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr) return 0;
        if (l <= tl && tr <= r) return t[v];
        push(v);
        int tm = tl + tr >> 1;
        return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }
    inline void update(int l, int r, int x) { if (l <= r) update(1, 1, n, l + 1, r + 1, x); }
    inline int get(int l, int r) {
        if (l <= r) return get(1, 1, n, l + 1, r + 1);
        return 0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n + 1), lmn(n + 1), rmn(n + 1, n + 1), lmx(n + 1), rmx(n + 1, n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    Segtree dp(n + 1);
    {
        std::stack<int> stk, stk2;
        for (int i = 1; i <= n; ++i) {
            while (stk.size() && a[stk.top()] >= a[i]) stk.pop();
            while (stk2.size() && a[stk2.top()] <= a[i]) stk2.pop();
            if (stk.size()) lmn[i] = stk.top();
            if (stk2.size()) lmx[i] = stk2.top();
            stk.emplace(i), stk2.emplace(i);
        }
    }
    std::stack<int> stk, stk2;
    for (int i = n; i >= 1; --i) {
        while (stk.size() && a[stk.top()] > a[i]) stk.pop();
        while (stk2.size() && a[stk2.top()] < a[i]) stk2.pop();
        if (stk.size()) rmn[i] = stk.top();
        if (stk2.size()) rmx[i] = stk2.top();
        stk.emplace(i), stk2.emplace(i);
    }
    dp.update(0, 0, 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = mod(a[i]);
        dp.update(i, rmn[i] - 1, mul(mod(-a[i]), dp.get(lmn[i], i - 1)));
        dp.update(i, rmx[i] - 1, mul(a[i], dp.get(lmx[i], i - 1)));
    }
    std::cout << dp.get(n, n) << '\n';
    return 0;
}
