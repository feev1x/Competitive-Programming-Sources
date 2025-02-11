#include <iostream>
#include "cards.h"

using ll = long long;

static constexpr int MAX_N = 2e5;
static constexpr int MOD = 1e9 + 7;

int product(int a, int b) {

    if(a > b) return 0;
    if(a < 1) return 0;
    if(b > MAX_N) return 0;

    static int factorial[MAX_N + 5], inv_factorial[MAX_N + 5];
    static bool calculated = false;

    if (!calculated) {
        factorial[0] = 1;
        for (int i = 1; i <= MAX_N; i++)
            factorial[i] = (ll) factorial[i - 1] * i % MOD;

        inv_factorial[MAX_N] = 750007460;

        for (int i = MAX_N - 1; i >= 0; i--)
            inv_factorial[i] = (ll) inv_factorial[i + 1] * (i + 1) % MOD;

        calculated = true;
    }

    return (ll) factorial[b] * inv_factorial[a - 1] % MOD;
}

