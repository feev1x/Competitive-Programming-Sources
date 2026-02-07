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
    std::cout << "1\n";

    i64 n = rnd(2, 10), m = rnd(1, 10); std::cout << n << ' ' << m << '\n';

    for (int i = 0; i < m; ++i) {
        i64 l = rnd(1, n - 1);

        std::cout << l << ' ' << rnd(l + 1, n) << '\n';
    }

    return 0;
}
