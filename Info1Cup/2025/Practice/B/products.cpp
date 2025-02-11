#include "products.h"

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

int solve(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        add_self(res, product(i, 2 * i));
    }

    return res;
}
