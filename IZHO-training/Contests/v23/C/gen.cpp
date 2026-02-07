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
    int n = rnd(3, 15); cout << n << '\n';

    for (int i = 0; i < n; ++i) {
        cout << rnd(1, 100) << " \n"[i == n - 1];
    }

    for (int i = 0; i < n; ++i) {
        cout << rnd(1, 100) << " \n"[i == n - 1];
    }

    return 0;
}
