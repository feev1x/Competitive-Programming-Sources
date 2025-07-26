/**
 *    author:  feev1x
 *    created: 31.10.2024 10:08:06
**/
#include "bits/stdc++.h"
using namespace std;

using i64 = long long;
using u64 = unsigned i64;
using i128 = __int128_t;
using u128 = __uint128_t;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<i64>(l, r)(rng)

signed main() {
    int n = rnd(1, 5), m = rnd(1, 5); std::cout << n << ' ' << m << '\n';

    char ch[]{'.', '*'};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            std::cout << ch[rnd(0, 1)];

        std::cout << '\n';
    }
    return 0;
}
