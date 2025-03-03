/**
 *    author:  feev1x
 *    created: 16.02.2025 20:40:29
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::map<int, int> mp;
        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;

            mp[u]++;
        }

        int ls = -2, sz = -5, l = -1, r = -5, nw = n + 5;
        for (int i = 0; i < n; ++i) {
            if (mp[a[i]] == 1) {
                if (ls == -2) {
                    nw = i, sz = 1, l = i, r = i;
                } else if (ls != i - 1) {
                    nw = i; 
                }

                if (sz < i - nw + 1) {
                    sz = i - nw + 1;

                    l = nw, r = i;
                }

                ls = i;
            }
        }

        if (l == -1) {
            std::cout << "0\n";
        } else {
            std::cout << l + 1 << ' ' << r + 1 << '\n';
        }
    }
    return 0;
}
