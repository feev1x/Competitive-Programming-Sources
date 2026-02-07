#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

struct Line {
    mutable int64_t m, b, r;

    inline bool operator<(const Line &a) const {
        return m > a.m;
    }

    inline bool operator<(int64_t x) const {
        return r < x;
    }
};

struct Cht : std::multiset<Line, std::less<>> {
    inline int64_t div(int64_t a, int64_t b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    inline bool isec(iterator x, iterator y) {
        if (y == end()) {
            x->r = INF;
            return false;
        }

        if (x->m == y->m) {
            x->r = x->b < y->b ? INF : -INF;
        } else {
            x->r = div(x->b - y->b, y->m - x->m);
        }

        return x->r >= y->r;
    }

    inline void add(int64_t m, int64_t b) {
        auto x = insert({m, b, -INF}), y = x++, z = y;

        while (isec(y, x)) {
            x = erase(x);
        }

        if (y != begin() && isec(--y, z)) {
            isec(y, z = erase(z));
        }

        while ((z = y) != begin() && (--y)->r >= z->r) {
            isec(y, erase(z));
        }
    }

    inline int64_t get(int64_t x) {
        auto y = lower_bound(x);

        return y->m * x + y->b;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; int64_t c; std::cin >> n >> c;

    std::vector<int64_t> h(n);
    for (auto &u: h) {
        std::cin >> u;
    }

    std::vector<int64_t> dp(n, INF);
    
    dp[0] = 0;

    Cht cht;

    cht.add(-2 * h[0], h[0] * h[0]);
    for (int i = 1; i < n; ++i) {
        dp[i] = cht.get(h[i]) + h[i] * h[i] + c;

        cht.add(-2 * h[i], h[i] * h[i] + dp[i]);
    }

    std::cout << dp.back() << '\n';
    return 0;
}
