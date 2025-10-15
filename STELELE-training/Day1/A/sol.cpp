#include <bits/stdc++.h>
#include "joker.h"

using namespace std;

void solve(int n) {
    if (n <= 2) {
        answer(0, 0);
        return;
    }

    std::vector<int> a;

    for (int i = 0; i < n; ++i)
        a.push_back(i);

    int mid = query(a); 

    a.clear();

    bool rev = true;
    int x = 10000, nw = 1;
    for (int i = mid - 1; i >= 0; --i) {
        a.emplace_back(x + nw * (rev ? -1 : 1));

        rev = !rev;
        if (rev)
            nw += 2;
    }

    std::reverse(a.begin(), a.end());

    rev = false, nw = 0;
    for (int i = mid; i < n; ++i) {
        a.emplace_back(x + nw * (rev ? -1 : 1));

        rev = !rev;
        if (rev)
            nw += 2;
    }

    int got = query(a);

    for (int i = 0; i < n; ++i)
        if (a[i] == got) {
            answer(std::min(mid, i), std::max(mid, i));
            return;
        }
}
