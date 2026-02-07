#include "grader.h"
#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int> (l, r)(rng)

void solve(int n) {
    int q;
    if (n <= 50) {
        q = 25;
    } else {
        q = 30;
    }

    while (q--) {
        int val = kth(rnd(1, n)), c = cnt(val);

        if (c > n / 3) {
            return say_answer(val);
        }
    }

    return say_answer(-1);
}
