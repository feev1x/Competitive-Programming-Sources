#include "rotate.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

void energy(int n, std::vector<int> v){
    int p1 = v[0], p2 = v[1], ps1 = 0, ps2 = 1;

    if (p1 > p2) {
        std::swap(p1, p2);
        std::swap(ps1, ps2);
    }

    if (p2 - p1 <= 25000) {
        rotate({ps2}, -p2 + p1 + 25000);
    } else {
        rotate({ps1}, -p1 + p2 - 25000);
    }
}
