/**
 *    author:  feev1x
 *    created: 10.02.2025 10:35:50
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("convention.in", "r", stdin);
    std::freopen("convention.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, c; std::cin >> n >> m >> c;

    std::vector<int> t(n);
    for (auto &u: t) {
        std::cin >> u;
    }

    std::sort(t.begin(), t.end());

    auto Can = [&](int x) {
        if (c == 1) {
            return true;
        }

        int l = 0, cnt = 0;
        for (int r = 0; r < n; ++r) {
            if (t[r] - t[l] > x) {
                l = r;
                r--;
                cnt++;

                continue;
            }

            if (r - l + 1 == c) {
                l = r + 1;
                cnt++;

                continue; 
            }

            if (r == n - 1) {
                cnt++;

                break;
            }
        }

        return cnt <= m;
    };

    int l = 0, r = 1e9, ans = -1;
    while (l <= r) {
        int _m = l + r >> 1;

        if (Can(_m)) {
            r = _m - 1;
            ans = _m;
        } else {
            l = _m + 1;
        }
    }

    std::cout << ans << '\n';
    return 0;
}
