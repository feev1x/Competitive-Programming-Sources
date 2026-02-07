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
    int n = rnd(5, 10), q = rnd(5, 10); cout << n << ' ' << q << '\n';

    for (int i = 0; i < n; ++i) {
        cout << rnd(1, 20) << " \n"[i == n - 1];
    }

    for (int i = 0; i < q; ++i) {
        int l = rnd(1, n), r = rnd(l, n), k = rnd(1, r - l + 1);

        std::cout << l << ' ' << r << ' ' << k << '\n';
    }

    return 0;
}
