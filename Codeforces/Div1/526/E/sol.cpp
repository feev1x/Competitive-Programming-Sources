/**
 *    author:  feev1x
 *    created: 10.03.2025 09:17:53
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
            x->r = div(x->b - y->b, y->m - x->m);
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

    std::vector<int> x(n), y(n), pos(n);
    std::vector<int64_t> dp(n), a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> a[i];

        pos[i] = i;
    }


    std::sort(pos.begin(), pos.end(), [&](int i, int j) {
        return x[i] < x[j];
    });

    Cht cht;

    cht.add(0, 0);
    for (auto i: pos) {
        dp[i] = cht.get(y[i]) - a[i] + (int64_t)x[i] * y[i];

        cht.add(-x[i], dp[i]);
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
