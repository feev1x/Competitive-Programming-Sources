/**
 *    author:  feev1x
 *    created: 10.03.2025 14:17:54
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1), pos(q + 1), x(q + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    
    for (int i = 1; i <= q; ++i) {
        std::cin >> pos[i];
    }

    std::multiset<int> l, r;

    int64_t suml = 0, sumr = 0;

    for (int i = 1; i <= n; ++i) {
        r.emplace(a[i]);

        sumr += a[i];
    }

    while (r.size() > l.size()) {
        l.emplace(*r.begin());

        suml += *r.begin();
        sumr -= *r.begin();

        r.erase(r.begin());
    }

    for (int i = 1; i <= q; ++i) {
        std::cin >> x[i];

        if (r.find(a[pos[i]]) != r.end()) {
            r.erase(r.find(a[pos[i]]));

            sumr -= a[pos[i]];
        } else {
            l.erase(l.find(a[pos[i]]));
            
            suml -= a[pos[i]];
        }

        a[pos[i]] = x[i];

        if (*l.rbegin() >= x[i]) {
            l.emplace(x[i]);

            suml += x[i];
        } else {
            r.emplace(x[i]);

            sumr += x[i];
        }

        while (l.size() > r.size()) {
            r.emplace(*l.rbegin());

            sumr += *l.rbegin();
            suml -= *l.rbegin();

            l.erase(--l.end());
        }

        while (r.size() > l.size()) {
            l.emplace(*r.begin());

            suml += *r.begin();
            sumr -= *r.begin();

            r.erase(r.begin());
        }

        std::cout << (sumr - suml + (n & 1 ? *l.rbegin() : 0)) * 2 << '\n';
    }
    return 0;
}
