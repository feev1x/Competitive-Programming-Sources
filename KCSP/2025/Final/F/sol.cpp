/**
 *    author:  feev1x
 *    created: 15.06.2025 11:39:55
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> p(n), s(n);
    for (auto &u: p) {
        std::cin >> u;
    }

    for (auto &u: s) {
        std::cin >> u;
    }

    std::set<std::array<int, 3>> pbs, sbp;
    for (int i = 0; i < n; ++i) {
        if (p[i] >= s[i]) {
            pbs.insert({s[i], p[i], i});
        }

        if (p[i] <= s[i]) {
            sbp.insert({p[i], s[i], i});
        }
    }

    int x = -1, y = -1, fir = 0, sec = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] <= s[i]) {
            sbp.erase({p[i], s[i], i});
        }

        auto it = sbp.upper_bound({std::min(p[i], s[i]), (int)1e9, n});

        
        if (sbp.size() && it != sbp.begin()) {
            --it;

            int fs = (*it)[0];
            int sc = std::min(p[i], (*it)[1]);

            if (fir < fs || fir == fs && sec < sc) {
                fir = fs, sec = sc;
                y = (*it)[2];
                x = i;
            }
        }

        if (p[i] <= s[i]) {
            sbp.insert({p[i], s[i], i});
        }
    }

    for (int i = 0; i < n; ++i) {
        if (p[i] >= s[i]) {
            pbs.erase({s[i], p[i], i});
        }

        auto it = pbs.upper_bound({std::min(s[i], p[i]), (int)1e9, n});
        
        if (pbs.size() && it != pbs.begin()) {
            --it;

            int fs = (*it)[0];
            int sc = std::min(s[i], (*it)[1]);

            if (fir < fs || fir == fs && sec < sc) {
                fir = fs, sec = sc;
                x = (*it)[2];
                y = i;
            }
        }

        if (p[i] >= s[i]) {
            pbs.insert({s[i], p[i], i});
        }
    }

    std::cout << x + 1 << ' ' << y + 1 << '\n';
    return 0;
}
