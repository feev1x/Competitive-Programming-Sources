#include <bits/stdc++.h>
#include "ping-pong.h"
#include "sl.cpp"
using namespace std;

namespace combiGenerator {
    const int MAXIMUMVALUE = 5e6;
    const int MODULO = 1e9 + 7;

    int FACT[MAXIMUMVALUE + 1], INVFACT[MAXIMUMVALUE + 1];

    int logpower(int a, int n) {
        int p = 1;
        while(n) {
            if(n % 2 == 1)
                p = 1LL * p * a % MODULO;
            a = 1LL * a * a % MODULO;
            n /= 2;
        }
        return p;
    }

    void initialization() {
        FACT[0] = 1;
        for(int i = 1; i <= MAXIMUMVALUE; i++)
            FACT[i] = 1LL * FACT[i - 1] * i % MODULO;
        INVFACT[MAXIMUMVALUE] = logpower(FACT[MAXIMUMVALUE], MODULO - 2);
        for(int i = MAXIMUMVALUE - 1; i >= 0; i--)
            INVFACT[i] = 1LL * INVFACT[i + 1] * (i + 1) % MODULO;
    }
}



int combinations(int n, int k) {
    static bool firstTime = true;
    if(firstTime) {
        combiGenerator::initialization();
        firstTime = false;
    }
    if(n < 0 || k < 0)
        return 0;
    if(n > combiGenerator::MAXIMUMVALUE || k > combiGenerator::MAXIMUMVALUE)
        return 0;
    if(k > n)
        return 0;
    return 1LL * combiGenerator::FACT[n] * combiGenerator::INVFACT[k] % combiGenerator::MODULO
           * combiGenerator::INVFACT[n - k] % combiGenerator::MODULO;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
    return 0;
}
