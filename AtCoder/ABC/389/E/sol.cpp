/**
 *    author:  feev1x
 *    created: 12.02.2025 11:57:47
**/
#include <bits/stdc++.h>

#define int64_t __int128

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; long long m; std::cin >> n >> m;    

    std::vector<long long> p(n);
    for (auto &u: p) {
        std::cin >> u;
    }

    std::sort(p.begin(), p.end());

    int64_t l = 0, r = m, ans = 0;
    while (l <= r) {
        int64_t _m = l + r >> 1;

        int64_t cash = 0;
        for (auto u: p) {
            int64_t dv = _m / u; 

            int64_t k = dv + 1 >> 1;

            if (k > 1e9) {
                cash = m + 1;

                break;
            }

            cash += k * k * u;

            if (cash > m) {
                break;
            }
        }

        if (cash <= m) {
            l = _m + 1;

            ans = _m;
        } else {
            r = _m - 1;
        }
    }

    int64_t cash = 0; long long cnt = 0;
    for (auto u: p) {
        int64_t dv = ans / u;

        int64_t k = dv + 1 >> 1;

        cnt += k;
        cash += k * k * u;
    }

    cnt += (m - cash) / (ans + 1);

    std::cout << cnt << '\n';
    return 0;
}
