#include "hack.h"
#include <bits/stdc++.h>

constexpr int N = 5e5;
bool calc;
std::vector<int> divs[N + 1];

int hack() {
    for (int i = 3; i <= N; ++i) {
        if (collisions({1, i})) {
            return i - 1;
        }
    }

    return N;
}
