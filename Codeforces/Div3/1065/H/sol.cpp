/**
 *    author:  feev1x
 *    created: 20.11.2025 21:17:43
**/
#include <bits/stdc++.h>

inline void chmax(int64_t &a, int64_t b) {
    if (a < b)
        a = b;
}

struct Bit {
    std::vector<int64_t> p;
    int n;

    Bit(int _n) : n(_n), p(n + 1) {}

    inline void update(int r, int64_t x) {
        for (; r <= n; r += r & -r)
            chmax(p[r], x);
    }

    inline int64_t get(int r) {
        int64_t res = 0;

        for (; r > 0; r -= r & -r)
            chmax(res, p[r]);

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        Bit bit(m);
        for (int i = 2; i <= n; ++i) {
            for (int j = m - (m % i); j >= i; j -= i) {
                int64_t mx = 1;

                for (int64_t pw = 1, k = 0; pw <= j; pw *= i, k++)
                    if (j % pw == 0)
                        mx = k;

                bit.update(j, bit.get(j - 1) + mx);
            }
        }

        std::cout << bit.get(m) << '\n';
    }
    return 0;
}
