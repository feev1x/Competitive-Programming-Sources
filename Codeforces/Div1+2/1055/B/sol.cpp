#include <bits/stdc++.h>

inline void solve() {
    int n, rk, ck, rd, cd; std::cin >> n >> rk >> ck >> rd >> cd;

    int cr = 0, cc = 0;

    if (rk > rd) {
        cr = n - rk;
    } else { 
        cr = rk;
    }

    if (ck > cd) {
        cc = n - ck;
    } else {
        cc = ck;
    }

    std::cout << std::max((rk == rd ? std::abs(ck - cd) : cr) + (rk == rd ? 0 : std::max(std::abs(ck - cd) - cr, std::abs(rk - rd))), (ck == cd ? std::abs(rk - rd) : cc) + (ck == cd ? 0 : std::max(std::abs(ck - cd), std::abs(rk - rd) - cc))) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
