/**
 *    author:  feev1x
 *    created: 02.02.2025 11:24:55
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, e, s; std::cin >> n >> e >> s;    

    std::vector<int> p(n), pref(n);
    for (auto &u: p) {
        std::cin >> u;
    }
    
    std::vector<int> ans(n + 1);
    std::vector<int> suf(n + 1);

    for (int i = 0; i < n; ++i) {
        if (i) {
            pref[i] = pref[i - 1];
        }

        pref[i] += p[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        int j = i + e + s, r = std::min(i + e - 1, n - 1);

        ans[i] = pref[r] - (i ? pref[i - 1] : 0);

        if (j < n) {
            ans[i] += suf[j];
        }

        suf[i] = std::max(suf[i + 1], ans[i]);
    }

    std::cout << suf[0] << '\n';
    return 0;
}
