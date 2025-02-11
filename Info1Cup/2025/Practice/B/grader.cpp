#include "products.h"
#include <iostream>

using namespace std;

namespace productGenerator {
    const int MOD = 1e9 + 7;
    const int NMAX = 2e6;
    bool usedAlready = 0;
    int f[NMAX + 1];
    int invf[NMAX + 1];
    int lgput(int a, int b) {
        int r = 1;
        while (b > 0) {
            if (b & 1)
                r = 1LL * r * a % MOD;
            a = 1LL * a * a % MOD;
            b >>= 1;
        }
        return r;
    }
    void init() {
        f[0] = 1;
        for (int i = 1; i <= NMAX; i++)
            f[i] = 1LL * f[i - 1] * i % MOD;
        invf[NMAX] = lgput(f[NMAX], MOD - 2);
        for (int i = NMAX - 1; i >= 0; i--)
            invf[i] = 1LL * invf[i + 1] * (i + 1) % MOD;
    }
}

int product(int i, int j) {
    if (productGenerator::usedAlready == false) {
        productGenerator::init();
        productGenerator::usedAlready = true;
    }
    if (i < 1 || j < 1 || i > j || j > productGenerator::NMAX)
        return 0;
    return 1LL * productGenerator::f[j] * productGenerator::invf[i - 1] % productGenerator::MOD;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
