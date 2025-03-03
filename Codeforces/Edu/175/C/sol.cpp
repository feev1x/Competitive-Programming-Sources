/**
 *    author:  feev1x
 *    created: 27.02.2025 20:46:43
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::string s; std::cin >> s;

        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        if (std::count(s.begin(), s.end(), 'B') == 0) {
            std::cout << "0\n";
            
            continue;
        }

        std::vector<int> b;
        int l = 0, r = n - 1;
        
        while (s[l] == 'R') {
            l++;
        }

        while (s[r] == 'R') {
            r--;
        }

        int mx = a[l];
        for (int i = l + 1; i <= r; ++i) {
            if (s[i] != s[i - 1]) {
                b.emplace_back(mx);

                mx = 0;
            }

            mx = std::max(mx, a[i]);
        }

        b.emplace_back(mx);

        if (((int)b.size() + 1) / 2 <= k) {
            std::cout << "0\n";

            continue;
        }

        l = 0, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int m = l + r >> 1;
            
            std::vector<int> v;
            bool flag = false;
            int cnt = 0;
            for (int i = 0; i < b.size(); ++i) {
                if (b[i] > m) {
                    if (i & 1) {
                        cnt += flag;

                        flag = false;
                    } else {
                        flag = true;
                    }
                }
            }

            cnt += flag;

            if (cnt <= k) {
                r = m - 1;

                ans = m;
            } else {
                l = m + 1;
            }
        }

        std::cout << ans << '\n';
    }
    return 0;
}
