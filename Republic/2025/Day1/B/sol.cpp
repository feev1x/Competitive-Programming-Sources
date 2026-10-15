#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;
constexpr int64_t INF = (int64_t)9e18;

struct Line {
    int64_t m, b;
    Line () { m = 0, b = -INF; }
    Line(int64_t m, int64_t b) : m(m), b(b) {}
    inline int64_t operator ()(int64_t x) { return m * x + b; }
};

struct Lichao {
    std::vector<Line> t;
    std::vector<int64_t> a;
    int n;
    Lichao(int n, const std::vector<int64_t> &a) : n(n), a(a) { t.resize(4 * n); }
    inline void update(int v, int tl, int tr, Line f) {
        int tm = tl + tr >> 1;
        if (f(a[tm]) > t[v](a[tm])) std::swap(f, t[v]);
        if (tl == tr) return;
        if (f(a[tl]) > t[v](a[tl])) return update(v << 1, tl, tm, f);
        update(v << 1 | 1, tm + 1, tr, f);
    }
    inline int64_t get(int v, int tl, int tr, int i) {
        if (tl == tr) return t[v](a[i]);
        int tm = tl + tr >> 1;
        if (i <= tm) return std::max(t[v](a[i]), get(v << 1, tl, tm, i));
        return std::max(t[v](a[i]), get(v << 1 | 1, tm + 1, tr, i));
    }
    inline void update(Line f) { update(1, 0, n - 1, f); }
    inline int64_t get(int i) { return get(1, 0, n - 1, i); }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; int64_t d; std::cin >> n >> d;
    std::vector<int64_t> a(n), dp(n, -INF);
    for (auto &u: a) std::cin >> u;
    auto b = a;
    std::sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int64_t sum = (a[0] - d) * (a[0] - d);
    Lichao t(b.size(), b);
    dp[0] = -sum;
    t.update({-2 * a[0], a[0] * a[0] + dp[0]});
    for (int i = 1; i < n; ++i) {
        dp[i] = t.get(std::lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + a[i] * a[i] + sum;
        sum += (a[i] - d) * (a[i] - d);
        dp[i] -= sum;
        t.update({-2 * a[i], a[i] * a[i] + dp[i]});
    }
    std::cout << dp[n - 1] + sum << '\n';
    return 0;
}
