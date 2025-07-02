/**
 *    author:  feev1x
 *    created: 29.03.2025 20:43:26
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int cnt1 = 0, cnt2 = 0;
        
        std::string a, b; std::cin >> a >> b;

        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                cnt1 += b[i] - '0';
                cnt2 += a[i] - '0';
            } else {
                cnt1 += a[i] - '0';
                cnt2 += b[i] - '0';
            }
        }

        if (cnt1 <= n / 2 && cnt2 <= (n + 1) / 2) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
