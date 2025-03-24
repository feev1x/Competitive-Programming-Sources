/**
 *    author:  feev1x
 *    created: 10.03.2025 11:48:55
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

struct Line {
    mutable int64_t m, b, r;

    inline bool operator<(const Line &ot) const {
        return m < ot.m;
    }
    
    inline bool operator<(int64_t x) const {
        return r < x;
    }
};

struct Cht : std::multiset<Line, std::less<>> {
    inline int64_t div(int64_t a, int64_t b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    inline bool close(iterator x, iterator y) {
        if (y == end()) {
            return x->r = INF, false;
        }

        if (x->m == y->m) {
            x->r = x->b > y->b ? INF : -INF;
        } else {
            x->r = div(y->b - x->b, x->m - y->m); 
        }

        return x->r >= y->r;
    }

    inline void add(int64_t m, int64_t b) {
        auto z = insert({m, b, 0}), y = z++, x = y;

        while (close(y, z)) {
            z = erase(z);
        }

        if (x != begin() && close(--x, y)) {
            close(x, erase(y));
        }

        while ((y = x) != begin() && (--x)->r >= y->r) {
            close(x, erase(y));
        }
    }

    inline int64_t get(int64_t x) {
        auto f = *lower_bound(x);
        
        return f.m * x + f.b;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n), b(n);
    int opt = 0, sum = 0;
    for (auto &u: a) {
        std::cin >> u;

        sum += u;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    opt = b.back();
    for (auto &u: b) {
        u -= opt;
    }

    Cht cht;
    std::vector<int64_t> dp(n);

    cht.add(-b[0], 0);
    for (int i = 1; i < n; ++i) {
        dp[i] = -cht.get(a[i]);

        cht.add(-b[i], -dp[i]);
    }

    std::cout << dp.back() + (int64_t)sum * opt << '\n';
    return 0;
}
